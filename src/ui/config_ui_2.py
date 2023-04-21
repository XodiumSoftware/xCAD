# type: ignore
from PySide6.QtCore import *
from PySide6.QtWidgets import *

from constants import *


class ConfigUI:
    def config_ui_layout_setup(self):
        """
        Setup config_ui_layout with properties, widgets, and alignments.
        """
        # config_ui_layout properties
        self.config_ui_layout = QGridLayout()()
        self.config_ui_layout.setAlignment(Qt.AlignCenter)
        self.config_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Add Widgets
        self.config_ui_scroll_area_0()
        self.config_ui_scroll_area_1()

        # Add widgets to config_ui_layout
        self.config_ui_layout.addWidget(self.config_ui_scroll_area_0, 0, 0)
        self.config_ui_layout.addWidget(self.config_ui_scroll_area_1, 0, 1)

        # Set widgets alignment
        self.config_ui_scroll_area_0.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.config_ui_scroll_area_1.setAlignment(Qt.AlignmentFlag.AlignCenter)

    def config_ui_scroll_area_0(self):
        pass

    def frame_group_box_setup(self):
        pass

    def profile_group_box_setup(self):
        pass

    def plate_group_box_setup(self):
        pass

    def config_ui_scroll_area_1(self):
        pass

    def calc_group_box_setup(self):
        pass
