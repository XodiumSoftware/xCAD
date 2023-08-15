from math import ceil, isqrt
from typing import List

from constants import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.properties_handler import PropertiesHandler
from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QRectF
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItemGroup, QGraphicsRectItem


class GraphicsObjectDelegate:
    """A delegate class for QGraphicsRectItem"""

    @staticmethod
    def setup_graphics_object(
        obj: QGraphicsRectItem,
        pos_x: float,
        pos_y: float,
    ):
        """Setup the object"""
        properties = PropertiesHandler.setup_init_object_properties()

        general_settings = properties["General settings:"]
        dimension_settings = properties["Dimension settings:"]
        fill_settings = properties["Fill settings:"]
        pen_settings = properties["Pen settings:"]

        x = dimension_settings[0]["Width:"]
        y = dimension_settings[0]["Height:"]
        obj.setRect(QRectF(pos_x, pos_y, x, y))
        obj.setRotation(dimension_settings[0]["Rotation:"])
        obj.setScale(dimension_settings[0]["Scale:"])

        obj.setFlag(GraphicsItemFlagTypes.ISMOVABLE.value, True)
        obj.setFlag(GraphicsItemFlagTypes.ISSELECTABLE.value, True)
        obj.setFlag(GraphicsItemFlagTypes.SENDSGEOMETRYCHANGES.value, True)

        if fill_settings[0]["Fill:"]:
            fill_color = QColor(fill_settings[0]["Fill color:"])
            fill_style = getattr(BrushStyleTypes, fill_settings[0]["Fill pattern:"])
            fill_opacity = fill_settings[0]["Fill opacity:"]
            obj.setBrush(QBrush(fill_color, fill_style))
            obj.setOpacity(max(0, min(fill_opacity, 100)) / 100)
        else:
            obj.setBrush(QBrush(BrushStyleTypes.NOBRUSH.value))

        pen_color = QColor(pen_settings[0]["Pen color:"])
        pen_thickness = pen_settings[0]["Pen thickness:"]
        pen_style = getattr(PenStyleTypes, pen_settings[0]["Pen style:"])
        obj.setPen(QPen(pen_color, pen_thickness, pen_style))

        obj.setZValue(general_settings[0]["Draw order:"])

        obj.setToolTip(general_settings[0]["Name:"])

        signal_handler = SignalHandler()
        obj.mouseDoubleClickEvent = (
            lambda event: signal_handler.objectDoubleClicked.emit(obj)
        )

    @staticmethod
    def setup_graphics_object_group(objects: List[QGraphicsRectItem]):
        num_objects = len(objects)
        num_per_row = ceil(isqrt(num_objects))

        group = QGraphicsItemGroup()
        object_matrix = [[None] * num_per_row for _ in range(num_per_row)]

        obj_width = objects[0].boundingRect().width() if objects else 0
        obj_height = objects[0].boundingRect().height() if objects else 0

        for index, obj in enumerate(objects):
            row, col = divmod(index, num_per_row)
            x, y = col * obj_width, row * obj_height
            obj.setPos(x, y)
            group.addToGroup(obj)

        return group, object_matrix


# sample:
object_matrix = (
    [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],
    ],
)
