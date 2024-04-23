document.querySelectorAll("a").forEach(function (link) {
  link.addEventListener("click", function (e) {
    e.preventDefault();
  });
});
