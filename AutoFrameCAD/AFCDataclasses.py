from dataclasses import dataclass, field

from AFCConstants import UI_ICON_PATH


@dataclass
class EventsDataclass:
    """A class used to represent an event handler."""

    KEYS: list[str] = field(
        default_factory=lambda: ['<Escape>', '<Control-q>']
    )


@dataclass
class MainMatrixDataclass:
    """A class used to represent a matrix configuration."""

    MATRIX: list[dict] = field(default_factory=lambda: [{}])


@dataclass
class MainUIDataclass:
    """A class used to represent a ui configuration."""

    ICON: str = UI_ICON_PATH
    ICON_DEFAULT: bool = True
    INIT_SIZE: tuple[int, int] = (600, 400)
    INIT_VISIBILITY: bool = True
    RESIZABLE: bool = True
    THEME: str = 'dark'
    TITLE: str = 'AutoFrameCAD'


@dataclass
class TimberTypeDataclass:
    """A class used to represent a timber type."""

    CLS: list[tuple[int, int]] = field(
        default_factory=lambda: [
            (50, 75),
            (50, 100),
            (50, 125),
            (50, 150),
            (50, 175),
        ]
    )
    SLS: list[tuple[int, int]] = field(
        default_factory=lambda: [
            (38, 89),
            (38, 120),
            (38, 140),
            (38, 170),
            (38, 184),
            (38, 235),
            (38, 285),
        ]
    )
