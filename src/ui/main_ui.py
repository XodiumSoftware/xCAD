from PyQt6.QtCore import QSize, Qt
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QPushButton, QSizePolicy,
                             QSpacerItem, QVBoxLayout, QWidget)

from constants import (ICON_TO_BUTTON_MARGIN, MAIN_WINDOW_BUTTON_SIZE,
                       MAIN_WINDOW_BUTTON_TEXTS, MAIN_WINDOW_GROUPBOX_TITLE,
                       MAIN_WINDOW_ICON_PATHS, WINDOW_GROUPBOX_STYLESHEET)
from events.on_press_events import OnPressEvents
from ui.tfcc_ui import TFCCUi
from ui.ui_setup import UiSetup


# The MainWindow class is a QWidget used for creating a window in a GUI application.
class MainUi(UiSetup, OnPressEvents, QWidget):
    def __init__(self):
        """
        This function initializes a group box and adds it to the main layout with a specified size
        policy.
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
        This function creates a group box with buttons and spacers inside it.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.group_box.setStyleSheet(WINDOW_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(MAIN_WINDOW_GROUPBOX_TITLE)
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum)
        self.group_box_layout.setContentsMargins(0, 0, 0, 0)

        self.create_buttons(MAIN_WINDOW_BUTTON_TEXTS)

        button_layout = QHBoxLayout()
        button_layout.setContentsMargins(0, 0, 0, 0)
        button_layout.addStretch()
        for button in self.buttons:
            button_layout.addWidget(button)
            button_layout.addStretch()
        button_layout.addStretch()

        self.group_box_layout.addLayout(button_layout)

    def create_buttons(self, button_texts):
        """
        This function creates buttons with icons and tooltips based on given button texts.

        :param button_texts: A list of strings or tuples where each string represents the text to be
        displayed on a button and each tuple contains two elements where the first element is the text
        to be displayed on the button and the second element is the tooltip text to be displayed when
        the user hovers over the button
        """
        self.buttons = []

        icon_paths = MAIN_WINDOW_ICON_PATHS

        for i in range(len(button_texts)):
            button_text = button_texts[i]
            icon_path = icon_paths[i]

            button = QPushButton()

            if isinstance(button_text, tuple):
                button_text, tooltip = button_text
            else:
                tooltip = " ".join(button_text.split("_")).title()

            button.setIcon(QIcon(icon_path))

            button.setIconSize(
                QSize(*(x - ICON_TO_BUTTON_MARGIN for x in MAIN_WINDOW_BUTTON_SIZE)))

            button.setFixedSize(QSize(*MAIN_WINDOW_BUTTON_SIZE))

            button.setToolTip(tooltip)

            self.group_box_layout.addWidget(button)

            self.buttons.append(button)

    # Make it work with button_press_events.py
    def open_window(self):
        """
        This function creates and displays a DTFCWindow object.
        """
        dtfc_window = TFCCUi()
        dtfc_window.show()
