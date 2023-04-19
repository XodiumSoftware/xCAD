from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QFormLayout,
    QGridLayout,
    QGroupBox,
    QLabel,
    QLineEdit,
    QSpinBox,
    QVBoxLayout,
    QWidget,
)


def create_ui() -> QWidget:
    """
    Creates a QWidget with a QVBoxLayout and adds three group boxes to it.

    Returns:
        QWidget: The created main window.
    """
    # Create vertical layout for main window
    main_layout = QVBoxLayout()

    # Create group boxes for frame, profile, and plate
    config_layout_main_label = create_config_layout_main_label()
    frame_group_box = create_frame_group_box()
    profile_group_box = create_profile_group_box()
    plate_group_box = create_plate_group_box()
    crlabel = create_crlabel()

    # Add group boxes to main layout
    main_layout.addWidget(config_layout_main_label)
    main_layout.addWidget(frame_group_box)
    main_layout.addWidget(profile_group_box)
    main_layout.addWidget(plate_group_box)
    main_layout.addWidget(crlabel)

    # Set main layout for widget
    widget = QWidget()
    widget.setLayout(main_layout)

    return widget


def create_config_layout_main_label() -> QLabel:
    config_layout_main_label = QLabel("Configuration Layout Main Label")
    config_layout_main_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
    return config_layout_main_label


def create_frame_group_box() -> QGroupBox:
    # Create group box for frame
    frame_group_box = QGroupBox("Frame")
    frame_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

    # Create grid layout for frame group box
    frame_layout = QGridLayout()

    # Add label and input field for frame length
    frame_length_label = QLabel("Frame Length:")
    frame_length_input = QSpinBox()
    frame_length_input.setRange(0, 100)
    frame_length_input.setFixedWidth(100)
    frame_layout.addWidget(frame_length_label, 0, 0)
    frame_layout.addWidget(frame_length_input, 0, 1)

    # Add label and input field for frame height
    frame_height_label = QLabel("Frame Height:")
    frame_height_input = QSpinBox()
    frame_height_input.setRange(0, 100)
    frame_height_input.setFixedWidth(100)
    frame_layout.addWidget(frame_height_label, 1, 0)
    frame_layout.addWidget(frame_height_input, 1, 1)

    frame_group_box.setLayout(frame_layout)

    return frame_group_box


def create_profile_group_box() -> QGroupBox:
    # Create group box for profile
    profile_group_box = QGroupBox("Profile")
    profile_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

    # Create form layout for profile group box
    profile_layout = QGridLayout()

    # Add label and input field for profile type
    profile_type_label = QLabel("Profile Type:")
    profile_type_input = QLineEdit()
    profile_type_input.setFixedWidth(100)
    profile_layout.addWidget(profile_type_label, 0, 0)
    profile_layout.addWidget(profile_type_input, 0, 1)

    # Add label and input field for profile length
    profile_length_label = QLabel("Profile Length:")
    profile_length_input = QSpinBox()
    profile_length_input.setRange(0, 100)
    profile_length_input.setFixedWidth(100)
    profile_layout.addWidget(profile_length_label, 1, 0)
    profile_layout.addWidget(profile_length_input, 1, 1)

    # Add label and input field for profile width
    profile_width_label = QLabel("Profile Width:")
    profile_width_input = QSpinBox()
    profile_width_input.setRange(0, 100)
    profile_width_input.setFixedWidth(100)
    profile_layout.addWidget(profile_width_label, 2, 0)
    profile_layout.addWidget(profile_width_input, 2, 1)

    profile_group_box.setLayout(profile_layout)

    return profile_group_box


def create_plate_group_box() -> QGroupBox:
    # Create group box for plate
    plate_group_box = QGroupBox("Plate Material")
    plate_group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)

    # Create grid layout for plate group box
    plate_layout = QGridLayout()

    # Add label and input field for plate material type
    plate_material_type_label = QLabel("Plate Material Type:")
    plate_material_type_input = QLineEdit()
    plate_material_type_input.setFixedWidth(100)
    plate_layout.addWidget(plate_material_type_label, 0, 0)
    plate_layout.addWidget(plate_material_type_input, 0, 1)

    # Add label and input field for plate material thickness
    plate_material_thickness_label = QLabel("Plate Material Thickness (mm):")
    plate_material_thickness_input = QSpinBox()
    plate_material_thickness_input.setRange(0, 100)
    plate_material_thickness_input.setFixedWidth(100)
    plate_layout.addWidget(plate_material_thickness_label, 1, 0)
    plate_layout.addWidget(plate_material_thickness_input, 1, 1)

    plate_group_box.setLayout(plate_layout)

    return plate_group_box


def create_crlabel() -> QLabel:
    cr_label = QLabel("CR Label")
    cr_label.setAlignment(Qt.AlignmentFlag.AlignLeft)
    return cr_label


if __name__ == "__main__":
    # Create application instance
    app = QApplication([])

    # Create UI and show main window
    ui = create_ui()
    ui.show()

    # Run event loop
    app.exec()
