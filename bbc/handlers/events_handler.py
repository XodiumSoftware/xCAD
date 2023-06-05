from PySide6.QtCore import QObject, Slot
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication


class EventsHandler(QObject):
    def __init__(self):
        """
        Initialize the EventsHandler.
        """
        super().__init__()

    @Slot()
    def quit_on_key_press_event(self):
        """
        Quit on Escape key or Ctrl+Q.
        """
        # Create separate QShortcut instances for "Escape" and "Ctrl+Q"
        escape_shortcut = QShortcut(QKeySequence("Escape"), self)
        ctrl_q_shortcut = QShortcut(QKeySequence("Ctrl+Q"), self)

        # Connect both shortcuts to the same slot
        escape_shortcut.activated.connect(QApplication.quit)
        ctrl_q_shortcut.activated.connect(QApplication.quit)
