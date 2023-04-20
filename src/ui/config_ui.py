from PySide6.QtCore import QLocale, Qt
from PySide6.QtWidgets import (
    QDoubleSpinBox,
    QFormLayout,
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QWidget,
)

from constants import CONFIG_UI_TITLE
from ui.setup_ui import SetupUI


class ConfigUI(SetupUI):
    def __init__(self):
        super().__init__()

        self.setWindowTitle(CONFIG_UI_TITLE)

        # Set window flags
        self.setWindowFlags(
            Qt.WindowType.WindowTitleHint
            | Qt.WindowType.CustomizeWindowHint
            | Qt.WindowType.MSWindowsFixedSizeDialogHint
        )

        # Create main layout for widget
        self.widget = QWidget()
        self.config_layout = QGridLayout(self.widget)

        # Add group boxes and labels to the configuration ui layout
        self.config_layout.addWidget(self.create_frame_group_box(), 0, 0)
        self.config_layout.addWidget(self.create_profile_group_box(), 1, 0)
        self.config_layout.addWidget(self.create_plate_group_box(), 2, 0)
        self.config_layout.addWidget(self.create_frame_calc_group_box(), 0, 1)
        self.config_layout.addWidget(self.create_crlabel(), 3, 0)

        # Set the main layout for the window
        self.setLayout(self.config_layout)

        # Set the window size based on the widget size hint
        self.resize(self.widget.sizeHint())

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

    def create_frame_calc_group_box(self) -> QGroupBox:
        # Create group box for frame calculations
        self.frame_calc_group_box = QGroupBox(self)
        self.frame_calc_group_box.setTitle("Frame Calculations")
        self.frame_calc_group_box.setStyleSheet("QGroupBox { font-weight: bold; }")
        self.frame_calc_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Create form layout for frame calculations group box
        self.frame_calc_layout = QFormLayout(self)
        self.frame_calc_layout.setFieldGrowthPolicy(
            QFormLayout.FieldGrowthPolicy.AllNonFixedFieldsGrow
        )

        # Add label and output field for frame area
        self.frame_area_prefix = QLabel("Frame Area:")
        self.frame_area_output = QLineEdit()
        self.frame_area_output.setReadOnly(True)
        self.frame_area_output.setFixedWidth(100)
        self.frame_area_output.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.frame_area_suffix = QLabel("m2")

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
        self.frame_calc_layout.addRow(frame_area_layout)

        self.frame_calc_group_box.setLayout(self.frame_calc_layout)

        return self.frame_calc_group_box
