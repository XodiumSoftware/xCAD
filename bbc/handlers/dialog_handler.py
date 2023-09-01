import sys
from functools import partial

from constants import (
    COLOR_PICKER_DIALOG_TITLE,
    OBJECT_EDITOR_DIALOG_TITLE,
    QUIT_DIALOG_TITLE,
    UI_ICON_PATH,
)
from enums.afc_enums import LumberTypes
from enums.q_enums import BrushStyleTypes, PenStyleTypes
from PySide6.QtCore import Qt
from PySide6.QtGui import QColor, QIcon, QPalette
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
    QGroupBox,
    QInputDialog,
    QLabel,
    QMessageBox,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
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

        layout = QVBoxLayout(dialog)

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
                            "widget": QPushButton(),
                            "content": obj_props["type"],
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
                "frame_title": "Dimension Settings:",
                "frame_border": QFrame.Shape.Box,
                "data": [
                    [
                        {
                            "widget": QLabel(),
                            "content": "Pos (X, Y):",
                        },
                        {
                            "widget": QLabel(),
                            "content": str(obj_props["x"]) + ", " + str(obj_props["y"]),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Dim (LxB):",
                        },
                        {
                            "widget": QLabel(),
                            "content": str(obj_props["h"])
                            + " x "
                            + str(obj_props["w"]),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Rotation:",
                        },
                        {
                            "widget": QLabel(),
                            "content": str(obj_props["rad"]),
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
                            "content": obj_props["fill_color"],
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

        for prop_group in props:
            group_box = QGroupBox(prop_group["frame_title"])
            frame_layout = QGridLayout(group_box)

            for row, prop_data in enumerate(prop_group["data"]):
                label_widget: QLabel = prop_data[0]["widget"]
                label_widget.setText(prop_data[0]["content"])
                frame_layout.addWidget(label_widget, row, 0)

                input_widget: QWidget = prop_data[1]["widget"]
                input_widget.setFixedWidth(150)
                frame_layout.addWidget(input_widget, row, 1)

                if isinstance(input_widget, QPushButton):
                    if prop_data[0]["content"] == "Type:":
                        input_widget.setText(prop_data[1]["content"])
                        input_widget.clicked.connect(
                            partial(_dialog_handler.lumber_type_dialog, input_widget)
                        )
                    else:
                        input_widget.setStyleSheet(
                            f"background-color: {prop_data[1]['content']};"
                            "border: 1px solid lightgray;"
                        )
                        input_widget.setFixedSize(16, 16)
                        input_widget.clicked.connect(
                            partial(_dialog_handler.color_picker_dialog, input_widget)
                        )
                elif isinstance(input_widget, QCheckBox):
                    input_widget.setChecked(prop_data[1]["content"])
                elif isinstance(input_widget, QComboBox):
                    input_widget.addItems(prop_data[1]["content_options"])
                    input_widget.setCurrentText(prop_data[1]["content"])
                elif isinstance(input_widget, QDoubleSpinBox):
                    if prop_data[0]["content"] == "Fill Opacity:":
                        input_widget.setRange(0, 100)
                    else:
                        input_widget.setRange(0, sys.float_info.max)
                    input_widget.setSingleStep(1)
                    input_widget.setDecimals(0)
                    input_widget.setValue(prop_data[1]["content"])
                    input_widget.setButtonSymbols(
                        QAbstractSpinBox.ButtonSymbols.NoButtons
                    )
                elif isinstance(input_widget, QLabel):
                    input_widget.setText(prop_data[1]["content"])

                inputs[prop_data[0]["content"]] = input_widget
                row += 1

                frame_layout.addWidget(
                    label_widget, row, 0, alignment=Qt.AlignmentFlag.AlignLeft
                )
                frame_layout.addWidget(
                    input_widget, row, 1, alignment=Qt.AlignmentFlag.AlignCenter
                )

            group_box.setLayout(frame_layout)
            layout.addWidget(group_box)

        layout.addWidget(save_button)
        layout.addWidget(discard_button)

        dialog.setFixedSize(dialog.sizeHint())

        if dialog.exec() == dialog.DialogCode.Accepted:
            for prop_name, input_widget in inputs.items():
                if isinstance(input_widget, QPushButton):
                    obj_props[prop_name] = input_widget.text()
                elif isinstance(input_widget, QCheckBox):
                    obj_props[prop_name] = input_widget.isChecked()
                elif isinstance(input_widget, QComboBox):
                    obj_props[prop_name] = input_widget.currentText()
                elif isinstance(input_widget, QDoubleSpinBox):
                    obj_props[prop_name] = input_widget.value()

    @staticmethod
    def color_picker_dialog(input_widget: QPushButton) -> None:
        """A dialog for picking a color."""
        dialog = QColorDialog()
        dialog.setWindowTitle(COLOR_PICKER_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setFixedSize(dialog.sizeHint())

        selected_color = dialog.getColor(
            QColor(input_widget.palette().color(QPalette.ColorRole.Window))
        )

        if selected_color.isValid():
            hex_color = selected_color.name(QColor.NameFormat.HexRgb)
            input_widget.setStyleSheet(
                f"background-color: {hex_color};" "border: 1px solid lightgray;"
            )

    @staticmethod
    def lumber_type_dialog(input_widget: QPushButton) -> None:
        """A dialog for picking a lumber type."""
        dialog = QInputDialog()
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))
        dialog.setFixedSize(dialog.sizeHint())

        lumber_types = [type_name for type_name, _ in LumberTypes.get_all_content()]
        current_type = input_widget.text()

        selected_type, _ = dialog.getItem(
            dialog,
            "Select Lumber Type",
            "Choose a lumber type:",
            lumber_types,
            lumber_types.index(current_type),
            False,
        )

        input_widget.setText(selected_type)
