# Third-party imports
from PyQt6.QtCore import (
    Qt,
)

def closeOnKeyPressEvent(ui, event):
    """
    This function checks if the user presses the escape or Ctrl+Q key(combination) and closes the window if either key
    is pressed.
    """
    if event.key() == Qt.Key.Key_Escape or event.key() == Qt.Key.Key_Q:
        ui.close()
