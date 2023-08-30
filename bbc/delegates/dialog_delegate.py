from PySide6.QtWidgets import QDialog


class DialogDelegate(QDialog):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the label delegate."""
        super().__init__()
        self.setup_dialog(module_data)

    def setup_dialog(self, module_data: dict) -> None:
        """Setup the label delegate."""

    def update_window_title(self, title: str) -> None:
        """Update the window title."""
        self.setWindowTitle(title)
