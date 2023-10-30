from PySide6.QtWidgets import QStatusBar

# TODO: this file
from interfaces.configs.status_bar_configs import StatusBarTypeHints


class StatusBarModule(QStatusBar):
    """A class used to represent a statusbar module."""

    def __init__(self, configs: StatusBarTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (StatusBarTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: StatusBarTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (StatusBarTypeHints): A configuration.
        """
        self.setStatusTip(configs.Status_tip)
        self.setStyleSheet(configs.Stylesheet)
        self.setLayout(configs.Layout)
        self.setSizePolicy(*configs.SizePolicy)
