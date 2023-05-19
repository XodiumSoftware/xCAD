from constants import BUTTONS, DEBUG_NAME
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

    def on_button_clicked_event(self):
        sender = self.sender()
        button_index = sender.property("index")
        if button_index is not None and 0 <= button_index < len(BUTTONS):
            if button_index == 0:
                self.handle_theme_button_click()
            elif button_index == 1:
                self.handle_viewer_button_click()
        else:
            print(DEBUG_NAME + "Unknown Button Clicked!")

    def handle_theme_button_click(self):
        print(DEBUG_NAME + "Theme Button Clicked!")
        # Add your custom logic for the ThemeButton click here

    def handle_viewer_button_click(self):
        print(DEBUG_NAME + "Viewer Button Clicked!")
        # Add your custom logic for the ViewerButton click here
