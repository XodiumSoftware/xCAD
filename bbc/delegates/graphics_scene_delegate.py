from enum import Enum
from typing import Dict, Optional

from constants import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.signal_handler import SignalHandler
from inits import Inits
from PySide6.QtCore import Qt
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem, QGraphicsScene


class Dim(Enum):
    WallX = 4000
    WallY = 2000
    StudThickness = 38
    StudSpacing = 600


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    def __init__(self, parent: Optional[QGraphicsRectItem] = None) -> None:
        """Initialize the graphics object delegate."""
        super().__init__(parent)
        self.setup_graphics_object()

    def setup_graphics_object(self):
        """Setup the graphics object delegate."""
        props = Inits.setup_init_graphics_object_properties()
        wall_y = Dim.WallY.value
        stud_thickness = Dim.StudThickness.value
        signal_handler = SignalHandler()

        fill_settings, pen_settings, general_settings = (
            props["Fill settings:"],
            props["Pen settings:"],
            props["General settings:"],
        )

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsMovable.value
            | GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        self.setRect(0, 0, stud_thickness, wall_y)
        self.setBrush(QBrush(QColor("#ebd3b0"), Qt.BrushStyle.SolidPattern))

        self.setPen(
            QPen(
                QColor(pen_settings["Pen color:"]),
                pen_settings["Pen thickness:"],
                PenStyleTypes[pen_settings["Pen style:"]].value,
            )
        )

        if fill_settings["Fill:"]:
            self.setBrush(
                QBrush(
                    QColor(fill_settings["Fill color:"]),
                    BrushStyleTypes[fill_settings["Fill pattern:"]].value,
                )
            )
            self.setOpacity(max(0, min(fill_settings["Fill opacity:"], 100)) / 100)
        else:
            self.setBrush(QBrush(BrushStyleTypes.NoBrush.value))

        self.setZValue(general_settings["Draw order:"])
        self.setToolTip(general_settings["Name:"])

        self.mouseDoubleClickEvent = (
            lambda event: signal_handler.objectDoubleClicked.emit(self)
        )


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self, parent: Optional[QGraphicsScene] = None) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__(parent)
        self.setup_graphics_scene()
        self.load_scene()

    def setup_graphics_scene(self):
        """Setup the graphics scene delegate."""
        self.stud_items: Dict[int, GraphicsObjectDelegate] = {}

        for x in range(0, Dim.WallX.value, Dim.StudSpacing.value):
            stud_item = GraphicsObjectDelegate()
            self.addItem(stud_item)
            stud_item.setPos(x, 0)
            self.stud_items[x] = stud_item
            self.save_scene()

    @staticmethod
    def save_scene():
        """Save the graphics scene."""
        pass

    @staticmethod
    def load_scene():
        """Load the graphics scene."""
        pass
