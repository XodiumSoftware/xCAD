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
    UI_GROUPBOX_STYLESHEET,
)


class ConfigUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowFlags(
            Qt.WindowType.WindowTitleHint
            | Qt.WindowType.CustomizeWindowHint
            | Qt.WindowType.MSWindowsFixedSizeDialogHint
        )
        self.setWindowTitle(CONFIG_UI_TITLE)

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
        # Create group box for frame
        self.frame_group_box = QGroupBox(self)
        self.frame_group_box.setTitle("Frame")
        self.frame_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.frame_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame group box
        self.frame_layout = QGridLayout(self)
        self.frame_layout.setColumnStretch(0, 1)

        # Add label and input field for frame material
        self.frame_material_prefix = QLabel("Frame Material:")

        self.frame_material_input = QLineEdit()
        self.frame_material_input.setFixedWidth(100)
        self.frame_material_input.setPlaceholderText("Enter frame material")

        self.frame_layout.addWidget(self.frame_material_prefix, 0, 0)
        self.frame_layout.addWidget(self.frame_material_input, 0, 1)

        # Add label and input field for frame length
        self.frame_length_prefix = QLabel("Frame Length:")

        self.frame_length_input = QDoubleSpinBox()
        self.frame_length_input.setRange(0, 1e100)
        self.frame_length_input.setDecimals(0)
        self.frame_length_input.setFixedWidth(100)
        self.frame_length_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.frame_length_suffix = QLabel("mm")

        self.frame_layout.addWidget(self.frame_length_prefix, 1, 0)
        self.frame_layout.addWidget(self.frame_length_input, 1, 1)
        self.frame_layout.addWidget(self.frame_length_suffix, 1, 2)

        # Add label and input field for frame height
        self.frame_height_prefix = QLabel("Frame Height:")

        self.frame_height_input = QDoubleSpinBox()
        self.frame_height_input.setRange(0, 1e100)
        self.frame_height_input.setDecimals(0)
        self.frame_height_input.setFixedWidth(100)
        self.frame_height_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.frame_height_suffix = QLabel("mm")

        self.frame_layout.addWidget(self.frame_height_prefix, 2, 0)
        self.frame_layout.addWidget(self.frame_height_input, 2, 1)
        self.frame_layout.addWidget(self.frame_height_suffix, 2, 2)

        self.frame_group_box.setLayout(self.frame_layout)

        return self.frame_group_box

    def create_profile_group_box(self) -> QGroupBox:
        # Create group box for profile
        self.profile_group_box = QGroupBox(self)
        self.profile_group_box.setTitle("Profile")
        self.profile_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.profile_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for profile group box
        self.profile_layout = QGridLayout(self)
        self.profile_layout.setColumnStretch(0, 1)  # Add stretch to the left column

        # Add label and input field for profile type
        self.profile_type_prefix = QLabel("Profile Type:")

        self.profile_type_input = QLineEdit()
        self.profile_type_input.setFixedWidth(100)
        self.profile_type_input.setPlaceholderText("Enter profile type")

        self.profile_layout.addWidget(self.profile_type_prefix, 0, 0)
        self.profile_layout.addWidget(self.profile_type_input, 0, 1)

        # Add label and input field for profile length
        self.profile_length_prefix = QLabel("Profile Length:")

        self.profile_length_input = QDoubleSpinBox()
        self.profile_length_input.setRange(0, 1e100)
        self.profile_length_input.setDecimals(0)
        self.profile_length_input.setFixedWidth(100)
        self.profile_length_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.profile_length_suffix = QLabel("mm")

        self.profile_layout.addWidget(self.profile_length_prefix, 1, 0)
        self.profile_layout.addWidget(self.profile_length_input, 1, 1)
        self.profile_layout.addWidget(self.profile_length_suffix, 1, 2)

        # Add label and input field for profile width
        self.profile_width_prefix = QLabel("Profile Width:")

        self.profile_width_input = QDoubleSpinBox()
        self.profile_width_input.setRange(0, 1e100)
        self.profile_width_input.setDecimals(0)
        self.profile_width_input.setFixedWidth(100)
        self.profile_width_input.setAlignment(Qt.AlignmentFlag.AlignRight)

        self.profile_width_suffix = QLabel("mm")

        self.profile_layout.addWidget(self.profile_width_prefix, 2, 0)
        self.profile_layout.addWidget(self.profile_width_input, 2, 1)
        self.profile_layout.addWidget(self.profile_width_suffix, 2, 2)

        self.profile_group_box.setLayout(self.profile_layout)

        return self.profile_group_box

    def create_plate_group_box(self) -> QGroupBox:
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
        print("[DEBUG] SAVING INPUTS:")
        inputs = {}

        # Save inputs from the frame group box
        inputs["frame_material"] = self.frame_material_input.text()
        inputs["frame_length"] = self.frame_length_input.value()
        inputs["frame_height"] = self.frame_height_input.value()

        # Save inputs from the profile group box
        inputs["profile_type"] = self.profile_type_input.text()
        inputs["profile_length"] = self.profile_length_input.value()
        inputs["profile_width"] = self.profile_width_input.value()

        # Save inputs from the plate group box
        inputs["plate_material"] = self.plate_material_input.text()
        inputs["plate_thickness"] = self.plate_thickness_input.value()

        self.write_inputs_to_file(inputs)

        return inputs

    def connect_input_widgets(self):
        # Connect inputs from the frame group box
        self.frame_material_input.editingFinished.connect(self.save_inputs)
        self.frame_length_input.editingFinished.connect(self.save_inputs)
        self.frame_height_input.editingFinished.connect(self.save_inputs)

        # Connect inputs from the profile group box
        self.profile_type_input.editingFinished.connect(self.save_inputs)
        self.profile_length_input.editingFinished.connect(self.save_inputs)
        self.profile_width_input.editingFinished.connect(self.save_inputs)

        # Connect inputs from the plate group box
        self.plate_material_input.editingFinished.connect(self.save_inputs)
        self.plate_thickness_input.editingFinished.connect(self.save_inputs)

    def write_inputs_to_file(
        self,
        inputs: Dict[str, Union[str, float]],
        filename: str = "configurator_inputs.txt",
        directory: str = "data",
    ):
        inputs_path = os.path.join(directory, filename)

        # Create the directory if it doesn't exist
        os.makedirs(directory, exist_ok=True)

        # Write the inputs to the file
        with open(inputs_path, "w") as f:
            for key, value in inputs.items():
                f.write(f"{key}: {value}\n")
                print("[DEBUG] SAVING INPUT:", key, value)

        # Close the file
        f.close()


if __name__ == "__main__":
    # Create application instance
    app = QApplication([])

    # Create UI and show main window

    ui = ConfigUI()
    ui.show()

    # Run event loop
    app.exec()
