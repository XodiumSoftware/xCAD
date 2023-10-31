from PySide6.QtWidgets import QLineEdit

from interfaces.configs.line_edit_configs import LineEditTypeHints


class LineEditModule(QLineEdit):
    """A class to represent a label module."""

    def __init__(self, configs: LineEditTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (LineEditTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: LineEditTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (LineEditTypeHints): A configuration.
        """
        self.setPlaceholderText(configs.placeholder)
        self.setStyleSheet(configs.stylesheet)
        self.setLayout(configs.layout)
        self.setAlignment(configs.alignment)
        self.setSizePolicy(*configs.size_policy)
