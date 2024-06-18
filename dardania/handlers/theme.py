"""This module contains the theme functionality."""

from __config__ import (
    DARK_MODE_ICON_FILE,
    LIGHT_MODE_ICON_FILE,
)
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QPushButton,
)

DARK_THEME: str = "dark"
LIGHT_THEME: str = "light"


class Theme:
    """A class used to represent a theme module."""

    @staticmethod
    def _set_theme() -> None:
        """Set the theme."""

    set_theme = _set_theme

    @staticmethod
    def _get_theme() -> None:
        """Get the theme."""

    get_theme = _get_theme

    @staticmethod
    def _toggle_theme() -> None:
        """Toggle the theme."""

    toggle_theme = _toggle_theme

    @staticmethod
    def _set_theme_icon(widget: QPushButton, theme: str) -> None:
        """Set the theme icon.

        Args:
            widget: The widget.
            theme: The theme.
        """
        if theme == DARK_THEME:
            widget.setIcon(
                QIcon(str(DARK_MODE_ICON_FILE)),
            )
        elif theme == LIGHT_THEME:
            widget.setIcon(
                QIcon(str(LIGHT_MODE_ICON_FILE)),
            )
        else:
            error_message: str = "Invalid theme."
            raise ValueError(error_message)

    set_theme_icon = _set_theme_icon
