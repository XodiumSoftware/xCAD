/**
 * A class that manages registration-related popups and interactions.
 */
class RegistrationPopupManager {
  /**
   * Creates an instance of RegistrationPopupManager.
   */
  constructor (clientId) {
    this.clientId = clientId

    this.githubOAuthButton = document.getElementById('githubOAuthButton')
    this.loginLink = document.getElementById('loginLink')
    this.loginPopup = document.getElementById('loginPopup')
    this.closeLoginPopup = document.getElementById('closeLoginPopup')
    this.carousel = document.querySelector('.carousel')
    this.carouselSlides = document.querySelectorAll('.slide')

    this.setupEventListeners()
  }

  /**
   * Sets up event listeners for various interactions.
   */
  setupEventListeners () {
    this.githubOAuthButton.addEventListener(
      'click',
      this.performGitHubOAuth.bind(this)
    )
    this.loginLink.addEventListener('click', this.showLoginPopup.bind(this))
    this.closeLoginPopup.addEventListener(
      'click',
      this.closeLoginPopupHandler.bind(this)
    )
  }

  /**
   * Displays a popup and adds an exit button to it.
   */
  showPopup (popup) {
    popup.style.display = 'flex'
    const exitButton = document.createElement('button')
    exitButton.className = 'popup-exit-button overlay-exit-button'
    exitButton.innerText = 'X'
    popup.appendChild(exitButton)

    exitButton.addEventListener('click', () => {
      this.closePopup(popup)
    })
  }

  /**
   * Closes a popup and removes the exit button from it.
   * @static
   */
  static closePopup (popup) {
    popup.style.display = 'none'
    const exitButton = popup.querySelector('.overlay-exit-button')
    if (exitButton) {
      exitButton.remove()
    }
  }

  /**
   * Pauses the carousel animation.
   */
  pauseCarousel () {
    this.carousel.removeAttribute('data-carousel')
    this.carouselSlides.forEach((slide) => {
      slide.style.animationPlayState = 'paused'
    })
  }

  /**
   * Resumes the carousel animation.
   */
  resumeCarousel () {
    this.carousel.setAttribute('data-carousel', '')
    this.carouselSlides.forEach((slide) => {
      slide.style.animationPlayState = 'running'
    })
  }

  /**
   * Initiates GitHub OAuth authentication by redirecting the user to GitHub's authorization page.
   */
  performGitHubOAuth () {
    const redirectUri = 'https://illyrius.me/AutoFrameCAD/auth/github/callback'
    const oauthUrl = `https://github.com/login/oauth/authorize?client_id=${this.clientId}&redirect_uri=${redirectUri}`
    window.location.href = oauthUrl
  }

  /**
   * Event handler for closing the login popup and resuming the carousel.
   */
  closeLoginPopupHandler () {
    this.closePopup(this.loginPopup)
    this.resumeCarousel()
  }
}

const clientId = 'Iv1.c014788a30bf9f06'
const _ = new RegistrationPopupManager(clientId)
