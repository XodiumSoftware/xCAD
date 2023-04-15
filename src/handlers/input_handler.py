import os

from PySide6.QtCore import QRegularExpression, Qt
from PySide6.QtGui import QIntValidator, QRegularExpressionValidator
from PySide6.QtWidgets import QGridLayout, QLineEdit, QWidget

from constants import (
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    SAVE_UI_TEXT,
)


class InputHandler(QWidget):
    def __init__(self):
        super().__init__()
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()
        self.line_validator = QLineEdit()

    def input_signal(self):
        for input_widget in self.inputs:
            input_widget.textChanged.connect(self.save_inputs)

    def input_validator(self, input):
        # shouldn't input.text() be desc1?
        if not any(char.isdigit() for char in input.text()):
            validator = QRegularExpressionValidator(QRegularExpression(".+"), self)
        else:
            # if not any(char.isalpha() for char in input.text()):
            validator = QIntValidator(0, 2147483647, self)

        # Added the else but it doesn't work. should remove it and replace elif with something better.

        self.line_validator.setValidator(validator)
        self.line_validator.setAlignment(Qt.AlignmentFlag.AlignRight)
        # self.line_validator.setPlaceholderText("")

        return validator

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
            for i, value in input_values.items():
                f.write(f"{CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0[i]}: {value}\n")

        print(SAVE_UI_TEXT)
