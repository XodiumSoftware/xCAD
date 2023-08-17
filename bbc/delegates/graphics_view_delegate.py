from typing import Optional

from constants import (
    AspectRatioModeTypes,
    DragModeTypes,
    PenStyleTypes,
    RenderHintTypes,
    ScrollBarPolicyTypes,
)
from delegates.graphics_scene_delegate import GraphicsSceneDelegate
from inits import Inits
from PySide6.QtCore import QPointF, QRectF
from PySide6.QtGui import QColor, QPainter, QPainterPath, QPen, QWheelEvent
from PySide6.QtWidgets import QGraphicsView


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, parent: Optional[QGraphicsView] = None) -> None:
        """Initialize the graphics view delegate."""
        super().__init__(parent)
        self._graphics_scene_delegate = GraphicsSceneDelegate()
        self._general_settings = Inits.setup_init_graphics_view_properties()[
            "General settings:"
        ]

        self.setup_graphics_view()

    def setup_graphics_view(self):
        """Setup the graphics view delegate."""
        self.setScene(self._graphics_scene_delegate)

        self.setRenderHint(RenderHintTypes.Antialiasing.value)
        self.setHorizontalScrollBarPolicy(ScrollBarPolicyTypes.ScrollBarAlwaysOff.value)
        self.setVerticalScrollBarPolicy(ScrollBarPolicyTypes.ScrollBarAlwaysOff.value)
        self.setDragMode(DragModeTypes.ScrollHandDrag.value)
        self.setInteractive(True)
        self.fitInView(self.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value)

        self.wheelEvent = self.wheel_event

    def drawBackground(self, painter: QPainter, rect: QRectF) -> None:
        """Draws the background of the graphics view delegate."""
        super().drawBackground(painter, rect)
        self.draw_background(painter, rect, self._general_settings)
        self.draw_grid(painter, rect, self._general_settings)
        # self.draw_axis(painter, rect, self._general_settings)

    @staticmethod
    def draw_background(
        painter: QPainter, rect: QRectF, general_settings: dict
    ) -> None:
        """Draws the background of the graphics view delegate."""
        return painter.fillRect(rect, general_settings["Background color:"])

    @staticmethod
    def draw_grid(painter: QPainter, rect: QRectF, general_settings: dict) -> None:
        """Draws the grid of the graphics view delegate."""
        grid_spacing = general_settings["Grid size:"]

        pen = QPen(QColor(general_settings["Grid color:"]))
        pen.setStyle(PenStyleTypes[general_settings["Grid style:"]].value)
        painter.setPen(pen)

        grid_path = QPainterPath()

        left, top, right, bottom = (
            int(x - x % grid_spacing)
            for x in (rect.left(), rect.top(), rect.right(), rect.bottom())
        )

        right += grid_spacing
        bottom += grid_spacing

        for coord in range(left, right, grid_spacing):
            grid_path.moveTo(coord, top)
            grid_path.lineTo(coord, bottom)
            grid_path.moveTo(left, coord)
            grid_path.lineTo(right, coord)

        painter.drawPath(grid_path)

    @staticmethod
    def draw_axis(painter: QPainter, rect: QRectF, general_settings: dict) -> None:
        """Draws the axis of the graphics view delegate."""
        axis_properties = {
            "x": {
                "color": general_settings["X-axis color:"],
                "pos": rect.top() + general_settings["Grid size:"],
                "start": -rect.width(),
                "end": rect.width(),
            },
            "y": {
                "color": general_settings["Y-axis color:"],
                "pos": rect.left() + general_settings["Grid size:"],
                "start": -rect.height(),
                "end": rect.height(),
            },
        }

        for axis, props in axis_properties.items():
            painter.setPen(QPen(QColor(props["color"])))
            if axis == "x":
                painter.drawLine(
                    QPointF(props["start"], props["pos"]),
                    QPointF(props["end"], props["pos"]),
                )
            else:
                painter.drawLine(
                    QPointF(props["pos"], props["start"]),
                    QPointF(props["pos"], props["end"]),
                )

    def wheel_event(self, event: "QWheelEvent") -> None:
        """Zooms the graphics view delegate."""
        if event.angleDelta().y() > 0:
            self.scale(1.1, 1.1)
        else:
            self.scale(0.9, 0.9)
