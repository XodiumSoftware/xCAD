from constants import UI_ICON_PATH, UI_TITLE
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings, Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QStackedWidget, QWidget
from ui.modules.button_module import ButtonModule
from ui.modules.checkbox_module import CheckBoxModule
from ui.modules.container_module import ContainerModule
from ui.modules.frame_module import FrameModule
from ui.modules.label_module import LabelModule
from ui.modules.settings_list_module import TableModule


class MainUI(QMainWindow):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self.setup_database()
        self.setup_settings()
        self.setup_main_ui()

    def setup_settings(self):
        """
        Setup the settings.
        """
        self._settings = QSettings()

        self.main_ui_visibility_state = self._settings.value(
            "main_ui_visibility_state", 0, type=int
        )
        self.viewer_visibility_state = self._settings.value(
            "viewer_visibility_state", 0, type=int
        )
        self.theme_state = self._settings.value("theme_state", 0, type=int)

    def setup_database(self):
        """
        Setup the database.
        """
        self._settings_db_handler = DataBaseHandler()

    def setup_main_ui(self):
        """
        Setup the MainUI.
        """
        self.setCentralWidget(QWidget())
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setContentsMargins(0, 0, 0, 0)

        self._ui_handler = UIHandler(self)
        self._ui_handler.ui_size_handler(self, 600, 400)
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler = EventsHandler()
        EventsHandler.quit_on_key_press_event(self)

        # Setup checkboxes:
        self.checkbox_0 = CheckBoxModule(0)
        self.checkbox_0.on_checkbox_clicked.connect(self.toggle_visibility_states)

        # Setup buttons:
        self.button_0 = ButtonModule(0)
        self.button_0.on_button_clicked.connect(self._events_handler.on_button_clicked)

        self.button_1 = ButtonModule(1)
        self.button_1.on_button_clicked.connect(self._events_handler.on_button_clicked)

        self.button_2 = ButtonModule(2)
        self.button_2.on_button_clicked.connect(self._events_handler.on_button_clicked)

        self.button_3 = ButtonModule(3)
        self.button_3.on_button_clicked.connect(self._events_handler.on_button_clicked)

        # Setup containers:
        self.button_container_0 = ContainerModule("HBox", [0, 0, 0, 0])
        self.button_container_0.add_widget(self.button_0)
        self.button_container_0.add_spacer()
        self.button_container_0.add_widget(self.button_1)

        self.button_container_1 = ContainerModule("HBox", [0, 0, 0, 0])
        self.button_container_1.add_spacer()
        self.button_container_1.add_widget(self.button_2)
        self.button_container_1.add_widget(self.button_3)

        self.stacked_widget = QStackedWidget()

        self.setCentralWidget(self.stacked_widget)

    def setup_main_containers(self):
        """
        Setup the main containers.
        """
        self.main_container_0 = ContainerModule("Grid", [0, 0, 0, 0])
        self.main_container_0.add_widget(self.button_container_0, 0, 0, 1, 1)
        self.main_container_0.add_widget(TableModule(0), 1, 0, 1, 1)
        self.main_container_0.add_widget(self.button_container_1, 2, 0, 1, 1)
        self.main_container_0.add_widget(self.checkbox_0, 3, 0, 1, 1)
        self.main_container_0.add_widget(LabelModule(0), 4, 0, 1, 1)
        self.stacked_widget.addWidget(self.main_container_0)

        self.main_container_1 = ContainerModule("Grid", [0, 0, 0, 0])
        self.main_container_1.add_widget(LabelModule(1), 1, 0, 1, 1)
        self.main_container_1.add_widget(
            FrameModule(0), 0, 1, 4, 1, Qt.AlignmentFlag.AlignCenter
        )
        self.main_container_1.add_widget(self.checkbox_0, 3, 0, 1, 1)
        self.main_container_1.add_widget(LabelModule(0), 4, 0, 1, 2)
        self.stacked_widget.addWidget(self.main_container_1)

    def toggle_visibility_states(self):
        """
        Toggle the visibility states.
        """
        if self.main_ui_visibility_state == 0:
            self.main_ui_visibility_state = 1
        elif self.main_ui_visibility_state == 1:
            self.main_ui_visibility_state = 0

        self.show_container()
        self._settings.setValue(
            "main_ui_visibility_state", self.main_ui_visibility_state
        )  # NOTE: Do i need this? looks like duplicated code.

    def show_container(self):
        """
        Show the container.
        """
        self.stacked_widget.setCurrentIndex(self.main_ui_visibility_state)
