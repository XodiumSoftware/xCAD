from typing import Optional

from constants import GRAPHICS_VIEWS
from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QBrush, QColor, QPainter, QPen
from PySide6.QtWidgets import (
    QGraphicsLineItem,
    QGraphicsRectItem,
    QGraphicsScene,
    QGraphicsTextItem,
    QGraphicsView,
    QSizePolicy,
)


class Frame2DView(QGraphicsView):
    """A class to represent a 2D frame view."""

    def __init__(self, module_data: Optional[dict] = None, parent=None):
        """Initialize the Frame2DView."""
        super().__init__(parent)
        self.module_data = module_data
        self.setup_frame_2d_view()

    def setup_frame_2d_view(self):
        """Setup the Frame2DView."""
        self.scene: QGraphicsScene = QGraphicsScene(self)
        self.setScene(self.scene)

        self.scene.setBackgroundBrush(QColor(0, 0, 0))

        self.setTransformationAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setMinimumSize(300, 300)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)

        self.create_items()

    def drawBackground(self, painter: QPainter, rect: QRectF):
        """Draw the background."""
        super().drawBackground(painter, rect)

        painter.setPen(QPen(QColor(200, 200, 200), 0.5, Qt.PenStyle.SolidLine))

        grid_size = 50

        left = int(rect.left()) - (int(rect.left()) % grid_size)
        top = int(rect.top()) - (int(rect.top()) % grid_size)

        lines = []
        for x in range(int(left), int(rect.right()), grid_size):
            lines.append(((x, rect.top()), (x, rect.bottom())))
        for y in range(int(top), int(rect.bottom()), grid_size):
            lines.append(((rect.left(), y), (rect.right(), y)))

        for line in lines:
            painter.drawLine(*line[0], *line[1])

    def create_items(self):
        """Draw the items."""
        pass

    def fit_to_items(self):
        """Automatically zoom in to fit the items in the view with some extra space."""
        extra_space = 50
        items_rect = self.scene.itemsBoundingRect()
        scene_rect = items_rect.adjusted(
            -extra_space, -extra_space, extra_space, extra_space
        )
        self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def resizeEvent(self, event):
        """Override the resize event to fit the items whenever the view is resized."""
        super().resizeEvent(event)
        self.fit_to_items()
