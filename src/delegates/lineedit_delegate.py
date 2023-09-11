from PySide6.QtWidgets import QLineEdit


class LineEditDelegate(QLineEdit):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the label delegate."""
        super().__init__()
        self.setup_line_edit(module_data)

    def setup_line_edit(self, module_data: dict) -> None:
        """Setup the label delegate."""
        self.setStyleSheet(module_data["stylesheet"])
        self.setPlaceholderText(module_data["placeholder"])
