class ImageContextMenuDisabler {
    constructor() {
        this.disableContextMenuForImages();
    }

    disableContextMenuForImages() {
        const images = document.getElementsByTagName('img');
        Array.from(images).forEach(image => {
            image.addEventListener('contextmenu', event => {
                event.preventDefault();
            });
        });
    }
}

document.addEventListener('DOMContentLoaded', () => {
    const imageContextMenuDisabler = new ImageContextMenuDisabler();
});
