import sys

from constants import (
    COLOR_PICKER_DIALOG_TITLE,
    ITEM_PROPERTIES_DIALOG_TITLE,
    QUIT_DIALOG_TITLE,
    UI_ICON_PATH,
)
from PySide6.QtCore import Qt
from PySide6.QtGui import QColor, QIcon
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QColorDialog,
    QDialog,
    QDoubleSpinBox,
    QGridLayout,
    QLabel,
    QLineEdit,
    QMessageBox,
    QPushButton,
)


class DialogHandler:
    """A class to handle dialogs."""

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
    def item_properties_dialog(
        desc: str, length: float, height: float, fill_state: bool
    ):
        """A dialog for setting the item properties."""
        dialog = QDialog()
        dialog.setWindowTitle(ITEM_PROPERTIES_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setFixedSize(dialog.sizeHint())

        max_double_value = sys.float_info.max

        desc_edit = QLineEdit()
        desc_edit.setText(desc)
        desc_edit.setPlaceholderText("Enter object name")
        desc_edit.setMaxLength(50)
        desc_edit.setClearButtonEnabled(True)

        length_edit = QDoubleSpinBox()
        length_edit.setValue(length)
        length_edit.setRange(0, max_double_value)
        length_edit.setDecimals(0)
        length_edit.setSuffix(" mm")

        height_edit = QDoubleSpinBox()
        height_edit.setValue(height)
        height_edit.setRange(0, max_double_value)
        height_edit.setDecimals(0)
        height_edit.setSuffix(" mm")

        fill_edit = QCheckBox()
        fill_edit.setChecked(fill_state)

        ok_button = QPushButton("OK")

        layout = QGridLayout()

        layout.addWidget(QLabel("Name:"), 0, 0)
        layout.addWidget(desc_edit, 0, 1)

        layout.addWidget(QLabel("Length:"), 1, 0)
        layout.addWidget(length_edit, 1, 1)

        layout.addWidget(QLabel("Height:"), 2, 0)
        layout.addWidget(height_edit, 2, 1)

        layout.addWidget(QLabel("Fill:"), 3, 0)
        layout.addWidget(fill_edit, 3, 1, Qt.AlignmentFlag.AlignCenter)

        layout.addWidget(ok_button, 4, 0, 1, 2)

        dialog.setLayout(layout)

        if dialog.exec_() == QDialog.DialogCode.Accepted:
            new_length = length_edit.value()
            new_height = height_edit.value()

            return new_length, new_height

    @staticmethod
    def color_picker_dialog(color: QColor):
        """A dialog for picking a color."""
        dialog = QColorDialog()
        dialog.setWindowTitle(COLOR_PICKER_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setFixedSize(dialog.sizeHint())

        dialog.setOption(QColorDialog.ColorDialogOption.ShowAlphaChannel, True)
        dialog.setOption(QColorDialog.ColorDialogOption.DontUseNativeDialog, True)
        dialog.setCurrentColor(QColor(color))

        if dialog.exec() == QMessageBox.StandardButton.Yes:
            QApplication.activeWindow().close()
