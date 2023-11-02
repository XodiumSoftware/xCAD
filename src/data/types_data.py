from dataclasses import dataclass


@dataclass
class DataTypeHints:
    """A class used to represent type hints."""

    SLS: list[tuple[int, int]]
    CLS: list[tuple[int, int]]


class LumberTypesData(DataTypeHints):
    """A class to represent different types of lumber."""

    def __init__(self):
        super().__init__(
            SLS=[
                (38, 89),
                (38, 120),
                (38, 140),
                (38, 170),
                (38, 184),
                (38, 235),
                (38, 285),
            ],
            CLS=[
                (50, 75),
                (50, 100),
                (50, 125),
                (50, 150),
                (50, 175),
            ],
        )
