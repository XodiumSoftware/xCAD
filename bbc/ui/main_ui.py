from constants import MAIN_TITLE, UI_ICON_PATH
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QWidget
from ui.configurator_ui import ConfiguratorUI


class MainUI(QWidget):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self._db_handler = DataBaseHandler()
        self._visibility_handler = VisibilityHandler()
        self._ui_handler = UIHandler()
        self._events_handler = EventsHandler()
        self._signal_handler = SignalHandler()

        self.setup_main_ui()

    def setup_main_ui(self):
        """
        Setup the MainUI.
        """
        self.setWindowTitle(MAIN_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setContentsMargins(0, 0, 0, 0)

        self._ui_handler.set_ui_size(self, (600, 400))
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler.quit_on_key_press_event(self)

        self._main_module = ModuleHandler(0)

        layout = QGridLayout(self)
        layout.addWidget(self._main_module)

        self._configurator_ui = ConfiguratorUI()
        self._configurator_ui.show()  # TODO: Implement properly.
