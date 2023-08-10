from functools import partial
from typing import Optional

from handlers.dialog_handler import DialogHandler
from PySide6.QtCore import QLineF, QPointF, QRectF, QSettings, Qt
from PySide6.QtGui import (
    QAction,
    QBrush,
    QColor,
    QContextMenuEvent,
    QMouseEvent,
    QPainter,
    QPen,
    QResizeEvent,
    QWheelEvent,
)
from PySide6.QtWidgets import (
    QGraphicsItem,
    QGraphicsScene,
    QGraphicsView,
    QMenu,
    QSizePolicy,
    QWidget,
)


class Frame2DViewEventHandler:
    """A class to represent a 2D frame view event handler."""

    def __init__(self, frame_view: "Frame2DView"):
        """Initialize the 2D frame view event handler."""
        self.frame_view = frame_view
        self._last_pan_point = QPointF()

    def handle_mousePressEvent(self, event: QMouseEvent):
        """Handle mouse press events."""
        if event.button() == Qt.MouseButton.RightButton:
            item = self.frame_view.itemAt(event.pos())
            if isinstance(item, QGraphicsItem):
                self.frame_view.show_item_properties_dialog()

        if event.button() == Qt.MouseButton.MiddleButton:
            self.frame_view.setDragMode(QGraphicsView.DragMode.ScrollHandDrag)
            self._last_pan_point = event.pos()

        if event.button() == Qt.MouseButton.LeftButton:
            position_in_scene = self.frame_view.mapToScene(event.pos())
            self.frame_view.create_item(position_in_scene)

    def handle_resizeEvent(self, event: QResizeEvent):
        """Handle resize events."""
        self.frame_view.fit_to_items()

    def handle_wheelEvent(self, event: QWheelEvent):
        """Handle wheel events."""
        if event.modifiers() == Qt.KeyboardModifier.ControlModifier:
            zoom_factor = 1.15
            zoom = zoom_factor if event.angleDelta().y() > 0 else 1 / zoom_factor
            self.frame_view.scale(zoom, zoom)


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
        self._event_handler = Frame2DViewEventHandler(self)

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

    def drawBackground(self, painter: QPainter, rect: QRectF):
        """Draw the background."""
        super().drawBackground(painter, rect)

        grid_color = QColor(200, 200, 200)
        grid_pen = QPen(grid_color, 0.5, Qt.PenStyle.SolidLine)

        grid_size = 50
        left = int(rect.left()) - (int(rect.left()) % grid_size)
        top = int(rect.top()) - (int(rect.top()) % grid_size)
        right = int(rect.right())
        bottom = int(rect.bottom())

        vertical_lines = [
            ((x, rect.top()), (x, rect.bottom())) for x in range(left, right, grid_size)
        ]
        horizontal_lines = [
            ((rect.left(), y), (rect.right(), y)) for y in range(top, bottom, grid_size)
        ]

        lines = vertical_lines + horizontal_lines

        painter.setPen(grid_pen)
        painter.drawLines([QLineF(*line[0], *line[1]) for line in lines])

    def create_item(self, position: QPointF):
        """Create an item."""
        item_length = 100.0
        item_height = 100.0

        item = self._scene.addRect(0, 0, item_length, item_height)
        item.setPos(position)
        item.setFlags(QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)

        pen = QPen(QColor(255, 255, 255))
        brush = QBrush(QColor(235, 211, 176), Qt.BrushStyle.SolidPattern)

        item.setPen(pen)
        item.setBrush(brush)

        if item.isUnderMouse():
            self._dialog_handler.item_properties_dialog(0)

    def fit_to_items(self):
        """Fit the view to the items."""
        extra_space = 50
        items_rect = self._scene.itemsBoundingRect()
        scene_rect = items_rect.adjusted(
            -extra_space, -extra_space, extra_space, extra_space
        )
        self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def show_item_properties_dialog(self):
        """Show the item properties dialog."""
        selected_item = self._scene.selectedItems()
        if selected_item:
            item_index = self._scene.items().index(selected_item[0])
            self._dialog_handler.item_properties_dialog(item_index)

    def context_menu(self, event_pos: QPointF):
        """Show the context menu."""
        context_menu = QMenu(self)

        create_item_action = QAction("Create New Item", self)
        create_item_action.triggered.connect(partial(self.create_item, event_pos))
        context_menu.addAction(create_item_action)

        context_menu.exec_(self.mapToGlobal(event_pos.toPoint()))

    def mousePressEvent(self, event: QMouseEvent):
        """Handle mouse press events."""
        super().mousePressEvent(event)
        self._event_handler.handle_mousePressEvent(event)

    def resizeEvent(self, event: QResizeEvent):
        """Handle resize events."""
        super().resizeEvent(event)
        self._event_handler.handle_resizeEvent(event)

    def wheelEvent(self, event: QWheelEvent):
        """Handle wheel events."""
        self._event_handler.handle_wheelEvent(event)

    def contextMenuEvent(self, event: QPointF) -> None:
        """Handle context menu events."""
        self.context_menu(event)
