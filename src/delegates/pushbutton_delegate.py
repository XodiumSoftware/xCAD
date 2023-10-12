from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QLabel, QPushButton, QSizePolicy, QVBoxLayout


class PushButtonDelegate(QPushButton):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the label delegate."""
        super().__init__()
        self.setup_push_button(module_data)

    def setup_push_button(self, module_data: dict) -> None:
        """Setup the label delegate."""
        if module_data["icon_path"]:
            icon = QIcon(module_data["icon_path"])
            self.setIcon(icon)
            self.setStyleSheet(module_data["stylesheet"])
        elif isinstance(module_data["title"] and module_data["stylesheet"], tuple):
            layout = QVBoxLayout()
            layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
            for title, stylesheet in zip(
                module_data["title"], module_data["stylesheet"]
            ):
                label = QLabel(title)
                label.setStyleSheet(stylesheet)
                label.setAlignment(Qt.AlignmentFlag.AlignCenter)
                layout.addWidget(label)
            self.setLayout(layout)
        else:
            self.setText(module_data["title"])
            self.setStyleSheet(module_data["stylesheet"])

        if module_data["size"] is not None:
            self.setFixedSize(*module_data["size"])
        else:
            self.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum)
