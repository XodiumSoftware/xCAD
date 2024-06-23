"""This module contains the UI functionality."""

from __config__ import (
    DATABASE_FILE,
    UI_ICON_FILE,
)
from dalmatia import Utils
from db_tables import PreferencesTable
from handlers.theme import Theme
from PySide6.QtCore import Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import (
    QGridLayout,
    QLabel,
    QMainWindow,
    QPushButton,
    QTreeWidget,
    QWidget,
)

WINDOW_TITLE: str = "Dardania"
WINDOW_MIN_SIZE: tuple[int, int] = 1200, 800


class UI(QMainWindow):
    """A class used to represent a ui module."""

    def __init__(self: "UI") -> None:
        """Initialize the class."""
        super().__init__()
        self.db = Utils.database(DATABASE_FILE)
        self.preferences_table = PreferencesTable
        self.handle_theme = Theme(self.db, self.preferences_table)

        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(str(UI_ICON_FILE)))
        self.setMinimumSize(*WINDOW_MIN_SIZE)

        self.setCentralWidget(QWidget(self))
        self.__layout__ = QGridLayout(self.centralWidget())

        self._header()
        self._body()
        self._footer()

        list(
            map(
                self.__layout__.addWidget,
                [
                    self.header_title,
                    self.body_props_tree,
                    self.footer_copyright,
                    self.footer_theme_button,
                ],
                [0, 1, 2, 2],
                [0, 0, 0, 1],
                [1, 1, 1, 1],
                [2, 2, 1, 1],
            ),
        )

        self.handle_theme.set_theme(self)

    def _header(self: "UI") -> None:
        """Create the header."""
        self.header_title = QLabel("BIM Object Configurator")
        self.header_title.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.header_title.setFont(QFont("", 12, QFont.Weight.Bold))

    def _body(self: "UI") -> None:
        """Create the body."""
        self.body_props_tree = QTreeWidget()
        self.body_props_tree.setColumnCount(2)
        self.body_props_tree.setHeaderLabels(["Property", "Value"])

    def _footer(self: "UI") -> None:
        """Create the footer."""
        self.footer_copyright = QLabel("©2024 Illyrion")
        self.footer_theme_button = QPushButton()
        self.footer_theme_button.setMaximumWidth(40)
        self.handle_theme.set_theme_icon(self.footer_theme_button)
        self.footer_theme_button.clicked.connect(
            lambda: self.handle_theme.toggle_theme(
                self,
                self.footer_theme_button,
            ),
        )
