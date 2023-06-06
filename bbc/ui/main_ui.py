from constants import QSETTINGS, UI_ICON_PATH, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QCheckBox, QGridLayout, QMainWindow, QWidget
from ui.modules.button_module import ButtonModule
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

        # Setup containers:
        button_container_0 = ContainerModule("HBox")
        button_container_0.add_widget(ButtonModule(0))
        button_container_0.add_stretch()
        button_container_0.add_widget(ButtonModule(1))

        button_container_1 = ContainerModule("HBox")
        button_container_1.add_stretch()
        button_container_1.add_widget(ButtonModule(2))
        button_container_1.add_widget(ButtonModule(3))

        main_ui_layout = QGridLayout()

        # Visibility State 0:
        if self._settings.value("checkbox_state", True):
            main_ui_layout.addWidget(LabelModule(1, self), 1, 0)
            main_ui_layout.addWidget(self.modular_checkbox, 2, 0)
            main_ui_layout.addWidget(LabelModule(0, self), 3, 0)

        # Visibility State 1:
        if not self._settings.value("checkbox_state", True):
            main_ui_layout.addWidget(button_container_0, 0, 0)
            main_ui_layout.addWidget(TableModule(0, self), 1, 0)
            main_ui_layout.addWidget(button_container_1, 2, 0)
            main_ui_layout.addWidget(self.modular_checkbox, 3, 0)
            main_ui_layout.addWidget(LabelModule(0, self), 4, 0)

        central_widget = QWidget()
        central_widget.setLayout(main_ui_layout)
        self.setCentralWidget(central_widget)

        self._ui_handler.center_ui_on_screen_handler(self)

    @property
    def modular_checkbox(self):
        """
        Create and configure the checkbox.
        """
        if not hasattr(self, "_modular_checkbox"):
            checkbox = QCheckBox("Toggle startup page")
            state = bool(self._settings.value("checkbox_state", True))
            checkbox.setChecked(state)
            checkbox.stateChanged.connect(self._ui_handler.toggle_ui_state_handler)
            self._modular_checkbox = checkbox

        return self._modular_checkbox
