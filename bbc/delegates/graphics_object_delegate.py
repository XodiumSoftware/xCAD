from enums.afc_enums import ObjSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from helpers.helper import Helper
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    object_id = 0

    def __init__(self, posx: int, posy: int, dimx: int, dimy: int, rad: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self._helpers = Helper

        self.setup_graphics_object(posx, posy, dimx, dimy, rad)

    def setup_graphics_object(
        self, posx: int, posy: int, dimx: int, dimy: int, rad: int
    ) -> None:
        """Setup the graphics object delegate."""
        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )
        self.object_id = self._helpers.generate_complex_id()
        self.setToolTip(ObjSettings.Type.value)
        self.setZValue(ObjSettings.DrawOrder.value)
        self.setPos(posx, posy)
        self.setRect(self.rect().x(), self.rect().y(), dimx, dimy)
        self.setRotation(rad)
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
