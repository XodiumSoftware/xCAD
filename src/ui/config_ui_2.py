from PySide6.QtCore import *
from PySide6.QtWidgets import *

from constants import *


class ConfigUI:
    def config_ui_layout_setup(self):
        # Create a new frame to hold the layout
        self.config_ui_frame = QFrame()
        self.config_ui_frame.setFrameShape(QFrame.Shape.StyledPanel)

        # config_ui_layout properties
        self.config_ui_layout = QGridLayout(self.config_ui_frame)
        self.config_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.config_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Create a QScrollArea object
        scroll_area = QScrollArea()
        scroll_area.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOn)
        scroll_area.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        scroll_area.setStyleSheet("border: none;")
        scroll_area.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
        )

        # Call create_frame_group_box to create the QGroupBox for the frame
        frame_group_box = self.create_frame_group_box()

        # Set the frame_group_box as the widget of the QScrollArea
        scroll_area.setWidget(frame_group_box)

        # Add the QScrollArea to the layout
        self.config_ui_layout.addWidget(scroll_area, 0, 0)

        self.config_ui_frame.hide()

    def create_frame_group_box(self) -> QGroupBox:
        # Create group box for frame
        self.frame_group_box = QGroupBox()
        self.frame_group_box.setTitle("Frame")
        self.frame_group_box.setStyleSheet(CONFIG_UI_GROUPBOX_STYLESHEET)
        self.frame_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame group box
        self.frame_layout = QGridLayout()
        self.frame_layout.setColumnStretch(0, 1)

        # Add label and input field for frame material
        self.frame_material_prefix = QLabel("Frame Material:")

        self.frame_material_input = QLineEdit()
        self.frame_material_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.frame_material_input.setPlaceholderText("Enter frame material")

        self.frame_layout.addWidget(self.frame_material_prefix, 0, 0)
        self.frame_layout.addWidget(self.frame_material_input, 0, 1)

        # Add label and input field for frame length
        self.frame_length_prefix = QLabel("Frame Length:")

        self.frame_length_input = QDoubleSpinBox()
        self.frame_length_input.setRange(*INPUT_RANGE)
        self.frame_length_input.setDecimals(0)
        self.frame_length_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.frame_length_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.frame_length_suffix = QLabel(CONFIG_UI_SUFFIX_MM)

        self.frame_layout.addWidget(self.frame_length_prefix, 1, 0)
        self.frame_layout.addWidget(self.frame_length_input, 1, 1)
        self.frame_layout.addWidget(self.frame_length_suffix, 1, 2)

        # Add label and input field for frame height
        self.frame_height_prefix = QLabel("Frame Height:")

        self.frame_height_input = QDoubleSpinBox()
        self.frame_height_input.setRange(*INPUT_RANGE)
        self.frame_height_input.setDecimals(0)
        self.frame_height_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.frame_height_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.frame_height_suffix = QLabel(CONFIG_UI_SUFFIX_MM)

        self.frame_layout.addWidget(self.frame_height_prefix, 2, 0)
        self.frame_layout.addWidget(self.frame_height_input, 2, 1)
        self.frame_layout.addWidget(self.frame_height_suffix, 2, 2)

        self.frame_group_box.setLayout(self.frame_layout)

        return self.frame_group_box

    # def profile_group_box_setup(self):
    #     pass

    # def plate_group_box_setup(self):
    #     pass

    # def calc_group_box_setup(self):
    #     pass
