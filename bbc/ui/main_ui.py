from events.main_events import *
from handlers.input_handler import *
from handlers.theme_handler import *
from handlers.ui_handler import *
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *
from ui.object_viewer_ui import *

# TODO: MainUI: Implement functions.


class MainUI(QWidget, ObjectViewerUI, Events, UIHandler, InputHandler, ThemeHandler):
    def __init__(self):
        super().__init__()
