from functools import partial

import qdarktheme
from enums.matrix_enums import Matrices
from enums.module_enums import PushButtons
from enums.q_enums import ModuleType
from enums.ui_enums import UIs
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget


class UI(QMainWindow):
    """A class to handle the UI."""

    def __init__(self) -> None:
        """Initialize the MainUI."""
        super().__init__()

        self._main_module_0 = ModuleHandler(Matrices.MainMatrix0)
        self._main_module_1 = ModuleHandler(Matrices.MainMatrix1)
        self._signal_handler = SignalHandler()
        self._ui_handler = UIHandler()

        self._main_ui = QWidget()

        self._events_handler = EventsHandler()

        self.setup_ui()

    def setup_ui(self) -> None:
        """Setup the UIs."""
        qdarktheme.setup_theme("auto")

        main_ui_info = UIs.MainUI.value

        self._main_ui.setWindowTitle(main_ui_info["title"])

        self._main_ui.setWindowIcon(QIcon(main_ui_info["icon"]))

        self._ui_handler.center_ui_on_screen_handler(self)

        self._ui_handler.set_ui_size(self._main_ui, main_ui_info["initial_size"])

        self._events_handler.quit_on_key_press_event(self._main_ui)

        self._main_modules_stack = ModuleType.StackedWidget.value(self._main_ui)
        self._main_modules_stack.addWidget(self._main_module_0)
        self._main_modules_stack.addWidget(self._main_module_1)

        self._main_ui_layout = QGridLayout(self._main_ui)
        self._main_ui_layout.addWidget(self._main_modules_stack)

        self._configurator_modules_stack = ModuleType.StackedWidget.value(self._main_ui)

        if main_ui_info["initial_visibility"]:
            self._main_ui.show()
        else:
            self._main_ui.hide()

        self.setup_connections()

    def setup_connections(self) -> None:
        """Setup the connections."""
        self._main_module_0.module_connection(
            PushButtons.AutoFrameCAD,
            partial(
                self._ui_handler.switch_modules,
                module=self._main_modules_stack,
            ),
        )
        self._main_module_1.module_connection(
            PushButtons.StartupPage,
            partial(
                self._ui_handler.switch_modules,
                module=self._main_modules_stack,
            ),
        )
