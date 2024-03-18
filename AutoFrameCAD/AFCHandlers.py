from tkinter import NSEW
from tkinter import Tk as tkTk
from tkinter import ttk as tkttk
from typing import Any

import numpy as np
from numpy.typing import NDArray


class MatrixHandler:
    """A class used to represent a matrix."""

    def __init__(self, master: tkTk, matrix: NDArray[Any]) -> None:
        """Initialize the class.

        Args:
            master (tkTk): The master to use.
            matrix (np.ndarray): The matrix to use.
        """
        print(matrix)
        for (i, j), value in np.ndenumerate(matrix):
            if not isinstance(value, tkttk.Widget):
                value = tkttk.Frame(master)
            value.grid(row=i, column=j, sticky=NSEW)
            master.rowconfigure(i, weight=1)
            master.columnconfigure(j, weight=1)


class EventHandler:
    """A class used to represent an event handler."""

    def __init__(self, master: tkTk, events: list[str]) -> None:
        """Initialize the class.

        Args:
            master (tkTk): The master to use.
            events (list[str]): The events to use.
        """
        for key in events:
            master.bind(key, lambda event: event.widget.quit())
