from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem, QGraphicsSceneMouseEvent

from delegates.dialog_delegate import DialogDelegate
from enums.module_enums import Dialogs
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from enums.settings_enums import ObjSettings
from helpers.helper import Helper


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    def __init__(self, posx: int, posy: int, dimx: int, dimy: int, rad: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self._helpers, self._dialog_delegate = Helper, DialogDelegate

        self.setup_graphics_object(posx, posy, dimx, dimy, rad)

    def setup_graphics_object(
        self, posx: int, posy: int, dimx: int, dimy: int, rad: int
    ) -> None:
        """Setup the graphics object delegate."""
        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )
        self.object_id = self._helpers.complex_id_generator()
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

    def mouseDoubleClickEvent(self, event: QGraphicsSceneMouseEvent) -> None:
        """Handle the mouse double click event."""
        super().mouseDoubleClickEvent(event)
        self._dialog_delegate(Dialogs.ObjectDialog.value, self, self.object_id)
