import random
import string
import sys
from functools import partial

from constants import OBJECT_EDITOR_DIALOG_TITLE, UI_ICON_PATH
from enums.afc_enums import LumberTypes, StudSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.dialog_handler import DialogHandler
from PySide6.QtGui import QBrush, QColor, QIcon, QPen
from PySide6.QtWidgets import (
    QCheckBox,
    QComboBox,
    QDialog,
    QDoubleSpinBox,
    QGraphicsRectItem,
    QGridLayout,
    QLabel,
    QLineEdit,
    QPushButton,
)


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    obj_counter = 0

    def __init__(self, x: int, y: int, w: int, h: int, rad: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self._dialog_handler = DialogHandler()
        self.obj_id = GraphicsObjectDelegate.generate_complex_id()
        self.obj_props = {
            "object_id": self.obj_id,
            "type": StudSettings.Type.value,
            "x": x,
            "y": y,
            "w": w,
            "h": h,
            "rad": rad,
            "pen_color": StudSettings.PenColor.value,
            "pen_thickness": StudSettings.PenThickness.value,
            "pen_style": StudSettings.PenStyle.value,
            "fill_state": StudSettings.Fill.value,
            "fill_color": StudSettings.FillColor.value,
            "fill_pattern": StudSettings.FillPattern.value,
            "fill_opacity": max(0, min(StudSettings.FillOpacity.value, 100)) / 100,
            "draw_order": StudSettings.DrawOrder.value,
        }
        GraphicsObjectDelegate.obj_counter += 1
        self.setup_graphics_object(x, y, w, h, rad)

    @staticmethod
    def generate_complex_id(char_len=6) -> str:
        """Generate a complex ID."""
        chars = string.ascii_letters + string.digits
        return "".join(random.choice(chars) for _ in range(char_len))

    def setup_graphics_object(
        self,
        x: int,
        y: int,
        w: int,
        h: int,
        rad: int,
    ) -> None:
        """Setup the graphics object delegate."""
        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        self.setPos(x, y)
        self.setRect(self.rect().x(), self.rect().y(), w, h)
        self.setRotation(rad)
        self.mouseDoubleClickEvent = partial(self.object_editor_dialog)

        self.setPen(
            QPen(
                QColor(StudSettings.PenColor.value),
                StudSettings.PenThickness.value,
                PenStyleTypes[StudSettings.PenStyle.value].value,
            )
        )
        if StudSettings.Fill.value:
            self.setBrush(
                QBrush(
                    QColor(StudSettings.FillColor.value),
                    BrushStyleTypes[StudSettings.FillPattern.value].value,
                )
            )
            self.setOpacity(max(0, min(StudSettings.FillOpacity.value, 100)) / 100)
        else:
            self.setBrush(QBrush(BrushStyleTypes.NoBrush.value))

        self.setZValue(StudSettings.DrawOrder.value)
        self.setToolTip(StudSettings.Type.value)

    def object_editor_dialog(self, event) -> None:
        """Open a dialog when an object is pressed."""
        dialog = QDialog()
        dialog.setWindowTitle(OBJECT_EDITOR_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))

        layout = QGridLayout(dialog)
        row_offset = 2

        properties = [
            "object_id",
            "type",
            "pen_color",
            "pen_thickness",
            "pen_style",
            "fill_state",
            "fill_color",
            "fill_pattern",
            "fill_opacity",
            "draw_order",
        ]
        inputs = {}

        for row, prop_name in enumerate(properties):
            label = QLabel(f"{prop_name.capitalize()}:")
            label.setWordWrap(True)

            input_widget = None

            if prop_name in self.obj_props:
                prop_value = self.obj_props[prop_name]

                if prop_name == "object_id":
                    input_widget = QLabel()
                    input_widget.setText(self.obj_id)
                elif prop_name == "type":
                    input_widget = QComboBox()
                    input_widget.addItems([enum.name for enum in LumberTypes])
                    input_widget.setCurrentText(prop_value)
                elif isinstance(prop_value, str) and prop_value.startswith("#"):
                    input_widget = QPushButton(prop_value)
                    input_widget.clicked.connect(
                        partial(
                            self._dialog_handler.color_picker_dialog,
                            button=input_widget,
                            properties=self.obj_props,
                            key=prop_name,
                        )
                    )
                elif prop_name == "pen_style":
                    input_widget = QComboBox()
                    input_widget.addItems([enum.name for enum in PenStyleTypes])
                    input_widget.setCurrentText(prop_value)
                elif prop_name == "fill_pattern":
                    input_widget = QComboBox()
                    input_widget.addItems([enum.name for enum in BrushStyleTypes])
                    input_widget.setCurrentText(prop_value)
                elif isinstance(prop_value, bool):
                    input_widget = QCheckBox()
                    input_widget.setChecked(prop_value)
                elif isinstance(prop_value, int) or isinstance(prop_value, float):
                    input_widget = QDoubleSpinBox()
                    input_widget.setRange(0, sys.float_info.max)
                    input_widget.setSingleStep(1)
                    input_widget.setDecimals(0)
                    input_widget.setValue(prop_value)
                elif isinstance(prop_value, str):
                    input_widget = QLineEdit()
                    input_widget.setText(prop_value)

            if input_widget is not None:
                inputs[prop_name] = input_widget
                layout.addWidget(label, row + row_offset, 0)
                layout.addWidget(input_widget, row + row_offset, 1)

        save_button = QPushButton("Save")
        discard_button = QPushButton("Discard")

        save_button.clicked.connect(dialog.accept)
        discard_button.clicked.connect(dialog.reject)

        layout.addWidget(save_button, row_offset + len(properties), 0, 1, 2)
        layout.addWidget(discard_button, row_offset + len(properties) + 1, 0, 1, 2)

        if dialog.exec() == dialog.DialogCode.Accepted:
            for prop_name, input_widget in inputs.items():
                if isinstance(input_widget, QDoubleSpinBox):
                    self.obj_props[prop_name] = input_widget.value()
                elif isinstance(input_widget, QLineEdit):
                    self.obj_props[prop_name] = input_widget.text()

            self.setRect(
                self.obj_props["x"],
                self.obj_props["y"],
                self.obj_props["w"],
                self.obj_props["h"],
            )
            self.setRotation(self.obj_props["rad"])
