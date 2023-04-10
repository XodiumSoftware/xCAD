# These lines of code are importing necessary modules and packages for the program to run.

# Third-party imports
from PyQt6.QtCore import QSize, Qt
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QLabel, QPushButton,
                             QWidget)

# Internal module imports
from constants import (COPYRIGHT_LABEL, ICON_TO_BUTTON_MARGIN,
                       MAIN_WINDOW_BUTTON_SIZE, MAIN_WINDOW_BUTTON_TEXTS,
                       MAIN_WINDOW_GROUPBOX_TITLE, MAIN_WINDOW_ICON_PATHS,
                       WINDOW_GROUPBOX_STYLESHEET)
from events.press_events import OnPressEvents
from functions.window_setup import WindowSetup
from window_frames.tfcc_window import TFCCWindow


# The MainWindow class is a QWidget used for creating a window in a GUI application.
class MainWindow(WindowSetup, OnPressEvents, QWidget):
    def __init__(self):
        """
        This function initializes a class instance and adds a group box widget to its main layout.
        """
        super().__init__()

        self.create_group_box()

        self.crlabel = QLabel(COPYRIGHT_LABEL)

        self.main_layout.addWidget(
            self.group_box, alignment=Qt.AlignmentFlag.AlignTop)
        self.main_layout.addWidget(
            self.crlabel, alignment=Qt.AlignmentFlag.AlignLeft)

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
        self.group_box.setFlat(True)

        self.create_buttons(MAIN_WINDOW_BUTTON_TEXTS)

        self.group_box_layout.addStretch()

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
        dtfc_window = TFCCWindow()
        dtfc_window.show()
