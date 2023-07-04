class Carousel {
  constructor(carouselElement) {
    this.carousel = carouselElement;
    this.slides = this.carousel.querySelector("[data-slides]");
    this.buttons = this.carousel.querySelectorAll("[data-carousel-button]");
    this.currentIndex = 0;
    this.intervalId = null;
    this.intervalTime = 3000;

    this.changeSlide = this.changeSlide.bind(this);
    this.startSlideInterval = this.startSlideInterval.bind(this);
    this.pauseSlideInterval = this.pauseSlideInterval.bind(this);
    this.isCarouselVisible = this.isCarouselVisible.bind(this);

    this.setupCarousel();
  }

  changeSlide(offset) {
    const activeSlide = this.slides.querySelector("[data-active]");
    activeSlide.removeAttribute("data-active");

    this.currentIndex += offset;
    if (this.currentIndex < 0) this.currentIndex = this.slides.children.length - 1;
    if (this.currentIndex >= this.slides.children.length) this.currentIndex = 0;

    this.slides.children[this.currentIndex].setAttribute("data-active", true);
  }

  startSlideInterval() {
    this.intervalId = setInterval(() => {
      if (this.isCarouselVisible()) {
        this.changeSlide(1);
      }
    }, this.intervalTime);
  }

  pauseSlideInterval() {
    clearInterval(this.intervalId);
  }

  isCarouselVisible() {
    const rect = this.carousel.getBoundingClientRect();
    const windowHeight = window.innerHeight || document.documentElement.clientHeight;
    const carouselHeight = rect.height;

    return (
      rect.top >= -carouselHeight * 0.5 &&
      rect.bottom <= windowHeight + carouselHeight * 0.5
    );
  }

  setupCarousel() {
    this.buttons.forEach(button => {
      button.addEventListener("click", () => {
        const offset = button.dataset.carouselButton === "next" ? 1 : -1;
        this.changeSlide(offset);
      });

      button.addEventListener("mouseenter", this.pauseSlideInterval);
      button.addEventListener("mouseleave", this.startSlideInterval);
    });

    this.slides.addEventListener("mouseenter", this.pauseSlideInterval);
    this.slides.addEventListener("mouseleave", this.startSlideInterval);

    this.startSlideInterval();
  }
}

const carouselElement = document.querySelector("[data-carousel]");
new Carousel(carouselElement);
