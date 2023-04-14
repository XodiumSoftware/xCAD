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
            input = MyLineEdit(desc1, self)
            label1 = QLabel(desc2, self)
            self.labels.append(label0)
            self.inputs.append(input)
            self.labels.append(label1)
            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

        self.setLayout(self.input_fields_layout)

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


class MyLineEdit(QLineEdit):
    """
    This class extends the QLineEdit class to add a validator based on the field's description.
    """

    def __init__(self, desc, parent=None):
        super().__init__(parent)
        self.setPlaceholderText(desc)

        if "text" in desc:
            validator = QRegularExpressionValidator(QRegularExpression(".+"), self)
        elif "number" in desc:
            validator = QIntValidator(0, 2147483647, self)
        else:
            validator = QRegularExpressionValidator(QRegularExpression(".*"), self)

        self.setValidator(validator)
        self.setAlignment(Qt.AlignmentFlag.AlignRight)
