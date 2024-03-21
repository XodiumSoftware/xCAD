from dataclasses import dataclass, field
from pathlib import Path
from tkinter import ttk as tkttk
from typing import Any

import numpy as np
import sv_ttk
from AFCConstants import DATABASE_PATH, UI_ICON_PATH
from AFCDatabase import Database as AFCDatabase
from numpy.typing import NDArray


@dataclass
class UIDataclass:
    """A class used to represent a ui configuration."""

    # TODO: If alternative is possible, get rid of nested class.
    @dataclass
    class TYPING:
        """A class used to represent typing."""

        TITLE: str
        THEME: str
        VISIBILITY: bool
        RESIZABLE: bool
        ICON: bool
        ICON_PATH: Path
        GEOM_X: int
        GEOM_Y: int
        PAD_X: int
        PAD_Y: int
        EVENTS: list[str]
        MATRIX: NDArray[Any]

    PRIMARY: TYPING = field(
        default_factory=lambda: UIDataclass.TYPING(
            TITLE='AutoFrameCAD',
            THEME='dark',
            VISIBILITY=True,
            RESIZABLE=True,
            ICON=True,
            ICON_PATH=UI_ICON_PATH,
            GEOM_X=1200,
            GEOM_Y=800,
            PAD_X=10,
            PAD_Y=10,
            EVENTS=['<Control-w>'],
            MATRIX=np.array(
                [
                    [
                        tkttk.Label(
                            text='Structura Engineering', anchor='center'
                        ),
                        None,
                    ],
                    [
                        tkttk.Button(
                            text='TEST1',
                            command=AFCDatabase(DATABASE_PATH).add_data,
                        ),
                        tkttk.Button(
                            text='TEST0', command=sv_ttk.toggle_theme
                        ),
                    ],
                ],
                dtype=object,
            ),
        ),
    )
