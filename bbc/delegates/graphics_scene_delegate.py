import sys
from typing import Dict

from constants import OBJECT_EDITOR_DIALOG_TITLE, UI_ICON_PATH
from delegates.graphics_object_delegate import GraphicsObjectDelegate
from enums.afc_enums import FrameSettings, StudSettings
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QDialog,
    QDoubleSpinBox,
    QGraphicsScene,
    QGraphicsSceneMouseEvent,
    QGridLayout,
    QLabel,
    QPushButton,
)


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__()
        self.setup_frame_work(self)

    @staticmethod
    def setup_frame_work(scene: QGraphicsScene) -> None:
        """Setup the frame work."""
        stud_objs: Dict[int, GraphicsObjectDelegate] = {}

        for x in range(0, FrameSettings.FrameX.value, FrameSettings.StudSpacing.value):
            stud_obj = GraphicsObjectDelegate()
            scene.addItem(stud_obj)
            stud_obj.setPos(x, 0)
            stud_obj.setRect(0, 0, StudSettings.StudX.value, FrameSettings.FrameY.value)
            stud_objs[x] = stud_obj
            stud_obj.mouseDoubleClickEvent = lambda event, stud_obj=stud_obj: GraphicsSceneDelegate.object_editor_dialog(
                event, stud_obj
            )

    @staticmethod
    def object_editor_dialog(
        event: QGraphicsSceneMouseEvent, stud_obj: GraphicsObjectDelegate
    ) -> None:
        """Open a dialog when a stud is pressed."""
        dialog = QDialog()
        dialog.setWindowTitle(OBJECT_EDITOR_DIALOG_TITLE)
        dialog.setWindowIcon(QIcon(UI_ICON_PATH))

        layout = QGridLayout()
        dialog.setLayout(layout)

        label = QLabel("Stud width:")

        stud_size_spinbox = QDoubleSpinBox()
        stud_size_spinbox.setRange(0, sys.float_info.max)
        stud_size_spinbox.setSingleStep(1)
        stud_size_spinbox.setDecimals(0)
        stud_size_spinbox.setValue(stud_obj.rect().width())

        save_button = QPushButton("Save")
        discard_button = QPushButton("Discard")

        save_button.clicked.connect(dialog.accept)
        discard_button.clicked.connect(dialog.reject)

        layout.addWidget(label, 0, 0)
        layout.addWidget(stud_size_spinbox, 0, 1)
        layout.addWidget(save_button, 1, 0)
        layout.addWidget(discard_button, 1, 1)

        dialog.setLayout(layout)
        dialog.setMinimumSize(dialog.sizeHint())
        dialog.setMaximumSize(dialog.sizeHint())

        result = dialog.exec()

        if result == QDialog.DialogCode.Accepted:
            stud_obj.setRect(
                0, 0, stud_size_spinbox.value(), FrameSettings.FrameY.value
            )
            print("Accepted")
        elif result == QDialog.DialogCode.Rejected:
            print("Rejected")
