import math
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
from PySide6.QtCore import QEvent, QRectF, Qt
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

        self.installEventFilter(self)

    def eventFilter(self, instance: QGraphicsView, event: QWheelEvent) -> bool:
        """Event filter for the graphics view delegate."""
        event_handlers = {
            QEvent.Type.MouseButtonDblClick: self.fit_on_double_click_event,
            QEvent.Type.Wheel: self.zoom_on_wheel_event,
        }

        handler_method = event_handlers.get(event.type())
        if handler_method:
            handler_method(self, event)

        return super().eventFilter(instance, event)

    def drawBackground(self, painter: QPainter, rect: QRectF) -> None:
        """Draws the background of the graphics view delegate."""
        super().drawBackground(painter, rect)
        self.draw_background(painter, rect, self._general_settings)
        self.draw_grid(painter, rect, self._general_settings)

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
    def zoom_on_wheel_event(instance: QGraphicsView, event: QWheelEvent) -> None:
        """Zoom in/out on mouse wheel."""
        delta = event.angleDelta().y()
        factor = math.pow(1.1, math.copysign(1, delta))
        instance.scale(factor, factor)

    @staticmethod
    def fit_on_double_click_event(instance: QGraphicsView, event: QWheelEvent) -> None:
        """Fit on double click."""
        if event.button() == Qt.MouseButton.MiddleButton:
            instance.fitInView(
                instance.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value
            )
