from constants import DEBUG_NAME, QSETTINGS
from PySide6.QtCore import QObject, QSettings, Slot
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication


class EventsHandler(QObject):
    def __init__(self):
        """
        Initialize the EventsHandler.
        """
        super().__init__()
        self._settings = QSettings(QSETTINGS)

    @Slot()
    def quit_on_key_press_event(self):
        """
        Quit on Escape key or Ctrl+Q.
        """
        escape_shortcut = QShortcut(QKeySequence("Escape"), self)
        ctrl_q_shortcut = QShortcut(QKeySequence("Ctrl+Q"), self)

        escape_shortcut.activated.connect(QApplication.quit)
        ctrl_q_shortcut.activated.connect(QApplication.quit)

    def on_button_clicked(self, button_index):
        """
        Handle the button clicked event.
        """
        if button_index == 0:
            print(DEBUG_NAME + f"Button {button_index} clicked!")
        elif button_index == 1:
            print(DEBUG_NAME + f"Button {button_index} clicked!")
        elif button_index == 2:
            print(DEBUG_NAME + f"Button {button_index} clicked!")
        elif button_index == 3:
            print(DEBUG_NAME + f"Button {button_index} clicked!")

    def on_checkbox_clicked(self, checkbox_index):
        """
        Handle the checkbox clicked event.
        """
        if checkbox_index == 0:
            print(DEBUG_NAME + f"Checkbox {checkbox_index} clicked!")
            checkbox_state = self._settings.value("startup_page_visibility_state")
            self._settings.setValue("startup_page_visibility_state", checkbox_state)
            print(
                DEBUG_NAME + f"Startup page visibility state set to: {checkbox_state}!"
            )
