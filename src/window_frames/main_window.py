# These lines of code are importing necessary modules and packages for the program to run.

# Third-party imports
from PyQt6.QtCore import QMargins, QSize, Qt
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QLabel, QPushButton,
                             QStyleFactory, QVBoxLayout, QWidget)

# Internal module imports
from constants import (COPYRIGHT_LABEL, ICON_TO_BUTTON_MARGIN,
                       MAIN_WINDOW_BUTTON_SIZE, MAIN_WINDOW_BUTTON_TEXTS,
                       MAIN_WINDOW_CONTENTS_MARGINS,
                       MAIN_WINDOW_GROUPBOX_TITLE, MAIN_WINDOW_ICON_PATHS,
                       WINDOW_GROUPBOX_STYLESHEET, WINDOW_ICON_PATH,
                       WINDOW_STYLE, WINDOW_TITLE)
from events.key_press_events import close_on_key_press
from window_frames.dtfc_window import DTFCWindow


# The MainWindow class is a QWidget used for creating a window in a GUI application.
class MainWindow(QWidget):
    def __init__(self):
        """
        This function initializes a user interface with a group box and copyright label, and sets the
        current theme to 0.
        """
        super().__init__()

        self.setup_ui()

        self.crlabel = QLabel(COPYRIGHT_LABEL)

        self.main_layout = QVBoxLayout(self)
        self.main_layout.addWidget(
            self.group_box, alignment=Qt.AlignmentFlag.AlignTop)
        self.main_layout.addWidget(
            self.crlabel, alignment=Qt.AlignmentFlag.AlignLeft)

        self.adjustSize()

    def setup_ui(self):
        """
        This function sets up the user interface of a main window in a Python program.
        """
        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(WINDOW_ICON_PATH))
        self.margins = QMargins(*MAIN_WINDOW_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)
        self.setStyle(QStyleFactory.create(WINDOW_STYLE))

        self.create_group_box()

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

            icon_size = button.size().height()
            button.setIconSize(
                QSize(*(x - ICON_TO_BUTTON_MARGIN for x in MAIN_WINDOW_BUTTON_SIZE)))

            button.setFixedSize(QSize(*MAIN_WINDOW_BUTTON_SIZE))

            button.setToolTip(tooltip)

            self.group_box_layout.addWidget(button)

            self.buttons.append(button)

    def keyPressEvent(self, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        close_on_key_press(
            self, event)

    def buttonPressEvent(self, event):
        """
        Calls all the buttonPressEvent functions in the main window.
        """
        close_on_key_press(self, event)

    def open_window(self):
        """
        This function creates and displays a DTFCWindow object.
        """
        dtfc_window = DTFCWindow()
        dtfc_window.show()
