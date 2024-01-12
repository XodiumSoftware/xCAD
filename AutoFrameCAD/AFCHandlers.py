from tkinter import ttk as tkttk


class MatrixHandler:
    """A class used to represent a matrix."""

    def __init__(self, matrix: list) -> None:
        """Initialize the class.

        Args:
            matrix (list): The matrix to use.
        """
        self.matrix(matrix, sticky='nsew')

    def matrix(self, matrix: list, sticky: str, pos: int = 0) -> None:
        """Matrix the widgets.

        Args:
            matrix (list): The matrix to use.
            sticky (str): The sticky to use.
            pos (int, optional): The position to start from. Defaults to 0.
        """
        for i, item in enumerate(matrix):
            if isinstance(item, list):
                self.matrix(item, sticky, pos + 1)
            elif isinstance(item, tkttk.Widget):
                item.grid(row=pos, column=i, sticky=sticky)
