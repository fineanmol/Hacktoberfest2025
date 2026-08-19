(function () {
  const searchbox = document.getElementById('search');
  const container = document.getElementById('contributors');
  const loadMoreBtn = document.getElementById('loadMore');
  let visibleCount = 72;

  function githubHandle(url) {
    const match = String(url).match(/github\.com\/?([^/?#]+)/i);
    return match ? match[1].replace(/\/$/, '') : '';
  }

  function profileUrl(url) {
    const handle = githubHandle(url);
    return handle ? `https://github.com/${handle}` : url;
  }

  function avatarUrl(url) {
    const handle = githubHandle(url);
    return handle ? `https://avatars.githubusercontent.com/${handle}` : '';
  }

  function filterUsers(query, list) {
    const term = query.trim().toLowerCase();
    if (!term) {
      return list;
    }
    return list.filter((item) => (item.fullname || '').toLowerCase().includes(term));
  }

  function createCard(item) {
    const card = document.createElement('a');
    card.className = 'box-item';
    card.href = profileUrl(item.username);
    card.target = '_blank';
    card.rel = 'noopener noreferrer';

    const name = document.createElement('span');
    name.textContent = item.fullname;
    card.appendChild(name);

    const imgSrc = avatarUrl(item.username);
    if (imgSrc) {
      const img = document.createElement('img');
      img.loading = 'lazy';
      img.alt = item.fullname;
      img.src = imgSrc;
      card.appendChild(img);
    }

    return card;
  }

  function render(list, limit) {
    if (!container) {
      return;
    }
    container.innerHTML = '';
    const max = limit ?? list.length;
    list.forEach((item) => {
      if (item.id <= max) {
        container.appendChild(createCard(item));
      }
    });
  }

  function updateLoadMoreState(total) {
    if (!loadMoreBtn) {
      return;
    }
    loadMoreBtn.hidden = visibleCount >= total;
  }

  render(contributors, visibleCount);
  updateLoadMoreState(contributors.length);

  if (loadMoreBtn) {
    loadMoreBtn.addEventListener('click', () => {
      visibleCount += 84;
      render(contributors, visibleCount);
      updateLoadMoreState(contributors.length);
    });
  }

  if (searchbox) {
    searchbox.addEventListener('input', (event) => {
      const query = event.target.value;
      if (loadMoreBtn) {
        loadMoreBtn.classList.toggle('hidden', query.trim() !== '');
      }

      const results = filterUsers(query, contributors);
      if (query.trim() !== '') {
        container.innerHTML = '';
        results.forEach((item) => container.appendChild(createCard(item)));
        return;
      }

      render(contributors, visibleCount);
      updateLoadMoreState(contributors.length);
    });
  }
})();
