from tkinter import Tk as tkTk
from tkinter import ttk as tkttk
from typing import Any, Callable

import sv_ttk


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

    def _events(self, events: dict[str, Callable[[tkTk], None]]) -> None:
        """Set the events of the UI.

        Args:
            events (dict[str, Callable[[tkTk], None]]): The events to use.
        """
        for key, value in events.items():
            self.bind(key, value)  # type: ignore

    events = _events

    def _matrix(
        self,
        matrix: list[list[tkttk.Widget | None]],
        **options: Any,
    ) -> None:
        """Set the matrix of the UI.

        Args:
            matrix (list[list[tkttk.Widget | None]]): The matrix to use.
            **options (Any): The options to use are;
                *.rowconfigure();
                *.columnconfigure();
                *.grid();
                    For more information about each option,
                        visit the tkinter wikipedia online.
        """
        for i, row in enumerate(matrix):
            self.rowconfigure(i, weight=1, **options)
            for j, value in enumerate(row):
                self.columnconfigure(j, weight=1, **options)
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
                        **options,
                    )

    matrix = _matrix
