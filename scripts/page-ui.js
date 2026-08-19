(function () {
  const backToTopButton = document.querySelector('#back-to-top-btn');

  function easeInOutCubic(t, b, c, d) {
    t /= d / 2;
    if (t < 1) {
      return (c / 2) * t * t * t + b;
    }
    t -= 2;
    return (c / 2) * (t * t * t + 2) + b;
  }

  function scrollFunction() {
    if (!backToTopButton) {
      return;
    }
    if (window.pageYOffset > 300) {
      if (!backToTopButton.classList.contains('btnEntrance')) {
        backToTopButton.classList.remove('btnExit');
        backToTopButton.classList.add('btnEntrance');
        backToTopButton.style.display = 'block';
      }
    } else if (backToTopButton.classList.contains('btnEntrance')) {
      backToTopButton.classList.remove('btnEntrance');
      backToTopButton.classList.add('btnExit');
      setTimeout(() => {
        backToTopButton.style.display = 'none';
      }, 250);
    }
  }

  function smoothScrollBackToTop() {
    const startPosition = window.pageYOffset;
    const distance = -startPosition;
    const duration = 750;
    let start = null;

    function step(timestamp) {
      if (!start) {
        start = timestamp;
      }
      const progress = timestamp - start;
      window.scrollTo(0, easeInOutCubic(progress, startPosition, distance, duration));
      if (progress < duration) {
        window.requestAnimationFrame(step);
      }
    }

    window.requestAnimationFrame(step);
  }

  if (backToTopButton) {
    window.addEventListener('scroll', scrollFunction, { passive: true });
    backToTopButton.addEventListener('click', smoothScrollBackToTop);
  }

  const themeToggle = document.querySelector('.tdnn');
  if (themeToggle) {
    themeToggle.addEventListener('click', () => {
      document.body.classList.toggle('light');
      document.querySelector('.moon')?.classList.toggle('sun');
      themeToggle.classList.toggle('day');
    });
  }

  if (typeof AOS !== 'undefined') {
    AOS.init();
  }
})();
