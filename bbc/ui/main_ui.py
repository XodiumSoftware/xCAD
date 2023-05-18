from constants import UI_GEOMETRY, UI_ICON_PATH, UI_MINIMUM_SIZE, UI_TITLE
from handlers.input_handler import InputHandler
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget
from ui.modules.widget_module import WidgetModule
from ui.object_viewer_ui import ObjectViewerUI
from ui.modules.widget_module import WidgetModule


class MainUI(
    QMainWindow, ObjectViewerUI, UIHandler, InputHandler, ThemeHandler, WidgetModule
):
    def __init__(self):
        super().__init__()

        # Call functions here.
        self.setup_ui()
        self.quit_on_key_press_event()

        # self.set_theme_handler(KEY_THEME_LIGHT) # FIXME: AttributeError

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
