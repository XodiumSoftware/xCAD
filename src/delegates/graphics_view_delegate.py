import math

from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QColor, QPainter, QPainterPath, QPen
from PySide6.QtWidgets import QGraphicsView
from StenLib.StenHelper import StenHelper

from configs.settings_configs import GraphicsViewSettings
from delegates.graphics_scene_delegate import GraphicsSceneDelegate


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, _) -> None:
        """Initialize the graphics view delegate."""
        super().__init__()
        self._helper = StenHelper()
        self.properties()

    def properties(self) -> None:
        """Setup the graphics view delegate."""
        self.setScene(GraphicsSceneDelegate())

        self.setRenderHint(QPainter.RenderHint.Antialiasing)
        self.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.setStyleSheet(
            f"background-color: {GraphicsViewSettings.BackgroundColor};"
            f"border: {GraphicsViewSettings.BackgroundBorder};"
        )

        self.scale(1, -1)

        self._helper.fit_scene_in_view(self)

    def drawBackground(self, painter: QPainter, rect: QRectF) -> None:
        """Draws the background of the graphics view delegate."""
        super().drawBackground(painter, rect)
        self.draw_grid(painter, rect)
        self.update()

    @staticmethod
    def draw_grid(painter: QPainter, rect: QRectF) -> None:
        """Draws the grid of the graphics view delegate."""
        grid_spacing = GraphicsViewSettings.GridSpacing

        pen = QPen(QColor(GraphicsViewSettings.GridPenColor))
        pen.setStyle(Qt.PenStyle[GraphicsViewSettings.GridPenStyle])
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
        self._helper.fit_scene_in_view(self)
        super().resizeEvent(event)
