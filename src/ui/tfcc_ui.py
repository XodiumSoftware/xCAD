from PySide6.QtCore import Qt
from PySide6.QtGui import QFont
from PySide6.QtWidgets import (
    QGroupBox,
    QHBoxLayout,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    BACK_BUTTON,
    SAVE_BUTTON,
    TFCC_UI_GROUPBOX_TITLE,
    UI_CONTENTS_MARGINS,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_FONT_TYPE,
    UI_GROUPBOX_STYLESHEET,
)
from handlers.handler import Handler
from handlers.input_handler import InputHandler
from ui.setup_ui import SetupUI


class TFCCUI(SetupUI):
    inputHandler_instance = Handler().save_inputs()
    backButtonHandler_instance = Handler().back_button_handler()
    InputHandler_instance = InputHandler()

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

        self.InputHandler_instance.create_input_fields()
        self.group_box_layout.addLayout(self.InputHandler_instance.input_fields_layout)

    def create_button_layout(self):
        """
        This function creates a horizontal layout with a "Back" button and a "Save" button, each with
        their own respective click event handlers.
        """
        self.button_layout = QHBoxLayout()
        self.button_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.back_button = QPushButton(BACK_BUTTON, self)
        self.back_button.clicked.connect(self.backButtonHandler_instance)
        self.button_layout.addWidget(self.back_button)

        self.save_button = QPushButton(SAVE_BUTTON, self)
        self.save_button.clicked.connect(self.inputHandler_instance)
        self.button_layout.addWidget(self.save_button)

    def onClose(self):
        """
        This function handles the action of pressing the close button on the window
        and prompts the user to save changes before returning to the main UI.
        """
        self.backButtonHandler_instance

    # FIXME: red x back button handler
