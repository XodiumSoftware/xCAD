from enums.afc_enums import ObjSettings
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
            "object_id": ObjSettings.Object_ID.value,
            "type": ObjSettings.Type.value,
            "draw_order": ObjSettings.DrawOrder.value,
            "x": x,
            "y": y,
            "w": w,
            "h": h,
            "rad": rad,
            "pen_color": ObjSettings.PenColor.value,
            "pen_thickness": ObjSettings.PenThickness.value,
            "pen_style": ObjSettings.PenStyle.value,
            "fill_state": ObjSettings.Fill.value,
            "fill_color": ObjSettings.FillColor.value,
            "fill_pattern": ObjSettings.FillPattern.value,
            "fill_opacity": max(0, min(ObjSettings.FillOpacity.value, 100)),
        }
        GraphicsObjectDelegate.obj_counter += 1

        self.setup_graphics_object(x, y, w, h, rad)

    def setup_graphics_object(
        self,
        x: int,
        y: int,
        w: int,
        h: int,
        rad: int,
    ) -> None:
        """Setup the graphics object delegate."""
        _dialog_handler = DialogHandler()

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        self.setPos(x, y)
        self.setRect(self.rect().x(), self.rect().y(), w, h)
        self.setRotation(rad)
        self.mouseDoubleClickEvent = lambda event: _dialog_handler.object_editor_dialog(
            self.obj_props
        )

        self.setPen(
            QPen(
                QColor(ObjSettings.PenColor.value),
                ObjSettings.PenThickness.value,
                PenStyleTypes[ObjSettings.PenStyle.value].value,
            )
        )
        if ObjSettings.Fill.value:
            self.setBrush(
                QBrush(
                    QColor(ObjSettings.FillColor.value),
                    BrushStyleTypes[ObjSettings.FillPattern.value].value,
                )
            )
            self.setOpacity(max(0, min(ObjSettings.FillOpacity.value, 100)) / 100)
        else:
            self.setBrush(QBrush(BrushStyleTypes.NoBrush.value))

        self.setZValue(ObjSettings.DrawOrder.value)
        self.setToolTip(ObjSettings.Type.value)
