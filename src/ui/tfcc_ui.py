from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont
from PyQt6.QtWidgets import (QGridLayout, QGroupBox, QHBoxLayout, QLabel,
                             QLineEdit, QSizePolicy, QVBoxLayout, QWidget)

from constants import (TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0,
                       TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1,
                       TFCC_UI_GROUPBOX_TITLE, UI_CONTENTS_MARGINS,
                       UI_GROUPBOX_FONT_SIZE, UI_GROUPBOX_FONT_TYPE,
                       UI_GROUPBOX_STYLESHEET)
from events.on_press_events import OnPressEvents
from ui.ui_setup import UiSetup


# The TFCCUI class is a QWidget used for creating a UI in a GUI application.
class TFCCUi(UiSetup, OnPressEvents, QWidget):
    def __init__(self):
        """
        This function initializes a GUI layout with a group box and a copyright label.
        """
        super().__init__()

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.setup_ui()

        self.create_group_box()

        self.main_layout.addWidget(self.group_box)
        self.main_layout.addWidget(self.crlabel)

    def create_group_box(self):
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(TFCC_UI_GROUPBOX_TITLE)
        self.group_box.setFont(
            QFont(UI_GROUPBOX_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold))
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum)
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # call create_input_fields() to create input fields and add them to the group box layout
        self.create_input_fields()
        self.group_box_layout.addLayout(self.input_fields_layout)

    def create_input_fields(self):
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1) in enumerate(zip(TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0, TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1)):
            label0 = QLabel(desc0, self)
            input = QLineEdit(self)
            label1 = QLabel(desc1, self)
            self.labels.extend([label0, label1])
            self.inputs.append(input)
            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

            # You can set default text for the second column QLineEdit widget like this:
            # input_text.setText("Default Text")

            # You can also get the text from the second column QLineEdit widget like this:
            # text = input_text.text()
