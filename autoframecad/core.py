"""This module contains the core functionality of AutoFrameCAD."""

from collections.abc import Callable
from tkinter import Tk as tkTk
from typing import Any

import sv_ttk


class CoreUI(tkTk):
    """A class used to represent a extension of the TKinter ui module."""

    @staticmethod
    def _theme(theme: str) -> None:
        """Set the theme of the UI.

        Args:
            theme: The theme to use.
        """
        sv_ttk.set_theme(theme)

    theme = _theme

    @staticmethod
    def _toggle_theme() -> None:
        """Toggle the theme of the UI."""
        sv_ttk.toggle_theme()

    toggle_theme = _toggle_theme

    def _visible(self: "CoreUI", state: bool | int) -> None:
        """Set the visibility of the UI.

        Args:
            state: The state to use.
        """
        if state:
            self.deiconify()
        else:
            self.withdraw()

    visible = _visible

    def _events(
        self: "CoreUI",
        events: dict[str, Callable[[Any], None]],
    ) -> None:
        """Set the events of the UI.

        Args:
            events: The events to use.
        """
        for key, value in events.items():
            self.bind(key, value)

    events = _events

    # def _matrix(
    #     self: "CoreUI",
    #     matrix: Sequence[
    #         Sequence[tuple[tkttk.Widget | None, dict[str, Any] | None]]
    #     ],
    #     row_options: dict[str, Any] | None = None,
    #     col_options: dict[str, Any] | None = None,
    # ) -> None:
    #     """Set the matrix of the UI.

    #     Args:
    #         matrix:
    #             The matrix to use. Each element is a tuple where the first item
    #             is a tkttk.Widget or None, and the second item is a dictionary
    #             of grid options or None.
    #         row_options: The row options to use. Defaults to None.
    #         col_options: The column options to use. Defaults to None.
    #     """
    #     if row_options is None:
    #         row_options = {}
    #     if col_options is None:
    #         col_options = {}

    #     for i, row in enumerate(matrix):
    #         self.rowconfigure(i, weight=1, **row_options)
    #         for j, cell in enumerate(row):
    #             self.columnconfigure(j, weight=1, **col_options)
    #             if cell is not None and isinstance(cell, tuple):
    #                 widget, grid_options = cell
    #                 if grid_options is None:
    #                     grid_options = {}

    #                 colspan = 1
    #                 while j + colspan < len(row) and row[j + colspan] is None:
    #                     colspan += 1

    #                 rowspan = 1
    #                 while (
    #                     i + rowspan < len(matrix)
    #                     and matrix[i + rowspan][j] is not None
    #                     and isinstance(matrix[i + rowspan][j], tuple)
    #                 ):
    #                     rowspan += 1

    #                 if widget is not None:
    #                     widget.grid(
    #                         row=i,
    #                         column=j,
    #                         columnspan=colspan,
    #                         rowspan=rowspan,
    #                         **grid_options,
    #                     )

    # matrix = _matrix
