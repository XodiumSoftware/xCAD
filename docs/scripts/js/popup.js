class RegistrationPopupManager {
    constructor() {
        super();
        this.clientId = clientId;

        this.githubOAuthButton = document.getElementById('githubOAuthButton');
        this.githubOAuthButton.addEventListener('click', () => {
            this.performGitHubOAuth();
        });

        this.loginLink = document.getElementById('loginLink');
        this.registerLink = document.getElementById('registerLink');
        this.loginPopup = document.getElementById('loginPopup');
        this.registerPopup = document.getElementById('registerPopup');
        this.closeLoginPopup = document.getElementById('closeLoginPopup');
        this.closeRegisterPopup = document.getElementById('closeRegisterPopup');
        this.carousel = document.querySelector('.carousel');
        this.carouselSlides = document.querySelectorAll('.slide');
        this.registerPasswordInput = document.getElementById('registerPassword');
        this.passwordVisibilityToggle = document.getElementById('passwordVisibilityToggle');

        this.loginLink.addEventListener('click', (e) => {
            e.preventDefault();
            this.pauseCarousel();
            this.showPopup(this.loginPopup);
        });

        this.registerLink.addEventListener('click', (e) => {
            e.preventDefault();
            this.pauseCarousel();
            this.showPopup(this.registerPopup);
        });

        this.closeLoginPopup.addEventListener('click', () => {
            this.closePopup(this.loginPopup);
            this.resumeCarousel();
        });

        this.closeRegisterPopup.addEventListener('click', () => {
            this.closePopup(this.registerPopup);
            this.resumeCarousel();
        });

        this.passwordVisibilityToggle.addEventListener('click', () => {
            this.togglePasswordVisibility();
        });

        this.registerPasswordInput.addEventListener('input', () => {
            this.updatePasswordStrength();
        });

        this.registerPasswordInput.addEventListener('keyup', () => {
            this.updatePasswordStrength();
        });

        this.registerPasswordInput.addEventListener('keydown', () => {
            this.updatePasswordStrength();
        });
    }

    showPopup(popup) {
        popup.style.display = 'flex';
        const exitButton = document.createElement('button');
        exitButton.className = 'popup-exit-button overlay-exit-button';
        exitButton.innerText = 'X';
        popup.appendChild(exitButton);

        exitButton.addEventListener('click', () => {
            this.closePopup(popup);
        });
    }

    closePopup(popup) {
        popup.style.display = 'none';
        const exitButton = popup.querySelector('.overlay-exit-button');
        if (exitButton) {
            exitButton.remove();
        }
    }

    pauseCarousel() {
        this.carousel.removeAttribute('data-carousel');
        this.carouselSlides.forEach((slide) => {
            slide.style.animationPlayState = 'paused';
        });
    }

    resumeCarousel() {
        this.carousel.setAttribute('data-carousel', '');
        this.carouselSlides.forEach((slide) => {
            slide.style.animationPlayState = 'running';
        });
    }

    performGitHubOAuth() {
        const redirectUri = 'https://illyrius.me/AutoFrameCAD/auth/github/callback';
        const oauthUrl = `https://github.com/login/oauth/authorize?client_id=${this.clientId}&redirect_uri=${redirectUri}`;
        window.location.href = oauthUrl;
    }
}

const clientId = 'Iv1.c014788a30bf9f06';
new RegistrationPopupManager();
