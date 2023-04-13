from functools import partial

from PySide6.QtCore import QSize, Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import (
    QGroupBox,
    QHBoxLayout,
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
from ui.tfcc_ui import TFCCUi
from ui.ui_setup import UiSetup


class MainUi(UiSetup):
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

        self.tfccui_instance = TFCCUi()

    def keyPressEvent(self, tfccui_instance, event):
        """
        This function handles key press events and closes the main UI or goes back to the previous
        screen depending on the key pressed.
        """
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            if tfccui_instance():
                self.tfccui_instance.close()
                pass
        self.close()

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
            show_tfccui = partial(self.open_new_ui, i)
            button.clicked.connect(show_tfccui)

    def open_new_ui(self, index):
        """The function opens a new ui instance (closing the current one)
        based on the index of the button."""
        if index == 0:
            self.hide()
            self.tfccui_instance.show()
        # elif index == 1:
        #     self.close()
        #     self.tfccui_instance.show()
        # etc etc....
        # TODO: instead of putting tfccui_instance,
        # when other ui classes will be created
        # you have to put those classes inside the __init__
        # (e.g. self.calculations_instance = CalcUi())
        # and then check for the index in this function
        # and open it here
