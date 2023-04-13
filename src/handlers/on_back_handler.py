from PySide6.QtWidgets import QMessageBox

from constants import ON_BACK_BUTTON_PRESSED_DESC


def back_button_handler(self):
    """
    This function handles the action of pressing the back button in a UI and prompts the user to
    save changes before returning to the main UI.
    """
    print(self.parent())
    reply = QMessageBox.question(
        self.parent(),
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
