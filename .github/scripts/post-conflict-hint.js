module.exports = async ({ github, context, core }) => {
  const pr = context.payload.pull_request;

  async function getPullRequest() {
    for (let attempt = 0; attempt < 6; attempt += 1) {
      const { data } = await github.rest.pulls.get({
        owner: context.repo.owner,
        repo: context.repo.repo,
        pull_number: pr.number,
      });
      if (data.mergeable !== null) {
        return data;
      }
      core.info(`mergeable is null — waiting (attempt ${attempt + 1}/6)`);
      await new Promise((resolve) => setTimeout(resolve, 5000));
    }
    return (
      await github.rest.pulls.get({
        owner: context.repo.owner,
        repo: context.repo.repo,
        pull_number: pr.number,
      })
    ).data;
  }

  function hasConflicts(pull) {
    return pull.mergeable === false || pull.mergeable_state === 'dirty';
  }

  const fresh = await getPullRequest();
  if (!hasConflicts(fresh)) {
    core.info(
      `PR #${pr.number} mergeable=${fresh.mergeable}, state=${fresh.mergeable_state} — no conflict hint needed`
    );
    return;
  }

  const marker = '<!-- merge-conflict-hint -->';
  const { data: comments } = await github.rest.issues.listComments({
    owner: context.repo.owner,
    repo: context.repo.repo,
    issue_number: pr.number,
    per_page: 100,
  });

  if (comments.some((comment) => comment.body && comment.body.includes(marker))) {
    core.info('Conflict hint already posted');
    return;
  }

  const baseBranch = pr.base.ref;
  const body = [
    marker,
    '🔧 **Merge conflicts detected**',
    '',
    'To fix:',
    `1. \`git fetch upstream\` and merge latest \`${baseBranch}\` into your branch`,
    '2. Resolve conflicts locally',
    '3. Push your branch — we will merge once it is clean',
  ].join('\n');

  await github.rest.issues.createComment({
    owner: context.repo.owner,
    repo: context.repo.repo,
    issue_number: pr.number,
    body,
  });
};
