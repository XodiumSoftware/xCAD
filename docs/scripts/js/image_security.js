/**
 * Represents an ImageSecurity instance that obfuscates image URLs and prevents certain actions on images.
 */
class ImageSecurity {
  /**
   * Create an ImageSecurity instance.
   * Initializes instance properties and sets up event listeners.
   * Automatically obfuscates image URLs on initialization.
   */
  constructor () {
    this.images = document.querySelectorAll('img[data-obfuscate]')

    this.addEventListeners()
    this.obfuscateImageURLs()
  }

  /**
   * Add event listeners to images to prevent right-click, dragging, and specific key combinations.
   */
  addEventListeners () {
    const disableEvent = (event) => event.preventDefault()

    this.images.forEach((image) => {
      image.addEventListener('contextmenu', disableEvent)
      image.addEventListener('dragstart', disableEvent)

      image.addEventListener('keydown', (event) => {
        if (event.ctrlKey && (event.key === 'c' || event.key === 'i')) {
          event.preventDefault()
        }
      })
    })
  }

  /**
   * Generate a unique filename for an image based on its original filename.
   */
  generateUniqueFilename (originalFilename) {
    const hash = md5(originalFilename) // FIXME: md5 function is not available
    const fileExtension = originalFilename.split('.').pop()
    const uniqueFilename = `${hash}.${fileExtension}`
    return uniqueFilename
  }

  /**
   * Obfuscate image URLs by replacing them with unique filenames.
   */
  obfuscateImageURLs () {
    this.images.forEach((image) => {
      const originalSrc = image.getAttribute('src')
      const uniqueFilename = this.generateUniqueFilename.call(
        this,
        originalSrc
      )
      image.setAttribute('src', uniqueFilename)
    })
  }
}

document.addEventListener('DOMContentLoaded', () => {
  new ImageSecurity()
})
