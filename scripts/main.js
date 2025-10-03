// Initialize AOS (Animate On Scroll)
AOS.init();

// Array containing contributors data
const Contributors = contributors;

// ---------- Utilities for safe rendering and URL parsing ----------
function getGithubUsernameFromUrl(possibleUrl) {
  try {
    if (typeof possibleUrl !== "string" || possibleUrl.trim() === "") return null;
    // Accept plain usernames as well as full URLs
    if (!possibleUrl.includes("/")) return possibleUrl.trim();
    const url = new URL(possibleUrl);
    if (url.hostname !== "github.com") return null;
    const path = url.pathname.replace(/^\/+/, "").split("/");
    const username = path[0] || null;
    return username && username.length > 0 ? username : null;
  } catch (_) {
    // Handle malformed URLs like 'https://github,com/...'
    const fixed = possibleUrl.replace(",", ".");
    try {
      const url = new URL(fixed);
      if (url.hostname !== "github.com") return null;
      const path = url.pathname.replace(/^\/+/, "").split("/");
      const username = path[0] || null;
      return username && username.length > 0 ? username : null;
    } catch (__){
      return null;
    }
  }
}

function createAvatarImg(username) {
  const img = document.createElement("img");
  img.loading = "lazy";
  img.dataset.src = username
    ? `https://avatars.githubusercontent.com/${username}`
    : "https://avatars.githubusercontent.com/ghost";
  img.alt = username ? `${username}'s avatar` : "avatar";
  return img;
}

function createContributorAnchor(item) {
  const anchor = document.createElement("a");
  anchor.className = "box-item";
  const username = getGithubUsernameFromUrl(item.username);
  const href = typeof item.username === "string" ? item.username : "";
  if (href) {
    anchor.setAttribute("href", href);
    anchor.setAttribute("target", "_blank");
    anchor.setAttribute("rel", "noopener noreferrer");
  }

  const nameSpan = document.createElement("span");
  nameSpan.textContent = item.fullname || "Anonymous";
  anchor.appendChild(nameSpan);

  const img = createAvatarImg(username);
  anchor.appendChild(img);
  return anchor;
}

// Variables
const searchbox = document.getElementById("search");
let searchResult = null;
// Pagination state
let pageSize = 60;
let currentPage = 1;

// Get the current year dynamically
const currentYear = new Date().getFullYear();

// Function to set the current year in the HTML
function setCurrentYear() {
  const yearElements = [
    // { id: "current-year", defaultValue: currentYear },
    { id: "current-year-title", defaultValue: currentYear },
    { id: "current-year-footer", defaultValue: currentYear },
    { id: "current-year-copyright", defaultValue: currentYear },
  ];

  yearElements.forEach((element) => {
    const el = document.getElementById(element.id);
    if (el) {
      el.textContent = element.defaultValue;
    } else {
      console.warn(`Element with ID '${element.id}' not found in the DOM.`);
    }
  });

  // Set the document title with the current year
  document.title = `Hacktoberfest ${currentYear} - Contributors`;
}

// Call the function to set the current year
setCurrentYear();

/**
 * Filters contributors based on the search string.
 * @param {string} str - The search string.
 * @param {Array} array - The array of contributors.
 * @returns {Array} - The filtered list of contributors.
 */
function filterUsers(str = "ContributorName", array) {
  const inputString = typeof str === "string" ? str.toLowerCase() : "";
  if (str === "") return "Cannot be empty, please enter a name";
  return array.filter((item) => {
    const fullName = item.fullname || "";
    return fullName.toLowerCase().includes(inputString);
  });
}

/**
 * Renders the contributors on the page.
 * @param {Array} array - The array of contributors to render.
 * @param {Object} options - render options
 * @param {boolean} options.paginate - whether to paginate the array
 */
function render(array, options = { paginate: true }) {
  const container = document.getElementById("contributors");
  if (!container) {
    console.warn("Contributors container not found");
    return;
  }
  const list = options.paginate
    ? array.slice(0, currentPage * pageSize)
    : array;
  list.forEach((item) => {
    const anchor = createContributorAnchor(item);
    anchor.setAttribute("id", item.id);
    container.appendChild(anchor);
  });
  // After rendering batch, invoke lazy loading for avatars
  setupLazyLoadImages();
  // And ensure infinite scroll sentinel is available
  setupLoadMoreOnScroll();
}

// Load contributors after document loads.
render(contributors, { paginate: true });

/**
 * Loads more contributors when "Load More" button is clicked.
 */
function loadMore() {
  const container = document.getElementById("contributors");
  if (!container) return;
  const totalPages = Math.ceil(contributors.length / pageSize);
  if (currentPage >= totalPages) {
    render(contributors, { paginate: true });
  } else {
    currentPage += 1;
    container.innerHTML = "<div class='text-center' id='loading'>Loading...</div>";
    render(contributors, { paginate: true });
    const loading = document.getElementById("loading");
    if (loading) loading.setAttribute("hidden", true);
    if (currentPage >= totalPages) {
      const loadMoreEl = document.getElementById("loadMore");
      if (loadMoreEl) loadMoreEl.setAttribute("hidden", true);
    }
  }
}

