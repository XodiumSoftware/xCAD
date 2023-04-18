import os

from PySide6.QtCore import QRegularExpression, Qt
from PySide6.QtGui import QIntValidator, QRegularExpressionValidator
from PySide6.QtWidgets import QGridLayout, QLineEdit, QWidget

from constants import (
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    DEBUG_SAVE_UI_PRINT,
)


class InputHandler(QWidget):
    def __init__(self):
        super().__init__()
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()
        self.line_validator = QLineEdit()

        self.data_dir_folder = DATA_DIR_FOLDER
        self.data_dir_file = DATA_DIR_FILE

        self.file_path = os.path.join(self.data_dir_folder, self.data_dir_file)

        self.data_dir_handler()

    def input_signal(self):
        """Connect a slot to input textChanged signal."""
        for input_widget in self.inputs:
            input_widget.textChanged.connect(self.save_inputs)

    def input_validator(self, input):
        """
        This function validates input values.
        """
        # FIXME: input validator
        if not any(char.isdigit() for char in input.text()):
            validator = QRegularExpressionValidator(QRegularExpression(".+"), self)
        else:
            validator = QIntValidator(0, 2147483647, self)

        self.line_validator.setValidator(validator)
        self.line_validator.setAlignment(Qt.AlignmentFlag.AlignRight)

        return validator

    def data_dir_handler(self):
        """
        This function checks if the data file exists and creates it if it doesn't.
        """
        if not os.path.exists(os.path.dirname(self.file_path)):
            os.makedirs(os.path.dirname(self.file_path))
        if not os.path.exists(self.file_path):
            with open(self.file_path, "w") as f:
                f.write("")

    def save_inputs(self):
        """
        Saves input values from input widgets to a text file.
        """
        input_values = {
            i: input_widget.text() for i, input_widget in enumerate(self.inputs)
        }
        with open(self.file_path, "w") as f:
            for i, value in input_values.items():
                f.write(f"{CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0[i]}: {value}\n")
        print(DEBUG_SAVE_UI_PRINT)
