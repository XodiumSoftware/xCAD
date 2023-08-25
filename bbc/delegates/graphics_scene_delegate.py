from typing import Dict

from delegates.graphics_object_delegate import GraphicsObjectDelegate
from enums.afc_enums import FrameSettings, StudSettings
from PySide6.QtWidgets import QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__()
        self.setup_framework(self)

    @staticmethod
    def setup_framework(scene: QGraphicsScene) -> None:
        """Setup the framework."""
        stud_spacing_x = FrameSettings.StudSpacingX.value
        stud_spacing_y = FrameSettings.StudSpacingY.value
        stud_size = StudSettings.StudX.value
        frame_x = FrameSettings.FrameX.value
        frame_y = FrameSettings.FrameY.value
        max_frame = max(frame_x, frame_y)

        for i in range(max_frame):
            if i < frame_x and i % stud_spacing_x == 0:
                GraphicsSceneDelegate.add_stud(
                    scene, i, stud_size, stud_size, frame_y, 0
                )
            if i < frame_y and i % stud_spacing_y == 0:
                GraphicsSceneDelegate.add_stud(
                    scene, 0, i + stud_size, stud_size, frame_x, -90
                )

    @staticmethod
    def add_stud(scene: QGraphicsScene, x, y, w, h, r) -> None:
        stud = GraphicsObjectDelegate(x, y, w, h, r)
        scene.addItem(stud)
