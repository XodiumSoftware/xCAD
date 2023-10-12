from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QMessageBox


class MessageBoxDelegate(QMessageBox):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the message box delegate."""
        super().__init__()
        self.properties(module_data)

    def properties(self, module_data: dict) -> None:
        """Setup the message box delegate."""
        self.setWindowTitle(module_data["title"])
        self.setWindowIcon(QIcon(module_data["icon_path"]))
        self.setIcon(module_data["icon_type"])

        if module_data["size"] is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(module_data["size"])

        self.setText(module_data["text"])
        self.setStandardButtons(
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
        )
        if self.exec() == QMessageBox.StandardButton.Yes:
            QApplication.quit()
