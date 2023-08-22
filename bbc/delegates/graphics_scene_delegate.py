from enum import Enum
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
from PySide6.QtWidgets import QDialog, QGraphicsRectItem, QGraphicsScene


class Dim(Enum):
    """A class to represent dimensions."""

    WallX = 4000
    WallY = 2000
    StudThickness = 38
    StudSpacing = 600


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


class GraphicsObjectDialog(QDialog):
    """A class to represent a graphics object dialog."""

    def __init__(self, parent: Optional[QDialog] = None) -> None:
        """Initialize the graphics object dialog."""
        super().__init__(parent)
        self.setup_graphics_object_dialog()

    def setup_graphics_object_dialog(self):
        """Setup the graphics object dialog."""
        pass


class GraphicsObjectDelegate(QGraphicsRectItem):
    """A class to represent a graphics object delegate."""

    obj_counter = 0

    def __init__(self, parent: Optional[QGraphicsRectItem] = None) -> None:
        """Initialize the graphics object delegate."""
        super().__init__(parent)
        self.setup_graphics_object()
        self.obj_id = GraphicsObjectDelegate.obj_counter
        self.stud_objs: Dict[int, GraphicsObjectDelegate] = {}
        GraphicsObjectDelegate.obj_counter += 1

    def setup_graphics_object(self):
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
            self.save_data(self.stud_objs, db_handler)
        else:
            self.init_data(self, init_props)

        self.mouseDoubleClickEvent = (
            lambda event: signal_handler.objectDoubleClicked.emit(self)
        )

    @staticmethod
    def setup_table(db_handler: DataBaseHandler):
        """Setup the graphics objects table."""
        db_handler.create_table(*Graphics_objects_table)

    @staticmethod
    def saved_data(obj: QGraphicsRectItem, props):
        """Apply saved properties to the object."""
        obj.setPen(
            QPen(QColor(props[0][2]), props[0][3], PenStyleTypes[props[0][4]].value)
        )
        obj.setBrush(QBrush(QColor(props[0][5]), BrushStyleTypes[props[0][6]].value))
        obj.setOpacity(props[0][7] / 100)
        obj.setZValue(props[0][8])
        obj.setToolTip(props[0][9])

    @staticmethod
    def init_data(obj: QGraphicsRectItem, props: Dict):
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

    @staticmethod
    def save_data(stud_objs, db_handler: DataBaseHandler):
        """Save the graphics scene."""
        for _, obj in stud_objs.items():
            db_handler.insert_data(
                "graphics_objects",
                obj.obj_id,
                obj.pen().color().name(),
                obj.pen().width(),
                obj.pen().style(),
                obj.brush().color().name(),
                obj.brush().style(),
                int(obj.opacity() * 100),
                int(obj.zValue()),
                obj.toolTip(),
            )
        db_handler.backup_database(f"{DATABASE_PATH}")


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self, parent: Optional[QGraphicsScene] = None) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__(parent)
        self.setup_graphics_scene()

    def setup_graphics_scene(self):
        """Setup the graphics scene delegate."""
        self.stud_objs: Dict[int, GraphicsObjectDelegate] = {}

        for x in range(0, Dim.WallX.value, Dim.StudSpacing.value):
            stud_obj = GraphicsObjectDelegate()
            self.addItem(stud_obj)
            stud_obj.setPos(x, 0)
            stud_obj.setRect(0, 0, Dim.StudThickness.value, Dim.WallY.value)
            self.stud_objs[x] = stud_obj
