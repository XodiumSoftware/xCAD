from constants import *
from events.main_events import *
from handlers.input_handler import *
from handlers.theme_handler import *
from handlers.ui_handler import *
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *
from ui.modules.widget_module import *
from ui.object_viewer_ui import *


class MainUI(
    QMainWindow, ObjectViewerUI, Events, UIHandler, InputHandler, ThemeHandler
):
    def __init__(self):
        super().__init__()
        self.setup_ui()

    def setup_ui(self):
        # Set up the main window
        self.setWindowTitle(UI_TITLE)
        self.setGeometry(*UI_GEOMETRY)

        # Create a new central widget for the main window
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # Create a new layout for the central widget
        layout = QVBoxLayout(central_widget)

        # Add the WidgetModule to the layout
        widget_module = WidgetModule(self)
        layout.addWidget(widget_module)

        self.main_ui_icon()

    def main_ui_icon(self):
        QApplication.setWindowIcon(QIcon(UI_ICON_PATH))
