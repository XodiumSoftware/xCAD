// Function to generate a unique filename using a hashing algorithm
function generateUniqueFilename(originalFilename) {
    // Use a hashing algorithm (e.g., MD5, SHA-1) to generate a unique hash based on the original filename
    const hash = md5(originalFilename) // Replace md5 with your desired hashing algorithm

    // Get the file extension from the original filename
    const fileExtension = originalFilename.split('.').pop()

    // Concatenate the hash and file extension to create the unique filename
    const uniqueFilename = hash + '.' + fileExtension

    return uniqueFilename
}

// Obfuscate image URLs by generating unique filenames
function obfuscateImageURLs() {
    const images = document.querySelectorAll('img[data-obfuscate]')

    images.forEach((image) => {
        const originalSrc = image.getAttribute('src')
        const uniqueFilename = generateUniqueFilename(originalSrc)

        // Update the src attribute with the unique filename
        image.setAttribute('src', uniqueFilename)
    })
}

// Call the obfuscateImageURLs function after the DOM is fully loaded
window.addEventListener('DOMContentLoaded', obfuscateImageURLs)
