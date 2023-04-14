from functools import partial

from PySide6.QtCore import QSize, Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import (
    QGroupBox,
    QHBoxLayout,
    QMainWindow,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    ICON_TO_BUTTON_MARGIN,
    MAIN_UI_BUTTON_HEIGHT,
    MAIN_UI_BUTTON_TEXTS,
    MAIN_UI_BUTTON_WIDTH,
    MAIN_UI_GROUPBOX_TITLE,
    MAIN_UI_ICON_PATHS,
    UI_CONTENTS_MARGINS,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_FONT_TYPE,
    UI_GROUPBOX_STYLESHEET,
)
from handlers.ui_handler import UIHandler
from ui.setup_ui import SetupUI


class MainUI(QMainWindow, SetupUI):
    """Defines the ui for the main window."""

    def __init__(self):
        """__init__ is a special function that initializes the class attributes.
        In this case, it creates the layout for the main ui."""
        super().__init__()

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.setup_ui()

        self.create_group_box()

        self.main_layout.addWidget(self.group_box)
        self.main_layout.addWidget(self.crlabel)

    def create_group_box(self):
        """Creates group box and adds to main layout."""
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(MAIN_UI_GROUPBOX_TITLE)
        self.group_box.setFont(
            QFont(UI_GROUPBOX_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum
        )
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
        """This function creates buttons with icons and tooltips based on given constants."""

        self.buttons: list[QPushButton] = []

        icon_paths = MAIN_UI_ICON_PATHS

        for button_text, icon_path in zip(button_texts, icon_paths):
            button = QPushButton()

            if isinstance(button_text, tuple):
                button_text, tooltip = button_text
            else:
                tooltip = " ".join(button_text.split("_")).title()

            button.setIcon(QIcon(icon_path))

            btn_size = QSize(
                MAIN_UI_BUTTON_HEIGHT - ICON_TO_BUTTON_MARGIN,
                MAIN_UI_BUTTON_WIDTH - ICON_TO_BUTTON_MARGIN,
            )
            button.setIconSize(btn_size)

            button.setFixedSize(QSize(MAIN_UI_BUTTON_HEIGHT, MAIN_UI_BUTTON_WIDTH))

            button.setToolTip(tooltip)

            self.group_box_layout.addWidget(button)

            self.buttons.append(button)

        for i, button in enumerate(self.buttons):
            show_tfccui = partial(UIHandler.open_ui_handler)
            button.clicked.connect(show_tfccui)
