from PySide6.QtGui import QAction

from interfaces.configs.action_configs import ActionTypeHints


class ActionModule(QAction):
    """A class used to represent a action module."""

    def __init__(self, configs: ActionTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (ActionTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: ActionTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (ActionTypeHints): A configuration.
        """
        self.setIcon(configs.Icon)
        self.setToolTip(configs.Tooltip)
