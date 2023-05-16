from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class Events(QObject):
    def __init__(self):
        # Call the events in here.
        self.key_press_quit_event()

    def key_press_quit_event(self):
        # Quit on Escape key or Ctrl+Q.
        QShortcut(
            QKeySequence.fromString(
                "Escape, Ctrl+Q", QKeySequence.SequenceFormat.NativeText
            ),
            self,
            lambda: QApplication.quit(),
        )
