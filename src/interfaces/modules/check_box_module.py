from PySide6.QtWidgets import QCheckBox

from interfaces.configs.check_box_configs import CheckBoxTypeHints


class CheckBoxModule(QCheckBox):
    """A class to represent a check box module."""

    def __init__(self, configs: CheckBoxTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (CheckBoxTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: CheckBoxTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (CheckBoxTypeHints): A configuration.
        """
        self.setText(configs.Title)
        self.setStyleSheet(configs.Stylesheet)
        self.setLayout(configs.Layout)
        self.setSizePolicy(*configs.SizePolicy)
