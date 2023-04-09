# These lines of code are importing necessary modules and packages for the program to run.

# Third-party imports
from PyQt6.QtCore import QMargins, QSize, Qt
from PyQt6.QtGui import QColor, QIcon, QPalette, QPixmap
from PyQt6.QtWidgets import (QGroupBox, QHBoxLayout, QLabel, QPushButton,
                             QVBoxLayout, QWidget)

# Internal module imports
from constants import (TFCCAD_COPYRIGHT_LABEL, TFCCAD_GROUPBOX_TITLE,
                       TFCCAD_MAIN_WINDOW_BUTTON_ICONS,
                       TFCCAD_MAIN_WINDOW_BUTTON_SIZE,
                       TFCCAD_MAIN_WINDOW_BUTTON_TEXTS,
                       TFCCAD_MAIN_WINDOW_CONTENTS_MARGINS,
                       TFCCAD_MAIN_WINDOW_ICON_PATH, TFCCAD_MAIN_WINDOW_TITLE)
from events.key_press_events import close_on_key_press
from helpers.ms_colormode import detect_colormode_in_microsoft


# The class MainWindow is a QWidget used in Python programming.
class MainWindow(QWidget):
    def __init__(self):
        """
        This function initializes a user interface with a group box and copyright label, and sets the
        current theme to 0.
        """
        super().__init__()

        self.current_theme = 0

        self.setup_ui()

        self.flip_theme()

        self.crlabel = QLabel(TFCCAD_COPYRIGHT_LABEL)

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setContentsMargins(QMargins(0, 0, 0, 0))
        self.main_layout.addWidget(
            self.group_box, alignment=Qt.AlignmentFlag.AlignTop)
        self.main_layout.addWidget(
            self.crlabel, alignment=Qt.AlignmentFlag.AlignLeft)

        self.adjustSize()

    def setup_ui(self):
        """
        This function sets up the user interface of a main window in a Python program.
        """
        self.setWindowTitle(TFCCAD_MAIN_WINDOW_TITLE)
        self.setWindowIcon(QIcon(TFCCAD_MAIN_WINDOW_ICON_PATH))
        self.margins = QMargins(*TFCCAD_MAIN_WINDOW_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)

        self.create_group_box()

    def create_group_box(self):
        """
        This function creates a group box with a horizontal layout, a title, centered alignment, and
        stretchable buttons.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setTitle(TFCCAD_GROUPBOX_TITLE)
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)

        self.create_buttons()
        self.group_box_layout.addStretch()

    def set_button_theme(self, button):
        """
        This function sets the theme of a button by changing its background color and icon.
        """
        themes = {
            0: {"button_color": "#202020", "button_icon_path": None},
            1: {"button_color": "#FFFFFF", "button_icon_path": None}
        }
        theme = themes[self.current_theme]
        button.setStyleSheet(f"background-color: {theme['button_color']};")
        if theme['button_icon_path'] is not None:
            button.setIcon(QIcon(QPixmap(theme['button_icon_path'])))

    def create_buttons(self):
        """
        This function creates buttons with icons and tooltips and adds them to a group box layout.
        """
        self.buttons = []
        for button_text, button_icon_path in zip(TFCCAD_MAIN_WINDOW_BUTTON_TEXTS, TFCCAD_MAIN_WINDOW_BUTTON_ICONS):
            button = QPushButton()
            button.setToolTip(" ".join(button_text.split("_")).title())
            button.setFixedSize(QSize(*TFCCAD_MAIN_WINDOW_BUTTON_SIZE))
            button.setIcon(QIcon(QPixmap(button_icon_path)))
            self.set_button_theme(button)
            self.group_box_layout.addWidget(button)
            self.buttons.append(button)

    def KeyPressEvent(self, ui, event):
        """
        Calls all the keyPressEvent functions in the main window.
        """
        close_on_key_press(ui, event)

    def toggle_theme(self):
        """
        This function toggles the current theme and calls another function to update the UI accordingly.
        """
        self.current_theme = not self.current_theme
        self.flip_theme()

    def flip_theme(self):
        """
        This function flips the color theme of a GUI based on the current color mode of the operating
        system.
        """
        palette = QPalette()
        if detect_colormode_in_microsoft():
            palette.setColor(QPalette.ColorRole.Window, QColor(0, 0, 0))
            palette.setColor(QPalette.ColorRole.WindowText,
                             QColor(255, 255, 255))
            palette.setColor(QPalette.ColorRole.Base, QColor(35, 35, 35))
            palette.setColor(QPalette.ColorRole.AlternateBase,
                             QColor(45, 45, 45))
            palette.setColor(QPalette.ColorRole.ToolTipBase,
                             QColor(30, 30, 30))
            palette.setColor(QPalette.ColorRole.ToolTipText,
                             QColor(255, 255, 255))
            palette.setColor(QPalette.ColorRole.Text, QColor(255, 255, 255))
            palette.setColor(QPalette.ColorRole.Highlight,
                             QColor(30, 144, 255))

            title_text_color = QColor(255, 255, 255)
        else:
            palette.setColor(QPalette.ColorRole.Window, QColor(255, 255, 255))
            palette.setColor(QPalette.ColorRole.WindowText, QColor(0, 0, 0))
            palette.setColor(QPalette.ColorRole.Base, QColor(230, 230, 230))
            palette.setColor(QPalette.ColorRole.AlternateBase,
                             QColor(240, 240, 240))
            palette.setColor(QPalette.ColorRole.ToolTipBase,
                             QColor(230, 230, 230))
            palette.setColor(QPalette.ColorRole.ToolTipText, QColor(0, 0, 0))
            palette.setColor(QPalette.ColorRole.Text, QColor(0, 0, 0))
            palette.setColor(QPalette.ColorRole.Highlight,
                             QColor(51, 153, 255))

            title_text_color = QColor(0, 0, 0)

        title_palette = self.group_box.palette()
        title_palette.setColor(QPalette.ColorRole.WindowText, title_text_color)
        self.group_box.setPalette(title_palette)

        palette.setColor(QPalette.ColorRole.HighlightedText,
                         QColor(255, 255, 255))

        # Update UI
        for button in self.buttons:
            self.set_button_theme(button)

        self.setPalette(palette)
