#!/usr/bin/env python3
"""
issue_summarizer.py

Generate a triage-ready summary of open GitHub issues for a repository.

Usage:
    export GITHUB_TOKEN="ghp_..."
    python issue_summarizer.py --owner owner --repo repo --limit 20 --post

Options:
    --owner         GitHub owner/org (required)
    --repo          Repository name (required)
    --limit         How many issues to include in the summary (default 25)
    --post          Post the generated summary as a new issue to the repo
    --since         ISO date (YYYY-MM-DD) to only consider issues updated since this date
    --label-filter  Only include issues with this label (can pass multiple times)
    --format        Output format: md (default) or json
    --token         GitHub token. If omitted the script reads GITHUB_TOKEN env var or .env
"""

from __future__ import annotations
import os
import argparse
import json
import textwrap
from collections import defaultdict, Counter
from datetime import datetime
from typing import List, Optional, Dict, Any
from github import Github, GithubException
from dotenv import load_dotenv

load_dotenv()

# ---------- Configurable simple keyword-label map ----------
KEYWORD_LABEL_MAP = {
    "bug": ["bug", "exception", "traceback", "crash", "error", "fail", "wrong"],
    "enhancement": ["feature", "enhanc", "improve", "proposal", "request"],
    "docs": ["doc", "readme", "documentation", "typo", "guide", "docs/"],
    "question": ["how to", "why", "question", "help", "usage"],
    "tests": ["test", "pytest", "coverage", "flaky"],
    "ci": ["ci", "github actions", "workflow", ".github", "pipeline"],
    "performance": ["slow", "performance", "optimi", "latency", "throughput"],
}

# ---------- Helpers ----------
def get_token(cli_token: Optional[str]) -> str:
    token = cli_token or os.getenv("GITHUB_TOKEN")
    if not token:
        raise SystemExit("Provide a GitHub token via --token or GITHUB_TOKEN env var.")
    return token

def suggest_labels_for_text(text: str) -> List[str]:
    text_lower = text.lower()
    suggestions = set()
    for label, keywords in KEYWORD_LABEL_MAP.items():
        for kw in keywords:
            if kw in text_lower:
                suggestions.add(label)
                break
    return sorted(suggestions)

def excerpt(text: Optional[str], length: int = 200) -> str:
    if not text:
        return ""
    s = " ".join(text.strip().splitlines())
    s = s.strip()
    if len(s) <= length:
        return s
    # trim to last whitespace within length
    cut = s[:length].rsplit(" ", 1)[0]
    return cut + "..."

def iso_now() -> str:
    return datetime.utcnow().isoformat() + "Z"

# ---------- Core logic ----------
def fetch_issues(g: Github, owner: str, repo_name: str, since: Optional[str], label_filters: List[str]) -> List[Dict[str, Any]]:
    try:
        repo = g.get_repo(f"{owner}/{repo_name}")
    except GithubException as e:
        raise SystemExit(f"Could not access repository {owner}/{repo_name}: {e}")

    gh_kwargs = {"state": "open", "sort": "created", "direction": "desc"}
    if since:
        # GitHub API accepts datetime for since parameter in get_issues; use updated since
        try:
            dt = datetime.fromisoformat(since)
            gh_kwargs["since"] = dt
        except Exception:
            print("Warning: invalid --since format, expected YYYY-MM-DD or ISO. Ignoring.")
    issues = repo.get_issues(state="open")  # we filter locally for more control

    results = []
    for i in issues:
        # Exclude pull requests (issues that are PRs have pull_request attr)
        if i.pull_request is not None:
            continue
        if label_filters:
            names = [l.name for l in i.labels]
            if not any(l in names for l in label_filters):
                continue
        results.append({
            "number": i.number,
            "title": i.title,
            "labels": [l.name for l in i.labels],
            "created_at": i.created_at.isoformat(),
            "updated_at": i.updated_at.isoformat(),
            "user": i.user.login if i.user else None,
            "comments": i.comments,
            "body": i.body or "",
            "html_url": i.html_url,
            "issue_obj": i,  # keep for optional posting
        })
    return results

