import math
from typing import Union

from PySide6.QtCore import QRect, QRectF, Qt
from PySide6.QtGui import QColor, QPainter, QPainterPath, QPen
from PySide6.QtWidgets import QGraphicsView

from delegates.graphics_scene_module import GraphicsSceneDelegate
from interfaces.configs.graphics_view_configs import GraphicsViewConfig

# TODO


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, _) -> None:  # NOTE: why the _ in the args?
        """Initialize the graphics view delegate."""
        super().__init__()
        self._fit_scene_in_view = self.fitInView(
            self.sceneRect(), Qt.AspectRatioMode.KeepAspectRatio
        )
        self.properties()

    def properties(self) -> None:
        """Setup the graphics view delegate."""
        self.setScene(GraphicsSceneDelegate())

        self.setRenderHint(QPainter.RenderHint.Antialiasing)
        self.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.setStyleSheet(
            f"background-color: {GraphicsViewConfig.background_color};"
            f"border: {GraphicsViewConfig.background_border};"
        )

        self.scale(1, -1)

        self._fit_scene_in_view

    def drawBackground(self, painter: QPainter, rect: Union[QRectF, QRect]) -> None:
        """Draws the background of the graphics view delegate."""
        super().drawBackground(painter, rect)
        self.draw_grid(painter, rect)
        self.update()

    @staticmethod
    def draw_grid(painter: QPainter, rect: Union[QRectF, QRect]) -> None:
        """Draws the grid of the graphics view delegate."""
        grid_spacing = GraphicsViewConfig.grid_spacing

        pen = QPen(QColor(GraphicsViewConfig.grid_pen_color))
        pen.setStyle(Qt.PenStyle[GraphicsViewConfig.grid_pen_style])
        painter.setPen(pen)

        grid_path = QPainterPath()

        left, top = math.floor(rect.left()), math.floor(rect.top())
        right, bottom = math.ceil(rect.right()), math.ceil(rect.bottom())

        for coord in range(left, right, int(grid_spacing)):
            grid_path.moveTo(coord, top)
            grid_path.lineTo(coord, bottom)
            grid_path.moveTo(left, coord)
            grid_path.lineTo(right, coord)

        painter.drawPath(grid_path)

    def resizeEvent(self, event):
        """Custom slot to handle window resize events."""
        self._fit_scene_in_view
        super().resizeEvent(event)
