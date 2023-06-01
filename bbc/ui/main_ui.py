from constants import QSETTINGS, STARTUP_PAGE_CHECKBOX_TITLE, UI_ICON_PATH, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings, QTimer, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QCheckBox, QGridLayout, QMainWindow, QWidget
from ui.modules.button_widget import ButtonWidget
from ui.modules.label_widget import LabelWidget
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

        main_ui_layout = QGridLayout()
        main_ui_layout.setVerticalSpacing(5)
        main_ui_layout.setHorizontalSpacing(5)
        main_ui_layout.setContentsMargins(5, 5, 5, 5)

        # Visibility State 0:
        if self.modular_checkbox.isChecked():
            main_ui_layout.addWidget(LabelWidget(1, self), 1, 0)
            main_ui_layout.addWidget(self.modular_checkbox, 2, 0)
            main_ui_layout.addWidget(LabelWidget(0, self), 3, 0)

        # Visibility State 1:
        if not self.modular_checkbox.isChecked():
            main_ui_layout.addWidget(button_widget.button_container_0, 0, 0)
            main_ui_layout.addWidget(settings_widget, 1, 0)
            main_ui_layout.addWidget(button_widget.button_container_1, 2, 0)
            main_ui_layout.addWidget(self.modular_checkbox, 3, 0)
            main_ui_layout.addWidget(LabelWidget(0, self), 4, 0)

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
            checkbox = QCheckBox(STARTUP_PAGE_CHECKBOX_TITLE)
            state = bool(self._settings.value("checkbox_state", True, bool))
            checkbox.setChecked(state)
            checkbox.stateChanged.connect(
                lambda state: self._ui_handler.toggle_ui_visibility_state_handler(self, state)
            )
            self._modular_checkbox = checkbox

        return self._modular_checkbox
