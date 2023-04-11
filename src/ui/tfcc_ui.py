import os

from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont
from PyQt6.QtWidgets import (QFileDialog, QGridLayout, QGroupBox, QHBoxLayout,
                             QLabel, QLineEdit, QMessageBox, QPushButton,
                             QSizePolicy, QVBoxLayout, QWidget)

from constants import (TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0,
                       TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1,
                       TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2,
                       TFCC_UI_GROUPBOX_TITLE, UI_CONTENTS_MARGINS,
                       UI_GROUPBOX_FONT_SIZE, UI_GROUPBOX_FONT_TYPE,
                       UI_GROUPBOX_STYLESHEET)
from events.on_press_events import OnPressEvents
from ui.ui_setup import UiSetup


# The TFCCUI class is a QWidget used for creating a UI in a GUI application.
class TFCCUi(UiSetup, OnPressEvents, QWidget):
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
            QFont(UI_GROUPBOX_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold))
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum)
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

        for i, (desc0, desc1) in enumerate(zip(TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0, TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2)):
            label0 = QLabel(desc0, self)
            input = QLineEdit(self)
            label1 = QLabel(desc1, self)
            self.labels.extend([label0, label1])
            self.inputs.append(input)
            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

            input.setPlaceholderText(TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1[i])

    def create_button_layout(self):
        """
        This function creates a horizontal layout with a "Back" button and a "Save" button, each with
        their own respective click event handlers.
        """
        self.button_layout = QHBoxLayout()
        self.button_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.back_button = QPushButton("Back", self)
        self.back_button.clicked.connect(self.on_back_button_pressed)
        self.button_layout.addWidget(self.back_button)

        self.save_button = QPushButton("Save", self)
        self.save_button.clicked.connect(self.on_save_button_pressed)
        self.button_layout.addWidget(self.save_button)

    def on_save_button_pressed(self):
        file_path, _ = QFileDialog.getSaveFileName(
            self, "Save Input Values", "", "Text Files (*.txt)")

        if file_path:
            self.save_input_values()

    def on_back_button_pressed(self):
        reply = QMessageBox.question(
            self, "Save Changes", "Do you want to save the changes before going back?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No | QMessageBox.StandardButton.Cancel
        )

        if reply == QMessageBox.StandardButton.Yes:
            self.on_save_button_pressed()
            self.close()
        elif reply == QMessageBox.StandardButton.No:
            self.close()

    def save_input_values(self):
        input_values = {}
        for i, input_widget in enumerate(self.inputs):
            input_text = input_widget.text()
            input_values[i] = input_text

        data_dir = "data"
        if not os.path.exists(data_dir):
            os.makedirs(data_dir)
        file_path = os.path.join(data_dir, "input_values.txt")

        with open(file_path, 'w') as f:
            for key, value in input_values.items():
                f.write(f"{key}: {value}\n")

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_Escape:
            self.on_back_button_pressed()
        elif event.key() == Qt.Key.Key_Q and event.modifiers() == Qt.KeyboardModifier.ControlModifier:
            self.on_back_button_pressed()

    """ add when clicking on window red X button that it gives the message on_back_button_pressed() """
