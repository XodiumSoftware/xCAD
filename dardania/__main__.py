"""This module serves as the entry point for the application."""

import sys

from PySide6.QtWidgets import QApplication
from ui import UI


class App:
    """A class used to represent the application."""

    def __init__(self: "App") -> None:
        """Initializes and runs the application."""
        self.app = QApplication([])
        self.window = UI()
        self.window.show()
        sys.exit(self.app.exec())


if __name__ == "__main__":
    App()
