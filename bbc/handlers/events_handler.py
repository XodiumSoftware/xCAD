from constants import DEBUG_NAME
from PySide6.QtCore import QObject, Signal, Slot
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication


class EventsHandler(QObject):
    quit_signal = Signal()

    def __init__(self):
        """
        Initialize the events.
        """
        super().__init__()

        # Connect the signal to the slot
        self.quit_signal.connect(self.quit_on_key_press_event)

    @Slot()
    def quit_on_key_press_event(self) -> None:
        """
        Quit on Escape key or Ctrl+Q.
        """
        # Create separate QShortcut instances for "Escape" and "Ctrl+Q"
        escape_shortcut = QShortcut(QKeySequence("Escape"), self)
        ctrl_q_shortcut = QShortcut(QKeySequence("Ctrl+Q"), self)

        # Connect both shortcuts to the same slot
        escape_shortcut.activated.connect(QApplication.quit)
        ctrl_q_shortcut.activated.connect(QApplication.quit)

    @staticmethod
    def on_button_clicked_event(sender: QObject):
        if sender.objectName() == "ThemeButton":
            print(DEBUG_NAME + "Theme Button Clicked!")
        elif sender.objectName() == "ViewerButton":
            print(DEBUG_NAME + "Viewer Button Clicked!")
