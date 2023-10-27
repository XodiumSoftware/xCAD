from typing import List, Optional

from PySide6.QtGui import QAction
from PySide6.QtWidgets import QToolBar


class ToolBarModule(QToolBar):
    """A class used to represent a toolbar module."""

    def __init__(self, data: str, action: Optional[List[QAction]] = None) -> None:
        """Initialize the class.

        Args:
            data (str): A configuration.
            action (List[str]): List of actions.
        """
        super().__init__()
        self.setup_props(data, action)

    def setup_props(
        self, data: str, action: Optional[List[QAction]] = None
    ) -> None:  # TODO
        """Setup the properties.

        Args:
            data (str): A configuration.
            action (List[str]): List of actions.
        """
        self.setWindowTitle(data)

        if action:
            for actions in action:
                self.addAction(actions)
