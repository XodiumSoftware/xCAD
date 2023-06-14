from constants import DEBUG_NAME
from PySide6.QtCore import QObject, QSettings, Slot
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication


class EventsHandler(QObject):
    def __init__(self):
        """
        Initialize the EventsHandler.
        """
        super().__init__()

        self._settings = QSettings()

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
            current_button_state = self._settings.value("viewer_visibility_state")
            if current_button_state == 0:
                self._settings.setValue("viewer_visibility_state", 1)
            elif current_button_state == 1:
                self._settings.setValue("viewer_visibility_state", 0)

            print(
                DEBUG_NAME
                + f"Viewer visibility state set to: {self._settings.value('viewer_visibility_state')}!"
            )

        elif button_index == 2:
            print(DEBUG_NAME + f"Button {button_index} clicked!")

        elif button_index == 3:
            print(DEBUG_NAME + f"Button {button_index} clicked!")

    # def on_checkbox_clicked(self, checkbox_index):
    #     """
    #     Handle the checkbox clicked event.
    #     """
    #     if checkbox_index == 0:
    #         print(DEBUG_NAME + f"Checkbox {checkbox_index} clicked!")
    #         current_checkbox_state = self._settings.value("main_ui_visibility_state")

    #         if current_checkbox_state == 0:
    #             self._settings.setValue("main_ui_visibility_state", 1)

    #         elif current_checkbox_state == 1:
    #             self._settings.setValue("main_ui_visibility_state", 0)

    #         print(
    #             DEBUG_NAME
    #             + f"Main UI visibility state set to: {self._settings.value('main_ui_visibility_state')}!"
    #         )
