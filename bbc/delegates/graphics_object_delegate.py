from enums.afc_enums import ObjSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.db_handler import DataBaseHandler
from helpers.helper import Helper
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    object_id = 0

    def __init__(self, posx: int, posy: int, dimx: int, dimy: int, rad: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self._db_handler = DataBaseHandler
        self._helpers = Helper

        self.setup_graphics_object(posx, posy, dimx, dimy, rad)

    def setup_graphics_object(
        self, posx: int, posy: int, dimx: int, dimy: int, rad: int
    ) -> None:
        """Setup the graphics object delegate."""
        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )
        obj_id_exists = self.object_id in self._db_handler.retrieve_data(
            "Object_Properties"
        )
        if obj_id_exists:
            self.database_props()
        else:
            self.init_props(posx, posy, dimx, dimy, rad)

    def database_props(self) -> None:
        """Return the database properties."""
        retrieved_data = self._db_handler.retrieve_data("Object_Properties")

        self.object_id = retrieved_data[0]
        self.setToolTip(retrieved_data[1])
        self.setZValue(retrieved_data[2])
        self.setPos(retrieved_data[3])
        self.setRect(retrieved_data[4])
        self.setRotation(retrieved_data[5])
        self.setPen(
            QPen(
                QColor(retrieved_data[7]),
                retrieved_data[8],
                PenStyleTypes[retrieved_data[6]].value,
            )
        )
        if retrieved_data[9]:
            self.setBrush(
                QBrush(
                    QColor(retrieved_data[11]),
                    BrushStyleTypes[retrieved_data[10]].value,
                )
            )
            self.setOpacity(max(0, min(retrieved_data[12], 100)) / 100)

    def init_props(self, posx: int, posy: int, dimx: int, dimy: int, rad: int) -> None:
        """Initialize the properties."""
        self.object_id = self._helpers.generate_complex_id()
        self.setToolTip(ObjSettings.Type.value)
        self.setZValue(ObjSettings.DrawOrder.value)
        self.setPos(posx, posy)
        self.setRect(self.rect().x(), self.rect().y(), dimx, dimy)
        self.setRotation(rad)
        self.setPen(
            QPen(
                QColor(ObjSettings.PenColor.value),
                ObjSettings.PenThickness.value,
                PenStyleTypes[ObjSettings.PenStyle.value].value,
            )
        )
        if ObjSettings.Fill.value:
            self.setBrush(
                QBrush(
                    QColor(ObjSettings.FillColor.value),
                    BrushStyleTypes[ObjSettings.FillPattern.value].value,
                )
            )
            self.setOpacity(max(0, min(ObjSettings.FillOpacity.value, 100)) / 100)
        self.update_props()

    def update_props(self) -> None:
        """Update the properties."""
        stud_props = {
            ObjSettings.Object_ID: self.object_id,
            ObjSettings.Type: self.toolTip(),
            ObjSettings.DrawOrder: self.zValue(),
            ObjSettings.Rad: self.rotation(),
            ObjSettings.PenStyle: self.pen().style(),
            ObjSettings.PenColor: self.pen().color().name(),
            ObjSettings.PenThickness: self.pen().width(),
            ObjSettings.Fill: self.brush().isOpaque(),
            ObjSettings.FillPattern: self.brush().style(),
            ObjSettings.FillColor: self.brush().color().name(),
            ObjSettings.FillOpacity: int(self.opacity() * 100),
        }

        self._db_handler.insert_data("Object_Properties", stud_props)
