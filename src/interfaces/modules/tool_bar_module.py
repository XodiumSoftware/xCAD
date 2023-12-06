from interfaces.configs.tool_bar_configs import ToolBarTypeHints
from PySide6.QtGui import QAction
from PySide6.QtWidgets import QToolBar


class ToolBarModule(QToolBar):
    """A class used to represent a toolbar module."""

    def __init__(
        self,
        configs: ToolBarTypeHints,
        action: QAction | list[QAction] | None = None,
    ) -> None:
        """Initialize the class.

        Args:
            configs (ToolBarTypeHints): A configuration.
            action (Optional[Union[QAction, list[QAction]]]): list of actions.
        """
        super().__init__()
        self.setup_props(configs, action)

    def setup_props(
        self,
        configs: ToolBarTypeHints,
        action: QAction | list[QAction] | None = None,
    ) -> None:
        """Setup the properties.

        Args:
            configs (ToolBarTypeHints): A configuration.
            action (Optional[Union[QAction, list[QAction]]]): list of actions.
        """
        self.setWindowTitle(configs.title)
        self.setStyleSheet(configs.stylesheet)
        self.setLayout(configs.layout)
        self.setSizePolicy(*configs.size_policy)

        if action:
            if isinstance(action, QAction):
                self.addAction(action)
            elif isinstance(action, list):
                for actions in action:
                    self.addAction(actions)
