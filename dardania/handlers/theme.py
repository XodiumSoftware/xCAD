"""This module contains the theme functionality."""

import qdarktheme as qdt  # type: ignore[import]
from __config__ import (
    ICON_THEMES,
    PREFERENCES_DATA,
    THEMES,
    USR_THEME,
)
from dalmatia import Utils
from db_tables import PreferencesTable
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QPushButton


class Theme:
    """A class used to represent a theme module."""

    def __init__(
        self: "Theme",
        db: Utils.database,
        table: PreferencesTable,
    ) -> None:
        """Initialize the class.

        Args:
            db: The database.
            table: The table.
        """
        self.__db__ = db
        self.__table__ = table
        self.__theme__ = self.__db__.get_data(self.__table__, USR_THEME)
        self.__db__.add_data(self.__table__, PREFERENCES_DATA)

    def _set_theme(self: "Theme", widget: QMainWindow) -> None:
        """Set the theme.

        Args:
            widget: The widget.
        """
        widget.setStyleSheet(qdt.load_stylesheet(self.__theme__))
        self.__db__.set_data(self.__table__, {USR_THEME: self.__theme__})

    set_theme = _set_theme

    def _set_theme_icon(self: "Theme", widget: QPushButton) -> None:
        """Set the theme icon.

        Args:
            widget: The widget.
        """
        try:
            widget.setIcon(QIcon(ICON_THEMES[self.__theme__]))
        except KeyError as err:
            err_msg = f"Invalid theme: {self.__theme__}."
            raise ValueError(err_msg) from err

    set_theme_icon = _set_theme_icon

    def _toggle_theme(
        self: "Theme",
        widget: QMainWindow,
        target: QPushButton,
    ) -> None:
        """Toggle between light and dark themes.

        Args:
            widget: The widget.
            target: The target.
        """
        self.__theme__ = THEMES[self.__theme__]
        self.set_theme(widget)
        self.set_theme_icon(target)

    toggle_theme = _toggle_theme
