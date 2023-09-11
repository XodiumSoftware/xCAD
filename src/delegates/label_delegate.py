from PySide6.QtWidgets import QLabel


class LabelDelegate(QLabel):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the label delegate."""
        super().__init__()
        self.setup_label(module_data)

    def setup_label(self, module_data: dict) -> None:
        """Setup the label delegate."""
        self.setText(module_data["title"])
        self.setStyleSheet(module_data["stylesheet"])
