from tkinter import ttk as tkttk

import numpy as np


class MatrixHandler:
    """A class used to represent a matrix."""

    def __init__(self, matrix: np.ndarray) -> None:
        """Initialize the class.

        Args:
            matrix (np.ndarray): The matrix to use.
        """
        for (i, j), value in np.ndenumerate(matrix):
            value: tkttk.Widget
            if value is None:
                value = tkttk.Label()
            value.grid(row=i, column=j)
