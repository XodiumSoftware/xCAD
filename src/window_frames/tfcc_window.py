# These lines of code are importing necessary modules and packages for the program to run.

# Third-party imports
from PyQt6.QtCore import QMargins, Qt
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QLabel, QStyleFactory,
                             QVBoxLayout, QWidget)

# Internal module imports
from constants import (COPYRIGHT_LABEL, MAIN_WINDOW_CONTENTS_MARGINS,
                       MAIN_WINDOW_GROUPBOX_TITLE, WINDOW_GROUPBOX_STYLESHEET,
                       WINDOW_ICON_PATH, WINDOW_STYLE, WINDOW_TITLE)


# The DTFCWindow class is a QWidget used for creating a window in a GUI application.
class TFCCWindow(QWidget):
    def __init__(self):
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

        self.create_buttons() # FIX: create_buttons(self) first, then add it to here.

        self.group_box_layout.addStretch()

    def create_buttons(self):
        pass
