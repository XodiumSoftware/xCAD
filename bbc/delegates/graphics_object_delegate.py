from enums.afc_enums import StudSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.db_handler import DataBaseHandler
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

    def __init__(self) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self.setup_graphics_object()

    def setup_graphics_object(self) -> None:
        """Setup the graphics object delegate."""
        db_handler = DataBaseHandler()
        self.setup_table(db_handler)
        db_props = db_handler.retrieve_data(*Graphics_objects_table)

        self.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        if db_props:
            self.saved_data(self, db_props)
        else:
            self.init_data(self)

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
    def init_data(obj: QGraphicsRectItem) -> None:
        """Apply initial properties to the object."""
        obj.setPen(
            QPen(
                QColor(StudSettings.PenColor.value),
                StudSettings.PenThickness.value,
                PenStyleTypes[StudSettings.PenStyle.value].value,
            )
        )
        if StudSettings.Fill.value:
            obj.setBrush(
                QBrush(
                    QColor(StudSettings.FillColor.value),
                    BrushStyleTypes[StudSettings.FillPattern.value].value,
                )
            )
            obj.setOpacity(max(0, min(StudSettings.FillOpacity.value, 100)) / 100)
        else:
            obj.setBrush(QBrush(BrushStyleTypes.NoBrush.value))
        obj.setZValue(StudSettings.DrawOrder.value)
        obj.setToolTip(StudSettings.Name.value)
