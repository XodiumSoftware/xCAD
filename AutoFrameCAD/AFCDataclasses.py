from dataclasses import dataclass, field
from tkinter import ttk as tkttk

from AFCConstants import UI_ICON_PATH
from sv_ttk import SunValleyTtkTheme as SVTtk_SetTheme


@dataclass
class EventsDataclass:
    """A class used to represent an event handler."""

    KEYS: list[str] = field(
        default_factory=lambda: ['<Escape>', '<Control-q>']
    )


@dataclass
class MatricesDataclass:
    """A class used to represent a matrix configuration."""

    PRIMARY: list = field(
        default_factory=lambda: [
            tkttk.Label(
                text='Structura Engineering',
            ),
            [
                tkttk.Checkbutton(
                    text='TEST0',
                    command=lambda: SVTtk_SetTheme.toggle_theme(),
                ),
                tkttk.Menubutton(
                    text='Select Timber Type',
                ),
                tkttk.Checkbutton(
                    text='TEST1',
                    command=lambda: SVTtk_SetTheme.toggle_theme(),
                ),
            ],
        ],
    )


@dataclass
class UIDataclass:
    """A class used to represent a ui configuration."""

    # TODO: If alternative is possible, get rid of nested class.
    @dataclass
    class TYPING:
        """A class used to represent typing."""

        ICON: bool
        ICON_PATH: str
        GEOM_X: int
        GEOM_Y: int
        VISIBILITY: bool
        RESIZABLE: bool
        THEME: str
        TITLE: str

    PRIMARY: TYPING = field(
        default_factory=lambda: UIDataclass.TYPING(
            ICON=True,
            ICON_PATH=UI_ICON_PATH,
            GEOM_X=1200,
            GEOM_Y=800,
            VISIBILITY=True,
            RESIZABLE=True,
            THEME='dark',
            TITLE='AutoFrameCAD',
        )
    )
