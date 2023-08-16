import matplotlib.pyplot as plt
import numpy as np
from delegates.graphics_scene_delegate import GraphicsSceneDelegate
from enums import SizePolicyType
from inits import Inits
from PySide6.QtCore import QPointF, QRectF, QSettings, Qt
from PySide6.QtGui import (
    QColor,
    QPainter,
    QPainterPath,
    QPaintEvent,
    QPen,
    QResizeEvent,
)
from PySide6.QtWidgets import QGraphicsView


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, parent=None):
        """Initialize the graphics view delegate."""
        super().__init__(parent)
        self._settings = QSettings()
        self._graphics_scene_delegate = GraphicsSceneDelegate()
        self._general_settings = Inits.setup_init_graphics_view_properties()[
            "General settings:"
        ]
        self._scene_rect = QRectF()

        self.setup_graphics_view()

    def setup_graphics_view(self):
        """Setup the graphics view delegate."""
        self.setScene(self._graphics_scene_delegate)

        self.setRenderHint(QPainter.RenderHint.Antialiasing)
        self.setTransformationAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.fitInView(self.sceneRect(), Qt.AspectRatioMode.KeepAspectRatio)
        self.setSizePolicy(
            SizePolicyType.EXPANDING.value, SizePolicyType.EXPANDING.value
        )

        self.setBackgroundBrush(QColor(self._general_settings["Background color:"]))

    def resizeEvent(self, event: QResizeEvent) -> None:
        """Resize the graphics view and adjust the view to fit the scene."""
        super().resizeEvent(event)

        self._scene_rect = QRectF(
            -self._general_settings["Grid size:"],
            -self._general_settings["Grid size:"],
            event.size().width(),
            event.size().height(),
        )
        self.setSceneRect(self._scene_rect)
        self.fitInView(self._scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def paintEvent(self, event: QPaintEvent) -> None:
        """Paint the graphics view delegate."""
        super().paintEvent(event)

        painter = QPainter(self.viewport())

        painter.setWorldTransform(
            self.transform()
            .scale(1, -1)
            .translate(
                self._general_settings["Grid size:"],
                -self.viewport().height() + self._general_settings["Grid size:"],
            )
        )

        self.setup_graphics_view_grid(painter, self._scene_rect, self._general_settings)
        self.setup_graphics_view_axis(painter, self._scene_rect, self._general_settings)

        painter.end()

    @staticmethod
    def setup_graphics_view_grid(
        painter: QPainter, rect: QRectF, general_settings: dict
    ) -> None:
        grid_size = general_settings["Grid size:"]

        left, top, right, bottom = (
            int(x - x % grid_size)
            for x in (rect.left(), rect.top(), rect.right(), rect.bottom())
        )

        right += grid_size
        bottom += grid_size

        painter.setPen(
            QPen(QColor(general_settings["Grid color:"]), 0.5, Qt.PenStyle.SolidLine)
        )

        grid_path = QPainterPath()

        for coord in range(left, right, grid_size):
            grid_path.moveTo(coord, top)
            grid_path.lineTo(coord, bottom)
            grid_path.moveTo(left, coord)
            grid_path.lineTo(right, coord)

        painter.drawPath(grid_path)

    @staticmethod
    def setup_graphics_view_axis(
        painter: QPainter, rect: QRectF, general_settings: dict
    ) -> None:
        """Draw the axis of the view."""
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
