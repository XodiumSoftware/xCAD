import csv

from PySide6.QtCore import Qt
from PySide6.QtGui import QFont, QKeySequence
from PySide6.QtWidgets import QGroupBox, QHBoxLayout, QLabel, QLineEdit, QSizePolicy

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
from handlers.input_handler import InputHandler
from ui.setup_ui import SetupUI


class ConfigUI(SetupUI, InputHandler):
    def __init__(self):
        super().__init__()
        self.setWindowFlags(
            Qt.WindowType.WindowTitleHint
            | Qt.WindowType.CustomizeWindowHint
            | Qt.WindowType.MSWindowsFixedSizeDialogHint
        )
        self.setWindowTitle(CONFIG_UI_TITLE)

        self.create_group_box()
        self.main_layout.addWidget(self.group_box)

        self.main_layout.addWidget(self.crlabel)

    def keyPressEvent(self, event):
        """
        This function is called when certain keys are pressed.
        """
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
        self.input_signal()

    def create_input_fields(self):
        """
        Creates input fields and adds them to the group box.
        """
        with open(self.file_path, "r") as f:
            saved_data = list(csv.reader(f))

        for i, (desc0, desc1, desc2) in enumerate(
            zip(
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1,
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
            )
        ):
            label0, input, label1 = [
                QLabel(desc0, self),
                QLineEdit(self),
                QLabel(desc2, self),
            ]
            placeholder_text = (
                saved_data[i][1].strip() if len(saved_data[i]) > 1 else desc1
            )
            input.setPlaceholderText(placeholder_text)
            input.setValidator(self.input_validator(input))

            self.labels.extend([label0, label1])
            self.inputs.append(input)

            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)
