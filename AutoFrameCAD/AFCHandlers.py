from tkinter import NSEW
from tkinter import Tk as tkTk
from tkinter import ttk as tkttk

import numpy as np


class MatrixHandler:
    """A class used to represent a matrix."""

    def __init__(self, master: tkTk, matrix: np.ndarray) -> None:
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
