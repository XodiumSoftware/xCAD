from PySide6.QtWidgets import QLabel

from interfaces.configs.label_configs import LabelTypeHints


class LabelModule(QLabel):
    """A class used to represent a label module."""

    def __init__(self, configs: LabelTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (LabelTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: LabelTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (LabelTypeHints): A configuration.
        """
        self.setText(configs.Title)
        self.setStyleSheet(configs.Stylesheet)
        self.setLayout(configs.Layout)
        self.setMargin(configs.Margin)
        self.setAlignment(configs.Alignment)
        self.setSizePolicy(*configs.SizePolicy)
