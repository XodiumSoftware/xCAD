from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QWidget


# This is a class for handling events that occur when a button is pressed in a PyQt5 GUI application.
class OnPressEvents(QWidget):
    def keyPressEvent(self, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        if event.key() == Qt.Key.Key_Escape or event.key() == Qt.Key.Key_Q:
            self.close()
