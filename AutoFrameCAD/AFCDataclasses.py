from dataclasses import dataclass, field
from pathlib import Path
from tkinter import ttk as tkttk
from typing import Any

import numpy as np
from numpy.typing import NDArray
from sv_ttk import SunValleyTtkTheme as SVTtk_SetTheme

from AutoFrameCAD.AFCConstants import UI_ICON_PATH


@dataclass
class EventsDataclass:
    """A class used to represent an event handler."""

    EXIT_KEYS: list[str] = field(
        default_factory=lambda: ['<Escape>', '<Control-q>']
    )


@dataclass
class MatrixDataclass:
    """A class used to represent a matrix configuration."""

    PRIMARY: NDArray[Any] = field(
        default_factory=lambda: np.array(
            [
                [
                    tkttk.Label(text='Structura Engineering'),
                    None,
                ],
                [
                    tkttk.Button(text='TEST1'),
                    tkttk.Button(
                        text='TEST0',
                        command=lambda: SVTtk_SetTheme.toggle_theme(),
                    ),
                ],
            ],
            dtype=object,
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
        ICON_PATH: Path
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


# class FrameTypeDataclass(Enum):
#     """A class used to represent a frame type configuration."""

#     DEFAULT
#     STAB
#     CONS


@dataclass
class StudDataclass:
    """A class used to represent a stud configuration."""

    SLS: list[tuple[int, int]] = field(
        default_factory=lambda: [
            (0, 0),
        ],
    )

    CLS: list[tuple[int, int]] = field(
        default_factory=lambda: [
            (0, 0),
        ],
    )


# @dataclass
# class FrameDataclass:
#     """A class used to represent a frame configuration."""

#     # TODO: If alternative is possible, get rid of nested class.
#     @dataclass
#     class TYPING:
#         """A class used to represent typing."""

#         FRAME_TYPE: str
#         FRAME_X: int
#         FRAME_Y: int
#         STUD_TYPE: StudDataclass

#     PRIMARY: TYPING = field(
#         default_factory=lambda: FrameDataclass.TYPING(
#             FRAME_TYPE='',
#             FRAME_X=0,
#             FRAME_Y=0,
#             STUD_TYPE=StudDataclass.SLS,
#         )
#     )
