from PySide6.QtCore import Qt
from PySide6.QtGui import QFont
from PySide6.QtWidgets import QGroupBox, QHBoxLayout, QSizePolicy, QVBoxLayout

from constants import (
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

        self.input_validator(input.placeholderText())

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
        self.input_signal()
