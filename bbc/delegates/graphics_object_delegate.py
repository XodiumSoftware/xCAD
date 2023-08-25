import sys

from constants import OBJECT_EDITOR_DIALOG_TITLE, UI_ICON_PATH
from enums.afc_enums import StudSettings
from enums.q_enums import BrushStyleTypes, GraphicsItemFlagTypes, PenStyleTypes
from handlers.db_handler import DataBaseHandler
from PySide6.QtGui import QBrush, QColor, QIcon, QPen
from PySide6.QtWidgets import (
    QDialog,
    QDoubleSpinBox,
    QGraphicsRectItem,
    QGridLayout,
    QLabel,
    QPushButton,
)

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

    def __init__(self, x: int, y: int, w: int, h: int, r: int) -> None:
        """Initialize the graphics object delegate."""
        super().__init__()
        self.setup_graphics_object(self, x, y, w, h, r)

    @staticmethod
    def setup_graphics_object(
        obj: QGraphicsRectItem, x: int, y: int, w: int, h: int, r: int
    ) -> None:
        """Setup the graphics object delegate."""
        db_handler = DataBaseHandler()
        GraphicsObjectDelegate.setup_table(db_handler)
        db_props = db_handler.retrieve_data(*Graphics_objects_table)

        obj.setFlags(
            GraphicsItemFlagTypes.ItemIsSelectable.value
            | GraphicsItemFlagTypes.ItemSendsGeometryChanges.value
        )

        if db_props:
            GraphicsObjectDelegate.saved_data(obj, db_props)
        else:
            GraphicsObjectDelegate.init_data(obj)

        obj.setPos(x, y)
        obj.setRect(obj.rect().x(), obj.rect().y(), w, h)
        obj.setRotation(r)
        obj.mouseDoubleClickEvent = (
            lambda event, obj=obj: GraphicsObjectDelegate.object_editor_dialog(obj)
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

        # TODO: save after initial setup

    @staticmethod
    def object_editor_dialog(obj: QGraphicsRectItem) -> None:
        """Open a dialog when a object is pressed."""
        dialog = QDialog()
        dialog.setWindowTitle(OBJECT_EDITOR_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))

        layout = QGridLayout()
        dialog.setLayout(layout)

        label = QLabel("Stud width:")

        obj_size_spinbox = QDoubleSpinBox()
        obj_size_spinbox.setRange(0, sys.float_info.max)
        obj_size_spinbox.setSingleStep(1)
        obj_size_spinbox.setDecimals(0)
        obj_size_spinbox.setValue(obj.rect().width())

        save_button = QPushButton("Save")
        discard_button = QPushButton("Discard")

        save_button.clicked.connect(dialog.accept)
        discard_button.clicked.connect(dialog.reject)

        layout.addWidget(label, 0, 0)
        layout.addWidget(obj_size_spinbox, 0, 1)
        layout.addWidget(save_button, 1, 0)
        layout.addWidget(discard_button, 1, 1)

        dialog.setLayout(layout)
        dialog.setMinimumSize(dialog.sizeHint())
        dialog.setMaximumSize(dialog.sizeHint())

        result = dialog.exec()

        if result == QDialog.DialogCode.Accepted:
            obj.setRect(
                obj.rect().x(),
                obj.rect().y(),
                obj_size_spinbox.value(),
                obj.rect().height(),
            )
            print("Accepted")
        elif result == QDialog.DialogCode.Rejected:
            print("Rejected")
