from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QGroupBox, QHBoxLayout, QLabel, QWidget

from constants import (COPYRIGHT_LABEL, MAIN_WINDOW_GROUPBOX_TITLE,
                       WINDOW_GROUPBOX_STYLESHEET)
from ui.ui_setup import UiSetup


# The TFCCWindow class is a QWidget used for creating a window in a GUI application.
class TFCCUi(UiSetup, QWidget):
    def __init__(self):
        """
        This function initializes a GUI layout with a group box and a copyright label.
        """
        super().__init__()

        self.create_group_box()

        self.crlabel = QLabel(COPYRIGHT_LABEL)

        self.main_layout.addWidget(
            self.group_box, alignment=Qt.AlignmentFlag.AlignTop)
        self.main_layout.addWidget(
            self.crlabel, alignment=Qt.AlignmentFlag.AlignBottom)

    def create_group_box(self):
        """
        This function creates a group box with a horizontal layout, a title, centered alignment, and
        stretchable buttons.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(WINDOW_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(MAIN_WINDOW_GROUPBOX_TITLE)
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)

        # FIX: create_buttons(self) first, then add it to here.
        self.create_buttons()

        self.group_box_layout.addStretch()

    def create_buttons(self):
        pass
