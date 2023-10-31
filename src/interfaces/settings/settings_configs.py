# TODO: move & remove.


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
