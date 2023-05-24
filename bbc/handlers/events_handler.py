from constants import DEBUG_NAME, THEME_DARK, THEME_LIGHT
from PySide6.QtCore import QObject, Signal, Slot
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication


class EventsHandler(QObject):
    toggle_viewer_signal = Signal()
    save_changes_signal = Signal()
    toggle_theme_signal = Signal(int)
    discard_changes_signal = Signal()

    def __init__(self, current_theme):
        """
        Initialize the EventsHandler.
        """
        super().__init__()
        self._current_theme = current_theme
        print(DEBUG_NAME + "EventsHandler initialized")

    @Slot()
    def quit_on_key_press_event(self):
        """
        Quit on Escape key or Ctrl+Q.
        """
        print(DEBUG_NAME + "Quit on Escape key or Ctrl+Q connection established")
        # Create separate QShortcut instances for "Escape" and "Ctrl+Q"
        escape_shortcut = QShortcut(QKeySequence("Escape"), self)
        ctrl_q_shortcut = QShortcut(QKeySequence("Ctrl+Q"), self)

        # Connect both shortcuts to the same slot
        escape_shortcut.activated.connect(QApplication.quit)
        ctrl_q_shortcut.activated.connect(QApplication.quit)

    @Slot(int)
    def on_button_clicked_event(self, index):
        """
        Handle button clicks.
        """
        if index == 0:
            print(DEBUG_NAME + "Theme Button Clicked!")
            if self._current_theme == THEME_DARK:
                self.toggle_theme_signal.emit(THEME_LIGHT)
            elif self._current_theme == THEME_LIGHT:
                self.toggle_theme_signal.emit(THEME_DARK)
        elif index == 1:
            print(DEBUG_NAME + "Viewer Button Clicked!")
            self.toggle_viewer_signal.emit()
        elif index == 2:
            print(DEBUG_NAME + "Save Button Clicked!")
            self.save_changes_signal.emit()
        elif index == 3:
            print(DEBUG_NAME + "Discard Button Clicked!")
            self.discard_changes_signal.emit()
        else:
            print(DEBUG_NAME + "Invalid button index")
