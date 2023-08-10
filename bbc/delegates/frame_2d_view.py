from typing import Optional

from handlers.dialog_handler import DialogHandler
from PySide6.QtCore import QPointF, QRectF, QSettings, Qt
from PySide6.QtGui import QBrush, QColor, QMouseEvent, QPainter, QPen, QResizeEvent
from PySide6.QtWidgets import (
    QGraphicsItem,
    QGraphicsScene,
    QGraphicsView,
    QLabel,
    QSizePolicy,
    QWidget,
)


class Frame2DViewEventHandler:
    def __init__(self, frame_view):
        self.frame_view = frame_view
        self._last_pan_point = QPointF()

    def handle_mousePressEvent(self, event: QMouseEvent):
        if event.button() == Qt.MouseButton.RightButton:
            item = self.frame_view.itemAt(event.pos())
            if isinstance(item, QGraphicsItem) and item == self.frame_view._item:
                self.frame_view.show_item_properties_dialog()

        if event.button() == Qt.MouseButton.MiddleButton:
            self.frame_view.setDragMode(QGraphicsView.DragMode.ScrollHandDrag)
            self._last_pan_point = event.pos()

    def handle_resizeEvent(self, event: QResizeEvent):
        self.frame_view.fit_to_items()

    def handle_wheelEvent(self, event: QMouseEvent):
        if event.modifiers() == Qt.KeyboardModifier.ControlModifier:
            zoom_factor = 1.15
            if event.angleDelta().y() > 0:
                self.frame_view.scale(zoom_factor, zoom_factor)
            else:
                self.frame_view.scale(1 / zoom_factor, 1 / zoom_factor)
        else:
            self.frame_view.wheelEvent(event)


class Frame2DView(QGraphicsView):
    """A class to represent a 2D frame view."""

    def __init__(
        self, module_data: Optional[dict] = None, parent: Optional[QWidget] = None
    ):
        """Initialize the 2D frame view."""
        super().__init__(parent)
        self.module_data = module_data
        self._settings = QSettings()
        self._item_position = QPointF()
        self._dialog_handler = DialogHandler()
        self._last_pan_point = QPointF()
        self._event_handler = Frame2DViewEventHandler(self)

        self.load_item_values()
        self.load_item_position()
        self.setup_frame_2d_view()

    def setup_frame_2d_view(self):
        """Setup the frame 2D view."""
        self._scene = QGraphicsScene(self)
        self.setScene(self._scene)

        self._scene.setBackgroundBrush(QColor(0, 0, 0))

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
        self._item_length = float(self._item_length) if self._item_length else 100.0
        self._item_height = float(self._item_height) if self._item_height else 100.0

        self._item = self._scene.addRect(0, 0, self._item_length, self._item_height)
        self._item.setFlags(QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)

        pen = QPen(QColor(255, 255, 255))
        self._item.setPen(pen)

        brush = QBrush(QColor(235, 211, 176))
        brush.setStyle(Qt.BrushStyle.SolidPattern)
        self._item.setBrush(brush)

        self.create_label()

    def create_label(self):
        """Create a label for the item."""
        label = QLabel()
        label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        return label

    def show_item_properties_dialog(self):
        """Show the item properties dialog."""
        if self._item.isUnderMouse():
            self._dialog_handler.item_properties_dialog(0)

    def load_item_values(self):
        """Load the item values."""
        self._item_length = self._settings.value("item_length", 38, type=float)
        self._item_height = self._settings.value("item_height", 1000, type=float)

    def load_item_position(self):
        """Load the item position."""
        self._item_position = self._settings.value(
            "item_position", QPointF(0, 0), type=QPointF
        )

    def save_item_values(self):
        """Save the item values."""
        self._settings.setValue("item_length", self._item.rect().width())
        self._settings.setValue("item_height", self._item.rect().height())

    def save_item_position(self):
        """Save the item position."""
        self._settings.setValue("item_position", self._item.pos())

    def update_rect_dimensions(self):
        """Update the dimensions of the rectangle."""
        self._item.setRect(0, 0, self._item_length, self._item_height)
        self.fit_to_items()
        self._scene.update()

        self.save_item_values()

    def update_item_position(self, position: QPointF):
        """Update the position of the item."""
        self._item.setPos(position)
        self.save_item_position()

    def fit_to_items(self):
        """Fit the view to the items."""
        extra_space = 50
        items_rect = self._scene.itemsBoundingRect()
        scene_rect = items_rect.adjusted(
            -extra_space, -extra_space, extra_space, extra_space
        )
        self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def delete_item(self):
        """Delete the item."""
        if self._item in self._scene.items():
            self._scene.removeItem(self._item)

    def mousePressEvent(self, event: QMouseEvent):
        """Handle mouse press events."""
        super().mousePressEvent(event)
        self._event_handler.handle_mousePressEvent(event)

    def resizeEvent(self, event: QResizeEvent):
        """Handle resize events."""
        super().resizeEvent(event)
        self._event_handler.handle_resizeEvent(event)

    def wheelEvent(self, event: QMouseEvent):
        """Handle wheel events."""
        self._event_handler.handle_wheelEvent(event)
