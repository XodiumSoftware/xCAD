from constants import MAIN_TITLE, UI_ICON_PATH
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.module_handler2 import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QWidget


class MainUI(QWidget):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self.setup_main_ui()
        self.setup_modules()

        self._db_handler = DataBaseHandler()
        self._signal_handler = SignalHandler()
        self._visibility_handler = VisibilityHandler()

    def setup_main_ui(self):
        """
        Setup the MainUI.
        """
        self.setWindowTitle(MAIN_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setContentsMargins(0, 0, 0, 0)

        self._ui_handler = UIHandler()
        self._ui_handler.set_ui_size(self, (600, 400))
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler = EventsHandler()
        self._events_handler.quit_on_key_press_event(self)

        self._main_layout = ModuleHandler.init_layout("Grid")

        self._main_layout.addWidget(self._main_module)

        self.setLayout(self._main_layout)

    def setup_modules(self):
        """
        Setup the modules.
        """
        self._main_module = ModuleHandler()
        self._main_module.init_module(
            module_grid_pos_matrix=[
                [
                    (0, "VBox", "Label", "Leading", (1, 1), (0, 0, 0, 0)),
                    (3, "VBox", "Checkbox", "Center", (1, 1), (0, 0, 0, 0)),
                    (4, "VBox", "Checkbox", "Right", (1, 2), (0, 0, 0, 0)),
                    (1, "VBox", "SpinBox", "Left", (2, 1), (0, 0, 0, 0)),
                ],
                [
                    (0, "VBox", "Button", "Left", (1, 2), (0, 0, 0, 0)),
                    (4, "VBox", "Button", "Right", (1, 1), (0, 0, 0, 0)),
                    (3, "VBox", "GraphicsView", "Center", (1, 1), (0, 0, 0, 0)),
                    (1, "VBox", "TableView", "Leading", (1, 1), (0, 0, 0, 0)),
                ],
                [
                    (0, "VBox", "SpinBox", "Right", (1, 1), (0, 0, 0, 0)),
                    (2, "VBox", "SpinBox", "Center", (1, 1), (0, 0, 0, 0)),
                    None,
                    (1, "VBox", "SpinBox", "Trailing", (1, 1), (0, 0, 0, 0)),
                ],
            ],
        )
