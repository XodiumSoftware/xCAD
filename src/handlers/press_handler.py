from PySide6.QtCore import Qt, Signal
from PySide6.QtWidgets import QMessageBox, QWidget

from constants import ON_BACK_BUTTON_PRESSED_DESC, SAVE_UI_TEXT, UI_TITLE
from handlers.input_handler import inputHandler
from ui.tfcc_ui import TFCCUI


class backButtonHandler(inputHandler):
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
            inputHandler.save_inputs(self)
            self.close()

        elif reply == QMessageBox.StandardButton.No:
            self.close()


class saveButtonHandler(QWidget):
    def save_button_handler(self):
        """
        This function handles the action of pressing the save button in a UI and prompts a message before returning.
        """
        QMessageBox.information(
            self, UI_TITLE, SAVE_UI_TEXT, QMessageBox.StandardButton.Ok
        )


class keyPressHandler(QWidget):
    key_pressed = Signal(int)

    def keyPressEvent(self, event):
        """
        This function handles key press events and closes the main UI or goes back to the previous
        screen depending on the key pressed.
        """
        # tfccui_instance = TFCCUI()
        key = event.key()
        self.key_pressed.emit(key)
        super().keyPressEvent(event)
        if key == Qt.Key.Key_Escape or (
            key == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            # if tfccui_instance.isVisible():
            #     self.tfcui_instance.close()

            self.close()
