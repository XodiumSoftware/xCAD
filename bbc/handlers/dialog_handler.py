from typing import Dict

from constants import COLOR_PICKER_DIALOG_TITLE, QUIT_DIALOG_TITLE, UI_ICON_PATH
from PySide6.QtGui import QColor, QIcon, QPalette
from PySide6.QtWidgets import (
    QApplication,
    QColorDialog,
    QDialog,
    QMessageBox,
    QPushButton,
)


class DialogHandler:
    """A class to handle dialogs."""

    def __init__(self):
        """Initialize the class."""

    @staticmethod
    def quit_dialog(quit_application: bool) -> None:
        """Show a dialog to confirm quitting."""
        dialog = QMessageBox()
        dialog.setWindowTitle(QUIT_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setIcon(QMessageBox.Icon.Warning)
        dialog.setFixedSize(dialog.sizeHint())

        if quit_application:
            dialog.setText(
                "<b>Are you sure you want to quit the application?</b><br>Any unsaved changes will be lost!"
            )
        else:
            dialog.setText(
                "<b>Are you sure you want to close this window?</b><br>Any unsaved changes will be lost!"
            )

        dialog.setStandardButtons(
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
        )

        if dialog.exec() == QMessageBox.StandardButton.Yes:
            if quit_application:
                QApplication.quit()
            else:
                QApplication.activeWindow().close()

    @staticmethod
    def color_picker_dialog(button: QPushButton, properties: Dict, key: str):
        """A dialog for picking a color."""
        dialog = QColorDialog()
        dialog.setWindowTitle(COLOR_PICKER_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setFixedSize(dialog.sizeHint())

        dialog.setOption(QColorDialog.ColorDialogOption.ShowAlphaChannel, True)
        dialog.setOption(QColorDialog.ColorDialogOption.DontUseNativeDialog, True)
        dialog.setCurrentColor(QColor(properties[key]))

        if dialog.exec() == QDialog.DialogCode.Accepted:
            selected_color = dialog.currentColor()
            button.setText(selected_color.name())
            properties[key] = selected_color.name()
            palette = button.palette()
            palette.setColor(QPalette.ColorRole.ButtonText, selected_color)
            button.setPalette(palette)
