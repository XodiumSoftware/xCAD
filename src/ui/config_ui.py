from PySide6.QtCore import *
from PySide6.QtWidgets import *

from constants import *


class ConfigUI:
    def config_ui_frame_setup(self):
        """
        Set up the UI frame for configuration options.
        """
        # Create a new frame to hold the layout
        self.config_ui_frame = QFrame()
        self.config_ui_frame.setFrameShape(QFrame.Shape.StyledPanel)

        # config_ui_layout properties
        self.config_ui_layout = QGridLayout(self.config_ui_frame)
        self.config_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.config_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Create a QScrollArea object
        self.scroll_area = QScrollArea()
        self.scroll_area.setVerticalScrollBarPolicy(
            Qt.ScrollBarPolicy.ScrollBarAsNeeded
        )
        self.scroll_area.setHorizontalScrollBarPolicy(
            Qt.ScrollBarPolicy.ScrollBarAsNeeded
        )
        self.scroll_area.setStyleSheet("border: none;")
        self.scroll_area.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
        )

        # Add the QScrollArea to the layout
        self.config_ui_layout.addWidget(self.scroll_area, 0, 0)

        # Call widgets
        self.config_ui_group_box_setup()

        self.config_ui_frame.hide()
        self.config_ui_frame.setMinimumSize(*UI_MINIMUM_SIZE)

    def config_ui_group_box_setup(self):
        """
        Sets up a group box for the configuration UI.
        """
        # Create group box for config
        self.config_group_box = QGroupBox()
        self.config_group_box.setStyleSheet(CONFIG_UI_GROUPBOX_STYLESHEET)
        self.config_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Call widgets
        self.frame_group_box_setup_instance = self.frame_group_box_setup()
        self.profile_group_box_setup_instance = self.profile_group_box_setup()
        self.plate_group_box_setup_instance = self.plate_group_box_setup()
        self.calc_group_box_setup_instance = self.calc_group_box_setup()

        # Create a QFormLayout for the config group box and add the frame_group_box to it
        self.config_layout = QGridLayout()
        self.config_layout.addWidget(self.frame_group_box_setup_instance, 0, 0)
        self.config_layout.addWidget(self.profile_group_box_setup_instance, 1, 0)
        self.config_layout.addWidget(self.plate_group_box_setup_instance, 2, 0)
        self.config_layout.addWidget(self.calc_group_box_setup_instance, 0, 1)

        # Set the config layout as the layout of the config group box
        self.config_group_box.setLayout(self.config_layout)

        # Set the config group box as the widget of the QScrollArea
        self.scroll_area.setWidget(self.config_group_box)

    def frame_group_box_setup(self) -> QGroupBox:
        """
        Creates a group box for a frame with input fields for frame material, length, and height.
        """
        # Create group box for frame
        self.frame_group_box = QGroupBox()
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

    def profile_group_box_setup(self) -> QGroupBox:
        # Create group box for profile
        self.profile_group_box = QGroupBox()
        self.profile_group_box.setStyleSheet(CONFIG_UI_GROUPBOX_STYLESHEET)
        self.profile_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for profile group box
        self.profile_layout = QGridLayout()
        self.profile_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and input field for profile type
        self.profile_type_prefix = QLabel("Profile Type:")

        self.profile_type_input = QLineEdit()
        self.profile_type_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.profile_type_input.setPlaceholderText("Enter profile type")

        self.profile_layout.addWidget(self.profile_type_prefix, 0, 0)
        self.profile_layout.addWidget(self.profile_type_input, 0, 1)

        # Add label and input field for profile length
        self.profile_length_prefix = QLabel("Profile Length:")

        self.profile_length_input = QDoubleSpinBox()
        self.profile_length_input.setRange(*INPUT_RANGE)
        self.profile_length_input.setDecimals(0)
        self.profile_length_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.profile_length_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.profile_length_suffix = QLabel(CONFIG_UI_SUFFIX_MM)

        self.profile_layout.addWidget(self.profile_length_prefix, 1, 0)
        self.profile_layout.addWidget(self.profile_length_input, 1, 1)
        self.profile_layout.addWidget(self.profile_length_suffix, 1, 2)

        # Add label and input field for profile width
        self.profile_width_prefix = QLabel("Profile Width:")

        self.profile_width_input = QDoubleSpinBox()
        self.profile_width_input.setRange(*INPUT_RANGE)
        self.profile_width_input.setDecimals(0)
        self.profile_width_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.profile_width_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.profile_width_suffix = QLabel(CONFIG_UI_SUFFIX_MM)

        self.profile_layout.addWidget(self.profile_width_prefix, 2, 0)
        self.profile_layout.addWidget(self.profile_width_input, 2, 1)
        self.profile_layout.addWidget(self.profile_width_suffix, 2, 2)

        self.profile_group_box.setLayout(self.profile_layout)

        return self.profile_group_box

    def plate_group_box_setup(self) -> QGroupBox:
        # Create group box for plate
        self.plate_group_box = QGroupBox()
        self.plate_group_box.setStyleSheet(CONFIG_UI_GROUPBOX_STYLESHEET)
        self.plate_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for plate group box
        self.plate_layout = QGridLayout()
        self.plate_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and input field for plate material
        self.plate_material_prefix = QLabel("Plate Material:")

        self.plate_material_input = QLineEdit()
        self.plate_material_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.plate_material_input.setPlaceholderText("Enter plate material")

        self.plate_layout.addWidget(self.plate_material_prefix, 0, 0)
        self.plate_layout.addWidget(self.plate_material_input, 0, 1)

        # Add label and input field for plate thickness
        self.plate_thickness_prefix = QLabel("Plate Thickness:")

        self.plate_thickness_input = QDoubleSpinBox()
        self.plate_thickness_input.setRange(*INPUT_RANGE)
        self.plate_thickness_input.setDecimals(0)
        self.plate_thickness_input.setFixedWidth(INPUT_BAR_WIDTH)
        self.plate_thickness_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.plate_thickness_suffix = QLabel(CONFIG_UI_SUFFIX_MM)

        self.plate_layout.addWidget(self.plate_thickness_prefix, 1, 0)
        self.plate_layout.addWidget(self.plate_thickness_input, 1, 1)
        self.plate_layout.addWidget(self.plate_thickness_suffix, 1, 2)

        self.plate_group_box.setLayout(self.plate_layout)

        return self.plate_group_box

    def calc_group_box_setup(self) -> QGroupBox:
        # Create group box for frame calculations
        self.calc_group_box = QGroupBox()
        self.calc_group_box.setStyleSheet(CONFIG_UI_GROUPBOX_STYLESHEET)
        self.calc_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame calculations group box
        self.calc_layout = QFormLayout()
        self.calc_layout.setFieldGrowthPolicy(
            QFormLayout.FieldGrowthPolicy.AllNonFixedFieldsGrow
        )

        # Add label and output field for frame area
        self.frame_area_prefix = QLabel("Frame Area:")

        self.frame_area_output = QLineEdit()
        self.frame_area_output.setReadOnly(True)
        self.frame_area_output.setFixedWidth(INPUT_BAR_WIDTH)
        self.frame_area_output.setPlaceholderText("Auto calculated")
        self.frame_area_output.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.frame_area_suffix = QLabel(CONFIG_UI_SUFFIX_M2)

        def update_frame_area_output():
            frame_area = (
                self.frame_length_input.value() * self.frame_height_input.value()
            ) / 1000000
            locale = QLocale(QLocale.Language.Dutch, QLocale.Country.Netherlands)
            options = QLocale.NumberOption.RejectGroupSeparator
            locale.setNumberOptions(options)
            frame_area_str = "{:.2f}".format(frame_area).replace(".", ",")
            self.frame_area_output.setText(frame_area_str)

        self.frame_length_input.valueChanged.connect(update_frame_area_output)
        self.frame_height_input.valueChanged.connect(update_frame_area_output)

        frame_area_layout = QHBoxLayout()
        frame_area_layout.addWidget(self.frame_area_prefix)
        frame_area_layout.addWidget(self.frame_area_output)
        frame_area_layout.addWidget(self.frame_area_suffix)
        self.calc_layout.addRow(frame_area_layout)

        self.calc_group_box.setLayout(self.calc_layout)

        return self.calc_group_box

    def connect_input_signals(self):
        self.frame_material_input.textChanged.connect(self.save_configurator_inputs)
        self.frame_length_input.valueChanged.connect(self.save_configurator_inputs)
        self.frame_height_input.valueChanged.connect(self.save_configurator_inputs)
        self.profile_type_input.textChanged.connect(self.save_configurator_inputs)
        self.profile_length_input.valueChanged.connect(self.save_configurator_inputs)
        self.profile_width_input.valueChanged.connect(self.save_configurator_inputs)
        self.plate_material_input.textChanged.connect(self.save_configurator_inputs)
        self.plate_thickness_input.valueChanged.connect(self.save_configurator_inputs)

    def save_configurator_inputs(self):
        inputs = [
            ("Frame Material", self.frame_material_input.text()),
            ("Frame Length", self.frame_length_input.value()),
            ("Frame Height", self.frame_height_input.value()),
            ("Profile Type", self.profile_type_input.text()),
            ("Profile Length", self.profile_length_input.value()),
            ("Profile Width", self.profile_width_input.value()),
            ("Plate Material", self.plate_material_input.text()),
            ("Plate Thickness", self.plate_thickness_input.value()),
        ]
        with open(DATA_DIR_FOLDER + DATA_DIR_FILE, "w") as f:
            for name, value in inputs:
                f.write("{}: {}\n".format(name, value))

        print(DEBUG_SAVE_INPUT_PRINT)
        for name, value in inputs:
            print("{}: {}".format(name, value))
