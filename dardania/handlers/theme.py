"""This module contains the theme functionality."""

import qdarktheme as qdt  # type: ignore[import]
from __config__ import (
    DARK_MODE_ICON_FILE,
    LIGHT_MODE_ICON_FILE,
)
from dalmatia import Utils
from db_tables import PreferencesTable
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QPushButton

USR_THEME: str = "usr_theme"
THEMES: dict[str, str] = {
    "dark": str(DARK_MODE_ICON_FILE),
    "light": str(LIGHT_MODE_ICON_FILE),
}


class Theme:
    """A class used to represent a theme module."""

    def __init__(
        self: "Theme",
        widget: QMainWindow,
        db: Utils.database,
        preferences_table: PreferencesTable,
    ) -> None:
        """Initialize the class."""
        self.current_theme = db.get_data(preferences_table, USR_THEME)
        self.set_theme(widget, self.current_theme)

    @staticmethod
    def _set_theme(widget: QMainWindow, mode: str) -> None:
        """Set the theme.

        Args:
            widget: The widget.
            mode: The mode.
        """
        widget.setStyleSheet(qdt.load_stylesheet(mode))

    set_theme = _set_theme

    @staticmethod
    def _set_theme_icon(widget: QPushButton, theme: str) -> None:
        """Set the theme icon.

        Args:
            widget: The widget.
            theme: The theme.
        """
        try:
            widget.setIcon(QIcon(THEMES[theme]))
        except KeyError as err:
            err_msg = f"Invalid theme: {theme}."
            raise ValueError(err_msg) from err

    set_theme_icon = _set_theme_icon

    def _toggle_theme(self: "Theme", widget: QMainWindow) -> None:
        """Toggle between light and dark themes."""
        try:
            self.set_theme(
                widget,
                next(theme for theme in THEMES),
            )
        except StopIteration as err:
            err_msg = "No theme found."
            raise ValueError(err_msg) from err

    toggle_theme = _toggle_theme
