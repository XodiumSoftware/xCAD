from typing import Dict

from delegates.graphics_object_delegate import GraphicsObjectDelegate
from enums.afc_enums import FrameSettings, StudSettings
from PySide6.QtWidgets import QGraphicsScene


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

        for i in range(0, max(FrameSettings.FrameX.value, FrameSettings.FrameY.value)):
            if i < FrameSettings.FrameX.value:
                if i % FrameSettings.StudSpacingX.value == 0:
                    stud_objs[i] = GraphicsObjectDelegate(
                        i,
                        StudSettings.StudX.value,
                        StudSettings.StudX.value,
                        FrameSettings.FrameY.value,
                        0,
                    )
                    scene.addItem(stud_objs[i])
                if i % FrameSettings.StudSpacingY.value == 0:
                    stud_objs[i] = GraphicsObjectDelegate(
                        0,
                        i + StudSettings.StudX.value,
                        StudSettings.StudX.value,
                        FrameSettings.FrameX.value,
                        -90,
                    )
                    scene.addItem(stud_objs[i])
