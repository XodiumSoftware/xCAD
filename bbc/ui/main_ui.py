from constants import *
from events.main_events import *
from handlers.theme_handler import *
from handlers.ui_handler import *
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


# TODO: Make MainUI work with the new input_handler and theme_handler.
class MainUI(QWidget, Events):
    def __init__(self):
        super().__init__()
        pass

    def keyPressEvent(self, event):
        Events.keyPressEvent(self, event)
