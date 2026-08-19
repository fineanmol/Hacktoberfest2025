#!/usr/bin/env node
'use strict';

const fs = require('fs');
const path = require('path');

const root = path.join(__dirname, '..');
const metaPath = path.join(root, 'site-meta.json');
const meta = JSON.parse(fs.readFileSync(metaPath, 'utf8'));

const owner = process.env.GITHUB_REPOSITORY
  ? process.env.GITHUB_REPOSITORY.split('/')[0]
  : meta.owner;
const repo = process.env.GITHUB_REPOSITORY
  ? process.env.GITHUB_REPOSITORY.split('/')[1]
  : meta.defaultRepoName;
const year = String(new Date().getFullYear());

const vars = {
  YEAR: year,
  REPO: repo,
  OWNER: owner,
  GITHUB_REPO: `https://github.com/${owner}/${repo}`,
  LIVE_URL: `https://${owner}.github.io/${repo}/`,
};

function render(templateName, outputName) {
  const templatePath = path.join(root, `${templateName}.template.md`);
  const outputPath = path.join(root, `${outputName}.md`);
  let content = fs.readFileSync(templatePath, 'utf8');

  for (const [key, value] of Object.entries(vars)) {
    content = content.split(`{{${key}}}`).join(value);
  }

  fs.writeFileSync(outputPath, content);
  console.log(`Wrote ${outputName}.md (${year}, ${owner}/${repo})`);
}

render('README', 'README');
render('CONTRIBUTING', 'CONTRIBUTING');
