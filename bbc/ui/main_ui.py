from events.main_events import *
from PySide6.QtCore import *


# TODO: Make MainUI work with the new input_handler and theme_handler.
class MainUI(QWidget, Events):
    def __init__(self):
        super().__init__()
        pass

    def keyPressEvent(self, event):
        Events.keyPressEvent(self, event)
