"""This module contains the UI functionality."""

import qdarktheme as qdt  # type: ignore[import]
from __config__ import (
    DATABASE_FILE,
    PREFERENCES_DATA,
    UI_ICON_FILE,
)
from dalmatia import Utils
from db_tables import PreferencesTable
from handlers import Handlers
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

USR_THEME: str = "usr_theme"
DARK_THEME: str = "dark"
LIGHT_THEME: str = "light"


class UI(QMainWindow):
    """A class used to represent a ui module."""

    def __init__(self: "UI") -> None:
        """Initialize the class."""
        super().__init__()
        self.db = Utils.database(DATABASE_FILE)
        self.preferences_table = PreferencesTable
        self.db.add_data(self.preferences_table, PREFERENCES_DATA)
        self.current_theme = self.db.get_data(
            self.preferences_table,
            USR_THEME,
        )

        self.handle = Handlers()

        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(str(UI_ICON_FILE)))
        self.setMinimumSize(*WINDOW_MIN_SIZE)

        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)
        self._layout = QGridLayout(self.central_widget)

        self._header()
        self._body()
        self._footer()

        self._layout.addWidget(self.header_title, 0, 0, 1, 2)
        self._layout.addWidget(self.body_props_tree, 1, 0, 1, 2)
        self._layout.addWidget(self.footer_copyright, 2, 0)
        self._layout.addWidget(self.footer_theme_button, 2, 1)

        self.setStyleSheet(
            qdt.load_stylesheet(
                self.db.get_data(self.preferences_table, USR_THEME),
            ),
        )

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
        self.handle.theme.set_theme_icon(
            self.footer_theme_button,
            self.current_theme,
        )
        self.footer_theme_button.clicked.connect(self.toggle_theme)

    def toggle_theme(self: "UI") -> None:
        """Toggle between light and dark themes."""
        if self.current_theme == DARK_THEME:
            self.setStyleSheet(qdt.load_stylesheet(LIGHT_THEME))
            self.db.set_data(self.preferences_table, {USR_THEME: LIGHT_THEME})
            self.current_theme = LIGHT_THEME
        else:
            self.setStyleSheet(qdt.load_stylesheet(DARK_THEME))
            self.db.set_data(self.preferences_table, {USR_THEME: DARK_THEME})
            self.current_theme = DARK_THEME
        self.handle.theme.set_theme_icon(
            self.footer_theme_button,
            self.current_theme,
        )
