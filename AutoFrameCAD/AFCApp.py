import sys
from tkinter import Tk as tkTk

from AFCUIModules import PrimaryUIModule as AFCPrimaryUIModule


class App:
    """A class used to represent the application."""

    def __init__(self, modules: list[tkTk]) -> None:
        """Initializes and runs the application.

        Args:
            modules (list[tkTk]): The modules to use.
        """
        [module.mainloop() for module in modules]
        sys.exit()


if __name__ == '__main__':
    App([AFCPrimaryUIModule()])
