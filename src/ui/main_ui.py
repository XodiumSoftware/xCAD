from PySide6.QtCore import QPoint, QSize, Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import (
    QApplication,
    QHBoxLayout,
    QLabel,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    CONFIG_UI_BUTTON_ICON_PATH,
    CONFIG_UI_BUTTON_TOOLTIP,
    COPYRIGHT_LABEL,
    COPYRIGHT_LABEL_SIZE,
    COPYRIGHT_LABEL_STYLE,
    MAIN_UI_BUTTON_ICON_SIZE,
    MAIN_UI_BUTTON_SIZE,
    MAIN_UI_GROUPBOX_TITLE,
    THEME_BUTTON_ICON_LIGHT_PATH,
    THEME_BUTTON_TOOLTIP,
    UI_CONTENTS_MARGINS,
    UI_DESC_LABEL_STYLE,
    UI_FONT_TYPE,
    UI_GEOMETRY,
    UI_GROUPBOX_FONT_SIZE,
    UI_ICON_PATH,
    UI_MINIMUM_SIZE,
    UI_TITLE,
)
from events.events import Events
from handlers.theme_handler import ThemeHandler
from ui.config_ui import ConfigUI


class MainUI(Events):  # TODO: Call ThemeHandler in here?
    def __init__(self):
        """
        Initializes instances of ConfigUI and ThemeHandler classes,
        and calls the functions main_ui_setup() and main_ui_layout_setup().
        """
        super().__init__()
        # Instances
        self.config_ui_instance = ConfigUI()
        self.theme_handler_instance = ThemeHandler()

        self.main_ui_setup()

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

        def center_window(self):
            """
            Centers the window on the primary screen.
            """
            screen_geometry = QApplication.screens()[0].geometry()
            center_point = screen_geometry.center()
            ui_center = self.rect().center()
            ui_top_left = QPoint(
                center_point.x() - ui_center.x(),
                center_point.y() - ui_center.y(),
            )
            self.move(ui_top_left)

        center_window(self)

        self.main_ui_layout_setup()

    def main_ui_layout_setup(self):
        """
        Set up the main UI layout by creating a QVBoxLayout and adding various widgets to it.
        """
        self.main_ui_layout = QVBoxLayout(self)
        self.main_ui_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.main_ui_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        self.button_layout_setup()
        self.desc_label()
        self.central_layout_setup()
        self.copy_right_label()

        self.main_label.setAlignment(
            Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignHCenter
        )
        self.central_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.crlabel.setAlignment(
            Qt.AlignmentFlag.AlignBottom | Qt.AlignmentFlag.AlignLeft
        )

        self.main_ui_layout.addLayout(self.button_layout)
        self.main_ui_layout.addWidget(self.main_label)
        self.main_ui_layout.addStretch()
        self.main_ui_layout.addLayout(self.central_layout)
        self.main_ui_layout.addStretch()
        self.main_ui_layout.addWidget(self.crlabel)

    def button_layout_setup(self):
        self.button_layout = QHBoxLayout(self)
        self.button_layout.setAlignment(
            Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignTop
        )

        self.theme_button_setup()
        self.config_ui_button_setup()

        self.button_layout.addWidget(self.theme_button)
        self.button_layout.addStretch()
        self.button_layout.addWidget(self.config_ui_button)

    def theme_button_setup(self):
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
        # TODO: add click connect.
        # self.theme_button.clicked.connect(lambda: self.theme_handler_instance)

    def config_ui_button_setup(self):
        self.config_ui_button = QPushButton(self)
        self.config_ui_button.setObjectName("config_ui_button")
        self.config_ui_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        self.config_ui_button.setToolTip(CONFIG_UI_BUTTON_TOOLTIP)
        self.config_ui_button.setFlat(True)
        self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_PATH))
        self.config_ui_button.setIconSize(
            self.config_ui_button.size() - QSize(*MAIN_UI_BUTTON_ICON_SIZE)
        )
        self.config_ui_button.setSizePolicy(
            QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
        )
        # TODO: add click connect.

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
        self.central_layout = QHBoxLayout()
        self.central_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

    def copy_right_label(self):
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL)
        self.crlabel.setFont(QFont(UI_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)
