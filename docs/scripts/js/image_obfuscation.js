class ImageObfuscator {
    constructor() {
        this.obfuscateImageURLs();
    }

    generateUniqueFilename(originalFilename) {
        const hash = md5(originalFilename);
        const fileExtension = originalFilename.split('.').pop();
        const uniqueFilename = hash + '.' + fileExtension;
        return uniqueFilename;
    }

    obfuscateImageURLs() {
        const images = document.querySelectorAll('img[data-obfuscate]');
        images.forEach(image => {
            const originalSrc = image.getAttribute('src');
            const uniqueFilename = this.generateUniqueFilename(originalSrc);
            image.setAttribute('src', uniqueFilename);
        });
    }
}

document.addEventListener('DOMContentLoaded', () => {
    const imageObfuscator = new ImageObfuscator();
});
