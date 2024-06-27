"""This module contains the theme functionality."""

import qdarktheme as qdt  # type: ignore[import]
from __config__ import (
    PREFERENCES_DATA,
    THEME_ICONS,
    THEMES,
    TREE_STATE,
    USR_THEME,
    UTF,
)
from dalmatia import Utils
from PySide6.QtCore import QByteArray
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QPushButton, QTreeWidget
from tables import PreferencesTable


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
        self.__db__.add_data(self.__table__, PREFERENCES_DATA)
        (
            self.__theme__,
            self.__tree_state__,
        ) = (
            self.__db__.get_data(self.__table__, USR_THEME),
            self.__db__.get_data(self.__table__, TREE_STATE),
        )

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
            widget.setIcon(QIcon(THEME_ICONS[self.__theme__]))
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

    def _set_tree_state(self: "Core", widget: QTreeWidget) -> None:
        """Set the tree state.

        Args:
            widget: The widget.
        """
        self.__db__.set_data(
            self.__table__,
            {
                TREE_STATE: bytes(
                    widget.header().saveState().toBase64().data(),
                ).decode(UTF),
            },
        )

    set_tree_state = _set_tree_state

    def _get_tree_state(self: "Core", widget: QTreeWidget) -> None:
        """Get the tree state.

        Args:
            widget: The widget.
        """
        try:
            if self.__tree_state__:
                widget.header().restoreState(
                    QByteArray.fromBase64(bytes(self.__tree_state__, UTF)),
                )
        except KeyError as err:
            err_msg = f"Invalid tree state: {self.__tree_state__}."
            raise ValueError(err_msg) from err

    get_tree_state = _get_tree_state
