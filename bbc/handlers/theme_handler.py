import os
import platform
import winreg

from constants import (
    DEBUG_NAME,
    ICONS_FILE_PATHS,
    MS_VALUE_NAME,
    THEME_DARK,
    THEME_FILE_PATHS,
    THEME_LIGHT,
    THEME_SYSTEM_DEFAULT,
    WINREG_THEME_KEY,
)
from PySide6.QtCore import QSettings
from PySide6.QtGui import QIcon


class ThemeHandler:
    def __init__(self):
        self._settings = QSettings("Qerimi_Engineering", "AutoFrameCAD")
        self._current_theme = THEME_LIGHT
        self._theme_states = [THEME_LIGHT, THEME_DARK, THEME_SYSTEM_DEFAULT]

    def init_theme_handler(self):
        self.load_saved_theme()
        self.update_button()

    def set_button(self, button):
        self._button = button
        self._button.clicked.connect(self.toggle_theme)
        self.update_button()

    def toggle_theme(self):
        self._current_theme = self._theme_states[
            (self._theme_states.index(self._current_theme) + 1)
            % len(self._theme_states)
        ]
        self.set_theme(self._current_theme)

    def set_theme(self, theme_name):
        if theme_name in THEME_FILE_PATHS:
            self._current_theme = theme_name
            theme_path = THEME_FILE_PATHS[theme_name]
            style_sheet = self._loadStyleSheet(theme_path)
            self._button.setStyleSheet(style_sheet)
            self._settings.setValue("theme", theme_name)
            self.update_button()

    def load_saved_theme(self):
        saved_theme = str(self._settings.value("theme"))
        if saved_theme is not None:
            self.set_theme(saved_theme)

    def update_button(self):
        if self._current_theme in ICONS_FILE_PATHS:
            icon_file = ICONS_FILE_PATHS[self._current_theme]
            if icon_file:
                icon = QIcon(icon_file)
                self._button.setIcon(icon)

    def detect_system_theme_handler(self):
        try:
            if platform.system() != "Windows":
                return None

            key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, WINREG_THEME_KEY)
            value_name = MS_VALUE_NAME
            value = winreg.QueryValueEx(key, value_name)[0]
            if value == 0:
                return THEME_SYSTEM_DEFAULT + "_" + THEME_DARK
            elif value == 1:
                return THEME_SYSTEM_DEFAULT + "_" + THEME_LIGHT
        except Exception as e:
            print(DEBUG_NAME + "Error detecting system theme:", e)

    @staticmethod
    def _loadStyleSheet(file_path):
        try:
            with open(file_path, "r") as file:
                return file.read()
        except IOError:
            return ""
