from constants import UI_GEOMETRY, UI_ICON_PATH, UI_MINIMUM_SIZE, UI_TITLE
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget
from ui.modules.widget_modules import WidgetModule
from ui.object_viewer_ui import ObjectViewerUI
from ui.modules.settings_list_widget import SettingsListWidget


class MainUI(QMainWindow, ObjectViewerUI, UIHandler, ThemeHandler, WidgetModule):
    def __init__(self):
        super().__init__()

        # Call functions here.
        self.initMainUI()
        self.quit_on_key_press_event()

        # self.set_theme_handler(KEY_THEME_LIGHT) # FIXME: AttributeError

    def initMainUI(self):
        settings_list_widget = SettingsListWidget(self)

        # Set up the main window
        self.setWindowTitle(UI_TITLE)
        self.setGeometry(*UI_GEOMETRY)
        self.setMinimumSize(*UI_MINIMUM_SIZE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        # Create a new central widget for the main window
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # Create a new layout for the central widget
        layout = QGridLayout(central_widget)

        # Add Modules to the layout
        layout.addWidget(self.button_setup(), 0, 0)
        layout.addWidget(settings_list_widget, 1, 0)

        # Center the window on the primary screen
        self.center_ui_on_screen_handler(self)
