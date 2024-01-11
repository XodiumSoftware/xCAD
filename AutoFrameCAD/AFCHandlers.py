from tkinter import ttk as tkttk

import numpy as np


class MatrixHandler:
    """A class used to represent a matrix."""

    def __init__(self, matrix: np.ndarray) -> None:
        """Initialize the class.

        Args:
            matrix (np.ndarray): The matrix to use.
        """
        for (i, j), widget in np.ndenumerate(matrix):
            (widget if widget is not None else tkttk.Frame()).grid(
                row=i, column=j, sticky='nsew'
            )
