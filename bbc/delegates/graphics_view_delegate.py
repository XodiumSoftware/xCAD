import math

from delegates.graphics_scene_delegate import GraphicsSceneDelegate
from enums.afc_enums import GraphicsViewSettings
from enums.q_enums import (
    AspectRatioModeTypes,
    PenStyleTypes,
    RenderHintTypes,
    ScrollBarPolicyTypes,
)
from PySide6.QtCore import QRectF
from PySide6.QtGui import QBrush, QColor, QPainter, QPainterPath, QPen
from PySide6.QtWidgets import QGraphicsView


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, _) -> None:
        """Initialize the graphics view delegate."""
        super().__init__()
        self.setup_graphics_view()

    def setup_graphics_view(self) -> None:
        """Setup the graphics view delegate."""
        self.setScene(GraphicsSceneDelegate())

        self.setRenderHint(RenderHintTypes.Antialiasing.value)
        self.setHorizontalScrollBarPolicy(ScrollBarPolicyTypes.ScrollBarAlwaysOff.value)
        self.setVerticalScrollBarPolicy(ScrollBarPolicyTypes.ScrollBarAlwaysOff.value)

        self.fit_scene_in_view(self)

    def drawBackground(self, painter: QPainter, rect: QRectF) -> None:
        """Draws the background of the graphics view delegate."""
        super().drawBackground(painter, rect)
        self.fill_background(painter, rect)
        self.draw_grid(painter, rect)

    @staticmethod
    def fill_background(painter: QPainter, rect: QRectF) -> None:
        """Draws the background of the graphics view delegate."""
        background_brush = QBrush(QColor(GraphicsViewSettings.BackgroundColor.value))
        painter.fillRect(rect, background_brush)

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

        # TODO: Add func to update grid after editing objects.

    @staticmethod
    def fit_scene_in_view(instance: QGraphicsView) -> None:
        """Fits the scene in the view with margins around the scene."""
        instance.fitInView(
            instance.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value
        )

    def resizeEvent(self, event):
        """Custom slot to handle window resize events."""
        GraphicsViewDelegate.fit_scene_in_view(self)
        super().resizeEvent(event)
