from constants import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.signal_handler import SignalHandler
from inits import Inits
from PySide6.QtCore import QRectF
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A delegate class for QGraphicsRectItem"""

    def __init__(self, parent=None):
        """Initialize the class"""
        super().__init__(parent)
        self.setup_graphics_object_properties()

    def setup_graphics_object_properties(
        self,
    ):
        """Setup the object"""
        properties = Inits.setup_init_graphics_object_properties()
        signal_handler = SignalHandler()

        dimension_settings, fill_settings, pen_settings, general_settings = (
            properties["Dimension settings:"],
            properties["Fill settings:"],
            properties["Pen settings:"],
            properties["General settings:"],
        )

        self.setFlags(
            GraphicsItemFlagTypes.ISMOVABLE.value
            | GraphicsItemFlagTypes.ISSELECTABLE.value
            | GraphicsItemFlagTypes.SENDSGEOMETRYCHANGES.value
        )

        self.setRect(
            QRectF(
                0,
                0,
                dimension_settings["Length:"],
                dimension_settings["Height:"],
            )
        )
        self.setRotation(dimension_settings["Rotation:"])
        self.setScale(dimension_settings["Scale:"])

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
            self.setBrush(QBrush(BrushStyleTypes.NOBRUSH.value))

        self.setZValue(general_settings["Draw order:"])
        self.setToolTip(general_settings["Name:"])

        self.mouseDoubleClickEvent = (
            lambda event: signal_handler.objectDoubleClicked.emit(self)
        )
