from constants import (
    SETTINGS_APPLICATION,
    SETTINGS_ORGANIZATION,
    UI_ICON_PATH,
    UI_TITLE,
)
from handlers.events_handler import EventsHandler
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QGridLayout, QMainWindow, QWidget
from ui.modules.button_widget import ButtonWidget
from ui.modules.label_widget import LabelWidget
from ui.modules.settings_list_widget import SettingsListWidget

# TODO: add startup page and add skip function.
# TODO: add save and discard buttons and change the save system to use the buttons instead or realtime saving.


class MainUI(QMainWindow, UIHandler, ThemeHandler, EventsHandler):
    def __init__(self):
        """
        Initialize the MainUI.
        """
        super().__init__()
        self.init_instances()

    def init_instances(self):
        """
        Initialize the instances.
        """
        self.settings = QSettings(SETTINGS_ORGANIZATION, SETTINGS_APPLICATION)
        self.app = QApplication.instance()

        self.events_handler = EventsHandler()
        self.theme_handler = ThemeHandler(self.settings, self.app)

        # Call functions here.
        self.setCentralWidget(QWidget())
        self.init_main_ui()
        self.quit_on_key_press_event()
        self.init_connections()

    def init_connections(self):
        """
        Initialize the connections.
        """
        # EventsHandler:
        self.quit_signal.connect(self.quit_on_key_press_event)
        self.events_handler.toggle_theme_signal.connect(
            self.theme_handler.toggle_theme_handler
        )

    def init_main_ui(self):
        """
        Initialize the main UI.
        """
        # Set up the main window
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        # Add the widget classes
        settings_widget = SettingsListWidget(self)
        button_widget = ButtonWidget(self)
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
        self.center_ui_on_screen_handler(self)