def build_summary(owner: str, repo: str, issues: List[Dict[str, Any]], limit: int = 25) -> str:
    total = len(issues)
    by_label = defaultdict(list)
    unlabeled = []
    comment_sorted = sorted(issues, key=lambda x: x["comments"], reverse=True)
    created_sorted = sorted(issues, key=lambda x: x["created_at"], reverse=True)

    for i in issues:
        if i["labels"]:
            for l in i["labels"]:
                by_label[l].append(i)
        else:
            unlabeled.append(i)

    label_counts = {l: len(lst) for l, lst in by_label.items()}
    lines = []
    header = f"# Issue Triage Summary — {owner}/{repo}\n\n"
    header += f"- Generated: {iso_now()}\n- Open issues considered: {total}\n\n"
    lines.append(header)

    # label counts
    if label_counts:
        lines.append("## Counts by label\n")
        for l, c in sorted(label_counts.items(), key=lambda kv: kv[1], reverse=True):
            lines.append(f"- **{l}**: {c}")
        lines.append("\n")
    else:
        lines.append("## Counts by label\n\n_No labeled issues found._\n\n")

    # Unlabeled issues + suggestions
    lines.append("## Unlabeled issues (with suggested labels)\n")
    if not unlabeled:
        lines.append("_No unlabeled issues._\n")
    else:
        for u in unlabeled[:limit]:
            s = excerpt(u["body"], 240)
            suggestions = suggest_labels_for_text(u["title"] + "\n" + (u["body"] or ""))
            sug_txt = ", ".join(suggestions) if suggestions else "—"
            lines.append(f"### #{u['number']} {u['title']}")
            lines.append(f"- Author: `{u['user']}` • Comments: {u['comments']} • Updated: {u['updated_at']}")
            lines.append(f"- URL: {u['html_url']}")
            lines.append(f"- Excerpt: \n\n```\n{s}\n```\n")
            lines.append(f"- Suggested labels: **{sug_txt}**\n")
    lines.append("\n")

    # Top commented issues
    lines.append("## Top commented issues\n")
    top_commented = comment_sorted[: min(limit, len(comment_sorted))]
    if not top_commented:
        lines.append("_No issues found._\n")
    else:
        for t in top_commented:
            s = excerpt(t["body"], 200)
            labels = ", ".join(t["labels"]) or "—"
            lines.append(f"- **#{t['number']} {t['title']}** ({t['comments']} comments) — Labels: {labels}")
            lines.append(f"  - {s}")
            lines.append(f"  - {t['html_url']}")
    lines.append("\n")

    # Newest issues
    lines.append("## Newest issues\n")
    newest = created_sorted[: min(limit, len(created_sorted))]
    for n in newest:
        s = excerpt(n["body"], 160)
        labels = ", ".join(n["labels"]) or "—"
        lines.append(f"- **#{n['number']} {n['title']}** — {labels}")
        lines.append(f"  - {s}")
        lines.append(f"  - {n['html_url']}")
    lines.append("\n")

    # Simple metrics
    avg_comments = sum(i["comments"] for i in issues) / (len(issues) or 1)
    lines.append("## Quick metrics\n")
    lines.append(f"- Total open issues: {total}")
    lines.append(f"- Average comments per issue: {avg_comments:.2f}")
    most_active_labels = Counter([lab for i in issues for lab in i["labels"]])
    if most_active_labels:
        top_labels = ", ".join(f"{k} ({v})" for k, v in most_active_labels.most_common(5))
        lines.append(f"- Most frequent labels: {top_labels}")
    else:
        lines.append("- Most frequent labels: —")
    lines.append("\n---\n_Auto-generated by `issue_summarizer.py` — adjust rules in KEYWORD_LABEL_MAP to improve suggestions._\n")
    return "\n".join(lines)

# ---------- CLI & action ----------
def main_cli():
    ap = argparse.ArgumentParser(description="Generate an issue triage summary for a GitHub repo.")
    ap.add_argument("--owner", required=True, help="GitHub owner/org")
    ap.add_argument("--repo", required=True, help="Repository name")
    ap.add_argument("--limit", type=int, default=20, help="How many items to show per section")
    ap.add_argument("--post", action="store_true", help="Create a new issue with the generated summary")
    ap.add_argument("--since", default=None, help="Only consider issues updated since this ISO date (YYYY-MM-DD)")
    ap.add_argument("--label-filter", action="append", default=[], help="Only include issues with this label (repeatable)")
    ap.add_argument("--format", choices=("md", "json"), default="md", help="Output format")
    ap.add_argument("--token", default=None, help="GitHub token (optional)")
    args = ap.parse_args()

    token = get_token(args.token)
    g = Github(token)

    issues = fetch_issues(g, args.owner, args.repo, args.since, args.label_filter)
    if not issues:
        print("No issues found (after filters). Exiting.")
        return

    if args.format == "json":
        # produce compact JSON metadata
        dump = json.dumps([{
            "number": i["number"],
            "title": i["title"],
            "labels": i["labels"],
            "comments": i["comments"],
            "url": i["html_url"]
        } for i in issues[: args.limit]], indent=2)
        print(dump)
        if args.post:
            print("Posting JSON as issue body not supported. Use --format md to post.")
        return

    # md
    summary_md = build_summary(args.owner, args.repo, issues, limit=args.limit)

    # output locally
    out_file = f"{args.repo}_issues_summary.md"
    with open(out_file, "w", encoding="utf-8") as f:
        f.write(summary_md)
    print(f"Wrote summary to {out_file}")

    if args.post:
        try:
            repo = g.get_repo(f"{args.owner}/{args.repo}")
            title = f"Issue Triage Summary — {datetime.utcnow().strftime('%Y-%m-%d')}"
            created_issue = repo.create_issue(title=title, body=summary_md)
            print(f"Posted summary as issue: {created_issue.html_url}")
        except GithubException as e:
            print("Failed to create issue:", e)

if __name__ == "__main__":
    main_cli()
