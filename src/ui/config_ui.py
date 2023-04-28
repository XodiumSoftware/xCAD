import configparser
import os
from collections import defaultdict

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *


class ConfigUI:
    def __init__(self):
        """
        Initialize the configurator application window.
        """
        self.config_ui_frame_setup()
        print("[DEBUG] ConfigUI initialized.")

        self.input_handler()

        # Connect signals and slots for input fields
        self.frame_material_input.textChanged.connect(self.input_handler)
        self.frame_length_input.valueChanged.connect(self.input_handler)
        self.frame_height_input.valueChanged.connect(self.input_handler)
        self.profile_type_input.textChanged.connect(self.input_handler)
        self.profile_length_input.valueChanged.connect(self.input_handler)
        self.profile_width_input.valueChanged.connect(self.input_handler)
        self.plate_material_input.textChanged.connect(self.input_handler)
        self.plate_thickness_input.valueChanged.connect(self.input_handler)

    def input_handler(self):
        """
        Load the inputs from the config file.
        """
        file_path = os.path.join(DATA_DIR_FOLDER, DATA_DIR_FILE)
        if not os.path.isfile(file_path):
            print(f"[DEBUG] File not found: {file_path}")
            return

        print(f"[DEBUG] Loading inputs from file: {file_path}")
        config = configparser.RawConfigParser()

        # Read file and create inputs section if it doesn't exist
        with open(file_path) as f:
            config.read_file(f)
        config.setdefault("inputs", defaultdict(str))

        # Set default values for missing keys
        required_keys = [
            "frame_material",
            "frame_length",
            "frame_height",
            "profile_type",
            "profile_length",
            "profile_width",
            "plate_material",
            "plate_thickness",
        ]
        for key in required_keys:
            config["inputs"].setdefault(key, "")

        # Convert inputs to appropriate types
        try:
            values = {
                "frame_length": float,
                "frame_height": float,
                "profile_length": float,
                "profile_width": float,
                "plate_thickness": float,
            }
            for key, converter in values.items():
                value = config["inputs"][key].strip()
                if not value:
                    value = 0.0
                config["inputs"][key] = str(converter(value))
        except ValueError:
            pass

        # Set input values
        self.frame_material_input.setText(config["inputs"]["frame_material"])
        self.frame_length_input.setValue(float(config["inputs"]["frame_length"]))
        self.frame_height_input.setValue(float(config["inputs"]["frame_height"]))
        self.profile_type_input.setText(config["inputs"]["profile_type"])
        self.profile_length_input.setValue(float(config["inputs"]["profile_length"]))
        self.profile_width_input.setValue(float(config["inputs"]["profile_width"]))
        self.plate_material_input.setText(config["inputs"]["plate_material"])
        self.plate_thickness_input.setValue(float(config["inputs"]["plate_thickness"]))

        # Write changes back to file
        with open(file_path, "w") as f:
            # Update inputs with new values
            config["inputs"]["frame_material"] = self.frame_material_input.text()
            config["inputs"]["frame_length"] = str(self.frame_length_input.value())
            config["inputs"]["frame_height"] = str(self.frame_height_input.value())
            config["inputs"]["profile_type"] = self.profile_type_input.text()
            config["inputs"]["profile_length"] = str(self.profile_length_input.value())
            config["inputs"]["profile_width"] = str(self.profile_width_input.value())
            config["inputs"]["plate_material"] = self.plate_material_input.text()
            config["inputs"]["plate_thickness"] = str(
                self.plate_thickness_input.value()
            )

            # Write changes to file
            config.write(f)

    def config_ui_frame_setup(self):
        """
        Set up the UI frame for configuration options.
        """
        # Create a new frame to hold the layout
        self.config_ui_frame = QFrame()
        self.config_ui_frame.setObjectName("config_ui_frame")
        self.config_ui_frame.setFrameShape(QFrame.Shape.StyledPanel)
        self.config_ui_frame.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
        )

        # config_ui_layout properties
        self.config_ui_frame_layout = QGridLayout(self.config_ui_frame)
        self.config_ui_frame_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

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
        self.config_ui_frame_layout.addWidget(self.scroll_area, 0, 0)

        # Call widgets
        self.config_ui_group_box_setup()

        self.config_ui_frame.hide()

    def config_ui_group_box_setup(self):
        """
        Sets up a group box for the configuration UI.
        """
        # Create group box for config
        self.config_group_box = QGroupBox()
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

    def label_input_pair_helper(
        self,
        label_text: str,
        input_object: QWidget,
        row: int,
        layout: QGridLayout,
        suffix_text: str = "",
    ):
        """
        Helper function to create a label-input field pair and add it to a given grid layout.
        """
        prefix_label = QLabel(label_text)
        input_object.setFixedWidth(INPUT_BAR_WIDTH)

        if suffix_text:
            suffix_label = QLabel(suffix_text)
            layout.addWidget(suffix_label, row, 2)

        layout.addWidget(prefix_label, row, 0)
        layout.addWidget(input_object, row, 1)

    def frame_group_box_setup(self) -> QGroupBox:
        """
        Creates a group box for a frame with input fields for frame material, length, and height.
        """
        # Create group box for frame
        self.frame_group_box = QGroupBox()
        self.frame_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame group box
        self.frame_layout = QGridLayout()
        self.frame_layout.setColumnStretch(0, 1)

        # Add label and input field for frame material
        self.frame_material_input = QLineEdit()
        self.frame_material_input.setObjectName("frame_material_input")
        self.frame_material_input.setPlaceholderText("WOOD")
        self.frame_material_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.label_input_pair_helper(
            "Frame Material:", self.frame_material_input, 0, self.frame_layout
        )

        # Add label and input field for frame length
        self.frame_length_input = QDoubleSpinBox()
        self.frame_length_input.setObjectName("frame_length_input")
        self.frame_length_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.frame_length_input.setButtonSymbols(
            QAbstractSpinBox.ButtonSymbols.NoButtons
        )
        self.frame_length_input.setRange(*INPUT_RANGE)
        self.frame_length_input.setDecimals(0)
        self.label_input_pair_helper(
            "Frame Length:",
            self.frame_length_input,
            1,
            self.frame_layout,
            CONFIG_UI_SUFFIX_MM,
        )

        # Add label and input field for frame height
        self.frame_height_input = QDoubleSpinBox()
        self.frame_height_input.setObjectName("frame_height_input")
        self.frame_height_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.frame_height_input.setButtonSymbols(
            QAbstractSpinBox.ButtonSymbols.NoButtons
        )
        self.frame_height_input.setRange(*INPUT_RANGE)
        self.frame_height_input.setDecimals(0)
        self.label_input_pair_helper(
            "Frame Height:",
            self.frame_height_input,
            2,
            self.frame_layout,
            CONFIG_UI_SUFFIX_MM,
        )

        self.frame_group_box.setLayout(self.frame_layout)

        return self.frame_group_box

    def profile_group_box_setup(self) -> QGroupBox:
        """
        Creates a group box for a profile with input fields for profile type, length, and height.
        """
        # Create group box for profile
        self.profile_group_box = QGroupBox()
        self.profile_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for profile group box
        self.profile_layout = QGridLayout()
        self.profile_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and input field for profile type
        self.profile_type_input = QLineEdit()
        self.profile_type_input.setObjectName("profile_type_input")
        self.profile_type_input.setPlaceholderText("SLS")
        self.profile_type_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.label_input_pair_helper(
            "Profile Type:", self.profile_type_input, 0, self.profile_layout
        )

        # Add label and input field for profile length
        self.profile_length_input = QDoubleSpinBox()
        self.profile_length_input.setObjectName("profile_length_input")
        self.profile_length_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.profile_length_input.setButtonSymbols(
            QAbstractSpinBox.ButtonSymbols.NoButtons
        )
        self.profile_length_input.setRange(*INPUT_RANGE)
        self.profile_length_input.setDecimals(0)
        self.label_input_pair_helper(
            "Profile Length:",
            self.profile_length_input,
            1,
            self.profile_layout,
            CONFIG_UI_SUFFIX_MM,
        )

        # Add label and input field for profile width
        self.profile_width_input = QDoubleSpinBox()
        self.profile_width_input.setObjectName("profile_width_input")
        self.profile_width_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.profile_width_input.setButtonSymbols(
            QAbstractSpinBox.ButtonSymbols.NoButtons
        )
        self.profile_width_input.setRange(*INPUT_RANGE)
        self.profile_width_input.setDecimals(0)
        self.label_input_pair_helper(
            "Profile Width:",
            self.profile_width_input,
            2,
            self.profile_layout,
            CONFIG_UI_SUFFIX_MM,
        )

        self.profile_group_box.setLayout(self.profile_layout)

        return self.profile_group_box

    def plate_group_box_setup(self) -> QGroupBox:
        """
        Creates a group box for a plate with input fields for plate material, thickness, and height.
        """
        # Create group box for plate
        self.plate_group_box = QGroupBox()
        self.plate_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for plate group box
        self.plate_layout = QGridLayout()
        self.plate_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and input field for plate material
        self.plate_material_input = QLineEdit()
        self.plate_material_input.setObjectName("plate_material_input")
        self.plate_material_input.setPlaceholderText("OSBIII")
        self.plate_material_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.label_input_pair_helper(
            "Plate Material:", self.plate_material_input, 0, self.plate_layout
        )

        # Add label and input field for plate thickness
        self.plate_thickness_input = QDoubleSpinBox()
        self.plate_thickness_input.setObjectName("plate_thickness_input")
        self.plate_thickness_input.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.plate_thickness_input.setButtonSymbols(
            QAbstractSpinBox.ButtonSymbols.NoButtons
        )
        self.plate_thickness_input.setRange(*INPUT_RANGE)
        self.plate_thickness_input.setDecimals(0)
        self.label_input_pair_helper(
            "Plate Thickness:",
            self.plate_thickness_input,
            1,
            self.plate_layout,
            CONFIG_UI_SUFFIX_MM,
        )

        self.plate_group_box.setLayout(self.plate_layout)

        return self.plate_group_box

    def calc_group_box_setup(self) -> QGroupBox:
        """
        Creates a group box for a calculation with input fields for frame area and plate area.
        """
        # Create the group box and set its alignment
        self.calc_group_box = QGroupBox()
        self.calc_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create the form layout and set its growth policy
        self.calc_layout = QGridLayout(self.calc_group_box)
        self.calc_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Call the label_input_pair_helper function to create the label and output field
        self.frame_area_output = QLineEdit()
        self.frame_area_output.setObjectName("frame_area_output")
        self.frame_area_output.setReadOnly(True)
        self.frame_area_output.setFixedWidth(INPUT_BAR_WIDTH)
        self.frame_area_output.setPlaceholderText("Auto calculated")
        self.frame_area_output.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.label_input_pair_helper(
            "Frame Area:",
            self.frame_area_output,
            0,
            self.calc_layout,
            CONFIG_UI_SUFFIX_M2,
        )

        # Connect signals and slots
        self.frame_length_input.valueChanged.connect(self.update_frame_area_output)
        self.frame_height_input.valueChanged.connect(self.update_frame_area_output)

        # Call update_frame_area_output once to set initial value of output
        self.update_frame_area_output()

        return self.calc_group_box

    def update_frame_area_output(self):
        """
        Updates the frame area output field.
        """
        frame_length = self.frame_length_input.value()
        frame_height = self.frame_height_input.value()
        frame_area = (frame_length * frame_height) / 1000000.0
        frame_area_str = "{:.2f}".format(frame_area).replace(".", ",")
        self.frame_area_output.setText(frame_area_str)
