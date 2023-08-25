const items = document.querySelectorAll('.item');
let selectedItem = null;

items.forEach(item => {
  item.addEventListener('mousedown', (e) => {
    selectedItem = item;
    item.style.cursor = 'grabbing';
  });
  item.addEventListener('mouseup', () => {
    selectedItem = null;
    item.style.cursor = 'grab';
  });
});

document.addEventListener('mousemove', (e) => {
  if (selectedItem) {
    const rect = selectedItem.getBoundingClientRect();
    selectedItem.style.left = `${e.clientX - rect.width / 2}px`;
    selectedItem.style.top = `${e.clientY - rect.height / 2}px`;
  }
});
