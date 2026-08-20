(function (global) {
  const FALLBACK = { owner: 'fineanmol', defaultRepoName: 'Hacktoberfest2025' };

  function repoNameFromPath(meta) {
    const segment = window.location.pathname.split('/').filter(Boolean)[0];
    if (segment && !segment.includes('.')) {
      return segment;
    }
    return meta.defaultRepoName || FALLBACK.defaultRepoName;
  }

  async function loadMeta() {
    try {
      const response = await fetch('./site-meta.json', { cache: 'no-store' });
      if (response.ok) {
        return { ...FALLBACK, ...(await response.json()) };
      }
    } catch (_) {
      /* local file:// or offline */
    }
    return { ...FALLBACK };
  }

  async function buildSiteConfig() {
    const meta = await loadMeta();
    const repoName = repoNameFromPath(meta);
    const owner = meta.owner || FALLBACK.owner;
    const year = new Date().getFullYear();

    return {
      owner,
      repoName,
      year,
      githubRepo: `https://github.com/${owner}/${repoName}`,
      liveUrl: `https://${owner}.github.io/${repoName}/`,
      contribListUrl: `https://github.com/${owner}/${repoName}/blob/master/contributors/contributorsList.js`,
      forkUrl: `https://github.com/${owner}/${repoName}/fork`,
    };
  }

  function applySiteLabels(site) {
    document.title = `Hacktoberfest ${site.year} - Contributors`;

    const logoTitle = document.getElementById('site-logo-title');
    if (logoTitle) {
      logoTitle.textContent = `Hacktoberfest ${site.year}`;
    }

    const footerHeading = document.getElementById('site-footer-heading');
    if (footerHeading) {
      footerHeading.textContent = `Hacktoberfest ${site.year}`;
    }

    const footerCopy = document.getElementById('site-footer-copy');
    if (footerCopy) {
      footerCopy.innerHTML =
        `This project takes part in <b>Hacktoberfest</b>. Copyright &copy; ${site.year}.`;
    }

    const brand = document.getElementById('site-brand');
    if (brand) {
      brand.setAttribute('href', site.liveUrl);
    }

    document.querySelectorAll('[data-site-github]').forEach((el) => {
      el.setAttribute('href', site.githubRepo);
      const label = el.getAttribute('aria-label');
      if (label) {
        el.setAttribute('aria-label', label.replace(/fineanmol\/[^\s"]+/, `${site.owner}/${site.repoName}`));
      }
    });

    const stats = document.getElementById('stats');
    if (stats) {
      stats.innerHTML =
        `Built for Hacktoberfest ${site.year} contributors. ` +
        `<a href="${site.githubRepo}" target="_blank" rel="noopener noreferrer">View the repo on GitHub</a>.`;
    }
  }

  global.initHacktoberfestSite = async function initHacktoberfestSite(onReady) {
    const site = await buildSiteConfig();
    applySiteLabels(site);
    if (typeof onReady === 'function') {
      onReady(site);
    }
    return site;
  };
})(window);
