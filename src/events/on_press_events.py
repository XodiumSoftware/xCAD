from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QFileDialog, QMessageBox, QWidget

from constants import ON_BACK_BUTTON_PRESSED_DESC, ON_BACK_BUTTON_PRESSED_FILE_PATH
from main import Run


# This is a class definition for a QWidget that handles on press events.
class OnPressEvents(QWidget):
    def keyPressEvent(self, event):
        """
        This function handles key press events and closes the main UI or goes back to the previous
        screen depending on the key pressed.

        :param event: The event parameter is an object that represents a key press event. It contains
        information about the key that was pressed, such as the key code and any modifiers (e.g. Ctrl,
        Shift) that were held down at the time of the press. The function is designed to handle key
        press events and
        """
        from ui.main_ui import MainUi
        from ui.tfcc_ui import TFCCUi

        # TODO: Fix this since it doesn't work.
        main_ui = MainUi()
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            if main_ui:
                main_ui.close()  # call close() method on the instance
            else:
                tfcc_ui = TFCCUi()
                tfcc_ui.on_back_button_pressed()
                Run().run()

    def on_back_button_pressed(self):
        """
        This function handles the action of pressing the back button in a UI and prompts the user to
        save changes before returning to the main UI.
        """
        from ui.main_ui import MainUi

        reply = QMessageBox.question(
            self,
            *ON_BACK_BUTTON_PRESSED_DESC,
            QMessageBox.StandardButton.Yes
            | QMessageBox.StandardButton.No
            | QMessageBox.StandardButton.Cancel,
        )

        if reply == QMessageBox.StandardButton.Yes:
            self.on_save_button_pressed()

        main_ui = MainUi()
        main_ui.show()
        self.close()

    def on_save_button_pressed(self):
        """
        This function prompts the user to select a file path to save input values.
        """
        from helpers.input_saver import save_input_values

        file_path, _ = QFileDialog.getSaveFileName(
            self, *ON_BACK_BUTTON_PRESSED_FILE_PATH
        )

        if file_path:
            save_input_values(self)

        # TODO: add when clicking on window red X button that it gives the message on_back_button_pressed()
