class RegistrationPopupManager {
    constructor() {
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

    updatePasswordStrength() {
        const passwordInput = this.registerPasswordInput;
        const password = passwordInput.value;

        const minLength = 8;
        const hasSymbol = /[!@#$%^&*()_+\-=[\]{};':"\\|,.<>/?]/.test(password);
        const hasNumber = /\d/.test(password);
        const hasUpper = /[A-Z]/.test(password);
        const hasLower = /[a-z]/.test(password);

        let strength = 0;

        if (password.length >= minLength) {
            strength++;
        }

        if (hasSymbol) {
            strength++;
        }

        if (hasNumber) {
            strength++;
        }

        if (hasUpper && hasLower) {
            strength++;
        }

        const progressBar = this.registerPopup.querySelector('.password-strength-bar');
        progressBar.style.width = `${(strength / 4) * 100}%`;

        if (strength === 0) {
            progressBar.style.backgroundColor = '#ff0000'; // Red (Weak)
        } else if (strength === 1) {
            progressBar.style.backgroundColor = '#ffa500'; // Orange (Medium)
        } else if (strength === 2) {
            progressBar.style.backgroundColor = '#ffd700'; // Gold (Strong)
        } else if (strength === 3) {
            progressBar.style.backgroundColor = '#00ff00'; // Green (Very Strong)
        } else {
            progressBar.style.backgroundColor = '#006400'; // Dark Green (Highest Strength)
        }
    }

    togglePasswordVisibility() {
        const passwordInput = this.registerPasswordInput;
        const passwordVisibilityIcon = this.passwordVisibilityToggle.querySelector('i');

        if (passwordInput.type === 'password') {
            passwordInput.type = 'text';
            passwordVisibilityIcon.classList.remove('fa-eye-slash');
            passwordVisibilityIcon.classList.add('fa-eye');
        } else {
            passwordInput.type = 'password';
            passwordVisibilityIcon.classList.remove('fa-eye');
            passwordVisibilityIcon.classList.add('fa-eye-slash');
        }
    }
}

const popupManager = new RegistrationPopupManager();
