from constants import CONFIGURATOR_TITLE, UI_ICON_PATH
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QWidget


class ConfiguratorUI(QWidget):
    def __init__(self):
        """
        Initialize the ConfiguratorUI.
        """
        super().__init__()

        self.setup_configurator_ui()

    def setup_configurator_ui(self):
        """
        Setup the ConfiguratorUI.
        """
        self.setWindowTitle(CONFIGURATOR_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        self._ui_handler = UIHandler()
        self._ui_handler.set_ui_size(self, (800, 400))
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler = EventsHandler()
        self._events_handler.quit_on_key_press_event(
            self
        )  # TODO: Implement properly so it only quits the window not the whole program.

        self._configurator_module = ModuleHandler(1)

        layout = QGridLayout(self)
        layout.addWidget(self._configurator_module)
