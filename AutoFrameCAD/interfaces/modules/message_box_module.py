from interfaces.configs.message_box_configs import MessageBoxTypeHints
from PySide6.QtWidgets import QApplication, QMessageBox


class MessageBoxModule(QMessageBox):
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
        self.setWindowTitle(configs.title)
        self.setWindowIcon(configs.icon_path)
        self.setIcon(configs.icon_type)

        if configs.size is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(*configs.size)

        self.setText(configs.text)
        self.setStandardButtons(configs.standard_buttons)
        if self.exec() == QMessageBox.StandardButton.Yes:
            QApplication.quit()
