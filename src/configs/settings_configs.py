from QeLib import QeHelper

from configs.type_configs import LumberTypes


class ObjSettings:
    """A class to represent stud settings."""

    Object_ID: str = QeHelper.complex_id_generator()
    Type: str = f"{LumberTypes.SLS} {LumberTypes.SLS[0][0]}x{LumberTypes.SLS[0][1]}"
    DrawOrder: int = 0

    PosX: int = 0
    PosY: int = 0
    DimX: int = LumberTypes.SLS[0][0]
    DimY: int = LumberTypes.SLS[0][1]
    Rad: int = 0

    PenStyle: str = "SolidLine"
    PenColor: str = "#ffffff"
    PenThickness: int = 2

    Fill: bool = True
    FillPattern: str = "SolidPattern"
    FillColor: str = "#ebd3b0"
    FillOpacity: int = 100


class FrameSettings:
    """A class to represent frame settings."""

    FrameX: int = 4000
    FrameY: int = 2500

    StudSpacingX: int = 600
    StudSpacingY: int = 2400


class GraphicsSceneSettings:
    """A class to represent graphics scene settings."""

    AxisPenColor: str = "#00FF00"


class GraphicsViewSettings:
    """A class to represent graphics view settings."""

    BackgroundColor: str = "#000000"
    BackgroundBorder: str = "2px solid lightgray"

    GridSpacing: int = 100
    GridPenStyle: str = "SolidLine"
    GridPenColor: str = "#ffffff"
