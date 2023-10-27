from PySide6.QtGui import QAction, QIcon


class ToolBarModule(QAction):
    """A class used to represent a action module."""

    def __init__(self, data: str) -> None:
        """Initialize the class.

        Args:
            data (str): A configuration.
        """
        super().__init__()
        self.setup_props(data)

    def setup_props(self, data: str) -> None:
        """Setup the properties.

        Args:
            data (str): A configuration.
        """
        self.setIcon(QIcon("icon.png"))
        self.setToolTip("Tooltip text")
