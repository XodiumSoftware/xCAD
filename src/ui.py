import qdarktheme
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QStackedWidget

from configs.matrix_configs import Matrices
from configs.module_configs import UIs
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from utils.ui_utils import UiUtils


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

        self._ui_utils, self._events_handler = (
            UiUtils(),
            EventsHandler(),
        )

        self.setup_ui()

    def setup_ui(self) -> None:
        """Setup the UIs."""
        ui_info = UIs.MainUI.value

        self.setWindowTitle(ui_info["title"])
        self.setWindowIcon(QIcon(ui_info["icon"]))

        self._ui_utils.center_ui_on_screen()

        self.resize(*ui_info["initial_size"])
        self.setContentsMargins(*ui_info["margins"])

        self._events_handler.quit_on_key_press_event(self)

        self._main_modules_stack = QStackedWidget(self)
        self._main_modules_stack.addWidget(self._main_module_0)
        self._main_modules_stack.addWidget(self._main_module_1)

        self.setCentralWidget(self._main_modules_stack)

        if ui_info["initial_visibility"]:
            self.show()
        else:
            self.hide()
