# type: ignore
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *
from handlers.data_handler import DataHandler
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from ui.config_ui_2 import ConfigUI


class MainUI(QWidget, ConfigUI):
    def __init__(self):
        """
        Initialize the main application window.
        """
        super().__init__()
        # Instances
        self.config_ui_instance = ConfigUI()
        self.theme_handler_instance = ThemeHandler()
        self.data_handler_instance = DataHandler()
        self.ui_handler_instance = UIHandler()

        self.data_handler_instance.dir_and_file_handler()
        self.main_ui_setup()

    def keyPressEvent(self, event):
        """
        This function is called when certain keys are pressed.
        """
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
        else:
            super().keyPressEvent(event)

    def main_ui_setup(self):
        """
        Set up the main user interface properties including the window title,
        icon, geometry, minimum size, and size policy.
        Also centers the window on the screen.
        """
        # Set ui properties
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setGeometry(*UI_GEOMETRY)
        self.setMinimumSize(*UI_MINIMUM_SIZE)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)

        self.ui_handler_instance.center_ui_on_screen_handler(self)

        self.main_ui_layout_setup()

    def main_ui_layout_setup(self):
        """
        Set up the main UI layout by creating a QVBoxLayout and adding various widgets to it.
        """
        # main_ui_layout properties
        self.main_ui_layout = QVBoxLayout(self)
        self.main_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.main_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Add widgets
        self.button_layout_setup()
        self.desc_label()
        self.central_layout_setup()
        self.copy_right_label()

        # Add widgets to main_ui_layout
        self.main_ui_layout.addWidget(self.button_frame)
        self.main_ui_layout.addWidget(self.main_label)
        self.main_ui_layout.addStretch()
        self.main_ui_layout.addWidget(self.central_frame)
        self.main_ui_layout.addStretch()
        self.main_ui_layout.addWidget(self.crlabel)

        # Set widgets alignment
        self.main_label.setAlignment(
            Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignHCenter
        )
        self.central_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.crlabel.setAlignment(
            Qt.AlignmentFlag.AlignBottom | Qt.AlignmentFlag.AlignLeft
        )

    def button_layout_setup(self):
        """
        Sets up the button layout for the UI.
        """
        # Create a new frame to hold the buttons
        self.button_frame = QFrame(self)
        self.button_frame.setFrameShape(QFrame.Shape.NoFrame)

        self.button_layout = QHBoxLayout(self.button_frame)
        self.button_layout.setAlignment(
            Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignTop
        )

        self.theme_button_setup()
        self.config_ui_button_setup()

        self.button_layout.addWidget(self.theme_button)
        self.button_layout.addStretch()
        self.button_layout.addWidget(self.config_ui_button)

        # Add the button frame to the main UI layout
        self.main_ui_layout.addWidget(self.button_frame)

    # FIXME: Save the current theme mode into the data folder.
    def theme_button_setup(self):
        """
        Setup the theme button in the main UI.
        """
        self.theme_button = QPushButton(self)
        self.theme_button.setObjectName("theme_button")
        self.theme_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        self.theme_button.setToolTip(THEME_BUTTON_TOOLTIP)
        self.theme_button.setFlat(True)
        self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_LIGHT_PATH))
        self.theme_button.setIconSize(
            self.theme_button.size() - QSize(*MAIN_UI_BUTTON_ICON_SIZE)
        )
        self.theme_button.setSizePolicy(
            QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
        )
        self.theme_button.clicked.connect(
            lambda: self.theme_handler_instance.switch_theme_handler(self)
        )

    def config_ui_button_setup(self):
        """
        Set up the configuration UI button.
        """
        self.config_ui_button = QPushButton(self)
        self.config_ui_button.setObjectName("config_ui_button")
        self.config_ui_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        self.config_ui_button.setToolTip(CONFIG_UI_BUTTON_TOOLTIP)
        self.config_ui_button.setFlat(True)

        self.config_ui_button_icon = QIcon(CONFIG_UI_BUTTON_ICON_PATH)
        self.pixmap = self.config_ui_button_icon.pixmap(
            self.config_ui_button_icon.actualSize(QSize(*MAIN_UI_BUTTON_ICON_SIZE))
        )
        self.flipped_pixmap = self.pixmap.transformed(QTransform().scale(-1, 1))

        # TODO: Make the arrow go left and right when opening and closing the config UI.
        if self.open_config_ui == True:
            self.config_ui_button.setIcon(self.flipped_pixmap)

        elif self.open_config_ui == False:
            self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_PATH))

        self.config_ui_button.setSizePolicy(
            QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
        )

        self.config_ui_button.clicked.connect(lambda: self.open_config_ui)

    def open_config_ui(self):
        """
        Open the configuration UI.
        """
        # TODO: Write open_config_ui function

    def desc_label(self):
        """
        Create a description label and set its style, font, and size policy.
        """
        self.main_label = QLabel(MAIN_UI_GROUPBOX_TITLE, self)
        self.main_label.setStyleSheet(UI_DESC_LABEL_STYLE)
        self.main_label.setFont(
            QFont(UI_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.main_label.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Maximum
        )

    def central_layout_setup(self):
        """
        Sets up the central layout for the application window.
        """
        # Create a new frame to hold the layout
        self.central_frame = QFrame(self)
        self.central_frame.setFrameShape(QFrame.Shape.NoFrame)

        # central_layout properties
        self.central_layout = QGridLayout(self.central_frame)
        self.central_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.central_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Add widgets
        self.logo()
        self.config_ui_layout_setup()

        # Add widgets to central_layout
        self.central_layout.addWidget(self.logo_label, 0, 0)
        # TODO: Add if statement and link it to the button.
        self.central_layout.addWidget(self.config_ui_frame, 0, 1)

        # Set widgets alignment
        # FIXME: Is it needed?
        # self.logo_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        # self.config_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        # Add the central frame to the main UI layout
        self.main_ui_layout.addWidget(self.central_frame)

    def copy_right_label(self):
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL, self)
        self.crlabel.setFont(QFont(UI_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)

    def logo(self):
        """
        This function creates a QLabel object with a text string containing a logo.
        """
        self.logo_label = QLabel("3D Viewer COMING SOON!", self)
