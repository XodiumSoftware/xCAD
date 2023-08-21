from typing import Optional

from constants import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.signal_handler import SignalHandler
from inits import Inits
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A delegate class for QGraphicsRectItem"""

    def __init__(self, parent: Optional[QGraphicsRectItem] = None) -> None:
        """Initialize the class"""
        super().__init__(parent)
        self.setup_graphics_object()

    def setup_graphics_object(self):
        """Setup the object"""
        properties = Inits.setup_init_graphics_object_properties()
        signal_handler = SignalHandler()

        fill_settings, pen_settings, general_settings = (
            properties["Fill settings:"],
            properties["Pen settings:"],
            properties["General settings:"],
        )

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsMovable.value
            | GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

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
