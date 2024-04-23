function executeAction(e, elementId, scrollOptions = { behavior: "auto" }) {
  e.preventDefault();
  document.getElementById(elementId).scrollIntoView(scrollOptions);
}
