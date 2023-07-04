function generateUniqueFilename(originalFilename) {
    const hash = md5(originalFilename)

    const fileExtension = originalFilename.split('.').pop()

    const uniqueFilename = hash + '.' + fileExtension

    return uniqueFilename
}

function obfuscateImageURLs() {
    const images = document.querySelectorAll('img[data-obfuscate]')

    images.forEach((image) => {
        const originalSrc = image.getAttribute('src')
        const uniqueFilename = generateUniqueFilename(originalSrc)

        image.setAttribute('src', uniqueFilename)
    })
}

window.addEventListener('DOMContentLoaded', obfuscateImageURLs)
