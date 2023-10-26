from typing import List, Optional

from PySide6.QtGui import QAction
from PySide6.QtWidgets import QToolBar


class ToolBarModule(QToolBar):
    """A class used to represent a toolbar module."""

    def __init__(self, data: str, action: Optional[List[str]] = None) -> None:
        """Initialize the class.

        Args:
            data (str): A configuration.
            action (List[str]): List of action names.
        """
        super().__init__()
        self.setup_props(data, action)

    def setup_props(
        self, data: str, action: Optional[List[str]] = None
    ) -> None:  # TODO
        """Setup the properties.

        Args:
            data (str): A configuration.
            action_names (List[str]): List of action names.
        """
        self.setWindowTitle(data)

        if action:
            for name in action:
                action = QAction(name, self)
                self.addAction(action)

                # Customize properties of the actions (optional)
                # action.setIcon(QIcon("icon.png"))
                # action.setToolTip("Tooltip text")
