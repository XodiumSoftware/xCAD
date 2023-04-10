from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QWidget


def close_on_key_press(ui, event):
    """
    This function checks if the user presses the escape or Ctrl+Q key(combination) and closes the window if either key
    is pressed.
    """
    if event.key() == Qt.Key.Key_Escape or event.key() == Qt.Key.Key_Q:
        ui.close()


def open_window_on_button_press(ui, event):
    """
    """
    pass


class OnPressEvents(QWidget):
    def keyPressEvent(self, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        close_on_key_press(self, event)
        open_window_on_button_press(self, event)
