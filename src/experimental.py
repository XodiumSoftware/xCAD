import os
from typing import Dict, Union

from PySide6.QtCore import Qt
from PySide6.QtGui import QFont
from PySide6.QtWidgets import (
    QApplication,
    QDoubleSpinBox,
    QGridLayout,
    QGroupBox,
    QLabel,
    QLineEdit,
    QMainWindow,
    QSizePolicy,
    QWidget,
)

from constants import (
    CONFIG_UI_TITLE,
    COPYRIGHT_LABEL,
    COPYRIGHT_LABEL_SIZE,
    COPYRIGHT_LABEL_STYLE,
    UI_FONT_TYPE,
)


class ConfigUI(QMainWindow):
    def __init__(self):
        """
        Initializes the Configurator UI window.
        """
        super().__init__()
        self.setWindowFlags(
            Qt.WindowType.WindowTitleHint
            | Qt.WindowType.CustomizeWindowHint
            | Qt.WindowType.MSWindowsFixedSizeDialogHint
        )
        self.setWindowTitle(CONFIG_UI_TITLE)

        self.frame_group_box = None
        self.frame_layout = None
        self.row = 0
        self.saved_inputs = {}

        # Create vertical layout for main window
        self.config_layout = QGridLayout()

        # Create labels for the configuration ui layout
        self.main_group_box = self.create_main_group_box()
        self.crlabel = self.create_crlabel()

        # Add group boxes and labels to the configuration ui layout
        self.config_layout.addWidget(self.main_group_box, 0, 0)
        self.config_layout.addWidget(self.crlabel, 1, 0)

        # Set main layout for widget
        self.widget = QWidget()
        self.widget.setLayout(self.config_layout)
        self.setCentralWidget(self.widget)

        self.connect_input_widgets()

    def keyPressEvent(self, event):
        """
        This function is called when certain keys are pressed.
        """
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
        else:
            super().keyPressEvent(event)

    def create_main_group_box(self) -> QGroupBox:
        """
        Creates a QGroupBox for the main window,
        with a grid layout and several sub-group boxes and labels.
        """
        # Create group box for main
        self.main_group_box = QGroupBox(self)
        self.main_group_box.setObjectName("mainGroupBox")
        self.main_group_box.setStyleSheet("#mainGroupBox { border: none; }")

        self.main_group_box.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
        )
        self.main_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create grid layout for main group box
        self.main_group_box_layout = QGridLayout(self)

        # Create group boxes and labels for the main group box layout
        # First row
        self.frame_group_box = self.create_frame_group_box()
        self.profile_group_box = self.create_profile_group_box()
        self.plate_group_box = self.create_plate_group_box()

        # Second row
        self.frame_group_calc_box = self.create_frame_group_calc_box()

        # Add group boxes and labels to main layout
        # First row
        self.main_group_box_layout.addWidget(self.frame_group_box, 0, 0)
        self.main_group_box_layout.addWidget(self.profile_group_box, 1, 0)
        self.main_group_box_layout.addWidget(self.plate_group_box, 2, 0)

        # Second row
        self.main_group_box_layout.addWidget(self.frame_group_calc_box, 0, 1)

        self.main_group_box.setLayout(self.main_group_box_layout)

        return self.main_group_box

    def create_frame_group_box(self) -> QGroupBox:
        """
        Creates a QGroupBox for the Frame section of the UI.
        """
        # Create group box for frame
        self.frame_group_box = QGroupBox(self)
        self.frame_group_box.setTitle("Frame")
        self.frame_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.frame_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame group box
        self.frame_layout = QGridLayout(self)
        self.frame_layout.setColumnStretch(0, 1)

        # Define default inputs
        default_inputs: Dict[str, Union[str, int]] = {
            "frame_material_input": "",
            "frame_length_input": 0,
            "frame_height_input": 0,
        }

        # Check if saved inputs exist
        if self.saved_inputs is not None and "frame" in self.saved_inputs:
            saved_inputs = self.saved_inputs["frame"]
        else:
            saved_inputs = {}

        # Loop through each input field
        for field_name, default_value in default_inputs.items():
            # Check if the saved input exists
            if field_name in saved_inputs:
                input_value = saved_inputs[field_name]
            else:
                input_value = default_value

            # Create label and input field
            label = QLabel(field_name.replace("_", " ").capitalize() + ":")
            input_field = None

            # Create the appropriate input field widget based on the field name
            if "material" in field_name:
                input_field = QLineEdit()
                input_field.setFixedWidth(100)
            elif "length" in field_name or "height" in field_name:
                input_field = QDoubleSpinBox()
                input_field.setRange(0, 1e100)
                input_field.setDecimals(0)
                input_field.setFixedWidth(100)
                input_field.setAlignment(Qt.AlignmentFlag.AlignRight)

                suffix_label = QLabel("mm")
                input_field.setSuffix(" mm")
                input_field.setPrefix(
                    f"Enter {field_name.replace('_', ' ').capitalize()}: "
                )
                self.frame_layout.addWidget(
                    suffix_label,
                    self.frame_layout.rowCount(),
                    2,
                    Qt.AlignmentFlag.AlignRight,
                )

            if input_field is not None:
                # Set the input field value
                if isinstance(input_field, QLineEdit):
                    input_field.setText(str(input_value))
                elif isinstance(input_field, QDoubleSpinBox):
                    input_field.setValue(float(input_value))

                # Add the label and input field to the layout
                self.frame_layout.addWidget(label, self.frame_layout.rowCount(), 0)
                self.frame_layout.addWidget(
                    input_field, self.frame_layout.rowCount() - 1, 1
                )

        self.frame_group_box.setLayout(self.frame_layout)

        return self.frame_group_box

    def create_profile_group_box(self) -> QGroupBox:
        """
        Creates a QGroupBox for the Profile section of the UI.
        """
        # Create group box for profile
        self.profile_group_box = QGroupBox(self)
        self.profile_group_box.setTitle("Profile")
        self.profile_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.profile_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for profile group box
        self.profile_layout = QGridLayout(self)
        self.profile_layout.setColumnStretch(0, 1)

        # Define default inputs
        default_inputs: Dict[str, Union[str, int]] = {
            "profile_type_input": "",
            "profile_length_input": 0,
            "profile_width_input": 0,
        }

        # Check if saved inputs exist
        if self.saved_inputs is not None and "profile" in self.saved_inputs:
            saved_inputs = self.saved_inputs["profile"]
        else:
            saved_inputs = {}

        # Loop through each input field
        for field_name, default_value in default_inputs.items():
            # Check if the saved input exists
            if field_name in saved_inputs:
                input_value = saved_inputs[field_name]
            else:
                input_value = default_value

            # Create label and input field
            label = QLabel(field_name.replace("_", " ").capitalize() + ":")
            input_field = None

            # Create the appropriate input field widget based on the field name
            if "type" in field_name:
                input_field = QLineEdit()
                input_field.setFixedWidth(100)
            elif "length" in field_name or "width" in field_name:
                input_field = QDoubleSpinBox()
                input_field.setRange(0, 1e100)
                input_field.setDecimals(0)
                input_field.setFixedWidth(100)
                input_field.setAlignment(Qt.AlignmentFlag.AlignRight)

                suffix_label = QLabel("mm")
                input_field.setSuffix(" mm")
                input_field.setPrefix(
                    f"Enter {field_name.replace('_', ' ').capitalize()}: "
                )
                self.profile_layout.addWidget(
                    suffix_label,
                    self.profile_layout.rowCount(),
                    2,
                    Qt.AlignmentFlag.AlignRight,
                )

            if input_field is not None:
                # Set the input field value
                if isinstance(input_field, QLineEdit):
                    input_field.setText(str(input_value))
                elif isinstance(input_field, QDoubleSpinBox):
                    input_field.setValue(float(input_value))

                # Add the label and input field to the layout
                self.profile_layout.addWidget(label, self.profile_layout.rowCount(), 0)
                self.profile_layout.addWidget(
                    input_field, self.profile_layout.rowCount() - 1, 1
                )

        self.profile_group_box.setLayout(self.profile_layout)

        return self.profile_group_box

    def create_plate_group_box(self) -> QGroupBox:
        """
        Creates a group box for plate inputs with labels and input fields for plate material and thickness.
        """
        # Create group box for plate
        self.plate_group_box = QGroupBox(self)
        self.plate_group_box.setTitle("Plate")
        self.plate_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.plate_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for plate group box
        self.plate_layout = QGridLayout(self)
        self.plate_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and input field for plate material
        self.plate_material_prefix = QLabel("Plate Material:")

        self.plate_material_input = QLineEdit()
        self.plate_material_input.setFixedWidth(100)
        self.plate_material_input.setPlaceholderText("Enter plate material")

        self.plate_layout.addWidget(self.plate_material_prefix, 0, 0)
        self.plate_layout.addWidget(self.plate_material_input, 0, 1)

        # Add label and input field for plate thickness
        self.plate_thickness_prefix = QLabel("Plate Thickness:")

        self.plate_thickness_input = QDoubleSpinBox()
        self.plate_thickness_input.setRange(0, 1e100)
        self.plate_thickness_input.setDecimals(0)
        self.plate_thickness_input.setFixedWidth(100)
        self.plate_thickness_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.plate_thickness_suffix = QLabel("mm")

        self.plate_layout.addWidget(self.plate_thickness_prefix, 1, 0)
        self.plate_layout.addWidget(self.plate_thickness_input, 1, 1)
        self.plate_layout.addWidget(self.plate_thickness_suffix, 1, 2)

        self.plate_group_box.setLayout(self.plate_layout)

        return self.plate_group_box

    def create_crlabel(self) -> QLabel:
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL)
        self.crlabel.setFont(QFont(UI_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)

        return self.crlabel

    def create_frame_group_calc_box(self) -> QGroupBox:
        """
        Creates a group box for frame calculations.
        """
        # Create group box for frame calculations
        self.frame_calc_group_box = QGroupBox(self)
        self.frame_calc_group_box.setTitle("Frame Calculations")
        self.frame_calc_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.frame_calc_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame calculations group box
        self.frame_calc_layout = QGridLayout(self)
        self.frame_calc_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and output field for frame area
        self.frame_area_prefix = QLabel("Frame Area:")

        self.frame_area_output = QLineEdit()
        self.frame_area_output.setReadOnly(True)
        self.frame_area_output.setFixedWidth(100)

        self.frame_area_suffix = QLabel("m2")

        self.frame_calc_layout.addWidget(self.frame_area_prefix, 0, 0)
        self.frame_calc_layout.addWidget(self.frame_area_output, 0, 1)
        self.frame_calc_layout.addWidget(self.frame_area_suffix, 0, 2)

        self.frame_calc_group_box.setLayout(self.frame_calc_layout)

        return self.frame_calc_group_box

    def save_inputs(self) -> Dict[str, Union[str, float]]:
        """
        Save inputs to a file and return a dictionary of input values.
        """
        inputs = {
            "frame_material": self.frame_material_input.text(),
            "frame_length": self.frame_length_input.value(),
            "frame_height": self.frame_height_input.value(),
            "profile_type": self.profile_type_input.text(),
            "profile_length": self.profile_length_input.value(),
            "profile_width": self.profile_width_input.value(),
            "plate_material": self.plate_material_input.text(),
            "plate_thickness": self.plate_thickness_input.value(),
        }

        self.write_inputs_to_file(inputs)

        return inputs

    def connect_input_widgets(self) -> None:
        """
        Connect input widgets to the save_inputs function.
        """
        # Connect inputs from the frame group box
        frame_inputs = [
            self.frame_material_input,
            self.frame_length_input,
            self.frame_height_input,
        ]
        for input_widget in frame_inputs:
            input_widget.editingFinished.connect(self.save_inputs)

        # Connect inputs from the profile group box
        profile_inputs = [
            self.profile_type_input,
            self.profile_length_input,
            self.profile_width_input,
        ]
        for input_widget in profile_inputs:
            input_widget.editingFinished.connect(self.save_inputs)

        # Connect inputs from the plate group box
        plate_inputs = [
            self.plate_material_input,
            self.plate_thickness_input,
        ]
        for input_widget in plate_inputs:
            input_widget.editingFinished.connect(self.save_inputs)

    def write_inputs_to_file(self, inputs: Dict[str, Union[str, float]]):
        """
        Write the inputs to a file at a given path. If the file already exists,
        overwrite it; otherwise, create a new file.
        """
        data_dir_folder = "src/data"
        data_dir_file = "configurator_inputs.txt"
        if not os.path.exists(data_dir_folder):
            os.makedirs(data_dir_folder)

        inputs_filepath = os.path.join(data_dir_folder, data_dir_file)

        mode = "w"

        with open(inputs_filepath, mode) as f:
            input_str = "\n".join([f"{key}: {value}" for key, value in inputs.items()])
            f.write(input_str + "\n")

        print("[DEBUG] SAVING INPUTS:", inputs)


if __name__ == "__main__":
    # Create application instance
    app = QApplication([])

    # Create UI and show main window

    ui = ConfigUI()
    ui.show()

    # Run event loop
    app.exec()
