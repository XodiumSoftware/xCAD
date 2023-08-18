from enum import Enum
from typing import List, Tuple

import matplotlib.pyplot as plt
from matplotlib import patches


class TimberFrameProperties(Enum):
    """Class to hold the props of the timber frame"""

    FrameLengthX = 4000
    FrameLengthY = 3000
    StudSpacingX = 600
    StudSpacingY = 2400
    StudWidth = 38
    StudFillColour = "#ebd3b0"
    StudPenColour = "#000000"


class TimberFrameHandler:
    """Class to handle the timber frame"""

    def __init__(self) -> None:
        """Constructor for the class"""
        super().__init__()
        self.setup_timber_frame()

    def setup_timber_frame(self) -> None:
        """Setup the timber frame"""
        plt.rcParams["toolbar"] = "None"

        _, ax = plt.subplots()
        ax.set_aspect("equal")

        plt.title("Timber Frame Wall", fontweight="bold")
        plt.xlabel("Length (mm)", fontweight="bold")
        plt.ylabel("Height (mm)", fontweight="bold")
        plt.grid(True, zorder=0)

        self.draw_border_studs()
        self.draw_vertical_studs()
        self.draw_horizontal_studs()

        plt.show()

    @staticmethod
    def draw_border_studs() -> None:
        """Draw the border studs"""
        props = TimberFrameProperties
        plt.plot(
            [0, props.FrameLengthX.value, props.FrameLengthX.value, 0, 0],
            [0, 0, props.FrameLengthY.value, props.FrameLengthY.value, 0],
            color="none",
        )

        sides: List[Tuple[int, int, int, int]] = [
            (0, 0, props.StudWidth.value, props.FrameLengthY.value),
            (
                props.FrameLengthX.value - props.StudWidth.value,
                0,
                props.StudWidth.value,
                props.FrameLengthY.value,
            ),
            (0, 0, props.FrameLengthX.value, props.StudWidth.value),
            (
                0,
                props.FrameLengthY.value - props.StudWidth.value,
                props.FrameLengthX.value,
                props.StudWidth.value,
            ),
        ]

        for x, y, width, height in sides:
            stud_rect = patches.Rectangle(
                (x, y),
                width,
                height,
                edgecolor=props.StudPenColour.value,
                facecolor=props.StudFillColour.value,
            )
            plt.gca().add_patch(stud_rect)

    @staticmethod
    def draw_vertical_studs() -> None:
        """Draw the vertical studs"""
        props = TimberFrameProperties
        stud_x_positions = [
            i * props.StudSpacingX.value
            for i in range(
                1,
                int(props.FrameLengthX.value / props.StudSpacingX.value) + 1,
            )
        ]

        stud_rectangles = [
            patches.Rectangle(
                (x, props.StudWidth.value),
                props.StudWidth.value,
                props.FrameLengthY.value - 2 * props.StudWidth.value,
                edgecolor=props.StudPenColour.value,
                facecolor=props.StudFillColour.value,
            )
            for x in stud_x_positions
        ]

        for stud_rect in stud_rectangles:
            plt.gca().add_patch(stud_rect)

    @staticmethod
    def draw_horizontal_studs() -> None:
        """Draw the horizontal studs"""
        props = TimberFrameProperties
        stud_y_positions = [
            i * props.StudSpacingY.value
            for i in range(
                1,
                int(props.FrameLengthY.value / props.StudSpacingY.value) + 1,
            )
        ]

        stud_rectangles = [
            patches.Rectangle(
                (props.StudWidth.value, y),
                props.FrameLengthX.value - 2 * props.StudWidth.value,
                props.StudWidth.value,
                edgecolor=props.StudPenColour.value,
                facecolor=props.StudFillColour.value,
            )
            for y in stud_y_positions
        ]

        for stud_rect in stud_rectangles:
            plt.gca().add_patch(stud_rect)


TimberFrameHandler()
