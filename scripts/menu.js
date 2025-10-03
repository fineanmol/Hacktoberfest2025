// scripts/menu.js - Fixed Menu Configuration
const menu = {
  'Home': {
    text: 'Contribute here',
    href: 'https://github.com/fineanmol/Hacktoberfest2024/blob/master/contributors/contributorsList.js'
  },
  'Project1': {
    text: 'HacktoberFest Project 1',
    href: 'https://github.com/fineanmol/Annoying-submit-button'
  },
  'Project2': {
    text: 'HacktoberFest Project 2',
    href: 'https://github.com/fineanmol/hacktoberfest'
  },
  'Others': {
    Instagram: {
      text: 'Connect on <i class="fa fa-instagram" style="font-size:22px"></i>',
      href: 'https://instagram.com/fineanmol'
    },
    Facebook: {
      text: '<i class="fa fa-facebook" style="font-size:20px"></i>acebook',
      href: 'https://www.facebook.com/fineanmol',
      id: 'facebook'
    },
    LinkedIn: {
      text: 'Linked<i class="fa fa-linkedin" style="font-size:20px"></i>',
      href: 'https://www.linkedin.com/in/fineanmol/',
      id: 'linkedin'
    },
    Twitter: {
      text: '<i class="fa fa-twitter" style="font-size:20px"></i>Twitter',
      href: 'https://twitter.com/fineanmol',
      id: 'twitter'
    },
    Stars: {
      text: '<a class="github-button" href="https://github.com/fineanmol/Hacktoberfest2024" data-icon="octicon-star" data-show-count="true" aria-label="Star fineanmol/Hacktoberfest2024 on GitHub">Stars</a>',
      href: 'https://github.com/fineanmol/Hacktoberfest2024',
      id: 'stars'
    },
    Forks: {
      text: '<a class="github-button" href="https://github.com/fineanmol/Hacktoberfest2024/fork" data-icon="octicon-repo-forked" data-show-count="true" aria-label="Fork fineanmol/Hacktoberfest2024 on GitHub">Fork</a>',
      href: 'https://github.com/fineanmol/Hacktoberfest2024/fork',
      id: 'forks'
    }
  }
}

function buildMenuHTML(obj = {}) {
  let html = ''
  let path = window.location.pathname.split('/')
  let currentPage = path[path.length - 1] === '' ? '/' : path[path.length - 1]

  Object.entries(obj).forEach(([key, item]) => {
    if (key === 'Others') {
      html += '<li class="nav-item dropdown">'
      html += '<a class="nav-link dropdown-toggle" href="#" id="othersDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">'
      html += 'Others'
      html += '</a>'
      html += '<ul class="dropdown-menu" aria-labelledby="othersDropdown">'
      Object.entries(item).forEach(([subKey, subItem]) => {
        html += '<li>'
        html += '<a class="dropdown-item" target="_blank" href="' + subItem.href + '"' + (subItem.id ? ' id="' + subItem.id + '"' : '') + '>'
        html += subItem.text
        html += '</a>'
        html += '</li>'
      })
      html += '</ul>'
      html += '</li>'
    } else {
      // Normalize current page for comparison
      if (currentPage.indexOf('.html') === -1 && currentPage !== '/') {
        currentPage = currentPage + '.html'
      }
      let isCurrent = (currentPage === item.href) ||
                      (item.href && window.location.href.includes(item.href))
      html += '<li class="nav-item' + (isCurrent ? ' active' : '') + '">'
      html += '<a class="nav-link" target="_blank" href="' + item.href + '"' + (item.id ? ' id="' + item.id + '"' : '') + '>'
      html += item.text
      html += '</a>'
      html += '</li>'
    }
  })

  const menuElement = document.getElementById('menu')
  if (menuElement) {
    menuElement.innerHTML = html
  } else {
    console.warn('Menu element with id "menu" not found')
  }
}

function buildMenu() {
  buildMenuHTML(menu)
}

// Initialize menu when DOM is ready
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', buildMenu)
} else {
  buildMenu()
}
