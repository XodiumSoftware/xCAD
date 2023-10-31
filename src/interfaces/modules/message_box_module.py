from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QMessageBox

from interfaces.configs.message_box_configs import MessageBoxTypeHints


class MessageBoxDelegate(QMessageBox):
    """A class to represent a message box module."""

    def __init__(self, configs: MessageBoxTypeHints) -> None:
        """Initialize the message box module.

        Args:
            configs (MessageBoxTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: MessageBoxTypeHints) -> None:
        """Setup the message box module.

        Args:
            configs (MessageBoxTypeHints): A configuration.
        """
        self.setWindowTitle(configs.Title)
        self.setWindowIcon(QIcon(configs.Icon_path))
        self.setIcon(configs.Icon_type)

        if configs.Size is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(*configs.Size)

        self.setText(configs.Text)
        self.setStandardButtons(configs.Standard_buttons)
        if self.exec() == QMessageBox.StandardButton.Yes:
            QApplication.quit()
