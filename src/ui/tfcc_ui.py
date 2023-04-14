from PySide6.QtCore import QRegularExpression, Qt
from PySide6.QtGui import QFont, QIntValidator, QRegularExpressionValidator, QValidator
from PySide6.QtWidgets import (
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    BACK_BUTTON,
    SAVE_BUTTON,
    TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    TFCC_UI_GROUPBOX_TITLE,
    UI_CONTENTS_MARGINS,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_FONT_TYPE,
    UI_GROUPBOX_STYLESHEET,
)
from handlers.input_handler import inputHandler
from handlers.press_handler import backButtonHandler
from ui.setup_ui import SetupUI


class TFCCUI(SetupUI):
    inputHandler_instance = inputHandler()
    backButtonHandler_instance = backButtonHandler()

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
        self.back_button.clicked.connect(
            self.backButtonHandler_instance.back_button_handler
        )
        self.button_layout.addWidget(self.back_button)

        self.save_button = QPushButton(SAVE_BUTTON, self)
        self.save_button.clicked.connect(self.inputHandler_instance.save_inputs)
        self.button_layout.addWidget(self.save_button)

    def onClose(self):
        """
        This function handles the action of pressing the close button on the window
        and prompts the user to save changes before returning to the main UI.
        """
        self.backButtonHandler_instance.back_button_handler()

    # FIXME: red x back button handler
