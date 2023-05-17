from constants import *
from handlers.events_handler import *
from handlers.input_handler import *
from handlers.theme_handler import *
from handlers.ui_handler import *
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *
from ui.modules.widget_module import *
from ui.object_viewer_ui import *


class MainUI(
    QMainWindow, ObjectViewerUI, EventsHandler, UIHandler, InputHandler, ThemeHandler
):
    def __init__(self):
        super().__init__()
        print("Initializing main UI")

        # Call functions here.
        self.setup_ui()
        self.quit_on_key_press_event()
        self.set_theme_handler(KEY_THEME_LIGHT)

        print("Finished initializing main UI")

    def setup_ui(self):
        # Set up the main window
        self.setWindowTitle(UI_TITLE)
        self.setGeometry(*UI_GEOMETRY)
        self.setMinimumSize(*UI_MINIMUM_SIZE)

        # Create a new central widget for the main window
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # Create a new layout for the central widget
        layout = QVBoxLayout(central_widget)

        # Add the WidgetModule to the layout
        widget_module = WidgetModule(self)
        layout.addWidget(widget_module)

        self.main_ui_icon()

        # Center the window on the primary screen
        self.center_ui_on_screen_handler(self)

    def main_ui_icon(self):
        QApplication.setWindowIcon(QIcon(UI_ICON_PATH))
