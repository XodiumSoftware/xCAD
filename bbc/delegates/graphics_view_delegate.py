import math

from delegates.graphics_scene_delegate import GraphicsSceneDelegate
from enums.q_enums import PenStyleTypes, RenderHintTypes, ScrollBarPolicyTypes
from enums.setting_enums import GraphicsViewSettings
from helpers.helper import Helper
from PySide6.QtCore import QRectF
from PySide6.QtGui import QColor, QPainter, QPainterPath, QPen
from PySide6.QtWidgets import QGraphicsView


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, _) -> None:
        """Initialize the graphics view delegate."""
        super().__init__()
        self._helper = Helper()
        self.setup_graphics_view()

    def setup_graphics_view(self) -> None:
        """Setup the graphics view delegate."""
        self.setScene(GraphicsSceneDelegate())

        self.setRenderHint(RenderHintTypes.Antialiasing.value)
        self.setHorizontalScrollBarPolicy(ScrollBarPolicyTypes.ScrollBarAlwaysOff.value)
        self.setVerticalScrollBarPolicy(ScrollBarPolicyTypes.ScrollBarAlwaysOff.value)
        self.setStyleSheet(
            f"background-color: {GraphicsViewSettings.BackgroundColor.value};"
            f"border: {GraphicsViewSettings.BackgroundBorder.value};"
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
        grid_spacing = GraphicsViewSettings.GridSpacing.value

        pen = QPen(QColor(GraphicsViewSettings.GridPenColor.value))
        pen.setStyle(PenStyleTypes[GraphicsViewSettings.GridPenStyle.value].value)
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
