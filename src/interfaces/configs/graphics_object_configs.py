from PySide6.QtCore import Qt
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItem

from data.obj_data import ObjInitData
from interfaces.configs.graphics_object_configs import GraphicsObjectTypeHints


class GraphicsObjectTypeHints:
    """A class used to represent graphics object type hints."""

    Object_id: str
    Flags = QGraphicsItem.GraphicsItemFlag | QGraphicsItem.GraphicsItemFlag
    Tooltip: str
    ZValue: int
    Pen: QPen
    Fill: bool
    Brush: QBrush
    Opacity: float


class GraphicsObjectConfig(GraphicsObjectTypeHints):
    """A class used to represent a graphics object config."""

    Object_id = ObjInitData.Object_ID
    Flags = (
        QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
        | QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
    )
    Tooltip = ObjInitData.Type
    ZValue = ObjInitData.DrawOrder
    Pen = QPen(
        QColor(ObjInitData.PenColor),
        ObjInitData.PenThickness,
        Qt.PenStyle[ObjInitData.PenStyle],
    )
    Fill = ObjInitData.Fill
    Brush = QBrush(
        QColor(ObjInitData.FillColor),
        Qt.BrushStyle(ObjInitData.FillPattern),
    )
    Opacity = max(0, min(ObjInitData.FillOpacity, 100)) / 100
