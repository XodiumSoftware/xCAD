import sys
from functools import partial
from typing import Dict

from constants import (
    COLOR_PICKER_DIALOG_TITLE,
    ITEM_PROPERTIES_DIALOG_TITLE,
    QUIT_DIALOG_TITLE,
    UI_ICON_PATH,
)
from handlers.signal_handler import SignalHandler
from PySide6.QtCore import Qt
from PySide6.QtGui import QColor, QFont, QIcon, QPalette
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QColorDialog,
    QComboBox,
    QDialog,
    QDoubleSpinBox,
    QFrame,
    QGridLayout,
    QLabel,
    QLineEdit,
    QMessageBox,
    QPushButton,
)


class DialogHandler:
    """A class to handle dialogs."""

    def __init__(self):
        """Initialize the class."""
        self._items = {}

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

    def item_properties_dialog(self, item_id: int) -> None:
        """A dialog for setting the item properties."""
        dialog = QDialog()
        dialog.setWindowTitle(ITEM_PROPERTIES_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))

        layout = QGridLayout()
        dialog.setLayout(layout)

        row = 0

        index_label = QLabel(f"Object_{item_id}")
        index_label.setFont(
            QFont(index_label.font().family(), weight=QFont.Weight.Bold)
        )
        layout.addWidget(
            index_label, row, 0, 1, 2, alignment=Qt.AlignmentFlag.AlignCenter
        )
        row += 1

        selected_item_properties = self._items.get(item_id, {})

        for category, settings_list in selected_item_properties.items():
            if category == "Index:":
                continue

            category_frame = QFrame()
            category_frame.setFrameShape(QFrame.Shape.StyledPanel)
            category_layout = QGridLayout(category_frame)
            category_frame.setLayout(category_layout)

            layout.addWidget(category_frame, row, 0, 1, 2)

            title_label = QLabel(category)
            title_label.setFont(
                QFont(title_label.font().family(), weight=QFont.Weight.Bold)
            )
            category_layout.addWidget(title_label, 0, 0, 1, 2)

            length_widget = QDoubleSpinBox()
            height_widget = QDoubleSpinBox()

            row_in_category = 1
            for setting in settings_list:
                for key, value in setting.items():
                    label = QLabel(key)
                    category_layout.addWidget(
                        label, row_in_category, 0, alignment=Qt.AlignmentFlag.AlignLeft
                    )

                    if isinstance(value, bool):
                        widget = QCheckBox()
                        widget.setChecked(value)
                        category_layout.addWidget(
                            widget,
                            row_in_category,
                            1,
                            alignment=Qt.AlignmentFlag.AlignCenter,
                        )
                    elif isinstance(value, (int, float)):
                        if key == "Length:":
                            widget = length_widget
                        elif key == "Height:":
                            widget = height_widget
                        else:
                            widget = QDoubleSpinBox()
                        widget.setValue(value)
                        widget.setSingleStep(1)
                        widget.setRange(0, sys.float_info.max)
                        widget.setDecimals(0)
                        category_layout.addWidget(widget, row_in_category, 1)
                    elif isinstance(value, list):
                        widget = QComboBox()
                        widget.addItems(value)
                        category_layout.addWidget(widget, row_in_category, 1)
                    elif isinstance(value, str) and value.startswith("#"):
                        widget = QPushButton()
                        widget.setText(value)
                        widget.setFont(
                            QFont(widget.font().family(), weight=QFont.Weight.Bold)
                        )
                        palette = widget.palette()
                        palette.setColor(QPalette.ColorRole.ButtonText, QColor(value))
                        widget.setPalette(palette)
                        widget.clicked.connect(
                            partial(
                                DialogHandler().color_picker_dialog,
                                widget,
                                setting,
                                key,
                            )
                        )
                        category_layout.addWidget(widget, row_in_category, 1)
                    elif isinstance(value, (str, type(None))):
                        widget = QLineEdit()
                        if (key == "Area:" and value is None) or (
                            key == "Perimeter:" and value is None
                        ):
                            widget.setReadOnly(True)
                            length_value = length_widget.value()
                            height_value = height_widget.value()
                            if key == "Area:":
                                area_value = length_value * height_value
                                widget.setText(f"{int(area_value)} m2")
                            elif key == "Perimeter:":
                                perimeter_value = 2 * (length_value + height_value)
                                widget.setText(f"{int(perimeter_value)} m1")
                            else:
                                widget.setText(value)
                        else:
                            widget.setText(value)
                            widget.setClearButtonEnabled(True)
                        category_layout.addWidget(widget, row_in_category, 1)

                    row_in_category += 1

            row += 1

        save_button = QPushButton("Save")
        delete_button = QPushButton("Delete")
        delete_button.setFont(
            QFont(delete_button.font().family(), weight=QFont.Weight.Bold)
        )
        palette = delete_button.palette()
        palette.setColor(QPalette.ColorRole.ButtonText, QColor("red"))
        delete_button.setPalette(palette)
        layout.addWidget(save_button, row, 0)
        layout.addWidget(delete_button, row, 1)

        delete_button.clicked.connect(
            partial(DialogHandler().item_delete_dialog, item_id)
        )

        dialog.setFixedSize(dialog.sizeHint())
        dialog.exec()

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

    @staticmethod
    def item_delete_dialog(item_index: int) -> None:
        """A dialog for deleting an item."""
        signal_handler = SignalHandler()

        dialog = QMessageBox()
        dialog.setWindowTitle("Delete item")
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setIcon(QMessageBox.Icon.Warning)
        dialog.setFixedSize(dialog.sizeHint())

        dialog.setText(
            f"<b>Are you sure you want to delete the item 'Object_{item_index}'?</b><br>It will be gone forever!"
        )

        dialog.setStandardButtons(
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
        )

        yes_button = dialog.button(QMessageBox.StandardButton.Yes)
        yes_button.clicked.connect(dialog.accept)
        yes_button.clicked.connect(signal_handler.deleteItemSignal.emit)

        dialog.exec()
