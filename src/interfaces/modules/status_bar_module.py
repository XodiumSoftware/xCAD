from PySide6.QtWidgets import QStatusBar

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
        self.setStatusTip(configs.status_tip)
        self.setStyleSheet(configs.stylesheet)
        self.setLayout(configs.layout)
        self.setSizePolicy(*configs.size_policy)
