from dataclasses import dataclass


@dataclass
class GraphicsViewTypeHints:
    """A class used to represent graphics view type hints."""

    background_color: str
    background_border: str
    grid_spacing: int
    grid_pen_style: str
    grid_pen_color: str


class GraphicsViewConfig(GraphicsViewTypeHints):
    """A class used to represent a graphics view config."""

    def __init__(self):
        super().__init__(
            background_color="#000000",
            background_border="2px solid lightgray",
            grid_spacing=100,
            grid_pen_style="SolidLine",
            grid_pen_color="#ffffff",
        )
