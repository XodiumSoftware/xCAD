import random
import string

from enums.afc_enums import StudSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.dialog_handler import DialogHandler
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    obj_counter = 0

    def __init__(self, x: int, y: int, w: int, h: int, rad: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self.obj_props = {
            "object_id": self.generate_complex_id(),
            "type": StudSettings.Type.value,
            "draw_order": StudSettings.DrawOrder.value,
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
        }
        GraphicsObjectDelegate.obj_counter += 1

        self._dialog_handler = DialogHandler()

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
        self.mouseDoubleClickEvent = (
            lambda event: self._dialog_handler.object_editor_dialog(self.obj_props)
        )

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
