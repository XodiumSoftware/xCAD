# type: ignore
from PySide6.QtCore import *
from PySide6.QtWidgets import *

from constants import *


class ConfigUI:
    def config_ui_layout_setup(self):
        """
        Setup config_ui_layout with properties, widgets, and alignments.
        """
        # Create a new frame to hold the layout
        self.config_ui_frame = QFrame(self)
        self.config_ui_frame.setFrameShape(QFrame.Shape.NoFrame)

        # config_ui_layout properties
        self.config_ui_layout = QGridLayout(self.config_ui_frame)
        self.config_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.config_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Add Widgets
        self.config_ui_scroll_area_0()
        self.config_ui_scroll_area_1()

        # Add widgets to config_ui_layout
        self.config_ui_layout.addWidget(self.scroll_area_0, 0, 0)
        self.config_ui_layout.addLayout(self.scroll_area_1, 0, 1)

        # Set widgets alignment
        self.scroll_area_0.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.scroll_area_1.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Add the config frame to the main UI layout
        self.main_ui_layout.addWidget(self.config_ui_frame)

    def config_ui_scroll_area_0(self):
        """
        Sets up the scroll area widget for the config_ui_frame.
        """
        # Create a new layout to hold the scroll area widget
        self.scroll_area_0_layout = QVBoxLayout()

        # Create the scroll area widget
        self.scroll_area_0 = QScrollArea(self)
        self.scroll_area_0.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.scroll_area_0.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)

        # Add the scroll area widget to the layout
        self.scroll_area_0_layout.addWidget(self.scroll_area_0)

        # Set the layout for the scroll area
        self.scroll_area_0.setLayout(self.scroll_area_0_layout)

    # def frame_group_box_setup(self):
    #     pass

    # def profile_group_box_setup(self):
    #     pass

    # def plate_group_box_setup(self):
    #     pass

    def config_ui_scroll_area_1(self):
        """
        Sets up the scroll area widget for the config_ui_frame.
        """
        # Create a new layout to hold the scroll area widget
        self.scroll_area_1_layout = QVBoxLayout()

        # Create the scroll area widget
        self.scroll_area_1 = QScrollArea(self)
        self.scroll_area_1.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.scroll_area_1.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)

        # Add the scroll area widget to the layout
        self.scroll_area_1_layout.addWidget(self.scroll_area_1)

        # Set the layout for the scroll area
        self.scroll_area_1.setLayout(self.scroll_area_1_layout)

    # def calc_group_box_setup(self):
    #     pass
