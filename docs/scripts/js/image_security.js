function disableContextMenuForImages() {
    const images = document.getElementsByTagName('img')
    Array.from(images).forEach(image => {
        image.addEventListener('contextmenu', event => {
            event.preventDefault()
        })
    })
}

window.addEventListener('DOMContentLoaded', disableContextMenuForImages)
