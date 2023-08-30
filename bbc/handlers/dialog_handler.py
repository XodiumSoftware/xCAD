import sys
from functools import partial
from typing import Dict

from constants import (
    COLOR_PICKER_DIALOG_TITLE,
    OBJECT_EDITOR_DIALOG_TITLE,
    QUIT_DIALOG_TITLE,
    UI_ICON_PATH,
)
from enums.afc_enums import LumberTypes
from enums.q_enums import BrushStyleTypes, PenStyleTypes
from PySide6.QtGui import QColor, QFont, QIcon, QPalette
from PySide6.QtWidgets import (
    QAbstractSpinBox,
    QApplication,
    QCheckBox,
    QColorDialog,
    QComboBox,
    QDialog,
    QDoubleSpinBox,
    QFrame,
    QGridLayout,
    QLabel,
    QMessageBox,
    QPushButton,
    QWidget,
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
    def object_editor_dialog(obj_props: dict) -> None:
        """Open a dialog when an object is pressed."""
        _dialog_handler = DialogHandler()

        dialog = QDialog()
        dialog.setWindowTitle(OBJECT_EDITOR_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))

        layout = QGridLayout(dialog)

        props = [
            {
                "frame_title": "General Settings:",
                "frame_border": QFrame.Shape.Box,
                "data": [
                    [
                        {
                            "widget": QLabel(),
                            "content": "Object ID:",
                        },
                        {
                            "widget": QLabel(),
                            "content": obj_props["object_id"],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Type:",
                        },
                        {
                            "widget": QComboBox(),
                            "content": obj_props["type"],
                            "content_options": [enum.name for enum in LumberTypes],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Draw Order:",
                        },
                        {
                            "widget": QDoubleSpinBox(),
                            "content": obj_props["draw_order"],
                        },
                    ],
                ],
            },
            {
                "frame_title": "Annotation Settings:",
                "frame_border": QFrame.Shape.Box,
                "data": [
                    [
                        {
                            "widget": QLabel(),
                            "content": "Pen Color:",
                        },
                        {
                            "widget": QPushButton(),
                            "content": obj_props["pen_color"],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Pen Thickness:",
                        },
                        {
                            "widget": QDoubleSpinBox(),
                            "content": obj_props["pen_thickness"],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Pen Style:",
                        },
                        {
                            "widget": QComboBox(),
                            "content": obj_props["pen_style"],
                            "content_options": [enum.name for enum in PenStyleTypes],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Fill State:",
                        },
                        {
                            "widget": QCheckBox(),
                            "content": obj_props["fill_state"],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Fill Color:",
                        },
                        {
                            "widget": QPushButton(),
                            "content": QPushButton(obj_props["fill_color"]),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Fill Pattern:",
                        },
                        {
                            "widget": QComboBox(),
                            "content": obj_props["fill_pattern"],
                            "content_options": [enum.name for enum in BrushStyleTypes],
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Fill Opacity:",
                        },
                        {
                            "widget": QDoubleSpinBox(),
                            "content": obj_props["fill_opacity"],
                        },
                    ],
                ],
            },
        ]

        inputs = {}

        save_button = QPushButton("Save")
        discard_button = QPushButton("Discard")

        save_button.clicked.connect(dialog.accept)
        discard_button.clicked.connect(dialog.reject)

        row = 0
        for prop_group in props:
            frame_title_widget = QLabel()
            frame_title_widget.setText(prop_group["frame_title"])
            frame_title_widget.setFrameShape(prop_group["frame_border"])

            bold_font = QFont()
            bold_font.setBold(True)

            frame_title_widget.setFont(bold_font)

            layout.addWidget(frame_title_widget, row, 0, 1, 2)

            row += 1

            for prop_data in prop_group["data"]:
                label_widget: QLabel = prop_data[0]["widget"]
                label_widget.setText(prop_data[0]["content"])
                layout.addWidget(label_widget, row, 0)

                input_widget: QWidget = prop_data[1]["widget"]
                input_content = prop_data[1]["content"]
                if isinstance(input_widget, QPushButton):
                    input_widget.clicked.connect(
                        partial(
                            _dialog_handler.color_picker_dialog,
                            button=input_widget,
                            properties=obj_props,
                            key=prop_data[1]["content"],
                        )
                    )
                if isinstance(input_widget, QCheckBox):
                    input_widget.setChecked(input_content)
                elif isinstance(input_widget, QComboBox):
                    input_widget.addItems(prop_data[1]["content_options"])
                    input_widget.setCurrentText(input_content)
                elif isinstance(input_widget, QDoubleSpinBox):
                    input_widget.setRange(0, sys.float_info.max)
                    input_widget.setSingleStep(1)
                    input_widget.setDecimals(0)
                    input_widget.setValue(input_content)
                    input_widget.setButtonSymbols(
                        QAbstractSpinBox.ButtonSymbols.NoButtons
                    )
                elif isinstance(input_widget, QLabel):
                    input_widget.setText(input_content)
                layout.addWidget(input_widget, row, 1)

                inputs[prop_data[0]["content"]] = input_widget
                row += 1

        layout.addWidget(save_button, row, 0, 1, 2)
        row += 1
        layout.addWidget(discard_button, row, 0, 1, 2)

        if dialog.exec() == dialog.DialogCode.Accepted:
            for prop_name, input_widget in inputs.items():
                obj_props[prop_name] = input_widget.getContent()

        dialog.setFixedSize(dialog.sizeHint())

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
