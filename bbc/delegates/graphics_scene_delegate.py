from typing import Dict

from delegates.graphics_object_delegate import GraphicsObjectDelegate
from enums.afc_enums import FrameSettings, StudSettings
from PySide6.QtWidgets import QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__()
        self.setup_graphics_scene()

    def setup_graphics_scene(self) -> None:
        """Setup the graphics scene delegate."""
        self.setup_frame_work(self)

    @staticmethod
    def setup_frame_work(scene: QGraphicsScene) -> None:
        """Setup the frame work."""
        stud_objs: Dict[int, GraphicsObjectDelegate] = {}

        for x in range(0, FrameSettings.FrameX.value, StudSettings.StudX.value):
            stud_obj = GraphicsObjectDelegate()
            scene.addItem(stud_obj)
            stud_obj.setPos(x, 0)
            stud_obj.setRect(
                0, 0, FrameSettings.StudSpacing.value, FrameSettings.FrameY.value
            )
            stud_objs[x] = stud_obj
