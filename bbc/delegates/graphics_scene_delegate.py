from collections import defaultdict
from typing import Dict

from handlers.dialog_handler import DialogHandler
from handlers.properties_handler import PropertiesHandler
from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QPointF, QSettings, Qt, Signal
from PySide6.QtGui import QBrush, QColor, QPen, QTransform
from PySide6.QtWidgets import QGraphicsItem, QGraphicsRectItem, QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A custom QGraphicsScene class."""

    itemDoubleClicked = Signal(int)

    def __init__(self):
        """Initialize the custom QGraphicsScene class."""
        super().__init__()
        self._properties_handler = PropertiesHandler()
        self._signal_handler = SignalHandler()
        self._items: Dict[int, dict] = defaultdict(dict)
        self._settings = QSettings()
        self._current_item_id = 0

        self.setup_connections()
        self.load_scene_state()

    def setup_connections(self):
        """Setup the connections."""
        self._signal_handler.deleteItemSignal.connect(self.delete_item)
        self._dialog_handler = DialogHandler(self._items)
        for item in self.items():
            self.connect_item_change_signal(item)

    def create_item(self, position: QPointF):
        """Create an item."""
        existing_item_ids = [
            item.data(Qt.ItemDataRole.UserRole) for item in self.items()
        ]
        if self._current_item_id in existing_item_ids:
            return

        item_properties = self._properties_handler.setup_init_item_properties()

        dimension_settings = item_properties["Dimension settings:"]
        fill_settings = item_properties["Fill settings:"]
        pen_settings = item_properties["Pen settings:"]

        item_length = dimension_settings[0]["Length:"]
        item_height = dimension_settings[0]["Height:"]

        rect_item = QGraphicsRectItem(0, 0, item_length, item_height)
        rect_item.setPos(position)
        rect_item.setFlags(QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)

        fill_state = fill_settings[0]["Fill:"]
        fill_color = QColor(fill_settings[0]["Fill color:"])
        fill_opacity = fill_settings[0]["Fill opacity:"]

        if fill_state == True:
            rect_item.setBrush(
                QBrush(
                    fill_color,
                    Qt.BrushStyle[fill_settings[0]["Fill pattern:"]],
                )
            )
            rect_item.setOpacity(fill_opacity)
        else:
            rect_item.setBrush(QBrush(Qt.BrushStyle.NoBrush))

        pen_color = QColor(pen_settings[0]["Pen color:"])
        pen_thickness = pen_settings[0]["Pen thickness:"]
        pen_style = Qt.PenStyle[pen_settings[0]["Pen style:"]]

        rect_item.setPen(QPen(pen_color, pen_thickness, pen_style))
        rect_item.setData(Qt.ItemDataRole.UserRole, self._current_item_id)

        self.addItem(rect_item)
        self._items[self._current_item_id] = item_properties

        self._current_item_id += 1

        if rect_item.isUnderMouse():
            self._dialog_handler.item_properties_dialog(0)

        self.save_scene_state()

        return rect_item

    def delete_item(self):
        """Delete the selected item."""
        print("delete_item method called")
        selected_items = self.selectedItems()
        if selected_items:
            for item in selected_items:
                self.removeItem(item)
        self.itemDoubleClicked.emit(-1)

    def save_scene_state(self):
        """Save the scene state."""
        self._settings.beginWriteArray("items")
        for item_id, item_properties in self._items.items():
            self._settings.setArrayIndex(item_id)
            self._settings.setValue("item_properties", item_properties)
            self._settings.setValue("item_position", self.items()[item_id].pos())
        self._settings.endArray()

    def load_scene_state(self):
        """Load the scene state."""
        self._settings.beginReadArray("items")
        for item_id in range(self._settings.beginReadArray("items")):
            self._settings.setArrayIndex(item_id)
            item_properties = self._settings.value("item_properties")
            item_position = self._settings.value("item_position", QPointF(0, 0))
            if item_properties is not None:
                self._items[item_id] = item_properties
            item = self.create_item(item_position)
            self.addItem(item)
        self._settings.endArray()

    def connect_item_change_signal(self, item: QGraphicsItem):
        """Connect item change signal"""
        item.itemChange.connect(self.item_position_changed)

    def item_position_changed(self, change: QGraphicsItem.GraphicsItemChange, value):
        """Handle item position change"""
        if change == QGraphicsItem.GraphicsItemFlag.ItemPositionChange:
            item_id = value.data(Qt.ItemDataRole.UserRole)
            self._items[item_id]["Item position:"] = (value.x(), value.y())
            self.save_scene_state()
        return value

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
        self.save_scene_state()
