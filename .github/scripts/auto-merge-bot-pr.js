const ALLOWED_BOT_LOGINS = new Set([
  'app/imgbot',
  'imgbot[bot]',
  'dependabot[bot]',
  'dependabot-preview[bot]',
  'renovate[bot]',
]);

function sleep(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

function isAllowedBot(user) {
  if (!user) {
    return false;
  }
  if (user.login === 'github-actions[bot]') {
    return false;
  }
  if (ALLOWED_BOT_LOGINS.has(user.login)) {
    return true;
  }
  return user.type === 'Bot';
}

function getPullRequestsFromContext(context) {
  if (context.payload.pull_request) {
    return [context.payload.pull_request];
  }

  if (context.payload.check_suite?.pull_requests?.length) {
    return context.payload.check_suite.pull_requests;
  }

  return [];
}

async function getPullRequestsForWorkflowRun(github, owner, repo, workflowRun) {
  const { data: prs } = await github.rest.pulls.list({
    owner,
    repo,
    state: 'open',
    head: `${owner}:${workflowRun.head_branch}`,
    per_page: 10,
  });

  return prs.filter((pr) => pr.head.sha === workflowRun.head_sha);
}

async function resolvePullRequests(github, context, core) {
  const { owner, repo } = context.repo;

  if (context.eventName === 'workflow_run') {
    const workflowRun = context.payload.workflow_run;
    if (workflowRun.conclusion !== 'success') {
      core.info(`workflow_run conclusion=${workflowRun.conclusion} — skip`);
      return [];
    }

    return getPullRequestsForWorkflowRun(github, owner, repo, workflowRun);
  }

  return getPullRequestsFromContext(context);
}

function requiredCheckName() {
  return process.env.REQUIRED_CHECK_NAME || 'validate';
}

async function requiredCheckPassed(github, owner, repo, sha, core, { wait = false } = {}) {
  const checkName = requiredCheckName();
  const attempts = wait ? 12 : 1;

  for (let attempt = 0; attempt < attempts; attempt += 1) {
    const { data } = await github.rest.checks.listForRef({
      owner,
      repo,
      ref: sha,
    });

    const checkRun = data.check_runs.find((run) => run.name === checkName);
    if (!checkRun) {
      core.info(`No ${checkName} check run found yet`);
    } else if (checkRun.status !== 'completed') {
      core.info(`${checkName} check status=${checkRun.status}`);
    } else if (checkRun.conclusion === 'success') {
      return true;
    } else {
      core.info(`${checkName} check conclusion=${checkRun.conclusion}`);
      return false;
    }

    if (attempt + 1 < attempts) {
      core.info(`Waiting for ${checkName} check (attempt ${attempt + 1}/${attempts})`);
      await sleep(15000);
    }
  }

  return false;
}

async function getMergeablePull(github, owner, repo, pullNumber, core) {
  for (let attempt = 0; attempt < 6; attempt += 1) {
    const { data } = await github.rest.pulls.get({
      owner,
      repo,
      pull_number: pullNumber,
    });

    if (data.mergeable !== null) {
      return data;
    }

    core.info(`PR #${pullNumber} mergeable is null — waiting (attempt ${attempt + 1}/6)`);
    await sleep(5000);
  }

  return (
    await github.rest.pulls.get({
      owner,
      repo,
      pull_number: pullNumber,
    })
  ).data;
}

module.exports = async ({ github, context, core }) => {
  const { owner, repo } = context.repo;
  const pullRequests = await resolvePullRequests(github, context, core);
  const waitForCheck =
    context.eventName === 'pull_request' ||
    context.eventName === 'pull_request_target' ||
    context.eventName === 'check_suite';

  if (pullRequests.length === 0) {
    core.info('No pull requests to process for this event');
    return;
  }

  for (const pr of pullRequests) {
    const pullNumber = pr.number;
    const fresh = await getMergeablePull(github, owner, repo, pullNumber, core);

    if (fresh.state !== 'open') {
      core.info(`PR #${pullNumber} is ${fresh.state} — skip`);
      continue;
    }

    if (fresh.merged) {
      core.info(`PR #${pullNumber} already merged — skip`);
      continue;
    }

    if (!isAllowedBot(fresh.user)) {
      core.info(
        `PR #${pullNumber} author @${fresh.user.login} is not an allowed bot — skip`
      );
      continue;
    }

    if (fresh.mergeable !== true) {
      core.info(
        `PR #${pullNumber} not mergeable (mergeable=${fresh.mergeable}, state=${fresh.mergeable_state}) — skip`
      );
      continue;
    }

    const checkOk = await requiredCheckPassed(
      github,
      owner,
      repo,
      fresh.head.sha,
      core,
      { wait: waitForCheck }
    );
    if (!checkOk) {
      core.info(`PR #${pullNumber} ${requiredCheckName()} check not green — skip`);
      continue;
    }

    core.info(`Merging bot PR #${pullNumber} from @${fresh.user.login}`);
    await github.rest.pulls.merge({
      owner,
      repo,
      pull_number: pullNumber,
      merge_method: 'squash',
    });
    core.info(`Merged PR #${pullNumber}`);
  }
};
