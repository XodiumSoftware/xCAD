from constants import UI_ICON_PATH, UI_TITLE
from handlers.db_handler import DataBaseHandler
from handlers.events_handler import EventsHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings, Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMainWindow, QStackedWidget, QVBoxLayout, QWidget
from ui.modules.button_module import ButtonModule
from ui.modules.container_module import ContainerModule
from ui.modules.graphics_view_module import GraphicsViewModule
from ui.modules.label_module import LabelModule
from ui.modules.table_module import TableModule


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
        self._db_handler = DataBaseHandler()
        self._db_handler.setup_database()

    def setup_main_ui(self):
        """
        Setup the MainUI.
        """
        self.setCentralWidget(QWidget())
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setContentsMargins(0, 0, 0, 0)
        self.sizeHint()

        self._ui_handler = UIHandler()
        self._ui_handler.set_ui_size(self)
        self._ui_handler.center_ui_on_screen_handler(self)

        self._events_handler = EventsHandler()
        EventsHandler.quit_on_key_press_event(self)

        self.central_widget = QWidget()

        # FIXME: Cannot assign member "layout" for type "MainUI" Type "QVBoxLayout" cannot be assigned to type "() -> QLayout"
        self.layout = QVBoxLayout(self.central_widget)  # type: ignore

        self.stacked_widget = QStackedWidget()
        self.layout.addWidget(self.stacked_widget)

        self.setCentralWidget(self.central_widget)

        self.setup_main_containers()

    def setup_modules(self):
        """
        Setup the modules.
        """
        # Setup labels:
        self.label_0 = LabelModule(0)
        self.label_1 = LabelModule(0)

        # Setup tables:
        self.table_0 = TableModule(1)

        # Setup graphics views:
        self.graphics_view_0 = GraphicsViewModule(1)

        # Setup buttons:
        self.button_0 = ButtonModule(0)
        self.button_0.on_button_clicked.connect(self.toggle_visibility_states)

        self.button_1 = ButtonModule(1)
        self.button_1.on_button_clicked.connect(self.graphics_view_0.toggle_module)

        self.button_2 = ButtonModule(2)

        self.button_3 = ButtonModule(3)

        self.button_4 = ButtonModule(4)

        self.button_5 = ButtonModule(5)
        self.button_5.on_button_clicked.connect(self.toggle_visibility_states)

    def setup_sub_containers(self):
        """
        Setup the sub containers.
        """
        self.setup_modules()

        self.sub_container_0 = ContainerModule("HBox")
        self.sub_container_0.add_spacer()
        self.sub_container_0.add_widget(self.button_2)
        self.sub_container_0.add_widget(self.button_3)
        self.sub_container_0.add_widget(self.button_4)

        self.sub_container_1 = ContainerModule("HBox")
        self.sub_container_1.add_widget(self.button_0)

        self.sub_container_2 = ContainerModule("HBox")
        self.sub_container_2.add_widget(self.label_0)
        self.sub_container_2.add_spacer()
        self.sub_container_2.add_widget(self.button_5)
        self.sub_container_2.add_widget(self.button_1)

        self.sub_container_3 = ContainerModule("HBox")
        self.sub_container_3.add_widget(self.label_1)
        self.sub_container_3.add_spacer()

        self.sub_container_4 = ContainerModule("HBox")
        self.sub_container_4.add_widget(self.table_0)

        self.sub_container_5 = ContainerModule("HBox")
        self.sub_container_5.add_widget(self.graphics_view_0)

    def setup_main_containers(self):
        """
        Setup the main containers.
        """
        self.setup_sub_containers()

        # Setup main container 0:
        self.main_container_0 = ContainerModule("Grid")
        self.main_container_0.add_widget(
            self.sub_container_1,
            1,
            0,
            alignment=Qt.AlignmentFlag.AlignCenter | Qt.AlignmentFlag.AlignBottom,
        )
        self.main_container_0.add_widget(
            self.sub_container_3,
            3,
            0,
            alignment=Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignBottom,
        )

        # Setup main container 1:
        self.main_container_1 = ContainerModule("Grid")
        self.main_container_1.add_widget(
            self.sub_container_4,
            0,
            0,
        )
        self.main_container_1.add_widget(
            self.sub_container_0,
            1,
            0,
            alignment=Qt.AlignmentFlag.AlignRight | Qt.AlignmentFlag.AlignBottom,
        )
        self.main_container_1.add_widget(
            self.sub_container_2,
            2,
            0,
            alignment=Qt.AlignmentFlag.AlignCenter | Qt.AlignmentFlag.AlignBottom,
        )

        self.main_container_1.add_widget(
            self.sub_container_5,
            0,
            1,
            rowspan=4,
            columnspan=1,
        )

        self.stacked_widget.addWidget(self.main_container_0)
        self.stacked_widget.addWidget(self.main_container_1)

    def toggle_visibility_states(self):
        """
        Toggle the visibility states.
        """
        if self.main_ui_visibility_state == 0:
            self.main_ui_visibility_state = 1
        elif self.main_ui_visibility_state == 1:
            self.main_ui_visibility_state = 0

        self.show_containers()

    def show_containers(self):
        self.stacked_widget.setCurrentIndex(self.main_ui_visibility_state)  # type: ignore
