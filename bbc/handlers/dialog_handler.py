import sys
from functools import partial
from typing import Dict

from constants import (
    COLOR_PICKER_DIALOG_TITLE,
    INIT_ITEM_PROPERTIES,
    ITEM_PROPERTIES_DIALOG_TITLE,
    QUIT_DIALOG_TITLE,
    UI_ICON_PATH,
)
from PySide6.QtCore import Qt
from PySide6.QtGui import QColor, QFont, QIcon, QPalette
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
    def item_properties_dialog(item_index: int) -> None:
        """A dialog for setting the item properties."""
        dialog = QDialog()
        dialog.setWindowTitle(ITEM_PROPERTIES_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setFixedSize(dialog.sizeHint())

        layout = QGridLayout()
        dialog.setLayout(layout)

        properties = INIT_ITEM_PROPERTIES[item_index]

        edited_properties = {}

        row = 0

        index_label = QLabel(f"Object_{item_index}")
        layout.addWidget(
            index_label, row, 0, 1, 2, alignment=Qt.AlignmentFlag.AlignCenter
        )
        row += 1
        for key, value in properties.items():
            label = QLabel(key)
            layout.addWidget(label, row, 0)

            max_double_value = sys.float_info.max

            if key in ["Fill color:", "Pen color:"]:
                widget = QPushButton()
                widget.setText(value)
                color_picker_button = widget
                widget.clicked.connect(
                    partial(
                        DialogHandler.color_picker_dialog,
                        color_picker_button,
                        properties,
                        key,
                    )
                )

                widget.setFont(QFont(widget.font().family(), weight=QFont.Weight.Bold))
                palette = widget.palette()
                palette.setColor(QPalette.ColorRole.ButtonText, QColor(value))
                widget.setPalette(palette)
                layout.addWidget(widget, row, 1)
            elif isinstance(value, bool):
                widget = QCheckBox()
                widget.setChecked(value)
                layout.addWidget(widget, row, 1, alignment=Qt.AlignmentFlag.AlignCenter)
            elif isinstance(value, int):
                widget = QDoubleSpinBox()
                widget.setValue(value)
                widget.setSingleStep(1)
                widget.setRange(0, max_double_value)
                widget.setDecimals(0)
                layout.addWidget(widget, row, 1)
                edited_properties[key] = widget
            else:
                widget = QLineEdit()
                widget.setText(value)
                widget.setClearButtonEnabled(True)
                layout.addWidget(widget, row, 1)
                edited_properties[key] = widget

            row += 1

        save_button = QPushButton("Save")
        delete_button = QPushButton("Delete")

        layout.addWidget(save_button, row, 0)
        layout.addWidget(delete_button, row, 1)

        dialog.exec_()

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
