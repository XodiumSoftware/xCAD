"""This module contains the UI functionality."""

from __config__ import (
    DATABASE_FILE,
    WINDOW_ICON,
    WINDOW_MIN_SIZE,
    WINDOW_TITLE,
)
from core import Core
from dalmatia import Utils
from PySide6.QtCore import Qt
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
from tables import UIStateTable


class UI(Core):
    """A class used to represent a ui module."""

    def __init__(self: "UI") -> None:
        """Initialize the class."""
        super().__init__(Utils.database(DATABASE_FILE), UIStateTable)
        self._main()

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

    def _main(self: "UI") -> None:
        """Create the main."""
        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(str(WINDOW_ICON)))
        self.setMinimumSize(*WINDOW_MIN_SIZE)

        self.setCentralWidget(QWidget(self))
        self.__layout__ = QGridLayout(self.centralWidget())

    def _header(self: "UI") -> None:
        """Create the header."""
        self.header_title = QLabel("BIM Object Configurator")
        self.header_title.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.header_title.setFont(QFont("", 12, QFont.Weight.Bold))

    def _body(self: "UI") -> None:
        """Create the body."""
        props_tree_headers: list[str] = ["Property", "Value"]

        self.body_props_tree = QTreeWidget()
        self.body_props_tree.setColumnCount(len(props_tree_headers))
        self.body_props_tree.setHeaderLabels(props_tree_headers)
        self.body_props_tree.setSortingEnabled(True)
        header = self.body_props_tree.header()
        header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        header.setSectionsClickable(True)
        self.get_tree_state(self.body_props_tree)
        header.sectionClicked.connect(
            lambda: self.set_tree_state(self.body_props_tree),
        )

        self.body_viewer = QOpenGLWidget()

        self.body_splitter = QSplitter(Qt.Orientation.Horizontal)
        self.body_splitter.setSizePolicy(
            QSizePolicy.Policy.Preferred,
            QSizePolicy.Policy.Expanding,
        )
        for widget in (self.body_props_tree, self.body_viewer):
            self.body_splitter.addWidget(widget)
        self.get_splitter_state(self.body_splitter)
        self.body_splitter.splitterMoved.connect(
            lambda: self.set_splitter_state(self.body_splitter),
        )

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
