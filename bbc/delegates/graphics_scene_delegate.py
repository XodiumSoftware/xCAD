import re
from typing import Optional

from constants import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.signal_handler import SignalHandler
from inits import Inits
from numpy import rec
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItemGroup, QGraphicsRectItem, QGraphicsScene


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A delegate class for QGraphicsRectItem"""

    def __init__(self, parent: Optional[QGraphicsRectItem] = None) -> None:
        """Initialize the class"""
        super().__init__(parent)
        self.setup_graphics_object()

    def setup_graphics_object(self):
        """Setup the object"""
        properties = Inits.setup_init_graphics_object_properties()
        signal_handler = SignalHandler()

        dimension_settings, fill_settings, pen_settings, general_settings = (
            properties["Dimension settings:"],
            properties["Fill settings:"],
            properties["Pen settings:"],
            properties["General settings:"],
        )

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsMovable.value
            | GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        self.setRotation(dimension_settings["Rotation:"])
        self.setScale(dimension_settings["Scale:"])

        self.setPen(
            QPen(
                QColor(pen_settings["Pen color:"]),
                pen_settings["Pen thickness:"],
                PenStyleTypes[pen_settings["Pen style:"]].value,
            )
        )

        if fill_settings["Fill:"]:
            self.setBrush(
                QBrush(
                    QColor(fill_settings["Fill color:"]),
                    BrushStyleTypes[fill_settings["Fill pattern:"]].value,
                )
            )
            self.setOpacity(max(0, min(fill_settings["Fill opacity:"], 100)) / 100)
        else:
            self.setBrush(QBrush(BrushStyleTypes.NoBrush.value))

        self.setZValue(general_settings["Draw order:"])
        self.setToolTip(general_settings["Name:"])

        self.mouseDoubleClickEvent = (
            lambda event: signal_handler.objectDoubleClicked.emit(self)
        )


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self, parent: Optional[QGraphicsScene] = None) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__(parent)
        self.setup_graphics_scene()

    def setup_graphics_scene(self):
        """Setup the graphics scene delegate."""
        num_rows = 3
        num_cols = 4
        spacing = 10
        rect_width = 38
        rect_height = 170
        boundary_spacing = 10

        group = QGraphicsItemGroup()

        pen_color = QColor("#FFFFFF")
        brush_color = QColor("#ebd3b0")

        for row in range(num_rows):
            for col in range(num_cols):
                rect_item = QGraphicsRectItem()
                rect_item.setRect(
                    col * (rect_width + spacing),
                    row * (rect_height + spacing),
                    rect_width,
                    rect_height,
                )
                rect_item.setPen(QPen(pen_color))
                rect_item.setBrush(QBrush(brush_color))
                group.addToGroup(rect_item)

        boundary_pen = QPen(QColor("#00FFFF"))

        bounding_rect = group.boundingRect().adjusted(
            -boundary_spacing, -boundary_spacing, boundary_spacing, boundary_spacing
        )
        boundary_item = QGraphicsRectItem(bounding_rect)
        boundary_item.setPen(boundary_pen)
        group.addToGroup(boundary_item)

        total_width = (
            num_cols * rect_width + (num_cols - 1) * spacing + 2 * boundary_spacing
        )
        total_height = (
            num_rows * rect_height + (num_rows - 1) * spacing + 2 * boundary_spacing
        )

        self.addItem(group)
        group.setPos(-boundary_spacing, -boundary_spacing)
        self.setSceneRect(
            -boundary_spacing, -boundary_spacing, total_width, total_height
        )

        frame_length = 1000
        frame_height = 1000
        x = None
        obj = QGraphicsRectItem()

        frame_matrix = [
            [x, obj, x],
            [obj, x, obj],
            [x, obj, x],
        ]
