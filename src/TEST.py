from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *
from handlers.data_handler import *
from handlers.theme_handler import *
from handlers.ui_handler import *
from ui.config_ui import *


def button_setup(self):
    # Set up the theme button
    self.theme_button = QPushButton(self)
    self.theme_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
    self.theme_button.setToolTip(THEME_BUTTON_TOOLTIP)
    self.theme_button.setFlat(True)
    self.theme_button.setSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)

    # Set up the config UI button
    self.config_ui_button = QPushButton(self)
    self.config_ui_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
    self.config_ui_button.setToolTip(CONFIG_UI_BUTTON_TOOLTIP)
    self.config_ui_button.setFlat(True)
    self.config_ui_button.setSizePolicy(
        QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
    )

    self.theme_button.clicked.connect(self.theme_handler_instance.cycle_theme_handler)

    # Update the button icon based on the theme.
    theme_instance = self.theme_handler_instance.current_theme

    if theme_instance == Theme.DARK:
        self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DARK_PATH))
        if self.config_ui_frame.isVisible():
            self.config_ui_frame.hide()
            self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_DARK_PATH))

            new_width = self.width() - self.config_ui_frame.width()
            self.setMinimumSize(*UI_MINIMUM_SIZE)

        else:
            self.config_ui_frame.show()
            self.config_ui_button.setIcon(
                QIcon(CONFIG_UI_BUTTON_ICON_FLIPPED_DARK_PATH)
            )

            new_width = self.width() + self.config_ui_frame.width()
            self.setMinimumWidth(new_width)

        self.resize(new_width, self.height())

    elif theme_instance == Theme.LIGHT:
        self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_LIGHT_PATH))
        if self.config_ui_frame.isVisible():
            self.config_ui_frame.hide()
            self.config_ui_button.setIcon(QIcon(CONFIG_UI_BUTTON_ICON_LIGHT_PATH))

            new_width = self.width() - self.config_ui_frame.width()
            self.setMinimumSize(*UI_MINIMUM_SIZE)

        else:
            self.config_ui_frame.show()
            self.config_ui_button.setIcon(
                QIcon(CONFIG_UI_BUTTON_ICON_FLIPPED_LIGHT_PATH)
            )

            new_width = self.width() + self.config_ui_frame.width()
            self.setMinimumWidth(new_width)

        self.resize(new_width, self.height())

    else:
        # self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DEFAULT_PATH))
        pass
