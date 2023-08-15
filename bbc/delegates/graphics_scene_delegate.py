from collections import defaultdict
from typing import Dict, Optional

from handlers.dialog_handler import DialogHandler
from handlers.properties_handler import PropertiesHandler
from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QPointF, QSettings, Qt
from PySide6.QtGui import QBrush, QColor, QPen, QTransform
from PySide6.QtWidgets import QGraphicsItem, QGraphicsRectItem, QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A custom QGraphicsScene class."""

    def __init__(self):
        """Initialize the custom QGraphicsScene class."""
        super().__init__()
        self._properties_handler = PropertiesHandler()
        self._signal_handler = SignalHandler()
        self._objects: Dict[int, dict] = defaultdict(dict)
        self._settings = QSettings()
        self._current_item_id = 0

        self.setup_connections()
        self.load_scene_state()

    def setup_connections(self):
        """Setup the connections."""
        self._signal_handler.deleteItemSignal.connect(self.delete_object)
        self._dialog_handler = DialogHandler(self._objects)

        self._item_id_mapping = {}

        for object in self.items():
            self.connect_item_change_signal(object)

    def create_object(self, position: QPointF) -> Optional[QGraphicsRectItem]:
        """Create an object."""
        existing_object_ids = [
            object.data(Qt.ItemDataRole.UserRole) for object in self.items()
        ]
        if self._current_item_id in existing_object_ids:
            return

        object_properties = self._properties_handler.setup_init_object_properties()

        dimension_settings = object_properties["Dimension settings:"]
        fill_settings = object_properties["Fill settings:"]
        pen_settings = object_properties["Pen settings:"]

        object_length = dimension_settings[0]["Length:"]
        object_height = dimension_settings[0]["Height:"]

        object = QGraphicsRectItem(0, 0, object_length, object_height)
        object.setPos(position)
        object.setFlags(QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)

        fill_state = fill_settings[0]["Fill:"]
        fill_color = QColor(fill_settings[0]["Fill color:"])
        fill_opacity = fill_settings[0]["Fill opacity:"]

        if fill_state == True:
            object.setBrush(
                QBrush(
                    fill_color,
                    Qt.BrushStyle[fill_settings[0]["Fill pattern:"]],
                )
            )
            object.setOpacity(fill_opacity)
        else:
            object.setBrush(QBrush(Qt.BrushStyle.NoBrush))

        pen_color = QColor(pen_settings[0]["Pen color:"])
        pen_thickness = pen_settings[0]["Pen thickness:"]
        pen_style = Qt.PenStyle[pen_settings[0]["Pen style:"]]

        object.setPen(QPen(pen_color, pen_thickness, pen_style))
        object.setData(Qt.ItemDataRole.UserRole, self._current_item_id)

        self.addItem(object)
        self._objects[self._current_item_id] = object_properties

        self._current_item_id += 1

        if object.isUnderMouse():
            self._dialog_handler.object_properties_dialog(0)

        self.save_scene_state()

        return object

    def delete_object(self):
        """Delete the selected object."""
        print("delete_object method called")  # NOTE: DEBUG
        selected_objects = self.selectedItems()
        if selected_objects:
            for object in selected_objects:
                self.removeItem(object)
        self._signal_handler.objectDoubleClicked.emit(-1)

    def save_scene_state(self):
        """Save the scene state."""
        self._settings.beginWriteArray("objects")
        for object_id, object_properties in self._objects.items():
            self._settings.setArrayIndex(object_id)
            self._settings.setValue("object_properties", object_properties)
            self._settings.setValue("object_position", self.items()[object_id].pos())
        self._settings.endArray()

    def load_scene_state(self):
        """Load the scene state."""
        self._settings.beginReadArray("objects")
        for object_id in range(self._settings.beginReadArray("objects")):
            self._settings.setArrayIndex(object_id)
            object_properties = self._settings.value("object_properties")
            object_position = self._settings.value("object_position", QPointF(0, 0))
            if object_properties is not None:
                self._objects[object_id] = object_properties
            object = self.create_object(object_position)
            self.addItem(object)
        self._settings.endArray()

    def connect_item_change_signal(self, object: QGraphicsItem):
        """Connect object change signal"""
        object.itemChange.connect(self.item_position_changed)

    def item_position_changed(
        self, change: QGraphicsItem.GraphicsItemChange, value: QPointF
    ):
        """Handle object position change"""
        if change == QGraphicsItem.GraphicsItemChange.ItemPositionChange:
            object_id = self._item_id_mapping[self.sender()]
            self._objects[object_id]["object position:"] = (value.x(), value.y())
            self.save_scene_state()
        return value

    def mouseDoubleClickEvent(self, event):
        """Override the mouseDoubleClickEvent to show the dialog"""
        object = self.itemAt(event.scenePos(), QTransform())
        if object:
            object_index = self.items().index(object)
            self._signal_handler.objectDoubleClicked.emit(object_index)
        else:
            super().mouseDoubleClickEvent(event)

    def mouseMoveEvent(self, event):
        """Override the mouseMoveEvent to handle object movement"""
        if self.mousePressed:
            super().mouseMoveEvent(event)

    def mouseReleaseEvent(self, event):
        """Override the mouseReleaseEvent to handle object movement"""
        self.mousePressed = False
        super().mouseReleaseEvent(event)
        self.save_scene_state()
