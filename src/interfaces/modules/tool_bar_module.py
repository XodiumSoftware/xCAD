from typing import Optional

from PySide6.QtGui import QAction
from PySide6.QtWidgets import QToolBar

from interfaces.configs.tool_bar_configs import ToolBarTypeHints


class ToolBarModule(QToolBar):
    """A class used to represent a toolbar module."""

    def __init__(
        self, configs: ToolBarTypeHints, action: Optional[list[QAction]] = None
    ) -> None:
        """Initialize the class.

        Args:
            configs (ToolBarTypeHints): A configuration.
            action (list[QAction]): list of actions.
        """
        super().__init__()
        self.setup_props(configs, action)

    def setup_props(
        self, configs: ToolBarTypeHints, action: Optional[list[QAction]] = None
    ) -> None:
        """Setup the properties.

        Args:
            configs (ToolBarTypeHints): A configuration.
            action (list[QAction]): list of actions.
        """
        self.setWindowTitle(configs.Title)
        self.setStyleSheet(configs.Stylesheet)
        self.setLayout(configs.Layout)
        self.setSizePolicy(*configs.SizePolicy)

        if action:
            for actions in action:
                self.addAction(actions)
