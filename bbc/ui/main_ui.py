from constants import UI_ICON_PATH, UI_MINIMUM_SIZE, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QGridLayout, QMainWindow, QWidget
from ui.modules.button_widget import ButtonWidget
from ui.modules.settings_list_widget import SettingsListWidget
from ui.object_viewer_ui import ObjectViewerUI


class MainUI(QMainWindow, ObjectViewerUI, UIHandler, ThemeHandler, EventsHandler):
    def __init__(self):
        super().__init__()

        # Call functions here.
        self.setCentralWidget(QWidget())
        self.initMainUI()
        self.quit_on_key_press_event()

    def initMainUI(self):
        # Set up the main window
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        settings_widget = SettingsListWidget(self)
        total_columns_width = settings_widget.get_total_columns_width()

        button_widget = ButtonWidget(self)

        # Create a new layout for the central widget
        central_layout = QGridLayout()
        central_layout.setVerticalSpacing(
            5
        )  # Adjust the vertical spacing here (e.g., 5 pixels)
        central_layout.setHorizontalSpacing(
            5
        )  # Adjust the horizontal spacing here (e.g., 5 pixels)
        central_layout.setContentsMargins(5, 5, 5, 5)  # Adjust the margins here

        # Add Modules to the layout
        central_layout.addWidget(button_widget, 0, 0)
        central_layout.addWidget(settings_widget, 1, 0)

        # Set the central widget
        central_widget = QWidget()
        central_widget.setLayout(central_layout)
        self.setCentralWidget(central_widget)

        # Calculate the desired width of the main window
        total_columns_width += central_layout.horizontalSpacing() * (
            settings_widget.table_widget.columnCount() - 1
        )
        window_width = (
            total_columns_width
            + central_layout.contentsMargins().left()
            + central_layout.contentsMargins().right()
        )

        # Set the initial width of the main window and allow manual resizing
        self.resize(window_width, self.height())

        # Center the window on the primary screen
        self.center_ui_on_screen_handler(self)
