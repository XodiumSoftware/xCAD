from functools import partial

from constants import UI_ICON_PATH
from PySide6.QtCore import Slot
from PySide6.QtGui import QIcon, QKeySequence, QShortcut
from PySide6.QtWidgets import QApplication, QMessageBox, QWidget


class EventsHandler:
    """A class to handle events."""

    @Slot()
    @staticmethod
    def quit_on_key_press_event(ui: QWidget, quit_application: bool = True) -> None:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]
        for shortcut in shortcuts:
            key_sequence = QKeySequence(shortcut)
            shortcut = QShortcut(key_sequence, ui)
            shortcut.activated.connect(
                partial(EventsHandler.show_quit_message_box, quit_application)
            )

    @staticmethod
    def show_quit_message_box(quit_application: bool) -> None:
        """Show a dialog to confirm quitting."""
        msg_box = QMessageBox()
        msg_box.setWindowTitle("Exit?")
        msg_box.setWindowIcon(QIcon(UI_ICON_PATH))
        msg_box.setIcon(QMessageBox.Icon.Warning)
        if quit_application:
            msg_box.setText(
                "<b>Are you sure you want to quit the application?</b><br>Any unsaved changes will be lost!"
            )
        else:
            msg_box.setText(
                "<b>Are you sure you want to close this window?</b><br>Any unsaved changes will be lost!"
            )

        msg_box.setStandardButtons(
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
        )

        if msg_box.exec() == QMessageBox.StandardButton.Yes:
            if quit_application:
                QApplication.quit()
            else:
                QApplication.activeWindow().close()
