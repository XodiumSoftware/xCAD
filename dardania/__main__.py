"""This module serves as the entry point for the application."""

import sys
from tkinter import Tk as tkTk

from dardania.ui import UI


class App:
    """A class used to represent the application."""

    def __init__(self: "App", module: tkTk) -> None:
        """Initializes and runs the application.

        Args:
            module: The modules to use.
        """
        module.mainloop()
        sys.exit()


if __name__ == "__main__":
    App(UI())
