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
            matrix (np.ndarray): The matrix to use.
        """
        for (i, j), value in np.ndenumerate(matrix):
            if isinstance(value, tkttk.Widget):
                value.grid(row=i, column=j, sticky=NSEW)
                master.rowconfigure(i, weight=1)
                master.columnconfigure(j, weight=1)
            else:
                value = tkttk.Frame()
