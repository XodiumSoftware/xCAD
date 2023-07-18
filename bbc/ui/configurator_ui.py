from constants import CONFIGURATOR_TITLE, UI_ICON_PATH
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QWidget
from ui.modules.container_module import ContainerModule


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
        self.setContentsMargins(0, 0, 0, 0)

        self._ui_handler = UIHandler()
        self._ui_handler.set_ui_size(self, (800, 400))
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler = EventsHandler()
        self._events_handler.quit_on_key_press_event(
            self
        )  # TODO: Implement properly so it only quits the window not the whole program.

        self.setup_modules()

        layout = QGridLayout(self)
        layout.addWidget(self._configurator_module)

    def setup_modules(self):
        """
        Setup the modules.
        """
        # TODO: replace content with actual modules.
        self._configurator_module = ModuleHandler(
            module_matrix_pos=[
                [
                    ("VBox", "Label", 0, (0, 0, 0, 0), "AlignLeading"),
                    ("VBox", "Button", 1, (0, 0, 0, 0), "AlignRight"),
                    ("HBox", "Button", 2, (0, 0, 0, 0), "AlignCenter"),
                    ("Grid", "Button", 3, (0, 0, 0, 0), "AlignTrailing"),
                    # Add more columns here...
                ],
                [
                    ("VBox", "GraphicsView", 4, (0, 0, 0, 0), "AlignLeft"),
                    ("HBox", "InputField", 5, (0, 0, 0, 0), "AlignBaseline"),
                    ("Grid", "TableView", 6, (0, 0, 0, 0), "AlignRight"),
                    # Add more columns here...
                ],
                # Add more rows here...
            ]
        )
