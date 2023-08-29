import random
import string
import sys

from constants import OBJECT_EDITOR_DIALOG_TITLE, UI_ICON_PATH
from enums.afc_enums import StudSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from PySide6.QtGui import QBrush, QColor, QIcon, QPen
from PySide6.QtWidgets import (
    QDialog,
    QDoubleSpinBox,
    QGraphicsRectItem,
    QGridLayout,
    QLabel,
    QPushButton,
)


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    obj_counter = 0

    def __init__(self, x: int, y: int, w: int, h: int, r: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self.obj_id = GraphicsObjectDelegate.generate_complex_id()
        GraphicsObjectDelegate.obj_counter += 1
        self.setup_graphics_object(self, x, y, w, h, r)

    @staticmethod
    def generate_complex_id(l=8) -> str:
        """Generate a complex ID."""
        characters = string.ascii_letters + string.digits
        return "".join(random.choice(characters) for _ in range(l))

    @staticmethod
    def setup_graphics_object(
        obj: QGraphicsRectItem, x: int, y: int, w: int, h: int, r: int
    ) -> None:
        """Setup the graphics object delegate."""
        obj.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        obj.setPos(x, y)
        obj.setRect(obj.rect().x(), obj.rect().y(), w, h)
        obj.setRotation(r)
        obj.mouseDoubleClickEvent = (
            lambda event, obj=obj: GraphicsObjectDelegate.object_editor_dialog(obj)
        )

        obj.setPen(
            QPen(
                QColor(StudSettings.PenColor.value),
                StudSettings.PenThickness.value,
                PenStyleTypes[StudSettings.PenStyle.value].value,
            )
        )
        if StudSettings.Fill.value:
            obj.setBrush(
                QBrush(
                    QColor(StudSettings.FillColor.value),
                    BrushStyleTypes[StudSettings.FillPattern.value].value,
                )
            )
            obj.setOpacity(max(0, min(StudSettings.FillOpacity.value, 100)) / 100)
        else:
            obj.setBrush(QBrush(BrushStyleTypes.NoBrush.value))
        obj.setZValue(StudSettings.DrawOrder.value)
        obj.setToolTip(StudSettings.Name.value)

    @staticmethod
    def object_editor_dialog(obj: QGraphicsRectItem) -> None:
        """Open a dialog when a object is pressed."""
        dialog = QDialog()
        dialog.setWindowTitle(OBJECT_EDITOR_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))

        layout = QGridLayout()
        dialog.setLayout(layout)

        label = QLabel("Stud width:")

        obj_size_spinbox = QDoubleSpinBox()
        obj_size_spinbox.setRange(0, sys.float_info.max)
        obj_size_spinbox.setSingleStep(1)
        obj_size_spinbox.setDecimals(0)
        obj_size_spinbox.setValue(obj.rect().width())

        save_button = QPushButton("Save")
        discard_button = QPushButton("Discard")

        save_button.clicked.connect(dialog.accept)
        discard_button.clicked.connect(dialog.reject)

        layout.addWidget(label, 0, 0)
        layout.addWidget(obj_size_spinbox, 0, 1)
        layout.addWidget(save_button, 1, 0)
        layout.addWidget(discard_button, 1, 1)

        dialog.setLayout(layout)
        dialog.setMinimumSize(dialog.sizeHint())
        dialog.setMaximumSize(dialog.sizeHint())

        result = dialog.exec()

        if result == dialog.DialogCode.Accepted:
            obj.setRect(
                obj.rect().x(),
                obj.rect().y(),
                obj_size_spinbox.value(),
                obj.rect().height(),
            )
