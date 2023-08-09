from typing import Optional

from handlers.dialog_handler import DialogHandler
from PySide6.QtCore import QPointF, QRectF, QSettings, Qt
from PySide6.QtGui import QBrush, QColor, QMouseEvent, QPainter, QPen, QResizeEvent
from PySide6.QtWidgets import (
    QDialog,
    QGraphicsItem,
    QGraphicsScene,
    QGraphicsView,
    QLabel,
    QSizePolicy,
    QWidget,
)


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

        self.draw_origin_symbol(painter, rect)

    def draw_origin_symbol(self, painter: QPainter, rect: QRectF):
        """Draw the origin symbol."""
        painter.setPen(QPen(QColor(255, 0, 0), 1.0, Qt.PenStyle.SolidLine))

        center_x = rect.width() / 2
        center_y = rect.height() / 2

        center_x_int = int(center_x)
        center_y_int = int(center_y)

        painter.drawLine(
            center_x_int, int(rect.top()), center_x_int, int(rect.bottom())
        )
        painter.drawLine(
            int(rect.left()), center_y_int, int(rect.right()), center_y_int
        )
        painter.drawEllipse(center_x_int - 3, center_y_int - 3, 6, 6)

    def create_items(self):
        """Draw the items."""
        self._item_length = float(self._item_length) if self._item_length else 100.0
        self._item_height = float(self._item_height) if self._item_height else 100.0

        self._item = self._scene.addRect(0, 0, self._item_length, self._item_height)
        self._item.setFlags(
            QGraphicsItem.GraphicsItemFlag.ItemIsMovable
            | QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
        )

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

    def mousePressEvent(self, event: QMouseEvent):
        """Handle mouse press event."""
        super().mousePressEvent(event)

        if event.button() == Qt.MouseButton.RightButton:
            item = self.itemAt(event.pos())
            if isinstance(item, QGraphicsItem) and item == self._item:
                self.show_item_properties_dialog()

        if event.button() == Qt.MouseButton.MiddleButton:
            self.setDragMode(QGraphicsView.DragMode.ScrollHandDrag)
            self._last_pan_point = event.pos()

    def show_item_properties_dialog(self):
        """Show the dimension dialog."""
        if self._item.isUnderMouse():
            desc = ""
            length = float(self._item_length)
            height = float(self._item_height)
            fill_state = True

            self._dialog_handler.item_properties_dialog(
                desc, length, height, fill_state
            )

            if length != self._item_length or height != self._item_height:
                self._item_length = length
                self._item_height = height
                self.update_rect_dimensions()

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
        try:
            length = float(
                self._dialog_handler.item_properties_dialog.length_edit.value()
            )
            height = float(
                self._dialog_handler.item_properties_dialog.height_edit.value()
            )
        except ValueError:
            return

        self._item.setRect(0, 0, length, height)
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

    def resizeEvent(self, event: "QResizeEvent"):
        """Resize the event."""
        super().resizeEvent(event)
        self.fit_to_items()

    def mouseReleaseEvent(self, event: QMouseEvent):
        """Handle mouse release event."""
        super().mouseReleaseEvent(event)
        if self._item.isSelected():
            self.update_item_position(self._item.pos())

        if event.button() == Qt.MouseButton.MiddleButton:
            self.setDragMode(QGraphicsView.DragMode.NoDrag)

    def wheelEvent(self, event: QMouseEvent):
        """Handle the mouse wheel event for zooming."""
        if event.modifiers() == Qt.KeyboardModifier.ControlModifier:
            zoom_factor = 1.15
            if event.angleDelta().y() > 0:
                self.scale(zoom_factor, zoom_factor)
            else:
                self.scale(1 / zoom_factor, 1 / zoom_factor)
        else:
            super().wheelEvent(event)

    def mouseMoveEvent(self, event: QMouseEvent):
        """Handle mouse move event."""
        super().mouseMoveEvent(event)

        if self.dragMode() == QGraphicsView.DragMode.ScrollHandDrag:
            delta = self.mapToScene(event.pos()) - self.mapToScene(self._last_pan_point)
            self.translate(delta.x(), delta.y())
            self._last_pan_point = event.pos()
