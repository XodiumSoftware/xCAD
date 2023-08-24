from enums.q_enums import SizePolicyType
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QPushButton


class PushButtonDelegate(QPushButton):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the label delegate."""
        super().__init__()
        self.setup_push_button(module_data)

    def setup_push_button(self, module_data: dict) -> None:
        """Setup the label delegate."""
        self.setStyleSheet(module_data["stylesheet"])
        if module_data["icon_path"]:
            icon = QIcon(module_data["icon_path"])
            self.setIcon(icon)
        else:
            self.setText(module_data["title"])
        if module_data["size"] is not None:
            self.setFixedSize(*module_data["size"])
        else:
            self.setSizePolicy(
                SizePolicyType.Minimum.value, SizePolicyType.Minimum.value
            )
