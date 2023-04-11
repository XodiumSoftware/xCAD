from functools import partial

from PyQt6.QtCore import QSize, Qt
from PyQt6.QtGui import QFont, QIcon
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QPushButton, QSizePolicy,
                             QVBoxLayout, QWidget)

from constants import (ICON_TO_BUTTON_MARGIN, MAIN_UI_BUTTON_SIZE,
                       MAIN_UI_BUTTON_TEXTS, MAIN_UI_GROUPBOX_TITLE,
                       MAIN_UI_ICON_PATHS, UI_CONTENTS_MARGINS,
                       UI_GROUPBOX_FONT_SIZE, UI_GROUPBOX_FONT_TYPE,
                       UI_GROUPBOX_STYLESHEET)
from events.on_press_events import OnPressEvents
from ui.tfcc_ui import TFCCUi
from ui.ui_setup import UiSetup


# The MainUi class is a QWidget used for creating a UI in a GUI application.
class MainUi(UiSetup, OnPressEvents, QWidget):
    def __init__(self):
        """
        This function initializes a group box and adds it to the main layout with a specified size
        policy.
        """
        super().__init__()

        self.tfccui_instance = TFCCUi()

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.setup_ui()

        self.create_group_box()

        self.main_layout.addWidget(self.group_box)
        self.main_layout.addWidget(self.crlabel)

    def create_group_box(self):
        """
        This function creates a group box with buttons and adds them to a layout.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(MAIN_UI_GROUPBOX_TITLE)
        self.group_box.setFont(
            QFont(UI_GROUPBOX_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold))
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum)
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        self.create_buttons(MAIN_UI_BUTTON_TEXTS)

        button_layout = QHBoxLayout()
        button_layout.setContentsMargins(*UI_CONTENTS_MARGINS)
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

        icon_paths = MAIN_UI_ICON_PATHS

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
                QSize(*(x - ICON_TO_BUTTON_MARGIN for x in MAIN_UI_BUTTON_SIZE)))

            button.setFixedSize(QSize(*MAIN_UI_BUTTON_SIZE))

            button.setToolTip(tooltip)

            self.group_box_layout.addWidget(button)

            self.buttons.append(button)

        for i, button in enumerate(self.buttons):
            show_tfccui = partial(self.open_tfccui, i)
            button.clicked.connect(show_tfccui)

    def open_tfccui(self, index):
        """
        The function opens a TFCCUI instance and closes the current instance if the index is 0.

        :param index: The index parameter is an integer value that is used to determine which action to
        take in the function. If the value of index is 0, the function will close the current instance
        and show a new instance of the tfccui
        """
        if index == 0:
            self.close()
            self.tfccui_instance.show()
