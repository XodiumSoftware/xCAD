from enum import Enum

from enums.type_enums import LumberTypes
from helpers.helper import Helper


class ObjSettings(Enum):
    """A class to represent stud settings."""

    Object_ID = Helper.complex_id_generator()
    Type = f"{LumberTypes.SLS.name} {LumberTypes.SLS.value[0][0]}x{LumberTypes.SLS.value[0][1]}"
    DrawOrder = 0

    PosX = 0
    PosY = 0
    DimX = LumberTypes.SLS.value[0][0]
    DimY = LumberTypes.SLS.value[0][1]
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

    AxisPenColor = "#00FF00"


class GraphicsViewSettings(Enum):
    """A class to represent graphics view settings."""

    BackgroundColor = "#000000"
    BackgroundBorder = "2px solid lightgray"

    GridSpacing = 100
    GridPenStyle = "SolidLine"
    GridPenColor = "#ffffff"
