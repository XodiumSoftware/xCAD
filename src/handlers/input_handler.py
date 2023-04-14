import os

from PySide6.QtCore import QRegularExpression
from PySide6.QtGui import QIntValidator, QRegularExpressionValidator, QValidator
from PySide6.QtWidgets import QGridLayout, QLabel, QLineEdit, QMessageBox, QWidget

from constants import (
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    SAVE_UI_TEXT,
    UI_TITLE,
)


class InputHandler(QWidget):
    def create_input_fields(self):
        """
        This function creates input fields with labels and placeholders in a QGridLayout.
        """
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1) in enumerate(
            zip(
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
            )
        ):
            label0 = QLabel(desc0, self)
            input = QLineEdit(self)
            label1 = QLabel(desc1, self)

            self.labels.extend([label0, label1])
            self.inputs.append(input)

            input_validate = QRegularExpressionValidator()
            input.setValidator(input_validate)

            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

            input.setPlaceholderText(CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1[i])

            if "text" in CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate.setRegularExpression(QRegularExpression(".+"))
            elif "number" in CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate = QIntValidator()
                input_validate.setBottom(0)
                input.setValidator(input_validate)
            else:
                input_validate.setRegularExpression(QRegularExpression(".*"))

    def input_validator(
        self, text_input: str, pos: int, obj_num: int
    ) -> tuple[QValidator.State, str, int]:
        placeholder = self.inputs[obj_num].placeholderText()
        if "text" in placeholder:
            if text_input == "":
                return QValidator.State.Intermediate, text_input, pos
            elif text_input.isalpha():
                return QValidator.State.Acceptable, text_input, pos
            else:
                return QValidator.State.Invalid, text_input, pos
        elif "number" in placeholder:
            if text_input == "":
                return QValidator.State.Intermediate, text_input, pos
            elif text_input.isnumeric() and int(text_input) >= 0:
                return QValidator.State.Acceptable, text_input, pos
            else:
                return QValidator.State.Invalid, text_input, pos
        else:
            return QValidator.State.Acceptable, text_input, pos

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

        QMessageBox.information(
            self, UI_TITLE, SAVE_UI_TEXT, QMessageBox.StandardButton.Ok
        )
