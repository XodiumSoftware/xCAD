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
        self.setPos(posx, posy)
        self.setRect(self.rect().x(), self.rect().y(), dimx, dimy)
        self.setRotation(rad)

        obj_id_exists = self._db_handler.retrieve_data("Object_Properties")
        if obj_id_exists:
            self.database_props()
        else:
            self.init_props()

    def database_props(self) -> None:
        """Return the database properties."""
        retrieved_data = self._db_handler.retrieve_data("Object_Properties")[0]

        self.object_id = retrieved_data["Object_ID"]
        self.setToolTip(retrieved_data["Type"])
        self.setZValue(retrieved_data["DrawOrder"])
        self.setPen(
            QPen(
                QColor(retrieved_data["PenColor"]),
                retrieved_data["PenThickness"],
                PenStyleTypes[retrieved_data["PenStyle"]].value,
            )
        )
        if retrieved_data["Fill"]:
            self.setBrush(
                QBrush(
                    QColor(retrieved_data["FillColor"]),
                    BrushStyleTypes[retrieved_data["FillPattern"]].value,
                )
            )
            self.setOpacity(max(0, min(retrieved_data["FillOpacity"], 100)) / 100)

    def init_props(self) -> None:
        """Initialize the properties."""
        self.object_id = self._helpers.generate_complex_id()
        self.setToolTip(ObjSettings.Type.value)
        self.setZValue(ObjSettings.DrawOrder.value)
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
            ObjSettings.PenStyle: self.pen().style().name,
            ObjSettings.PenColor: self.pen().color().name(),
            ObjSettings.PenThickness: self.pen().width(),
            ObjSettings.Fill: self.brush().isOpaque(),
            ObjSettings.FillPattern: self.brush().style().name,
            ObjSettings.FillColor: self.brush().color().name(),
            ObjSettings.FillOpacity: int(self.opacity() * 100),
        }

        self._db_handler.insert_data("Object_Properties", stud_props)
