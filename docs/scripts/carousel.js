const buttons = document.querySelectorAll("[data-carousel-button]");
const carousel = document.querySelector("[data-carousel]");
const slides = carousel.querySelector("[data-slides]");

let currentIndex = 0;
const intervalTime = 3000;
let intervalId;

function changeSlide(offset) {
  const activeSlide = slides.querySelector("[data-active]");
  activeSlide.removeAttribute("data-active");

  currentIndex += offset;
  if (currentIndex < 0) currentIndex = slides.children.length - 1;
  if (currentIndex >= slides.children.length) currentIndex = 0;

  slides.children[currentIndex].setAttribute("data-active", true);
}

function startSlideInterval() {
  intervalId = setInterval(() => {
    if (isCarouselVisible()) {
      changeSlide(1);
    }
  }, intervalTime);
}

function pauseSlideInterval() {
  clearInterval(intervalId);
}

function isCarouselVisible() {
  const rect = carousel.getBoundingClientRect();
  const windowHeight = window.innerHeight || document.documentElement.clientHeight;
  const carouselHeight = rect.height;

  return (
    rect.top >= -carouselHeight * 0.5 &&
    rect.bottom <= windowHeight + carouselHeight * 0.5
  );
}

buttons.forEach(button => {
  button.addEventListener("click", () => {
    const offset = button.dataset.carouselButton === "next" ? 1 : -1;
    changeSlide(offset);
  });

  button.addEventListener("mouseenter", pauseSlideInterval);
  button.addEventListener("mouseleave", startSlideInterval);
});

carousel.addEventListener("mouseenter", pauseSlideInterval);
carousel.addEventListener("mouseleave", startSlideInterval);
window.addEventListener("scroll", startSlideInterval);

startSlideInterval();
