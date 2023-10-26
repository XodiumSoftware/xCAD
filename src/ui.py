from typing import List

import qdarktheme
from PySide6.QtCore import QPoint
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QStackedWidget,
    QStatusBar,
    QToolBar,
    QWidget,
)

from configs.interfaces.main_ui_config import MainUI
from configs.matrix_configs import Matrices
from handlers.events_handler import EventsHandler
from handlers.module_handler import MatrixHandler


class UIS(QMainWindow):
    """A class to handle the UI."""

    def __init__(self) -> None:
        """Initialize the MainUI."""
        super().__init__()
        qdarktheme.setup_theme("auto")

        self._main_module_0, self._main_module_1 = (
            MatrixHandler(Matrices.MainMatrix0),
            MatrixHandler(Matrices.MainMatrix1),
        )

        self._events_handler = EventsHandler()

        self.setup_ui()

    def setup_ui(self) -> None:
        """Setup the UIs."""
        self.setup_window()
        self.setup_status_bar()
        self.setup_toolbars()
        self.setup_central_widget()
        self.setup_visibility()
        self._events_handler.quit_on_key_press_event(self)

    def setup_window(self) -> None:
        """Set up the main window properties."""
        self.setWindowTitle(MainUI.TITLE)
        self.setWindowIcon(QIcon(MainUI.ICON))
        self.resize(*MainUI.INIT_SIZE)
        self.setContentsMargins(*MainUI.MARGINS)

    def setup_status_bar(self) -> None:
        """Set up the status bar."""
        status_bar: QStatusBar = QStatusBar()
        status_bar.setStatusTip("lol")  # TODO: implement this.
        self.setStatusBar(status_bar)

    def setup_toolbars(self) -> None:
        """Set up toolbars."""
        toolbar_data: str = MainUI.TOOLBAR
        toolbars: List[QToolBar] = [
            QToolBar(name)
            for name in (
                [toolbar_data] if isinstance(toolbar_data, str) else toolbar_data
            )
        ]
        [self.addToolBar(toolbar) for toolbar in toolbars]

    def setup_central_widget(self) -> None:
        """Set up the central widget."""
        self._main_modules_stack = QStackedWidget(self)
        self._main_modules_stack.addWidget(self._main_module_0)
        self._main_modules_stack.addWidget(self._main_module_1)
        self.setCentralWidget(self._main_modules_stack)

    def setup_visibility(self) -> None:
        """Set up initial visibility."""
        self.show() if MainUI.INIT_VISIBILITY else self.hide()

    def center_ui_on_screen(self) -> None:
        """Centers a QWidget on the screen."""
        screen_center: QPoint = QApplication.primaryScreen().geometry().center()
        widget_center: QPoint = QPoint(
            self.size().width() // 2, self.size().height() // 2
        )
        self.move(screen_center - widget_center)

    def toggle_ui_visibility(self, uis: List[QWidget]) -> None:
        """Toggles the visibility of a list of QWidgets."""
        for ui in uis:
            ui.setVisible(not ui.isVisible()) and self.center_ui_on_screen()

    @staticmethod
    def switch_modules_on_event(module: QStackedWidget) -> None:
        """Switches the current module in a QStackedWidget."""
        module.setCurrentIndex((module.currentIndex() + 1) % module.count())
