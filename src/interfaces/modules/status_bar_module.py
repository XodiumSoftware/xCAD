from PySide6.QtWidgets import QStatusBar

# TODO: this file


class StatusBarModule(QStatusBar):
    """A class used to represent a statusbar module."""

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
        self.setStatusTip(data)
