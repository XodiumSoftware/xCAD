from constants import UI_ICON_PATH
from PySide6.QtCore import Slot
from PySide6.QtGui import QIcon, QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication, QMessageBox, QWidget


class EventsHandler:
    """A class to handle events."""

    @Slot()
    def quit_on_key_press_event(self, ui: QWidget) -> None:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]
        for shortcut in shortcuts:
            key_sequence = QKeySequence(shortcut)
            shortcut = QShortcut(key_sequence, ui)
            shortcut.activated.connect(self.show_quit_message_box)

    @staticmethod
    def show_quit_message_box() -> None:
        """Show a dialog to confirm quitting."""
        msg_box = QMessageBox()
        msg_box.setWindowTitle("Exit?")
        msg_box.setWindowIcon(QIcon(UI_ICON_PATH))
        msg_box.setIcon(QMessageBox.Icon.Warning)
        msg_box.setText(
            "<b>Are you sure you want to quit?</b><br>Any unsaved changes will be lost!"
        )
        msg_box.setStandardButtons(
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
        )
        if msg_box.exec() == QMessageBox.StandardButton.Yes:
            QApplication.quit()
