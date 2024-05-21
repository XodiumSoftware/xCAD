"""This module contains the core functionality."""

from collections.abc import Callable
from tkinter import Tk as tkTk
from tkinter.ttk import Button
from typing import Any

import sv_ttk
from PIL import Image, ImageTk

from autoframecad.__config__ import (
    DARK_MODE_ICON_FILE,
    DATABASE_FILE,
    LIGHT_MODE_ICON_FILE,
    PREFERENCES_DATA,
)
from autoframecad.db_tables import PreferencesTable
from stenlib import Utils


class CoreUI(tkTk):
    """A class used to represent a extension of the TKinter ui module."""

    def __init__(self: "CoreUI") -> None:
        """Initialize the class."""
        super().__init__()
        self.db = Utils.database(DATABASE_FILE)
        self.table = PreferencesTable
        self.db.add_data(self.table, PREFERENCES_DATA)

        self.dark_mode_icon = ImageTk.PhotoImage(
            Image.open(DARK_MODE_ICON_FILE).resize((20, 20), Image.LANCZOS),  # type: ignore[assignment]
        )
        self.light_mode_icon = ImageTk.PhotoImage(
            Image.open(LIGHT_MODE_ICON_FILE).resize((20, 20), Image.LANCZOS),  # type: ignore[assignment]
        )

    @staticmethod
    def _theme(theme: str) -> None:
        """Set the theme of the UI.

        Args:
            theme: The theme to use.
        """
        sv_ttk.set_theme(theme)

    theme = _theme

    @staticmethod
    def _get_theme() -> str:
        """Get the theme of the UI.

        Returns:
            The theme of the UI.
        """
        return sv_ttk.get_theme()

    get_theme = _get_theme

    def _toggle_theme(self: "CoreUI", button: Button) -> None:
        """Toggle the theme of the UI.

        Args:
            button: The button to toggle the theme.
        """
        sv_ttk.toggle_theme()
        self.db.set_data(self.table, {"usr_theme": sv_ttk.get_theme()})
        if sv_ttk.get_theme() == "dark":
            button.config(image=self.dark_mode_icon)  # type: ignore[arg-type]
        else:
            button.config(image=self.light_mode_icon)  # type: ignore[arg-type]

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
