from constants import MAIN_TITLE, UI_ICON_PATH
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.module_handler import ModuleHandler
from handlers.signal_handler import SignalHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget
from ui.configurator_ui import ConfiguratorUI
from ui.modules.container_module import ContainerModule


class MainUI(QMainWindow):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self.setup_database()
        self.setup_main_ui()

    def setup_database(self):
        """
        Setup the database.
        """
        self._db_handler = DataBaseHandler()
        self._configurator_ui = ConfiguratorUI()
        self._signal_handler = SignalHandler()

    def setup_main_ui(self):
        """
        Setup the MainUI.
        """
        self.setWindowTitle(MAIN_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setContentsMargins(0, 0, 0, 0)
        self.sizeHint()

        self._ui_handler = UIHandler()
        self._ui_handler.set_ui_size(self)
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler = EventsHandler()
        EventsHandler.quit_on_key_press_event(self)

        self.setup_modules()
        self.setup_sub_containers()
        self.setup_main_containers()
        self.setup_connections()

        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        layout = QGridLayout(central_widget)

        layout.addWidget(self.main_container_0, 0, 0)
        layout.addWidget(self.main_container_1, 1, 0)

        self.main_container_0.show()
        self.main_container_1.hide()

    def setup_modules(self):
        """
        Setup the modules.
        """
        # Setup labels:
        self.label_0 = ModuleHandler("VBox", "Label", 0)
        self.label_1 = ModuleHandler("VBox", "Label", 0)

        # Setup tables:
        self.table_0 = ModuleHandler("VBox", "TableView", 0)

        # Setup buttons:
        self.button_0 = ModuleHandler("VBox", "Button", 0)
        self.button_2 = ModuleHandler("VBox", "Button", 2)
        self.button_3 = ModuleHandler("VBox", "Button", 3)
        self.button_4 = ModuleHandler("VBox", "Button", 4)
        self.button_5 = ModuleHandler("VBox", "Button", 5)

    def setup_sub_containers(self):
        """
        Setup the sub containers.
        """
        self.sub_container_0 = ContainerModule("HBox")
        self.sub_container_0.add_spacer()
        self.sub_container_0.add_module(self.button_2)
        self.sub_container_0.add_module(self.button_3)
        self.sub_container_0.add_module(self.button_4)

        self.sub_container_1 = ContainerModule("HBox")
        self.sub_container_1.add_module(self.button_0)

        self.sub_container_2 = ContainerModule("HBox")
        self.sub_container_2.add_module(self.label_0)
        self.sub_container_2.add_spacer()
        self.sub_container_2.add_module(self.button_5)

        self.sub_container_3 = ContainerModule("HBox")
        self.sub_container_3.add_module(self.label_1)
        self.sub_container_3.add_spacer()

        self.sub_container_4 = ContainerModule("HBox")
        self.sub_container_4.add_module(self.table_0)

        self.sub_container_5 = ContainerModule("HBox")

    def setup_main_containers(self):
        """
        Setup the main containers.
        """
        # Setup main container 0:
        self.main_container_0 = ContainerModule("Grid")
        self.main_container_0.add_module(
            self.sub_container_1,
            row=1,
            column=0,
            alignment=Qt.AlignmentFlag.AlignCenter | Qt.AlignmentFlag.AlignBottom,
        )
        self.main_container_0.add_module(
            self.sub_container_3,
            row=3,
            column=0,
            alignment=Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignBottom,
        )

        # Setup main container 1:
        self.main_container_1 = ContainerModule("Grid")
        self.main_container_1.add_module(
            self.sub_container_4,
            row=0,
            column=0,
        )
        self.main_container_1.add_module(
            self.sub_container_0,
            row=1,
            column=0,
            alignment=Qt.AlignmentFlag.AlignRight | Qt.AlignmentFlag.AlignBottom,
        )
        self.main_container_1.add_module(
            self.sub_container_2,
            row=2,
            column=0,
            alignment=Qt.AlignmentFlag.AlignCenter | Qt.AlignmentFlag.AlignBottom,
        )

        self.main_container_1.add_module(
            self.sub_container_5,
            row=0,
            column=1,
            rowspan="auto",
            columnspan="auto",
        )

    def setup_connections(self):
        """
        Setup the connections.
        """
        self.button_0.onButtonModuleClicked.connect(self.toggle_main_containers)
        self.button_5.onButtonModuleClicked.connect(self.toggle_main_containers)
        self._signal_handler.structureButtonClicked.connect(self.toggle_configurator_ui)

    def toggle_main_containers(self):
        """
        Toggle the main containers.
        """
        self.main_container_0.setVisible(not self.main_container_0.isVisible())
        self.main_container_1.setVisible(not self.main_container_1.isVisible())

    def toggle_configurator_ui(self):
        """
        Toggle the configurator UI.
        """
        self._configurator_ui.setVisible(not self.isVisible())
        self.setVisible(not self._configurator_ui.isVisible())
