"""This module contains the theme functionality."""

import qdarktheme as qdt  # type: ignore[import]
from __config__ import (
    DARK_MODE_ICON,
    DATABASE_FILE,
    LIGHT_MODE_ICON,
    SPLITTER_STATE_KEY,
    THEME_STATE_KEY,
    TREE_STATE_KEY,
    UTF,
)
from dalmatium import Utils
from PySide6.QtCore import QByteArray
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QPushButton, QSplitter, QTreeWidget
from tables import UIStateTable

# Theme
# =============================================================================
DARK_MODE: str = "dark"
LIGHT_MODE: str = "light"
THEMES: dict[str, str] = {
    DARK_MODE: LIGHT_MODE,
    LIGHT_MODE: DARK_MODE,
}
THEME_ICONS: dict[str, str] = {
    DARK_MODE: str(DARK_MODE_ICON),
    LIGHT_MODE: str(LIGHT_MODE_ICON),
}
# =============================================================================


class Core(QMainWindow):
    """A class used to represent a Core module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        self.__db__ = Utils.db(DATABASE_FILE)
        self.__table__ = UIStateTable
        (
            self.__theme_state__,
            self.__tree_state__,
            self.__splitter_state__,
        ) = (
            self.__db__.get_data(self.__table__, THEME_STATE_KEY, DARK_MODE),
            self.__db__.get_data(self.__table__, TREE_STATE_KEY),
            self.__db__.get_data(self.__table__, SPLITTER_STATE_KEY),
        )

    def set_theme_state(
        self,
        widget: QMainWindow,
        target: QPushButton,
    ) -> None:
        """Set the theme state.

        Args:
            widget: The widget.
            target: The target.
        """
        self.__theme_state__ = THEMES[str(self.__theme_state__)]
        self.__db__.set_data(
            self.__table__,
            {THEME_STATE_KEY: self.__theme_state__},
        )
        self.get_theme_state(widget, target)

    def get_theme_state(
        self,
        widget: QMainWindow,
        target: QPushButton,
    ) -> None:
        """Get the theme state.

        Args:
            widget: The widget.
            target: The target.
        """
        try:
            if self.__theme_state__ in THEMES:
                widget.setStyleSheet(qdt.load_stylesheet(self.__theme_state__))
                target.setIcon(QIcon(THEME_ICONS[self.__theme_state__]))
        except KeyError as err:
            err_msg = f"Invalid theme: {self.__theme_state__}."
            raise ValueError(err_msg) from err

    def set_tree_state(self, widget: QTreeWidget) -> None:
        """Set the tree state.

        Args:
            widget: The widget.
        """
        self.__db__.set_data(
            self.__table__,
            {
                TREE_STATE_KEY: bytes(
                    widget.header().saveState().toBase64().data(),
                ).decode(UTF),
            },
        )

    def get_tree_state(self, widget: QTreeWidget) -> None:
        """Get the tree state.

        Args:
            widget: The widget.
        """
        try:
            if self.__tree_state__:
                widget.header().restoreState(
                    QByteArray.fromBase64(
                        bytes(str(self.__tree_state__), UTF),
                    ),
                )
        except KeyError as err:
            err_msg = f"Invalid tree state: {self.__tree_state__}."
            raise ValueError(err_msg) from err

    def set_splitter_state(self, widget: QSplitter) -> None:
        """Set the splitter state.

        Args:
            widget: The widget.
        """
        self.__db__.set_data(
            self.__table__,
            {
                SPLITTER_STATE_KEY: bytes(
                    widget.saveState().toBase64().data(),
                ).decode(UTF),
            },
        )

    def get_splitter_state(self, widget: QSplitter) -> None:
        """Get the splitter state.

        Args:
            widget: The widget.
        """
        try:
            if self.__splitter_state__:
                widget.restoreState(
                    QByteArray.fromBase64(
                        bytes(str(self.__splitter_state__), UTF),
                    ),
                )
        except KeyError as err:
            err_msg = f"Invalid splitter state: {self.__splitter_state__}."
            raise ValueError(err_msg) from err
