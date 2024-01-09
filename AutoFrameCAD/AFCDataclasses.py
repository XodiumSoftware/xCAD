from dataclasses import dataclass, field
from tkinter import ttk as tkttk

import numpy as np
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

    PRIMARY: np.ndarray = field(
        default_factory=lambda: np.array(
            [
                [
                    tkttk.Button(
                        text='TEST0',
                        command=lambda: SVTtk_SetTheme.toggle_theme(),
                    ),
                    tkttk.Button(
                        text='TEST1',
                        command=lambda: SVTtk_SetTheme.toggle_theme(),
                    ),
                ],
                [
                    tkttk.Button(
                        text='TEST2',
                        command=lambda: SVTtk_SetTheme.toggle_theme(),
                    ),
                    tkttk.Button(
                        text='TEST3',
                        command=lambda: SVTtk_SetTheme.toggle_theme(),
                    ),
                ],
            ]
        )
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
            ICON_PATH='UI_ICON_PATH',
            GEOM_X=1200,
            GEOM_Y=800,
            VISIBILITY=True,
            RESIZABLE=True,
            THEME='dark',
            TITLE='AutoFrameCAD',
        )
    )

    SECONDARY: TYPING = field(
        default_factory=lambda: UIDataclass.TYPING(
            ICON=False,
            ICON_PATH='UI_ICON_PATH',
            GEOM_X=400,
            GEOM_Y=300,
            VISIBILITY=False,
            RESIZABLE=False,
            THEME='light',
            TITLE='TEST',
        )
    )


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
