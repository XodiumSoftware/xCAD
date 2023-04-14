from PySide6.QtCore import QRegularExpression, Qt
from PySide6.QtGui import QFont, QIntValidator, QRegularExpressionValidator
from PySide6.QtWidgets import (
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    CONFIG_UI_TITLE,
    UI_CONTENTS_MARGINS,
    UI_FONT_TYPE,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_STYLESHEET,
)
from ui.setup_ui import SetupUI


class ConfigUI(SetupUI):
    def __init__(self):
        super().__init__()

        # Create some content for CONFIG_UI
        self.setWindowFlags(
            Qt.WindowType.WindowTitleHint | Qt.WindowType.CustomizeWindowHint
        )
        self.setWindowTitle(CONFIG_UI_TITLE)
        layout = QVBoxLayout(self)

        self.create_group_box()
        self.main_layout.addWidget(self.group_box)

        self.main_layout.addWidget(self.crlabel)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
        else:
            super().keyPressEvent(event)

    def create_group_box(self):
        """
        This function creates a group box with input fields and applies styling to it.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setFont(
            QFont(UI_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
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
