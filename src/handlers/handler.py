import os

from PySide6.QtCore import Qt, Signal
from PySide6.QtWidgets import QMessageBox, QWidget

from constants import (
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    ON_BACK_BUTTON_PRESSED_DESC,
    SAVE_UI_TEXT,
    UI_TITLE,
)
from handlers.input_handler import InputHandler


class Handler(QWidget):
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
            | QMessageBox.StandardButton.Cancel,
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
        QMessageBox.information(
            self, UI_TITLE, SAVE_UI_TEXT, QMessageBox.StandardButton.Ok
        )

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

    def save_inputs(self):
        """
        This function saves input values from input widgets to a text file.
        """
        InputHandler_instance = InputHandler()
        input_values = {}
        for i, input_widget in enumerate(
            InputHandler_instance.create_input_fields.inputs
        ):
            input_text = input_widget.text()
            input_values[i] = input_text

        data_dir = DATA_DIR_FOLDER

        if not os.path.exists(data_dir):
            os.makedirs(data_dir)

        file_path = os.path.join(data_dir, DATA_DIR_FILE)

        with open(file_path, "w") as f:
            for key, value in input_values.items():
                f.write(f"{key}: {value}\n")

        self.save_button_handler()
