from delegates.graphics_object_delegate import GraphicsObjectDelegate
from enums.afc_enums import FrameSettings, LumberTypes, ObjSettings
from PySide6.QtWidgets import QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    def __init__(self) -> None:
        """Initialize the graphics scene delegate."""
        super().__init__()
        self.setup_framework(self)

    @staticmethod
    def calculate_frame_coordinates(frame_size: int, spacing: int) -> list:
        """Calculate frame coordinates with given size and spacing."""
        return [i for i in range(frame_size) if i % spacing == 0]

    @staticmethod
    def setup_framework(scene: QGraphicsScene) -> None:
        """Setup the framework."""
        stud_spacing_x = FrameSettings.StudSpacingX.value
        stud_spacing_y = FrameSettings.StudSpacingY.value
        stud_size_x = ObjSettings.Dim.value[0]
        frame_x = FrameSettings.FrameX.value
        frame_y = FrameSettings.FrameY.value

        _add_stud = GraphicsSceneDelegate.add_stud

        for x_coord in GraphicsSceneDelegate.calculate_frame_coordinates(
            frame_x, stud_spacing_x
        ):
            _add_stud(
                scene, x_coord, stud_size_x, stud_size_x, frame_y - stud_size_x, 0
            )
        _add_stud(
            scene,
            frame_x - stud_size_x,
            stud_size_x,
            stud_size_x,
            frame_y - stud_size_x,
            0,
        )

        for y_coord in GraphicsSceneDelegate.calculate_frame_coordinates(
            frame_y, stud_spacing_y
        ):
            _add_stud(scene, 0, y_coord + stud_size_x, stud_size_x, frame_x, -90)
        _add_stud(scene, 0, frame_y + stud_size_x, stud_size_x, frame_x, -90)

    @staticmethod
    def add_stud(
        scene: QGraphicsScene, x: int, y: int, w: int, h: int, rad: int
    ) -> None:
        """Add a stud to the scene."""
        stud = GraphicsObjectDelegate(x, y, w, h, rad)
        scene.addItem(stud)
