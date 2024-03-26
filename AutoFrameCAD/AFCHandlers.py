from tkinter import NSEW
from tkinter import Tk as tkTk
from tkinter import ttk as tkttk
from typing import Any, Callable

import numpy as np
import sv_ttk
from numpy.typing import NDArray


class UIHandler(tkTk):
    """A class used to represent a extension of the TKinter ui module."""

    def _theme(self, theme: str) -> None:
        """Set the theme of the UI.

        Args:
            theme (str): The theme to use.
        """
        sv_ttk.set_theme(theme)

    theme = _theme

    def _visible(self, state: bool) -> None:
        """Set the visibility of the UI.

        Args:
            state (bool): The state to use.
        """
        if state:
            self.deiconify()
        else:
            self.withdraw()

    visible = _visible

    def _events(self, events: dict[str, Callable[[Any], None]]) -> None:
        """Set the events of the UI.

        Args:
            events (dict[str, Callable[[Any], None]]): The events to use.
        """
        for key, value in events.items():
            self.bind(key, value)

    events = _events

    def _matrix(self, matrix: NDArray[Any]) -> None:
        """Set the matrix of the UI.

        Args:
            matrix (np.ndarray): The matrix to use.
        """
        if matrix.ndim != 2:
            raise ValueError('Matrix must be a 2D numpy array.')
        for (i, j), value in np.ndenumerate(matrix):
            if not isinstance(value, tkttk.Widget):
                value = tkttk.Frame(self)
            value.grid(row=i, column=j, sticky=NSEW)
            self.rowconfigure(i, weight=1)
            self.columnconfigure(j, weight=1)

    matrix = _matrix
