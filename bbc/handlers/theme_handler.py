import os
import platform
import winreg
from enum import *

from constants import *
from PySide6.QtCore import *
from PySide6.QtWidgets import *


class Theme(Enum):
    SYSTEM = 0
    LIGHT = 1
    DARK = 2


class ThemeHandler:
    def __init__(self):
        """
        Initializes the theme handler.
        """
        self.settings = QSettings(SETTINGS_ORGANIZATION, SETTINGS_APPLICATION)
        self.app = QApplication([])
        self.dark_stylesheet = self.load_stylesheet_handler(DARK_THEME_FILE)
        self.light_stylesheet = self.load_stylesheet_handler(LIGHT_THEME_FILE)
        self.current_stylesheet = ""

        self.load_theme_handler()

    def load_stylesheet_handler(self, filename):
        """
        Loads a stylesheet from a file.
        """
        stylesheet = ""
        file = QFile(filename)
        if file.open(QFileDevice.ReadOnly | QFileDevice.Text):
            stream = QTextStream(file)
            stylesheet = stream.readAll()
        return stylesheet

    def detect_system_theme_handler(self):
        """
        Detects the system theme.
        """
        system = platform.system()
        if system == "Windows":
            try:
                # Open the registry key that stores the system-wide color settings
                key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, WINREG_THEME_KEY)

                # Read the value of the "AppsUseLightTheme" key
                # If the value is set to 1, the system is using the light theme
                # If the value is set to 0, the system is using the dark theme
                value_name = MS_VALUE_NAME
                value = winreg.QueryValueEx(key, value_name)[0]

                # Set the theme based on the system-wide color setting
                if value == 0:
                    self.set_theme_handler(Theme.DARK)
                else:
                    self.set_theme_handler(Theme.LIGHT)

            except Exception as e:
                print(DEBUG_ERROR_DETECTING_SYSTEM_THEME, e)

        else:
            # Get the current system theme on non-Windows platforms
            system_theme = os.environ.get("QT_STYLE_OVERRIDE", "")
            if "dark" in system_theme.lower():
                self.set_theme_handler(Theme.DARK)
            else:
                self.set_theme_handler(Theme.LIGHT)

    def load_theme_handler(self):
        """
        Loads the theme.
        """
        # Load the saved theme from the settings
        theme = self.settings.value(KEY_THEME, KEY_THEME_LIGHT)

        if theme == KEY_THEME_LIGHT:
            self.set_theme_handler(1)
        elif theme == KEY_THEME_DARK:
            self.set_theme_handler(2)
        else:
            self.set_theme_handler(0)

    def set_theme_handler(self, mode):
        """
        Sets the theme handler based on the given mode.
        """
        if mode == 0:
            self.detect_system_theme_handler()
            # TODO: add button icon path
        elif mode == 1:
            stylesheet = self.light_stylesheet
            self.app.setStyleSheet(stylesheet)
            self.settings.setValue(KEY_THEME, KEY_THEME_LIGHT)
            # TODO: add button icon path
        elif mode == 2:
            stylesheet = self.dark_stylesheet
            self.app.setStyleSheet(stylesheet)
            self.settings.setValue(KEY_THEME, KEY_THEME_DARK)
            # TODO: add button icon path
