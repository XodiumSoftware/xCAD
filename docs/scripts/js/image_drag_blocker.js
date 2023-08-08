class ImageDragBlocker {
    constructor() {
        const images = document.querySelectorAll('img');

        images.forEach((image) => {
            image.addEventListener('dragstart', (event) => {
                event.preventDefault();
            });
        });
    }
}

const blocker = new ImageDragBlocker();
