from constants import QSETTINGS, UI_ICON_PATH, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget
from ui.modules.button_module import ButtonModule
from ui.modules.checkbox_module import CheckBoxModule
from ui.modules.container_module import ContainerModule
from ui.modules.label_module import LabelModule
from ui.modules.settings_list_module import TableModule


class MainUI(QMainWindow):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self._settings = QSettings(QSETTINGS)
        self._ui_handler = UIHandler(self)
        self._events_handler = EventsHandler()

        self.setup_instances()

    def setup_instances(self):
        """
        Setup the instances.
        """
        self.setup_main_ui()
        EventsHandler.quit_on_key_press_event(self)
        self._ui_handler.ui_size_handler(self, 600, 400)

    def setup_main_ui(self):
        """
        Setup the MainUI.
        """
        self.setCentralWidget(QWidget())
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        # Setup checkboxes:
        self.checkbox_0 = CheckBoxModule(0)
        self.checkbox_0.onCheckBoxClicked.connect(
            self._events_handler.on_checkbox_clicked
        )

        # Setup buttons:
        self.button_0 = ButtonModule(0)
        self.button_0.onButtonClicked.connect(self._events_handler.on_button_clicked)

        self.button_1 = ButtonModule(1)
        self.button_1.onButtonClicked.connect(self._events_handler.on_button_clicked)

        self.button_2 = ButtonModule(2)
        self.button_2.onButtonClicked.connect(self._events_handler.on_button_clicked)

        self.button_3 = ButtonModule(3)
        self.button_3.onButtonClicked.connect(self._events_handler.on_button_clicked)

        # Setup containers:
        self.button_container_0 = ContainerModule("HBox")
        self.button_container_0.add_widget(self.button_0)
        self.button_container_0.add_stretch()
        self.button_container_0.add_widget(self.button_1)

        self.button_container_1 = ContainerModule("HBox")
        self.button_container_1.add_stretch()
        self.button_container_1.add_widget(self.button_2)
        self.button_container_1.add_widget(self.button_3)

        main_ui_layout = QGridLayout()

        # Visibility State 0:
        if self._settings.value("checkbox_state", True):
            main_ui_layout.addWidget(LabelModule(1), 1, 0)
            main_ui_layout.addWidget(self.checkbox_0, 2, 0)
            main_ui_layout.addWidget(LabelModule(0), 3, 0)

        # Visibility State 1:
        if not self._settings.value("checkbox_state", True):
            main_ui_layout.addWidget(self.button_container_0, 0, 0)
            main_ui_layout.addWidget(TableModule(0), 1, 0)
            main_ui_layout.addWidget(self.button_container_1, 2, 0)
            main_ui_layout.addWidget(self.checkbox_0, 3, 0)
            main_ui_layout.addWidget(LabelModule(0), 4, 0)

        central_widget = QWidget()
        central_widget.setLayout(main_ui_layout)
        self.setCentralWidget(central_widget)

        self._ui_handler.center_ui_on_screen_handler(self)
