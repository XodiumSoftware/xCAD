
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