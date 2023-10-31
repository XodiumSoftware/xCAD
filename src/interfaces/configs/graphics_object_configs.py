from PySide6.QtCore import Qt
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItem
from StenLib.StenUtils import Utils

from interfaces.configs.graphics_object_configs import GraphicsObjectTypeHints
from interfaces.settings.settings_configs import ObjSettings


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

    Object_id = Utils.alphanumeric_id_generator()
    Flags = (
        QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
        | QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
    )
    Tooltip = ObjSettings.Type
    ZValue = ObjSettings.DrawOrder
    Pen = QPen(
        QColor(ObjSettings.PenColor),
        ObjSettings.PenThickness,
        Qt.PenStyle[ObjSettings.PenStyle],
    )
    Fill = ObjSettings.Fill
    Brush = QBrush(
        QColor(ObjSettings.FillColor),
        Qt.BrushStyle(ObjSettings.FillPattern),
    )
    Opacity = max(0, min(ObjSettings.FillOpacity, 100)) / 100
