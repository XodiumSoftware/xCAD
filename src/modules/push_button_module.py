from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QLabel, QPushButton, QSizePolicy


class PushButtonModule(QPushButton):
    """A class used to represent a push button module."""

    def __init__(self, configs: Enum) -> None:
        """Initialize the class.

        Args:
            configs (Enum): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: Enum) -> None:
        """Setup the properties.

        Args:
            configs (Enum): A configuration.
        """
        value = configs.value
        self.setStyleSheet(value["stylesheet"])
        if value["icon_path"]:
            self.setIcon(QIcon(value["icon_path"]))
        elif isinstance(value["title"] and value["stylesheet"], tuple):
            layout = self.layout()  # NOTE: watch out for this when errors emerge!
            layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
            for title, stylesheet in zip(value["title"], value["stylesheet"]):
                label = QLabel(title)
                label.setStyleSheet(stylesheet)
                label.setAlignment(Qt.AlignmentFlag.AlignCenter)
                layout.addWidget(label)
            self.setLayout(layout)
        else:
            self.setText(value["title"])
            self.setStyleSheet(value["stylesheet"])

        if value["size"] is not None:
            self.setFixedSize(*value["size"])
        else:
            self.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum)
