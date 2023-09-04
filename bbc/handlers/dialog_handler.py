import sys
from functools import partial

from constants import OBJECT_EDITOR_DIALOG_TITLE, UI_ICON_PATH
from delegates.color_dialog_delegate import ColorDialogDelegate
from delegates.input_dialog_delegate import InputDialogDelegate
from enums.module_enums import ColorDialogs, InputDialogs
from enums.q_enums import BrushStyleTypes, PenStyleTypes
from PySide6.QtCore import Qt
from PySide6.QtGui import QColor, QIcon
from PySide6.QtWidgets import (
    QAbstractSpinBox,
    QCheckBox,
    QComboBox,
    QDialog,
    QDoubleSpinBox,
    QFrame,
    QGraphicsRectItem,
    QGridLayout,
    QGroupBox,
    QLabel,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class DialogHandler:
    """A class to handle dialogs."""

    @staticmethod
    def object_editor_dialog(obj: QGraphicsRectItem, obj_id: str) -> None:
        """Open a dialog when an object is pressed."""
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
                            "content": obj_id,
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Type:",
                        },
                        {
                            "widget": QPushButton(),
                            "content": obj.toolTip(),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Draw Order:",
                        },
                        {
                            "widget": QDoubleSpinBox(),
                            "content": obj.zValue(),
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
                            "content": str(obj.pos().x()) + ", " + str(obj.pos().y()),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Dim (LxB):",
                        },
                        {
                            "widget": QLabel(),
                            "content": str(obj.rect().width())
                            + " x "
                            + str(obj.rect().height()),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Rotation:",
                        },
                        {
                            "widget": QLabel(),
                            "content": str(obj.rotation()),
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
                            "content": obj.pen().color().name(QColor.NameFormat.HexRgb),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Pen Thickness:",
                        },
                        {
                            "widget": QDoubleSpinBox(),
                            "content": obj.pen().widthF(),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Pen Style:",
                        },
                        {
                            "widget": QComboBox(),
                            "content": obj.pen().style().name,
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
                            "content": obj.brush().style() != Qt.BrushStyle.NoBrush,
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Fill Color:",
                        },
                        {
                            "widget": QPushButton(),
                            "content": obj.brush()
                            .color()
                            .name(QColor.NameFormat.HexRgb),
                        },
                    ],
                    [
                        {
                            "widget": QLabel(),
                            "content": "Fill Pattern:",
                        },
                        {
                            "widget": QComboBox(),
                            "content": obj.brush().style().name,
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
                            "content": obj.opacity() * 100,
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
                            partial(
                                InputDialogDelegate,
                                InputDialogs.LumberDialog.value,
                                input_widget,
                            )
                        )
                    else:
                        input_widget.setStyleSheet(
                            f"background-color: {prop_data[1]['content']};"
                            "border: 1px solid lightgray;"
                        )
                        input_widget.setFixedSize(16, 16)
                        input_widget.clicked.connect(
                            partial(
                                ColorDialogDelegate,
                                ColorDialogs.ColorDialog.value,
                                input_widget,
                            )
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
            pass
            # TODO: fix the return of values.

        # TODO: move this to its own delegate.
        # TODO: implement the returned values into the object delegate for the values to be applied.
