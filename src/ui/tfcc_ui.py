import os

from PySide6.QtCore import QRegularExpression, Qt
from PySide6.QtGui import QFont, QIntValidator, QRegularExpressionValidator, QValidator
from PySide6.QtWidgets import (
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMessageBox,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    BACK_BUTTON,
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    ON_BACK_BUTTON_PRESSED_DESC,
    SAVE_BUTTON,
    SAVE_UI_TEXT,
    TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    TFCC_UI_GROUPBOX_TITLE,
    UI_CONTENTS_MARGINS,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_FONT_TYPE,
    UI_GROUPBOX_STYLESHEET,
    UI_TITLE,
)
from ui.ui_setup import UiSetup


class TFCCUi(UiSetup):
    def __init__(self):
        """
        This function initializes a layout and adds various widgets to it.
        """
        super().__init__()

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.setup_ui()

        self.create_group_box()

        self.main_layout.addWidget(self.group_box)
        self.main_layout.addWidget(self.crlabel)
        self.main_layout.addWidget(self.group_box)
        self.create_button_layout()
        self.main_layout.addLayout(self.button_layout)
        self.main_layout.addWidget(self.crlabel)

    def create_group_box(self):
        """
        This function creates a group box with input fields and applies styling to it.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(TFCC_UI_GROUPBOX_TITLE)
        self.group_box.setFont(
            QFont(UI_GROUPBOX_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum
        )
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        self.create_input_fields()
        self.group_box_layout.addLayout(self.input_fields_layout)

    def create_input_fields(self):
        """
        This function creates input fields with labels and placeholders in a QGridLayout.
        """
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1) in enumerate(
            zip(
                TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0, TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2
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

            input.setPlaceholderText(TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1[i])

            if "text" in TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate.setRegularExpression(QRegularExpression(".+"))
            elif "number" in TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
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

    def create_button_layout(self):
        """
        This function creates a horizontal layout with a "Back" button and a "Save" button, each with
        their own respective click event handlers.
        """
        self.button_layout = QHBoxLayout()
        self.button_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.back_button = QPushButton(BACK_BUTTON, self)
        self.back_button.clicked.connect(self.on_back_button_pressed)
        self.button_layout.addWidget(self.back_button)

        self.save_button = QPushButton(SAVE_BUTTON, self)
        self.save_button.clicked.connect(self.on_save_button_pressed)
        self.button_layout.addWidget(self.save_button)

    def closeEvent(self, event):
        """
        This function handles the action of pressing the close button on the window
        and prompts the user to save changes before returning to the main UI.
        """
        self.on_back_button_pressed()

    def on_back_button_pressed(self):
        """
        This function handles the action of pressing the back button in a UI and prompts the user to
        save changes before returning to the main UI.
        """
        reply = QMessageBox.question(
            self,
            *ON_BACK_BUTTON_PRESSED_DESC,
            QMessageBox.StandardButton.Yes
            | QMessageBox.StandardButton.No
            | QMessageBox.StandardButton.Cancel,
        )
        if reply == QMessageBox.StandardButton.Yes:
            self.on_save_button_pressed()

        elif reply == QMessageBox.StandardButton.No:
            from ui.main_ui import MainUi

            main_ui = MainUi()
            main_ui.show()
            self.close()

    def on_save_button_pressed(self):
        """
        This function prompts the user to select a file path to save input values.
        """
        self.save_input_values()

    def save_input_values(self):
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
        # TODO: add way to go back instead of closing everything.
