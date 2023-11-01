from dataclasses import dataclass

from PySide6.QtCore import Qt
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItem

from data.obj_data import ObjInitData


@dataclass
class GraphicsObjectTypeHints:
    """A class used to represent graphics object type hints."""

    object_id: str
    flags: QGraphicsItem.GraphicsItemFlag | QGraphicsItem.GraphicsItemFlag
    tooltip: str
    zvalue: int
    pen: QPen
    fill: bool
    brush: QBrush
    opacity: float


class GraphicsObjectConfig(GraphicsObjectTypeHints):
    """A class used to represent a graphics object config."""

    def __init__(self):
        super().__init__(
            object_id=ObjInitData.Object_ID,
            flags=(
                QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
                | QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
            ),
            tooltip=ObjInitData.Type,
            zvalue=ObjInitData.DrawOrder,
            pen=QPen(
                QColor(ObjInitData.PenColor),
                ObjInitData.PenThickness,
                Qt.PenStyle[ObjInitData.PenStyle],
            ),
            fill=ObjInitData.Fill,
            brush=QBrush(
                QColor(ObjInitData.FillColor),
                Qt.BrushStyle(ObjInitData.FillPattern),
            ),
            opacity=max(0, min(ObjInitData.FillOpacity, 100)) / 100,
        )