// Event listener for "Load More" button
const loadMoreBtn = document.getElementById("loadMore");
if (loadMoreBtn) {
  loadMoreBtn.addEventListener("click", loadMore);
}

// Add avatars to existing contributor links (in case initial render occurred earlier)
document.querySelectorAll("a.box-item").forEach((con) => {
  const username = getGithubUsernameFromUrl(con.getAttribute("href"));
  const hasImg = con.querySelector("img");
  if (!hasImg) {
    con.appendChild(createAvatarImg(username));
  }
});
setupLazyLoadImages();
setupLoadMoreOnScroll();

// -------- Lazy loading avatars with IntersectionObserver --------
function setupLazyLoadImages() {
  const images = document.querySelectorAll("a.box-item img[data-src]");
  if (!("IntersectionObserver" in window)) {
    images.forEach((img) => {
      img.src = img.dataset.src;
      img.removeAttribute("data-src");
    });
    return;
  }
  const imgObserver = new IntersectionObserver((entries, observer) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        const img = entry.target;
        img.src = img.dataset.src;
        img.removeAttribute("data-src");
        observer.unobserve(img);
      }
    });
  }, { rootMargin: "100px 0px", threshold: 0.01 });
  images.forEach((img) => imgObserver.observe(img));
}

// -------- Infinite scroll: auto load more when near bottom --------
function setupLoadMoreOnScroll() {
  const loadMoreBtn = document.getElementById("loadMore");
  if (!loadMoreBtn) return;
  let sentinel = document.getElementById("load-more-sentinel");
  if (!sentinel) {
    sentinel = document.createElement("div");
    sentinel.id = "load-more-sentinel";
    sentinel.style.height = "1px";
    const container = document.getElementById("contributors");
    if (container) container.appendChild(sentinel);
  }
  if (!("IntersectionObserver" in window)) return;
  const totalPages = Math.ceil(contributors.length / pageSize);
  const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        if (currentPage < totalPages && (!searchbox || searchbox.value === "")) {
          loadMore();
        }
      }
    });
  }, { rootMargin: "200px 0px", threshold: 0 });
  observer.observe(sentinel);
}

function debounce(fn, delay) {
  let timer;
  return function(...args) {
    clearTimeout(timer);
    timer = setTimeout(() => fn.apply(this, args), delay);
  };
}

// Event listener for the search box with debounce
if (searchbox) {
  searchbox.addEventListener(
    "keyup",
    debounce(async (e) => {
      const loadMoreEl = document.getElementById("loadMore");
      if (loadMoreEl) {
        if (searchbox.value !== "") loadMoreEl.classList.add("hidden");
        else loadMoreEl.classList.remove("hidden");
      }

      searchResult = await filterUsers(e.target.value, contributors);
      const container = document.getElementById("contributors");
      if (!container) return;
      container.innerHTML = e.target.value !== "" ? "<div class='text-center' id='loading'>Loading...</div>" : "";

      if (e.target.value !== "") {
        searchResult.forEach((item) => {
          const anchor = createContributorAnchor(item);
          container.appendChild(anchor);
        });
      } else {
        // Reset pagination when clearing search
        currentPage = 1;
        render(contributors, { paginate: true });
      }

      const loading = document.getElementById("loading");
      if (loading) loading.setAttribute("hidden", true);
    }, 200)
  );
}

/* Back-to-top button functionality */
const backToTopButton = document.querySelector("#back-to-top-btn");

window.addEventListener("scroll", scrollFunction);
function scrollFunction() {
  if (window.pageYOffset > 300) {
    if (!backToTopButton.classList.contains("btnEntrance")) {
      backToTopButton.classList.remove("btnExit");
      backToTopButton.classList.add("btnEntrance");
      backToTopButton.style.display = "block";
    }
  } else {
    if (backToTopButton.classList.contains("btnEntrance")) {
      backToTopButton.classList.remove("btnEntrance");
      backToTopButton.classList.add("btnExit");
      setTimeout(function () {
        backToTopButton.style.display = "none";
      }, 250);
    }
  }
}

backToTopButton.addEventListener("click", smoothScrollBackToTop);

function smoothScrollBackToTop() {
  const targetPosition = 0;
  const startPosition = window.pageYOffset;
  const distance = targetPosition - startPosition;
  const duration = 750;
  let start = null;
  window.requestAnimationFrame(step);
  function step(timestamp) {
    if (!start) start = timestamp;
    const progress = timestamp - start;
    window.scrollTo(
      0,
      easeInOutCubic(progress, startPosition, distance, duration)
    );
    if (progress < duration) window.requestAnimationFrame(step);
  }
}

function easeInOutCubic(t, b, c, d) {
  t /= d / 2;
  if (t < 1) return (c / 2) * t * t * t + b;
  t -= 2;
  return (c / 2) * (t * t * t + 2) + b;
}

// Toggle dark/light theme
$(".tdnn").click(function () {
  $("body").toggleClass("light");
  $(".moon").toggleClass("sun");
  $(".tdnn").toggleClass("day");
});

// Display live stats with the dynamic year
document.getElementById(
  "stats"
).innerHTML = `You guys are awesome, we have again passed the GitHub rate limit this hour. <a href="https://github.com/fineanmol/Hacktoberfest${currentYear}" target="_blank">Here</a> is a link to check out our repo's live stats.`;
