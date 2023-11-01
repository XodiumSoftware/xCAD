from dataclasses import dataclass


@dataclass
class GraphicsSceneTypeHints:
    """A class used to represent graphics scene type hints."""

    axis_pen_color: str


class GraphicsSceneConfig(GraphicsSceneTypeHints):
    """A class used to represent a graphics scene config."""

    def __init__(self):
        super().__init__(
            axis_pen_color="#00FF00",
        )
