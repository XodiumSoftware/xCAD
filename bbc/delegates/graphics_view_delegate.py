from delegates.graphics_scene_delegate import GraphicsSceneDelegate
from enums import SizePolicyType
from inits import Inits
from PySide6.QtCore import QPointF, QRectF, QSettings, Qt
from PySide6.QtGui import QColor, QPainter, QPaintEvent, QPen, QResizeEvent
from PySide6.QtWidgets import QGraphicsView


class GraphicsViewDelegate(QGraphicsView):
    """A class to represent a graphics view delegate."""

    def __init__(self, parent=None):
        """Initialize the graphics view delegate."""
        super().__init__(parent)
        self._settings = QSettings()
        self._graphics_scene_delegate = GraphicsSceneDelegate()

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

    def resizeEvent(self, event: QResizeEvent) -> None:
        """Resize the graphics view and adjust the view to fit the scene."""
        super().resizeEvent(event)

        properties = Inits.setup_init_graphics_view_properties()
        general_settings = properties["General settings:"]

        self.setSceneRect(
            -general_settings["Grid size:"],
            -general_settings["Grid size:"],
            event.size().width(),
            event.size().height(),
        )
        self.fitInView(self.sceneRect(), Qt.AspectRatioMode.KeepAspectRatio)

    def paintEvent(self, event: QPaintEvent) -> None:
        """Paint the graphics view delegate."""
        super().paintEvent(event)

        properties = Inits.setup_init_graphics_view_properties()
        general_settings = properties["General settings:"]

        painter = QPainter(self.viewport())

        origin_offset_x = general_settings["Grid size:"]
        origin_offset_y = general_settings["Grid size:"]

        painter.setWorldTransform(
            self.transform()
            .scale(1, -1)
            .translate(origin_offset_x, -self.viewport().height() + origin_offset_y)
        )

        rect = QRectF(self.sceneRect())

        self.setup_graphics_view_grid(painter, rect, general_settings)
        self.setup_graphics_view_background(general_settings)
        self.setup_graphics_view_axis(painter, rect, general_settings)

    def setup_graphics_view_grid(
        self, painter: QPainter, rect: QRectF, general_settings: dict
    ) -> None:
        """Draw a grid in the background of the view."""
        grid_pen_color = QColor(general_settings["Grid color:"])
        grid_pen = QPen(grid_pen_color, 0.5, Qt.PenStyle.SolidLine)
        grid_size = general_settings["Grid size:"]

        left = int(rect.left())
        top = int(rect.top())
        right = int(rect.right())
        bottom = int(rect.bottom())

        left -= left % grid_size
        top -= top % grid_size
        right += grid_size - right % grid_size
        bottom += grid_size - bottom % grid_size

        painter.setPen(grid_pen)

        x_values = range(left, right + 1, grid_size)
        y_values = range(top, bottom + 1, grid_size)

        for x in x_values:
            painter.drawLine(x, top, x, bottom)

        for y in y_values:
            painter.drawLine(left, y, right, y)

    def setup_graphics_view_background(self, general_settings: dict) -> None:
        """Draw the background of the view."""
        self.setBackgroundBrush(QColor(general_settings["Background color:"]))

    def setup_graphics_view_axis(
        self, painter: QPainter, rect: QRectF, general_settings: dict
    ) -> None:
        """Draw the axis of the view."""
        x_axis_color = QColor(general_settings["X-axis color:"])
        y_axis_color = QColor(general_settings["Y-axis color:"])

        origin_offset = general_settings["Grid size:"]

        x_axis_start = QPointF(-rect.width(), rect.top() + origin_offset)
        x_axis_end = QPointF(rect.width(), rect.top() + origin_offset)

        y_axis_start = QPointF(rect.left() + origin_offset, -rect.height())
        y_axis_end = QPointF(rect.left() + origin_offset, rect.height())

        x_axis_pen = QPen(x_axis_color)
        y_axis_pen = QPen(y_axis_color)

        painter.setPen(x_axis_pen)
        painter.drawLine(x_axis_start, x_axis_end)

        painter.setPen(y_axis_pen)
        painter.drawLine(y_axis_start, y_axis_end)
