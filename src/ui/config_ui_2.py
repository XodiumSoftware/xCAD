# type: ignore
from PySide6.QtCore import *
from PySide6.QtWidgets import *

from constants import *


class ConfigUI:
    def config_ui_layout_setup(self):
        self.config_ui_layout = QScrollArea()
        self.config_ui_layout.setAlignment(Qt.AlignCenter)
        self.config_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)
