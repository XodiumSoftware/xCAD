from dataclasses import dataclass, field
from typing import List, Tuple

from AFCConstants import UI_ICON_PATH


@dataclass
class TimberTypeDataclass:
    """A class used to represent a timber type."""

    SLS: List[Tuple[int, int]] = field(
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
    CLS: List[Tuple[int, int]] = field(
        default_factory=lambda: [
            (50, 75),
            (50, 100),
            (50, 125),
            (50, 150),
            (50, 175),
        ]
    )


@dataclass
class UIDataclass:
    """A class used to represent a ui configuration."""

    background_color: str = 'black'
    content_margins: Tuple[int, int, int, int] = (10, 10, 10, 10)
    icon: str = UI_ICON_PATH
    icon_default: bool = True
    init_size: Tuple[int, int] = (600, 400)
    init_visibility: bool = True
    resizable: bool = True
    theme: str = 'alt'
    title: str = 'AutoFrameCAD'


@dataclass
class EventsDataclass:
    """A class used to represent an event handler."""

    KEYS: List[str] = field(
        default_factory=lambda: ['<Escape>', '<Control-q>']
    )
