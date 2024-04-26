"""This module contains the core functionality."""

from collections.abc import Callable
from tkinter import Tk as tkTk
from typing import Any

import sv_ttk


class CoreUI(tkTk):
    """A class used to represent a extension of the TKinter ui module."""

    @staticmethod
    def _theme(*, is_dark: bool) -> bool:
        """Set the theme of the UI.

        Args:
            is_dark: The state to use.

        Returns:
            bool: The state of the theme.
        """
        sv_ttk.set_theme("dark" if is_dark else "light")
        return is_dark

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

    # @staticmethod
    # def _matrix(
    #     widgets: list[tuple[Widget, int, int, dict[str, Any]]],
    # ) -> None:
    #     """Add widgets in a grid layout.

    #     Args:
    #         widgets: The widgets to use, where each tuple contains the widget,
    #             row, column, and kwargs.
    #     """
    #     for widget, row, column, kwargs in widgets:
    #         widget.grid(row=row, column=column, **kwargs)

    # matrix = _matrix
