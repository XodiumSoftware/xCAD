# These lines of code are importing necessary modules and packages for the program to run.

# Third-party imports
from PyQt6.QtCore import QMargins, QSize, Qt
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QLabel, QPushButton,
                             QVBoxLayout, QWidget, QStyleFactory)

# Internal module imports
from constants import (TFCCAD_COPYRIGHT_LABEL, TFCCAD_GROUPBOX_TITLE,
                       TFCCAD_MAIN_WINDOW_CONTENTS_MARGINS,
                       TFCCAD_MAIN_WINDOW_ICON_PATH, TFCCAD_MAIN_WINDOW_TITLE,
                       MAIN_WINDOW_ICON_PATHS, MAIN_WINDOW_BUTTON_SIZE)
from events.key_press_events import close_on_key_press


# The class MainWindow is a QWidget used in Python programming.
class MainWindow(QWidget):
    def __init__(self):
        """
        This function initializes a user interface with a group box and copyright label, and sets the
        current theme to 0.
        """
        super().__init__()

        self.setup_ui()

        self.crlabel = QLabel(TFCCAD_COPYRIGHT_LABEL)

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setContentsMargins(QMargins(0, 0, 0, 0))
        self.main_layout.addWidget(
            self.group_box, alignment=Qt.AlignmentFlag.AlignTop)
        self.main_layout.addWidget(
            self.crlabel, alignment=Qt.AlignmentFlag.AlignLeft)

        self.create_buttons(["Draw TFC", "Calculate Area",
                            "Button 3", "Button 4", "Button 5"])

        self.adjustSize()

    def setup_ui(self):
        """
        This function sets up the user interface of a main window in a Python program.
        """
        self.setWindowTitle(TFCCAD_MAIN_WINDOW_TITLE)
        self.setWindowIcon(QIcon(TFCCAD_MAIN_WINDOW_ICON_PATH))
        self.margins = QMargins(*TFCCAD_MAIN_WINDOW_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)
        self.setStyle(QStyleFactory.create("Fusion"))

        self.create_group_box()

    def create_group_box(self):
        """
        This function creates a group box with a horizontal layout, a title, centered alignment, and
        stretchable buttons.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(
            "QGroupBox { border: 0; padding-top: 20; }")
        self.group_box.setTitle(TFCCAD_GROUPBOX_TITLE)
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        # self.create_buttons()
        self.group_box_layout.addStretch()

    def create_buttons(self, button_texts):
        """
        This function creates buttons with icons and tooltips and adds them to a group box layout.
        """
        self.buttons = []
        
        # Define a list of icon paths for each button
        icon_paths = MAIN_WINDOW_ICON_PATHS

        # Loop through each button text and icon path
        for i in range(len(button_texts)):
            button_text = button_texts[i]
            icon_path = icon_paths[i]

            # Create a new button with the given text
            button = QPushButton()

            # Set the button's tooltip text to the capitalized version of the text
            button.setToolTip(" ".join(button_text.split("_")).title())
            
            # Set the button's icon using the given icon path
            button.setIcon(QIcon(icon_path))
            
            # Resize the icon based on the button size
            icon_size = button.size().height()
            button.setIconSize(QSize(*MAIN_WINDOW_BUTTON_SIZE))

            # Set the button's fixed size using the values in the TFCCAD_MAIN_WINDOW_BUTTON_SIZE constant
            # NOTE: Leaving QSize empty creates negative numbers in the terminal.
            button.setFixedSize(QSize(*MAIN_WINDOW_BUTTON_SIZE)) # NOTE: You can't leave the QSize empty otherwise it will give a "negative number" error in the terminal.

            # Add the button to the group box layout
            self.group_box_layout.addWidget(button)

            # Add the button to the list of buttons for later reference
            self.buttons.append(button)

    def keyPressEvent(self, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        close_on_key_press(
            self, event)  # NOTE: You don't need to call ui here since it's already being handled in the event file.

    def buttonPressEvent(self, event):
        """
        Calls all the buttonPressEvent functions in the main window.
        """
        close_on_key_press(self, event)
