from PySide6.QtCore import Qt
from PySide6.QtWidgets import QMessageBox

from constants import ON_BACK_BUTTON_PRESSED_DESC, SAVE_UI_TEXT, UI_TITLE


def back_button_handler(self):
    """
    This function handles the action of pressing the back button in a UI and prompts the user to
    save changes before returning to the main UI.
    """
    reply = QMessageBox.question(
        self,
        *ON_BACK_BUTTON_PRESSED_DESC,
        QMessageBox.StandardButton.Yes
        | QMessageBox.StandardButton.No
        | QMessageBox.StandardButton.Cancel
    )
    if reply == QMessageBox.StandardButton.Yes:
        self.save_inputs()
        self.close()

    elif reply == QMessageBox.StandardButton.No:
        self.close()


def save_button_handler(self):
    """
    This function handles the action of pressing the save button in a UI and prompts a message before returning.
    """
    QMessageBox.information(self, UI_TITLE, SAVE_UI_TEXT, QMessageBox.StandardButton.Ok)


def key_press_handler(self, tfccui_instance, event):
    """
    This function handles key press events and closes the main UI or goes back to the previous
    screen depending on the key pressed.
    """
    if event.key() == Qt.Key.Key_Escape or (
        event.key() == Qt.Key.Key_Q
        and event.modifiers() == Qt.KeyboardModifier.ControlModifier
    ):
        if tfccui_instance():
            back_button_handler(self)
    self.close()

    # FIXME: make the main window appear again
