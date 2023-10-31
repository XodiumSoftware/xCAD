from PySide6.QtCore import Qt
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItem, QGraphicsRectItem, QGraphicsSceneMouseEvent
from StenLib.StenUtils import Utils

from delegates.dialog_delegate import DialogDelegate
from interfaces.configs.dialog_configs import ObjectDialogConfig
from interfaces.settings.settings_configs import ObjSettings


# TODO
class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    def __init__(self, posx: int, posy: int, dimx: int, dimy: int, rad: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self.properties(posx, posy, dimx, dimy, rad)

    def properties(self, posx: int, posy: int, dimx: int, dimy: int, rad: int) -> None:
        """Setup the graphics object delegate."""
        self.setFlags(
            QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
            | QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
        )
        self.object_id = Utils.alphanumeric_id_generator()
        self.setToolTip(ObjSettings.Type)
        self.setZValue(ObjSettings.DrawOrder)
        self.setPos(posx, posy)
        self.setRect(self.rect().x(), self.rect().y(), dimx, dimy)
        self.setRotation(rad)
        self.setPen(
            QPen(
                QColor(ObjSettings.PenColor),
                ObjSettings.PenThickness,
                Qt.PenStyle[ObjSettings.PenStyle],
            )
        )
        if ObjSettings.Fill:
            self.setBrush(
                QBrush(
                    QColor(ObjSettings.FillColor),
                    Qt.BrushStyle[ObjSettings.FillPattern],
                )
            )
            self.setOpacity(max(0, min(ObjSettings.FillOpacity, 100)) / 100)

    def mouseDoubleClickEvent(self, event: QGraphicsSceneMouseEvent) -> None:
        """Handle the mouse double click event."""
        super().mouseDoubleClickEvent(event)
        DialogDelegate(ObjectDialogConfig(), self, self.object_id)
