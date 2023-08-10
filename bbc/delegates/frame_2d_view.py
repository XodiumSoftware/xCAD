from collections import defaultdict
from functools import partial
from typing import Optional

from handlers.dialog_handler import DialogHandler
from handlers.properties_handler import PropertiesHandler
from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QLineF, QPointF, QRectF, QSettings, Qt, Signal
from PySide6.QtGui import (
    QAction,
    QBrush,
    QColor,
    QContextMenuEvent,
    QMouseEvent,
    QPainter,
    QPen,
    QResizeEvent,
    QTransform,
    QWheelEvent,
)
from PySide6.QtWidgets import (
    QGraphicsItem,
    QGraphicsRectItem,
    QGraphicsScene,
    QGraphicsView,
    QMenu,
    QSizePolicy,
    QWidget,
)


class CustomGraphicsScene(QGraphicsScene):
    """A custom QGraphicsScene class."""

    itemDoubleClicked = Signal(int)

    def __init__(self):
        """Initialize the custom QGraphicsScene class."""
        super().__init__()
        self._dialog_handler = DialogHandler()
        self._properties_handler = PropertiesHandler()
        self._signal_handler = SignalHandler()
        self._items = defaultdict(dict)
        self._current_item_id = 0

        self.setup_connections()

    def setup_connections(self):
        """Setup the connections."""
        self._signal_handler.deleteItemSignal.connect(self.delete_item)

    def create_item(self, position: QPointF):
        """Create an item."""
        item_properties = self._properties_handler.setup_init_item_properties()

        general_settings = item_properties["General settings:"]
        dimension_settings = item_properties["Dimension settings:"]
        fill_settings = item_properties["Fill settings:"]
        pen_settings = item_properties["Pen settings:"]

        item_length = dimension_settings[0]["Length:"]
        item_height = dimension_settings[0]["Height:"]

        rect_item = QGraphicsRectItem(0, 0, item_length, item_height)
        rect_item.setPos(position)
        rect_item.setFlags(QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)

        fill_color = QColor(fill_settings[0]["Fill color:"])
        fill_opacity = fill_settings[0]["Fill opacity:"]
        rect_item.setBrush(
            QBrush(
                fill_color,
                PropertiesHandler.setup_fill_patterns(
                    fill_settings[0]["Fill pattern:"]
                ),
            )
        )
        rect_item.setOpacity(fill_opacity)

        pen_color = QColor(pen_settings[0]["Pen color:"])
        pen_thickness = pen_settings[0]["Pen thickness:"]
        pen_style = PropertiesHandler.setup_pen_styles(pen_settings[0]["Pen style:"])
        rect_item.setPen(QPen(pen_color, pen_thickness, pen_style))

        self.addItem(rect_item)
        self._items[self._current_item_id] = item_properties

        self._current_item_id += 1

        if rect_item.isUnderMouse():
            self._dialog_handler.item_properties_dialog(0)

    def delete_item(self):
        """Delete the selected item."""
        print("delete_item method called")
        selected_items = self.selectedItems()
        if selected_items:
            for item in selected_items:
                self.removeItem(item)
        self.itemDoubleClicked.emit(-1)

    def mouseDoubleClickEvent(self, event):
        """Override the mouseDoubleClickEvent to show the dialog"""
        item = self.itemAt(event.scenePos(), QTransform())
        if item:
            item_index = self.items().index(item)
            self.itemDoubleClicked.emit(item_index)
        else:
            super().mouseDoubleClickEvent(event)

    def mouseMoveEvent(self, event):
        """Override the mouseMoveEvent to handle item movement"""
        if self.mousePressed:
            super().mouseMoveEvent(event)

    def mouseReleaseEvent(self, event):
        """Override the mouseReleaseEvent to handle item movement"""
        self.mousePressed = False
        super().mouseReleaseEvent(event)


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
        self._custom_graphics_scene = CustomGraphicsScene()

        self.setup_frame_2d_view()

    def setup_frame_2d_view(self):
        """Setup the frame 2D view."""
        self.setScene(self._custom_graphics_scene)

        self._custom_graphics_scene.setBackgroundBrush(QColor(0, 0, 0))

        self.setTransformationAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setMinimumSize(300, 300)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)

        self._custom_graphics_scene.mousePressed = False
        self._custom_graphics_scene.itemDoubleClicked.connect(
            self.handle_item_double_clicked
        )

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

    def fit_to_items(self):
        """Fit the view to the items."""
        extra_space = 50
        items_rect = self._custom_graphics_scene.itemsBoundingRect()
        scene_rect = items_rect.adjusted(
            -extra_space, -extra_space, extra_space, extra_space
        )
        self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def show_item_properties_dialog(self):
        """Show the item properties dialog."""
        selected_item = self._custom_graphics_scene.selectedItems()
        if selected_item:
            item_id = self._custom_graphics_scene.items().index(selected_item[0])
            self._dialog_handler.item_properties_dialog(item_id)

    def context_menu(self, event_pos: QPointF):
        """Show the context menu."""
        context_menu = QMenu(self)

        context_menu.setStyleSheet(
            """
            QMenu {
                background-color: rgba(0, 0, 0, 0);
                border: 1px solid white;
                border-radius: 6px;
                color: white;
            }
            QMenu::item {
                padding: 8px 20px;
                font-weight: bold;
            }
            QMenu::item:selected {
                background-color: #f4c211;
                border-radius: 6px;
                color: black;
            }
            """
        )

        create_item_action = QAction("Create New Item", self)
        create_item_action.triggered.connect(
            partial(self._custom_graphics_scene.create_item, event_pos)
        )
        context_menu.addAction(create_item_action)

        context_menu.exec(self.mapToGlobal(event_pos.toPoint()))

    def resizeEvent(self, event: QResizeEvent):
        """Handle resize events."""
        super().resizeEvent(event)
        self.fit_to_items()

    def wheelEvent(self, event: QWheelEvent):
        """Handle wheel events."""
        if event.modifiers() == Qt.KeyboardModifier.ControlModifier:
            zoom_factor = 1.15
            zoom = zoom_factor if event.angleDelta().y() > 0 else 1 / zoom_factor
            self.scale(zoom, zoom)

    def contextMenuEvent(self, event: QContextMenuEvent) -> None:
        """Handle context menu events."""
        event_pos = QPointF(event.pos())
        self.context_menu(event_pos)

    def handle_item_double_clicked(self):
        """Handle item double clicked event"""
        self.show_item_properties_dialog()

    def mousePressEvent(self, event: QMouseEvent):
        """Handle mouse press events."""
        super().mousePressEvent(event)
        if event.button() == Qt.MouseButton.RightButton:
            item = self.itemAt(event.pos())
            if isinstance(item, QGraphicsItem):
                self.show_item_properties_dialog()

        if event.button() == Qt.MouseButton.MiddleButton:
            self.setDragMode(QGraphicsView.DragMode.ScrollHandDrag)
            self._last_pan_point = event.pos()

        if event.button() == Qt.MouseButton.LeftButton:
            self._custom_graphics_scene.mousePressed = True
            selected_item = self._custom_graphics_scene.selectedItems()
            if selected_item:
                self._item_position = selected_item[0].pos() - self.mapToScene(
                    event.pos()
                )

    def mouseMoveEvent(self, event: QMouseEvent):
        """Handle mouse move events."""
        super().mouseMoveEvent(event)
        if (
            self._custom_graphics_scene.mousePressed
            and self._custom_graphics_scene.selectedItems()
        ):
            item = self._custom_graphics_scene.selectedItems()[0]
            new_item_pos = self.mapToScene(event.pos()) + self._item_position
            item.setPos(new_item_pos)
