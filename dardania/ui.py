"""This module contains the UI functionality."""

from __config__ import (
    APP_NAME,
    COMPANY_NAME,
    DATABASE_FILE,
    WINDOW_ICON,
    WINDOW_MIN_SIZE,
    WINDOW_TITLE,
)
from core import Core
from dalmatia import Utils
from PySide6.QtCore import QSettings, Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtOpenGLWidgets import QOpenGLWidget
from PySide6.QtWidgets import (
    QGridLayout,
    QHeaderView,
    QLabel,
    QPushButton,
    QSizePolicy,
    QSplitter,
    QTreeWidget,
    QWidget,
)
from tables import PreferencesTable


class UI(Core):
    """A class used to represent a ui module."""

    def __init__(self: "UI") -> None:
        """Initialize the class."""
        super().__init__(Utils.database(DATABASE_FILE), PreferencesTable)
        self.__settings__ = QSettings(COMPANY_NAME, APP_NAME)

        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(str(WINDOW_ICON)))
        self.setMinimumSize(*WINDOW_MIN_SIZE)

        self.setCentralWidget(QWidget(self))
        self.__layout__ = QGridLayout(self.centralWidget())

        self._header()
        self._body()
        self._footer()

        for widget, params in {
            self.header_title: [0, 0, 1, 2],
            self.body_splitter: [1, 0, 1, 2],
            self.footer_copyright: [2, 0, 1, 1],
            self.footer_theme_button: [2, 1, 1, 1],
        }.items():
            self.__layout__.addWidget(widget, *params)

        self.set_theme(self)

    def _header(self: "UI") -> None:
        """Create the header."""
        self.header_title = QLabel("BIM Object Configurator")
        self.header_title.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.header_title.setFont(QFont("", 12, QFont.Weight.Bold))

    def _body(self: "UI") -> None:
        """Create the body."""
        self.body_props_tree = QTreeWidget()
        props_tree_headers: list[str] = ["Property", "Value"]
        self.body_props_tree.setColumnCount(len(props_tree_headers))
        self.body_props_tree.setHeaderLabels(props_tree_headers)
        self.body_props_tree.setSortingEnabled(True)
        header = self.body_props_tree.header()
        header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        header.setSectionsClickable(True)
        sort_indicator = self.__settings__.value(
            "sort_indicator",
            f"0,{Qt.SortOrder.AscendingOrder.name}",
            type=str,
        )
        column, order = sort_indicator.split(",")
        column = int(column)
        order = Qt.SortOrder[order]
        header.setSortIndicator(column, order)
        header.sortIndicatorChanged.connect(
            lambda column, order: self.__settings__.setValue(
                "sort_indicator",
                f"{column},{order.name()}",
            ),
        )

        self.body_viewer = QOpenGLWidget()

        self.body_splitter = QSplitter(Qt.Orientation.Horizontal)
        self.body_splitter.setSizePolicy(
            QSizePolicy.Policy.Preferred,
            QSizePolicy.Policy.Expanding,
        )
        for widget in (self.body_props_tree, self.body_viewer):
            self.body_splitter.addWidget(widget)

    def _footer(self: "UI") -> None:
        """Create the footer."""
        self.footer_copyright = QLabel("©2024 Illyrion")

        self.footer_theme_button = QPushButton()
        self.footer_theme_button.setMaximumWidth(40)
        self.set_theme_icon(self.footer_theme_button)
        self.footer_theme_button.clicked.connect(
            lambda: self.toggle_theme(
                self,
                self.footer_theme_button,
            ),
        )
