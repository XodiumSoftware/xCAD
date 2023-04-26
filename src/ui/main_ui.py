from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *
from handlers.data_handler import *
from handlers.theme_handler import *
from handlers.ui_handler import *
from ui.config_ui import *


class MainUI(QWidget, ConfigUI):
    def __init__(self):
        """
        Initialize the main application window.
        """
        super().__init__()
        # Instances
        self.data_handler_instance = DataHandler()
        self.theme_handler_instance = ThemeHandler()
        self.ui_handler_instance = UIHandler()

        self.config_ui_frame_visible = False
        self.theme_instance = self.theme_handler_instance.current_theme

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
        self.main_ui_layout = QGridLayout(self)
        self.main_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.main_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        # Call widgets
        self.button_layout_setup()
        self.desc_label()
        self.central_layout_setup()
        self.copy_right_label()
        self.config_ui_frame_setup()

        # Add widgets to main_ui_layout
        self.main_ui_layout.addWidget(self.button_frame, 0, 0)
        self.main_ui_layout.addWidget(
            self.main_label,
            1,
            0,
            alignment=Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignHCenter,
        )
        self.main_ui_layout.addWidget(
            self.central_frame, 2, 0, alignment=Qt.AlignmentFlag.AlignCenter
        )
        self.main_ui_layout.addWidget(
            self.crlabel,
            3,
            0,
            alignment=Qt.AlignmentFlag.AlignBottom | Qt.AlignmentFlag.AlignLeft,
        )

        self.main_ui_layout.addWidget(self.config_ui_frame, 0, 1, 4, 1)

        # set row stretch
        self.main_ui_layout.setRowStretch(2, 1)

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

    def theme_button_setup(self):
        """
        Setup the theme button in the main UI.
        """
        self.theme_button = QPushButton(self)
        self.theme_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        self.theme_button.setToolTip(THEME_BUTTON_TOOLTIP)
        self.theme_button.setFlat(True)
        self.theme_button.setSizePolicy(
            QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
        )
        self.update_theme_button_icon()
        self.theme_button.clicked.connect(
            self.theme_handler_instance.cycle_theme_handler
        )
        self.theme_handler_instance.theme_changed.connect(self.update_theme_button_icon)

    # TODO: config_button use correct icon based on theme
    def update_theme_button_icon(self):
        """
        Update the button icon based on the theme.
        """
        if self.theme_instance == Theme.LIGHT:
            self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_LIGHT_PATH))
        elif self.theme_instance == Theme.DARK:
            self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DARK_PATH))
        else:
            self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DEFAULT_PATH))

    def config_ui_button_setup(self):
        """
        Set up the configuration UI button.
        """
        self.config_ui_button = QPushButton(self)
        self.config_ui_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        self.config_ui_button.setToolTip(CONFIG_UI_BUTTON_TOOLTIP)
        self.config_ui_button.setFlat(True)
        self.config_ui_button.setSizePolicy(
            QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
        )
        self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_LIGHT_PATH))

        self.config_ui_button.clicked.connect(self.toggle_config_ui)

    def toggle_config_ui(self):
        """
        Toggle visibility of new frame.
        """
        if self.config_ui_frame.isVisible():
            self.config_ui_frame.hide()

            if self.theme_instance == Theme.LIGHT:
                self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_LIGHT_PATH))
            elif self.theme_instance == Theme.DARK:
                self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_DARK_PATH))
            else:
                self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_LIGHT_PATH))

            new_width = self.width() - self.config_ui_frame.width()
            self.setMinimumSize(*UI_MINIMUM_SIZE)
        else:
            self.config_ui_frame.show()

            if self.theme_instance == Theme.LIGHT:
                self.config_ui_button.setIcon(
                    QIcon(CONFIG_UI_BUTTON_ICON_FLIPPED_LIGHT_PATH)
                )
            elif self.theme_instance == Theme.DARK:
                self.config_ui_button.setIcon(
                    QIcon(CONFIG_UI_BUTTON_ICON_FLIPPED_DARK_PATH)
                )
            else:
                self.config_ui_button.setIcon(
                    QIcon(CONFIG_UI_BUTTON_ICON_FLIPPED_LIGHT_PATH)
                )

            new_width = self.width() + self.config_ui_frame.width()
            self.setMinimumWidth(new_width)
        self.resize(new_width, self.height())

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

        # Add widgets to central_layout
        self.central_layout.addWidget(self.logo_label, 0, 0)

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
