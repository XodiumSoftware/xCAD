from typing import Dict, Optional

from constants import (
    DATABASE_PATH,
    BrushStyleTypes,
    GraphicsItemFlagTypes,
    PenStyleTypes,
)
from handlers.db_handler import DataBaseHandler
from handlers.signal_handler import SignalHandler
from inits import Inits
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem

Graphics_objects_table = (
    "graphics_objects",
    "object_id",
    "pen_color",
    "pen_thickness",
    "pen_style",
    "fill_color",
    "fill_pattern",
    "fill_opacity",
    "z_value",
    "tooltip",
)


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    def __init__(self, parent: Optional[QGraphicsRectItem] = None) -> None:
        """Initialize the graphics object delegate."""
        super().__init__(parent)
        self.setup_graphics_object()

    def setup_graphics_object(self) -> None:
        """Setup the graphics object delegate."""
        init_props = Inits.setup_init_graphics_object_properties()
        db_handler = DataBaseHandler()
        self.setup_table(db_handler)
        db_props = db_handler.retrieve_data(*Graphics_objects_table)
        signal_handler = SignalHandler()

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsMovable.value
            | GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        if db_props:
            self.saved_data(self, db_props)
        else:
            self.init_data(self, init_props)

        self.mouseDoubleClickEvent = (
            lambda event: signal_handler.objectDoubleClicked.emit(self)
        )

    @staticmethod
    def setup_table(db_handler: DataBaseHandler) -> None:
        """Setup the graphics objects table."""
        db_handler.create_table(*Graphics_objects_table)

    @staticmethod
    def saved_data(obj: QGraphicsRectItem, props) -> None:
        """Apply saved properties to the object."""
        obj.setPen(
            QPen(QColor(props[0][2]), props[0][3], PenStyleTypes[props[0][4]].value)
        )
        obj.setBrush(QBrush(QColor(props[0][5]), BrushStyleTypes[props[0][6]].value))
        obj.setOpacity(props[0][7] / 100)
        obj.setZValue(props[0][8])
        obj.setToolTip(props[0][9])

    @staticmethod
    def init_data(obj: QGraphicsRectItem, props: Dict) -> None:
        """Apply initial properties to the object."""
        fill_settings, pen_settings, general_settings = (
            props["Fill settings:"],
            props["Pen settings:"],
            props["General settings:"],
        )

        obj.setPen(
            QPen(
                QColor(pen_settings["Pen color:"]),
                pen_settings["Pen thickness:"],
                PenStyleTypes[pen_settings["Pen style:"]].value,
            )
        )
        if fill_settings["Fill:"]:
            obj.setBrush(
                QBrush(
                    QColor(fill_settings["Fill color:"]),
                    BrushStyleTypes[fill_settings["Fill pattern:"]].value,
                )
            )
            obj.setOpacity(max(0, min(fill_settings["Fill opacity:"], 100)) / 100)
        else:
            obj.setBrush(QBrush(BrushStyleTypes.NoBrush.value))
        obj.setZValue(general_settings["Draw order:"])
        obj.setToolTip(general_settings["Name:"])
