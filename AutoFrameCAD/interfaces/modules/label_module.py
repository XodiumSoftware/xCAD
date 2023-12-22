from interfaces.configs.label_configs import LabelTypeHints
from PySide6.QtWidgets import QLabel


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
        self.setText(configs.title)
        self.setStyleSheet(configs.stylesheet)
        self.setLayout(configs.layout)
        self.setMargin(configs.margin)
        self.setAlignment(configs.alignment)
        self.setSizePolicy(*configs.size_policy)
