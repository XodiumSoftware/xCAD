from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLabel, QPushButton, QVBoxLayout

from interfaces.configs.push_button_configs import PushButtonTypeHints


class PushButtonModule(QPushButton):
    """A class used to represent a push button module."""

    def __init__(self, configs: PushButtonTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (PushButtonTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: PushButtonTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (PushButtonTypeHints): A configuration.
        """
        self.setSizePolicy(*configs.size_policy)

        if configs.icon_path:
            self.setIcon(configs.icon_path)

        if configs.size:
            self.setFixedSize(*configs.size)

        if configs.signals:
            if isinstance(configs.signals, tuple):
                for signal in configs.signals:
                    self.clicked.connect(signal)

            else:
                self.clicked.connect(configs.signals)

        if isinstance(configs.title, str) and isinstance(configs.stylesheet, str):
            self.setText(configs.title)
            self.setStyleSheet(configs.stylesheet)
            self.setFixedSize(self.sizeHint())
            return

        layout = QVBoxLayout()
        layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        for title, stylesheet, text_alignment in zip(
            configs.title, configs.stylesheet, configs.text_alignment
        ):
            label = QLabel()
            label.setText(title)
            label.setStyleSheet(stylesheet)
            label.setAlignment(text_alignment)
            layout.addWidget(label)

        self.setLayout(layout)
        self.setFixedSize(layout.sizeHint())
