from enum import Enum
from functools import partial
from typing import Callable

import qdarktheme
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QStackedWidget
from StenLib.StenHelper import Helper

from configs.matrix_configs import Matrices
from configs.module_configs import PushButtons, UIs
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler


class UI(QMainWindow):
    """A class to handle the UI."""

    def __init__(self) -> None:
        """Initialize the MainUI."""
        super().__init__()
        qdarktheme.setup_theme("auto")

        self._main_module_0, self._main_module_1 = (
            ModuleHandler(Matrices.MainMatrix0),
            ModuleHandler(Matrices.MainMatrix1),
        )

        self._helper, self._events_handler = (
            Helper(),
            EventsHandler(),
        )

        self.setup_ui()

    def setup_ui(self) -> None:
        """Setup the UIs."""
        main_ui_info = UIs.MainUI.value

        self.setWindowTitle(main_ui_info["title"])

        self.setWindowIcon(QIcon(main_ui_info["icon"]))

        self._helper.center_ui_on_screen(self)

        self._helper.set_ui_size(self, main_ui_info["initial_size"])

        self._events_handler.quit_on_key_press_event(self)

        self._main_modules_stack = QStackedWidget(self)
        self._main_modules_stack.addWidget(self._main_module_0)
        self._main_modules_stack.addWidget(self._main_module_1)

        self.setCentralWidget(self._main_modules_stack)
        self.setContentsMargins(*main_ui_info["margins"])

        if main_ui_info["initial_visibility"]:
            self.show()
        else:
            self.hide()

        self.setup_connections()

    def connect_button_to_action(
        self, module: ModuleHandler, button_enum: Enum, action: Callable
    ) -> None:
        """Connect a button in a module to a specific action."""
        module.module_connection(
            button_enum, partial(action, module=self._main_modules_stack)
        )

    def setup_connections(self) -> None:
        """Setup the connections."""
        self.connect_button_to_action(
            self._main_module_0, PushButtons.AutoFrameCAD, self._helper.switch_modules
        )
        self.connect_button_to_action(
            self._main_module_1, PushButtons.StartupPage, self._helper.switch_modules
        )
