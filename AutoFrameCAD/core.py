from tkinter import Tk as tkTk
from tkinter import ttk as tkttk
from typing import Any, Callable, Sequence

import sv_ttk


class CoreUI(tkTk):
    """A class used to represent a extension of the TKinter ui module."""

    @staticmethod
    def _theme(theme: str) -> None:
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

    def _matrix(
        self,
        matrix: Sequence[Sequence[tkttk.Widget | None]],
        row_options: dict[str, Any] = {},
        col_options: dict[str, Any] = {},
        grid_options: dict[str, Any] = {},
    ) -> None:
        """Set the matrix of the UI.

        Args:
            matrix (Sequence[Sequence[tkttk.Widget | None]]):
                The matrix to use.
            row_options (dict[str, Any]): The row options to use.
            col_options (dict[str, Any]): The column options to use.
            grid_options (dict[str, Any]): The grid options to use.
        """
        for i, row in enumerate(matrix):
            self.rowconfigure(i, weight=1, **row_options)
            for j, value in enumerate(row):
                self.columnconfigure(j, weight=1, **col_options)
                if value is not None:
                    colspan = 1
                    while j + colspan < len(row) and row[j + colspan] is None:
                        colspan += 1

                    rowspan = 1
                    while (
                        i + rowspan < len(matrix)
                        and matrix[i + rowspan][j] is None
                    ):
                        rowspan += 1

                    value.grid(
                        row=i,
                        column=j,
                        columnspan=colspan,
                        rowspan=rowspan,
                        **grid_options,
                    )

    matrix = _matrix
