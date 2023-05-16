from PySide6.QtCore import *
from PySide6.QtWidgets import *


class Events(QObject):
    def keyPressEvent(self, event):
        """
        This function is called when certain keys are pressed.
        """
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            QApplication.quit()
