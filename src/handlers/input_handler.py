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
        """
        This function is called when an input is changed.
        """
        for input_widget in self.inputs:
            input_widget.textChanged.connect(self.save_inputs)

    def input_validator(self, input):
        """
        This function validates input values.
        """
        # shouldn't input.text() be desc1?
        if not any(char.isdigit() for char in input.text()):
            validator = QRegularExpressionValidator(QRegularExpression(".+"), self)
        else:
            validator = QIntValidator(0, 2147483647, self)

        self.line_validator.setValidator(validator)
        self.line_validator.setAlignment(Qt.AlignmentFlag.AlignRight)
        # FIXME: placeholder text doesn't work.
        self.line_validator.setPlaceholderText("")

        return validator

    def save_inputs(self):
        # TODO: Add that it replaces the input text with the new value.
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
