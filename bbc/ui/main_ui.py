from constants import QSETTINGS, UI_ICON_PATH, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget
from ui.modules.button_widget import ButtonWidget
from ui.modules.checkbox_module import CheckBoxModule
from ui.modules.label_module import LabelModule
from ui.modules.settings_list_widget import SettingsListWidget


class MainUI(QMainWindow):
    toggle_theme_signal = Signal(int)

    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self._settings = QSettings(QSETTINGS)
        self._current_theme = None
        self._ui_handler = UIHandler()
        self._events_handler = EventsHandler(self._current_theme)

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

        settings_widget = SettingsListWidget()

        button_widget = ButtonWidget(
            self._events_handler, self._settings, self._current_theme
        )

        checkbox_module = CheckBoxModule(0, self)

        main_ui_layout = QGridLayout()
        main_ui_layout.setVerticalSpacing(5)
        main_ui_layout.setHorizontalSpacing(5)
        main_ui_layout.setContentsMargins(5, 5, 5, 5)

        # Visibility State 0:
        if checkbox_module.modular_checkbox.isChecked():
            main_ui_layout.addWidget(LabelModule(1, self), 1, 0)
            main_ui_layout.addWidget(checkbox_module, 2, 0)
            main_ui_layout.addWidget(LabelModule(0, self), 3, 0)

        # Visibility State 1:
        if not checkbox_module.modular_checkbox.isChecked():
            main_ui_layout.addWidget(button_widget.button_container_0, 0, 0)
            main_ui_layout.addWidget(settings_widget, 1, 0)
            main_ui_layout.addWidget(button_widget.button_container_1, 2, 0)
            main_ui_layout.addWidget(checkbox_module, 3, 0)
            main_ui_layout.addWidget(LabelModule(0, self), 4, 0)

        central_widget = QWidget()
        central_widget.setLayout(main_ui_layout)
        self.setCentralWidget(central_widget)

        self._ui_handler.center_ui_on_screen_handler(self)
