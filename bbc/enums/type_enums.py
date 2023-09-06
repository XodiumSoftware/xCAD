from enum import Enum


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
