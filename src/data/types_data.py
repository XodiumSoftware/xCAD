from dataclasses import dataclass


@dataclass
class LumberTypes:
    """A class to represent different types of lumber."""

    SLS: list[tuple[int, int]] = [
        (38, 89),
        (38, 120),
        (38, 140),
        (38, 170),
        (38, 184),
        (38, 235),
        (38, 285),
    ]

    CLS: list[tuple[int, int]] = [
        (50, 75),
        (50, 100),
        (50, 125),
        (50, 150),
        (50, 175),
    ]

    @classmethod
    def get_all_content(cls) -> list[tuple[str, tuple[int, int]]]:
        """Get all content from the lumber types."""
        return [
            (f"{name} {x}x{y}", (x, y))
            for name, values in cls.__dict__.items()
            if isinstance(values, list)
            for x, y in values
        ]
