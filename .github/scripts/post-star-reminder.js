module.exports = async ({ github, context, core }) => {
  const pr = context.payload.pull_request;
  const author = pr.user.login;
  const action = context.payload.action;
  const sender = context.payload.sender.login;

  const maintainerBots = ['fineanmol', 'github-actions[bot]'];
  if (action === 'synchronize' && maintainerBots.includes(sender)) {
    core.info(`Skipping star reminder for sync by ${sender}`);
    return;
  }

  const { data: fresh } = await github.rest.pulls.get({
    owner: context.repo.owner,
    repo: context.repo.repo,
    pull_number: pr.number,
  });

  if (fresh.mergeable === false || fresh.mergeable_state === 'dirty') {
    core.info('PR has merge conflicts — skipping star reminder');
    return;
  }

  const marker = '<!-- hacktoberfest-star-reminder -->';
  const body = [
    marker,
    `@${author} Please Star ⭐️ the repo to earn **hacktober-accepted** label for the event.`,
  ].join('\n');

  const { data: comments } = await github.rest.issues.listComments({
    owner: context.repo.owner,
    repo: context.repo.repo,
    issue_number: pr.number,
    per_page: 100,
  });

  const existing = comments.find((comment) => comment.body && comment.body.includes(marker));
  if (existing) {
    if (action === 'synchronize') {
      core.info('Star reminder already posted — skipping duplicate on sync');
      return;
    }
    await github.rest.issues.updateComment({
      owner: context.repo.owner,
      repo: context.repo.repo,
      comment_id: existing.id,
      body,
    });
    return;
  }

  await github.rest.issues.createComment({
    owner: context.repo.owner,
    repo: context.repo.repo,
    issue_number: pr.number,
    body,
  });
};
