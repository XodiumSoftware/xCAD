from typing import List

import qdarktheme
from PySide6.QtCore import QPoint
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QMainWindow, QStackedWidget, QWidget

from handlers.events_handler import EventsHandler
from handlers.module_handler import MatrixHandler
from interfaces.configs.main_ui_config import MainUI
from interfaces.configs.matrix_configs import Matrices
from interfaces.modules.status_bar_module import StatusBarModule
from interfaces.modules.tool_bar_module import ToolBarModule


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
        self.setStatusBar(StatusBarModule(MainUI.STATUSBAR))
        self.addToolBar(ToolBarModule(MainUI.TOOLBAR))
        self.setup_central_widget()
        self.setup_visibility()
        self._events_handler.quit_on_key_press_event(self)

    def setup_window(self) -> None:
        """Set up the main window properties."""
        self.setWindowTitle(MainUI.TITLE)
        self.setWindowIcon(QIcon(MainUI.ICON))
        self.resize(*MainUI.INIT_SIZE)
        self.setContentsMargins(*MainUI.MARGINS)

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

    def toggle_ui_visibility(self, uis: List[QWidget]) -> bool:
        """Toggles the visibility of a list of QWidgets."""
        visibility_changed = any(ui.isHidden() for ui in uis)
        for ui in uis:
            ui.setVisible(not ui.isVisible())
        if visibility_changed:
            self.center_ui_on_screen()
        return visibility_changed
