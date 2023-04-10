# These lines of code are importing necessary modules and packages for the program to run.

# Third-party imports
from PyQt6.QtWidgets import QWidget

# Internal module imports
from events.key_press_events import close_on_key_press


class OnPressEvents(QWidget):
    def keyPressEvent(self, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        close_on_key_press(
            self, event)
