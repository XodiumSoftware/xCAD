from enum import Enum

from helpers.helper import Helper


class LumberTypes(Enum):
    """A class to represent lumber types."""

    SLS = [
        (38, 89),
        (38, 120),
        (38, 140),
        (38, 170),
        (38, 184),
        (38, 235),
        (38, 285),
    ]

    CLS = [
        (50, 75),
        (50, 100),
        (50, 125),
        (50, 150),
        (50, 175),
    ]

    @classmethod
    def get_all_content(cls):
        """Get all content from the lumber types."""
        return [
            (f"{name} {x}x{y}", (x, y))
            for name, values in cls.__members__.items()
            for x, y in values.value
        ]


class ObjSettings(Enum):
    """A class to represent stud settings."""

    Object_ID = Helper.generate_complex_id()
    Type = f"{LumberTypes.SLS.name} {LumberTypes.SLS.value[0][0]}x{LumberTypes.SLS.value[0][1]}"
    DrawOrder = 0

    Pos = (0, 0, 0)
    Dim = (LumberTypes.SLS.value[0][0], LumberTypes.SLS.value[0][1], 0)
    Rad = 0

    PenStyle = "SolidLine"
    PenColor = "#ffffff"
    PenThickness = 2

    Fill = True
    FillPattern = "SolidPattern"
    FillColor = "#ebd3b0"
    FillOpacity = 100


class FrameSettings(Enum):
    """A class to represent frame settings."""

    FrameX = 4000
    FrameY = 2500

    StudSpacingX = 600
    StudSpacingY = 2400


class GraphicsSceneSettings(Enum):
    """A class to represent graphics scene settings."""

    BackgroundColor = "#000000"

    AxisPenColor = "#00FF00"


class GraphicsViewSettings(Enum):
    """A class to represent graphics view settings."""

    BackgroundColor = "#000000"

    GridSpacing = 100
    GridPenStyle = "SolidLine"
    GridPenColor = "#ffffff"
