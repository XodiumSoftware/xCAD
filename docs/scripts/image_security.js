function disableContextMenuForImages() {
    const images = document.getElementsByTagName('img');
    Array.from(images).forEach(image => {
        image.addEventListener('contextmenu', event => {
            event.preventDefault();
        });
    });
}

// Call the disableContextMenuForImages function after the DOM is fully loaded
window.addEventListener('DOMContentLoaded', disableContextMenuForImages);
