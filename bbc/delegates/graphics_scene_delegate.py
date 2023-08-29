from delegates.graphics_object_delegate import GraphicsObjectDelegate
from enums.afc_enums import FrameSettings, StudSettings
from PySide6.QtWidgets import QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A class to represent a graphics scene delegate."""

    total_studs = 0

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
        stud_size = StudSettings.StudX.value
        frame_x = FrameSettings.FrameX.value
        frame_y = FrameSettings.FrameY.value

        for x_coord in GraphicsSceneDelegate.calculate_frame_coordinates(
            frame_x, stud_spacing_x
        ):
            GraphicsSceneDelegate.add_stud(
                scene, x_coord, stud_size, stud_size, frame_y, 0
            )

        for y_coord in GraphicsSceneDelegate.calculate_frame_coordinates(
            frame_y, stud_spacing_y
        ):
            GraphicsSceneDelegate.add_stud(
                scene, 0, y_coord + stud_size, stud_size, frame_x, -90
            )

    @staticmethod
    def add_stud(scene: QGraphicsScene, x, y, w, h, r) -> None:
        """Add a stud to the scene."""
        stud = GraphicsObjectDelegate(x, y, w, h, r)
        scene.addItem(stud)

        GraphicsSceneDelegate.total_studs += 1
        print(
            f"Added stud with ID: {stud.obj_id}. Total studs: {GraphicsSceneDelegate.total_studs}"
        )
