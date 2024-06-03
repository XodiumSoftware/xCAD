"""This module contains the UI functionality."""

import pyqtdarktheme
from dalmatia import Utils
from PySide6.QtCore import Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import (
    QApplication,
    QGridLayout,
    QLabel,
    QMainWindow,
    QPushButton,
    QTreeWidget,
    QWidget,
)

from dardania.__config__ import (
    DARK_MODE_ICON_FILE,
    DATABASE_FILE,
    LIGHT_MODE_ICON_FILE,
    PREFERENCES_DATA,
    UI_ICON_FILE,
)
from dardania.db_tables import PreferencesTable


class UI(QMainWindow):
    """A class used to represent a ui module."""

    def __init__(self: "UI") -> None:
        """Initialize the class."""
        super().__init__()
        self.db = Utils.database(DATABASE_FILE)
        self.table = PreferencesTable
        self.db.add_data(self.table, PREFERENCES_DATA)

        self.setWindowTitle("Dardania")
        self.setWindowIcon(QIcon(str(UI_ICON_FILE)))
        self.setMinimumSize(1200, 800)

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

        self.setStyleSheet(pyqtdarktheme.load_stylesheet())

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
        self.footer_copyright = QLabel("©2023 Structura Engineering")
        self.footer_theme_button = QPushButton()
        self.footer_theme_button.clicked.connect(self.toggle_theme)

    def toggle_theme(self: "UI") -> None:
        """Toggle between light and dark themes."""
        current_theme = self.db.get_data(self.table, "usr_theme")
        if current_theme == "dark":
            QApplication.instance().setStyleSheet("")
            self.db.set_data(self.table, {"usr_theme": "light"})
            self.footer_theme_button.setIcon(QIcon(str(DARK_MODE_ICON_FILE)))
        else:
            QApplication.instance().setStyleSheet(
                pyqtdarktheme.load_stylesheet(),
            )
            self.db.set_data(self.table, {"usr_theme": "dark"})
            self.footer_theme_button.setIcon(QIcon(str(LIGHT_MODE_ICON_FILE)))
