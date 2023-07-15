from constants import MAIN_TITLE, UI_ICON_PATH
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget


class MainUI(QMainWindow, SignalHandler):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self._db_handler = DataBaseHandler()
        # self._configurator_ui = ConfiguratorUI()
        # self._configurator_ui.show()  # TODO: Implement properly.
        self._visibility_handler = VisibilityHandler()
        self._ui_handler = UIHandler()
        self._events_handler = EventsHandler()

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

        self.setup_modules()

        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        layout = QGridLayout(central_widget)
        layout.addWidget(self._main_module)

    def setup_modules(self):
        """
        Setup the modules.
        """
        # TODO: replace content with actual modules.
        self._main_module = ModuleHandler(
            module_matrix_pos=[
                [
                    ("VBox", "Label", 0, (0, 0, 0, 0), "AlignLeading"),
                    ("VBox", "Button", 1, (0, 0, 0, 0), "AlignRight"),
                    ("HBox", "SpinBox", 2, (0, 0, 0, 0), "AlignCenter"),
                    ("Grid", "Checkbox", 3, (0, 0, 0, 0), "AlignTrailing"),
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
