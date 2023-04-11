from PyQt6.QtCore import Qt, pyqtSlot
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QSizePolicy, QVBoxLayout,
                             QWidget)

from constants import (TFCC_UI_GROUPBOX_TITLE, UI_CONTENTS_MARGINS,
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
        """
        This function creates a group box with a horizontal layout, a title, centered alignment, and
        stretchable buttons.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(TFCC_UI_GROUPBOX_TITLE)
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum)
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # self.create_buttons(MAIN_UI_BUTTON_TEXTS)

        button_layout = QHBoxLayout()
        button_layout.setContentsMargins(*UI_CONTENTS_MARGINS)
        button_layout.addStretch()
        # for button in self.buttons:
        #    button_layout.addWidget(button)
        #    button_layout.addStretch()
        button_layout.addStretch()

        self.group_box_layout.addLayout(button_layout)

    def create_buttons(self):
        pass
