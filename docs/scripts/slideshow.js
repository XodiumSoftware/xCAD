// scripts/slideshow.js
// JavaScript for slideshow
const images = document.querySelectorAll("#media_content img");
let currentIndex = 0;

function showImage(index) {
  images.forEach((img, i) => {
    if (i === index) {
      img.classList.add("active");
    } else {
      img.classList.remove("active");
    }
  });
}

function nextImage() {
  currentIndex = (currentIndex + 1) % images.length;
  showImage(currentIndex);
}

setInterval(nextImage, 2000); // Change slide every 2 seconds
