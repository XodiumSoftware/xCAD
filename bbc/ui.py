from functools import partial

from constants import UIS
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import Slot
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget


class UI(QMainWindow):
    def __init__(self) -> None:
        """
        Initialize the MainUI.
        """
        super().__init__()

        self._db_handler = DataBaseHandler()
        self._main_module = ModuleHandler(0)
        self._configurator_module = ModuleHandler(1)
        self._signal_handler = SignalHandler()
        self._ui_handler = UIHandler()

        self._main_ui = QWidget()
        self._configurator_ui = QWidget()

        self._events_handler = EventsHandler()

        self.setup_ui()

    def setup_ui(self) -> None:
        """
        Setup the UIs.
        """
        main_ui_info = UIS[0]
        configurator_ui_info = UIS[1]

        self._main_ui.setWindowTitle(main_ui_info["title"])
        self._configurator_ui.setWindowTitle(configurator_ui_info["title"])

        self._main_ui.setWindowIcon(QIcon(main_ui_info["icon"]))
        self._configurator_ui.setWindowIcon(QIcon(configurator_ui_info["icon"]))

        self._ui_handler.center_ui_on_screen_handler(self)

        self._ui_handler.set_ui_size(self._main_ui, main_ui_info["initial_size"])
        self._ui_handler.set_ui_size(
            self._configurator_ui, configurator_ui_info["initial_size"]
        )

        self._events_handler.quit_on_key_press_event(self._main_ui)
        self._events_handler.quit_on_key_press_event(self._configurator_ui)

        self._main_ui_layout = QGridLayout(self._main_ui)
        self._main_ui_layout.addWidget(self._main_module)

        self._configurator_ui_layout = QGridLayout(self._configurator_ui)
        self._configurator_ui_layout.addWidget(self._configurator_module)

        if main_ui_info["initial_visibility"]:
            self._main_ui.show()
            self._main_ui.activateWindow()
        else:
            self._main_ui.hide()

        if configurator_ui_info["initial_visibility"]:
            self._configurator_ui.show()
            self._configurator_ui.activateWindow()
        else:
            self._configurator_ui.hide()

        self.setup_connections()

    def setup_connections(self) -> None:
        """
        Setup the connections.
        """
        self._main_module.module_connection(
            "Button",
            0,
            partial(
                self.toggle_ui_visibility,
                ui=self._configurator_ui,
            ),
        )
        self._configurator_module.module_connection(
            "Button",
            5,
            partial(
                self.toggle_ui_visibility,
                ui=self._configurator_ui,
            ),
        )
        self._configurator_module.module_connection(
            "Button",
            1,
            partial(
                self._configurator_module.toggle_module_visibility,
                "GraphicsView",
                0,
            ),
        )
        self._configurator_module.module_connection(
            "Button",
            2,
            partial(
                self._db_handler.save_table_data_changes,
                "OBJECT_ASSEMBLY_DATA",
            ),
        )

    @Slot(QWidget)
    @staticmethod
    def toggle_ui_visibility(ui: QWidget) -> None:
        """
        Toggles the visibility of the UI.
        """
        return ui.setVisible(not ui.isVisible())
