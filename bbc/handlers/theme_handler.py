import winreg
from enum import Enum

from constants import (
    DARK_THEME_FILE,
    DEBUG_ERROR_DETECTING_SYSTEM_THEME,
    KEY_THEME,
    KEY_THEME_DARK,
    KEY_THEME_LIGHT,
    LIGHT_THEME_FILE,
    MS_VALUE_NAME,
    SETTINGS_APPLICATION,
    SETTINGS_ORGANIZATION,
    WINREG_THEME_KEY,
)
from PySide6.QtCore import QSettings
from PySide6.QtWidgets import QApplication


class Theme(Enum):
    SYSTEM = 0
    LIGHT = 1
    DARK = 2


class ThemeHandler:
    def __init__(self):
        super().__init__()

        self.settings = QSettings(SETTINGS_ORGANIZATION, SETTINGS_APPLICATION)
        self.app = QApplication([])

        self.dark_stylesheet = self.load_stylesheet_handler(DARK_THEME_FILE)
        self.light_stylesheet = self.load_stylesheet_handler(LIGHT_THEME_FILE)
        self.current_stylesheet = ""

        self.load_theme_handler()

    def load_stylesheet_handler(self, filename):
        with open(filename, "r") as file:
            return file.read()

    def detect_system_theme_handler(self):
        try:
            key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, WINREG_THEME_KEY)
            value_name = MS_VALUE_NAME
            value = winreg.QueryValueEx(key, value_name)[0]
            if value == 0:
                self.set_theme_handler(Theme.DARK)
            else:
                self.set_theme_handler(Theme.LIGHT)
        except Exception as e:
            print(DEBUG_ERROR_DETECTING_SYSTEM_THEME, e)

    def load_theme_handler(self):
        theme = self.settings.value(KEY_THEME, KEY_THEME_LIGHT)
        if theme == KEY_THEME_LIGHT:
            self.set_theme_handler(Theme.LIGHT)
        elif theme == KEY_THEME_DARK:
            self.set_theme_handler(Theme.DARK)
        else:
            self.set_theme_handler(Theme.SYSTEM)

    def set_theme_handler(self, mode):
        if mode == Theme.SYSTEM:
            self.detect_system_theme_handler()
        elif mode == Theme.LIGHT:
            self.app.setStyleSheet(self.light_stylesheet)
            self.settings.setValue(KEY_THEME, KEY_THEME_LIGHT)
        elif mode == Theme.DARK:
            self.app.setStyleSheet(self.dark_stylesheet)
            self.settings.setValue(KEY_THEME, KEY_THEME_DARK)
