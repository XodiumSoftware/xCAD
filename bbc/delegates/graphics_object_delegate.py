import random
import string
import sys
from functools import partial

from constants import OBJECT_EDITOR_DIALOG_TITLE, UI_ICON_PATH
from enums.afc_enums import StudSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.dialog_handler import DialogHandler
from PySide6.QtGui import QBrush, QColor, QIcon, QPen
from PySide6.QtWidgets import (
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
            "x": x,
            "y": y,
            "w": w,
            "h": h,
            "rad": rad,
            "pen_color": StudSettings.PenColor.value,
            "pen_thickness": StudSettings.PenThickness.value,
            "pen_style": StudSettings.PenStyle.value,
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

        layout = QGridLayout()
        dialog.setLayout(layout)

        layout.addWidget(QLabel("Object ID:"), 0, 0)
        layout.addWidget(QLabel(str(self.obj_id)), 0, 1)

        layout.addWidget(QLabel("Tooltip:"), 1, 0)
        layout.addWidget(QLabel(StudSettings.Type.value), 1, 1)

        obj_props_labels = [
            "pen_color",
            "pen_thickness",
            "pen_style",
            "fill_color",
            "fill_pattern",
            "fill_opacity",
            "draw_order",
        ]
        obj_props_inputs = {}

        row_offset = 2

        for row, prop_name in enumerate(obj_props_labels):
            label = QLabel(f"{prop_name.capitalize()}:")
            label.setWordWrap(True)
            module = None

            if prop_name in self.obj_props:
                prop_value = self.obj_props[prop_name]

                if isinstance(prop_value, str) and prop_value.startswith("#"):
                    module = QPushButton(prop_value)
                    module.clicked.connect(
                        partial(
                            self._dialog_handler.color_picker_dialog,
                            button=module,
                            properties=self.obj_props,
                            key=prop_name,
                        )
                    )
                elif prop_name == "pen_style":
                    module = QComboBox()
                    enum_values = [enum.name for enum in PenStyleTypes]
                    module.addItems(enum_values)
                    if prop_value in enum_values:
                        module.setCurrentText(prop_value)
                elif prop_name == "fill_pattern":
                    module = QComboBox()
                    enum_values = [enum.name for enum in BrushStyleTypes]
                    module.addItems(enum_values)
                    if prop_value in enum_values:
                        module.setCurrentText(prop_value)
                elif isinstance(prop_value, int) or isinstance(prop_value, float):
                    module = QDoubleSpinBox()
                    module.setRange(0, sys.float_info.max)
                    module.setSingleStep(1)
                    module.setDecimals(0)
                    module.setValue(prop_value)
                elif isinstance(prop_value, str):
                    module = QLineEdit()
                    module.setText(prop_value)

            if module:
                obj_props_inputs[prop_name] = module
                layout.addWidget(label, row + row_offset, 0)
                layout.addWidget(module, row + row_offset, 1)

        save_button = QPushButton("Save")
        discard_button = QPushButton("Discard")

        save_button.clicked.connect(dialog.accept)
        discard_button.clicked.connect(dialog.reject)

        layout.addWidget(save_button, row_offset + len(obj_props_labels), 0, 1, 2)
        layout.addWidget(
            discard_button, row_offset + len(obj_props_labels) + 1, 0, 1, 2
        )

        dialog.setLayout(layout)
        dialog.setMinimumSize(dialog.sizeHint())
        dialog.setMaximumSize(dialog.sizeHint())

        result = dialog.exec()

        if result == dialog.DialogCode.Accepted:
            for prop_name, input_widget in obj_props_inputs.items():
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
