from constants import UI_ICON_PATH, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget
from ui.modules.button_widget import ButtonWidget
from ui.modules.label_widget import LabelWidget
from ui.modules.settings_list_widget import SettingsListWidget

# TODO: Add startup page.


class MainUI(QMainWindow):
    toggle_theme_signal = Signal(int)

    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()

        self._settings = QSettings("Qerimi_Engineering", "AutoFrameCAD")
        self._current_theme = None
        self._theme_handler = ThemeHandler(self._settings, self._current_theme)
        self._current_theme = self._theme_handler.get_current_theme()
        self._ui_handler = UIHandler()
        self._events_handler = EventsHandler(self._current_theme)

        self.init_instances()

    def init_instances(self):
        """
        Initialize the instances.
        """
        # Call functions here.
        self.init_main_ui()
        self._theme_handler.init_theme_handler(self)
        EventsHandler.quit_on_key_press_event(self)

    def init_main_ui(self):
        """
        Initialize the main UI.
        """
        # Set up the main window
        self.setCentralWidget(QWidget())
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        # Add the widget classes
        settings_widget = SettingsListWidget(self)
        button_widget = ButtonWidget(
            self._events_handler, self._settings, self._current_theme
        )
        label_widget = LabelWidget(0, self)

        # Create a new layout for the central widget
        main_ui_layout = QGridLayout()
        main_ui_layout.setVerticalSpacing(5)
        main_ui_layout.setHorizontalSpacing(5)
        main_ui_layout.setContentsMargins(5, 5, 5, 5)

        # Add Modules to the layout
        main_ui_layout.addWidget(button_widget.button_container_0, 0, 0)
        main_ui_layout.addWidget(settings_widget, 1, 0)
        main_ui_layout.addWidget(button_widget.button_container_1, 2, 0)
        main_ui_layout.addWidget(label_widget, 3, 0)

        # Set the central widget
        central_widget = QWidget()
        central_widget.setLayout(main_ui_layout)
        self.setCentralWidget(central_widget)

        # Calculate the desired width of the main window
        total_columns_width = settings_widget.get_total_columns_width()
        total_columns_width += main_ui_layout.horizontalSpacing() * (
            settings_widget.table_widget.columnCount() - 1
        )
        window_width = (
            total_columns_width
            + main_ui_layout.contentsMargins().left()
            + main_ui_layout.contentsMargins().right()
        )

        # Set the initial width of the main window and allow manual resizing
        self.resize(window_width, self.height())

        # Center the window on the primary screen
        self._ui_handler.center_ui_on_screen_handler(self)
