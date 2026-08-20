function buildFlatNav(site) {
  const items = [
    { text: 'Contribute here', href: site.contribListUrl },
    { text: 'Project 1', href: 'https://github.com/fineanmol/Annoying-submit-button' },
    { text: 'Project 2', href: 'https://github.com/fineanmol/hacktoberfest' },
    { text: 'Instagram', href: 'https://instagram.com/fineanmol', icon: 'fa-instagram' },
    { text: 'Facebook', href: 'https://www.facebook.com/fineanmol', icon: 'fa-facebook' },
    { text: 'LinkedIn', href: 'https://www.linkedin.com/in/fineanmol/', icon: 'fa-linkedin' },
    { text: 'Twitter', href: 'https://twitter.com/fineanmol', icon: 'fa-twitter' },
    { text: 'GitHub', href: site.githubRepo, icon: 'fa-github' },
    { text: 'Fork', href: site.forkUrl },
  ];

  const menu = document.getElementById('menu');
  if (!menu) {
    return;
  }

  menu.innerHTML = items
    .map((item) => {
      const label = item.icon
        ? `<i class="fa ${item.icon}" aria-hidden="true"></i> ${item.text}`
        : item.text;
      return (
        `<li class="nav-item">` +
        `<a class="nav-link" target="_blank" rel="noopener noreferrer" href="${item.href}">${label}</a>` +
        `</li>`
      );
    })
    .join('');
}

initHacktoberfestSite(buildFlatNav);
