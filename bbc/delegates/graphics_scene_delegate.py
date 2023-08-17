from typing import Optional

from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsItemGroup, QGraphicsRectItem, QGraphicsScene


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

        pen_color = QPen(QColor("#FFFFFF"))
        brush_color = QBrush(QColor("#EBD3B0"))

        group = QGraphicsItemGroup()

        for row in range(num_rows):
            for col in range(num_cols):
                rect_item = QGraphicsRectItem()
                rect_item.setRect(
                    col * (rect_width + spacing),
                    row * (rect_height + spacing),
                    rect_width,
                    rect_height,
                )
                rect_item.setPen(pen_color)
                rect_item.setBrush(brush_color)
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
