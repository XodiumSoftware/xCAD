import sys
from tkinter import Tk as tkTk

from .AFCUIs import PrimaryUI as AFCPrimaryUI


class App:
    """A class used to represent the application."""

    def __init__(self, modules: list[tkTk]) -> None:
        """Initializes and runs the application.

        Args:
            modules (list[tkTk]): The modules to use.
        """
        for module in modules:
            module.mainloop()
        sys.exit()


if __name__ == "__main__":
    App([AFCPrimaryUI()])
