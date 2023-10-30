from PySide6.QtWidgets import QLabel, QPushButton

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
        if configs.Icon_path:
            self.setIcon(configs.Icon_path)

        if isinstance(configs.Title, str) and isinstance(configs.Stylesheet, str):
            self.setText(configs.Title)
            self.setStyleSheet(configs.Stylesheet)
        else:
            layout = self.layout()  # NOTE: watch out for this when errors emerge!
            for title, stylesheet in zip(configs.Title, configs.Stylesheet):
                label = QLabel(title)
                label.setStyleSheet(stylesheet)
                label.setAlignment(layout.alignment())
                layout.addWidget(label)
            self.setLayout(layout)

        if configs.Size is not None:
            self.setFixedSize(*configs.Size)
