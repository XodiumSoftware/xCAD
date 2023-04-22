# type: ignore
from PySide6.QtCore import *
from PySide6.QtWidgets import *


class Events:
    # FIXME: keyPressEvent not working.
    def keyPressEvent(self, event):
        """
        This function is called when certain keys are pressed.
        """
        print("[DEBUG] Key pressed:", event.key())
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
        else:
            super().keyPressEvent(event)
