import os

from PySide6.QtCore import QRegularExpression, Qt
from PySide6.QtGui import QIntValidator, QRegularExpressionValidator
from PySide6.QtWidgets import QGridLayout, QLabel, QLineEdit, QWidget

from constants import (
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    SAVE_UI_TEXT,
)


class InputHandler(QWidget):
    def input_signal(self):
        for input_widget in self.inputs:
            input_widget.textChanged.connect(self.save_inputs)

    def create_input_fields(self):
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1, desc2) in enumerate(
            zip(
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1,
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
            )
        ):
            label0 = QLabel(desc0, self)
            input = QLineEdit(desc1, self)
            label1 = QLabel(desc2, self)

            self.labels.append(label0)
            self.inputs.append(input)
            self.labels.append(label1)

            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

        self.setLayout(self.input_fields_layout)

    def input_validator(self):
        line_validator = QLineEdit()
        line_validator.setPlaceholderText(self.create_input_fields.desc1)

        if not any(char.isdigit() for char in self.create_input_fields.desc1):
            # desc1 contains no digits, assume input field is for text
            validator = QRegularExpressionValidator(QRegularExpression(".+"), self)
        else:
            # desc1 contains digits, assume input field is for numbers
            validator = QIntValidator(0, 2147483647, self)

        line_validator.setValidator(validator)
        line_validator.setAlignment(Qt.AlignmentFlag.AlignRight)

        return line_validator

    def save_inputs(self):
        """
        This function saves input values from input widgets to a text file.
        """
        input_values = {}
        for i, input_widget in enumerate(self.inputs):
            input_text = input_widget.text()
            input_values[i] = input_text

        data_dir = DATA_DIR_FOLDER

        if not os.path.exists(data_dir):
            os.makedirs(data_dir)

        file_path = os.path.join(data_dir, DATA_DIR_FILE)

        with open(file_path, "w") as f:
            for key, value in input_values.items():
                f.write(f"{key}: {value}\n")

        print(SAVE_UI_TEXT)
