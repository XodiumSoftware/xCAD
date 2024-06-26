"""This module contains the theme functionality."""

import qdarktheme as qdt  # type: ignore[import]
from __config__ import (
    DARK_MODE,
    DARK_MODE_ICON,
    LIGHT_MODE,
    LIGHT_MODE_ICON,
    PREFERENCES_DATA,
    TREE_SORT_ORDER,
    USR_THEME,
)
from dalmatia import Utils
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QPushButton
from tables import PreferencesTable

ICON_THEMES: dict[str, str] = {
    DARK_MODE: str(DARK_MODE_ICON),
    LIGHT_MODE: str(LIGHT_MODE_ICON),
}
THEMES: dict[str, str] = {DARK_MODE: LIGHT_MODE, LIGHT_MODE: DARK_MODE}


class Core(QMainWindow):
    """A class used to represent a Core module."""

    def __init__(
        self: "Core",
        db: Utils.database,
        table: PreferencesTable,
    ) -> None:
        """Initialize the class.

        Args:
            db: The database.
            table: The table.
        """
        super().__init__()
        self.__db__ = db
        self.__table__ = table
        (
            self.__theme__,
            self.__order__,
        ) = (
            self.__db__.get_data(self.__table__, USR_THEME),
            self.__db__.get_data(
                self.__table__,
                TREE_SORT_ORDER,
            ),
        )
        self.__db__.add_data(self.__table__, PREFERENCES_DATA)

    def _set_theme(self: "Core", widget: QMainWindow) -> None:
        """Set the theme.

        Args:
            widget: The widget.
        """
        widget.setStyleSheet(qdt.load_stylesheet(self.__theme__))
        self.__db__.set_data(self.__table__, {USR_THEME: self.__theme__})

    set_theme = _set_theme

    def _set_theme_icon(self: "Core", widget: QPushButton) -> None:
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
        self: "Core",
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
