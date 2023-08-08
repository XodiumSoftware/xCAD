class ImageSecurity {
    constructor() {
        this.images = document.querySelectorAll('img[data-obfuscate]');
        this.addEventListeners();
        this.obfuscateImageURLs();
    }

    addEventListeners() {
        const disableEvent = event => event.preventDefault();
        this.images.forEach(image => {
            image.addEventListener('contextmenu', disableEvent);
            image.addEventListener('dragstart', disableEvent);
            image.addEventListener('keydown', event => {
                if (event.ctrlKey && (event.key === 'c' || event.key === 'i')) {
                    event.preventDefault();
                }
            });
        });
    }

    generateUniqueFilename(originalFilename) {
        const hash = md5(originalFilename);
        const fileExtension = originalFilename.split('.').pop();
        const uniqueFilename = `${hash}.${fileExtension}`;
        return uniqueFilename;
    }

    obfuscateImageURLs() {
        this.images.forEach(image => {
            const originalSrc = image.getAttribute('src');
            const uniqueFilename = this.generateUniqueFilename(originalSrc);
            image.setAttribute('src', uniqueFilename);
        });
    }
}

document.addEventListener('DOMContentLoaded', () => {
    const imageSecurity = new ImageSecurity();
});
