from enums.afc_enums import ObjSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    obj_counter = 0

    def __init__(self) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self.obj_counter += 1

        self.setup_graphics_object()

    def setup_graphics_object(self) -> None:
        """Setup the graphics object delegate."""

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        self.setPos(ObjSettings.Pos.value[0], ObjSettings.Pos.value[1])
        self.setRect(
            self.rect().x(),
            self.rect().y(),
            ObjSettings.Dim.value[0],
            ObjSettings.Dim.value[0],
        )
        self.setRotation(ObjSettings.Rad.value)

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

        self.setZValue(ObjSettings.DrawOrder.value)
        self.setToolTip(ObjSettings.Type.value)
