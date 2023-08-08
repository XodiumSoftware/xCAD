class ImageSecurity {
    constructor() {
        this.images = document.querySelectorAll('img[data-obfuscate]');
        this.disableContextMenuForImages();
        this.blockImageDrag();
        this.obfuscateImageURLs();
    }

    disableContextMenuForImages() {
        this.images.forEach(image => {
            image.addEventListener('contextmenu', event => {
                event.preventDefault();
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

    blockImageDrag() {
        this.images.forEach(image => {
            image.addEventListener('dragstart', event => {
                event.preventDefault();
            });
        });
    }
}

document.addEventListener('DOMContentLoaded', () => {
    const imageSecurity = new ImageSecurity();
});
