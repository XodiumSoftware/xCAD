import winreg

from PySide6.QtCore import QFile, QSettings, QTextStream
from PySide6.QtWidgets import QApplication

DARK_THEME_FILE = "bbc/data/themes/dark.css"
LIGHT_THEME_FILE = "bbc/data/themes/light.css"

SETTINGS_ORGANIZATION = "AFC"
SETTINGS_APPLICATION = "CurrentThemeSetting"

KEY_THEME = "theme"
KEY_THEME_LIGHT = "light"
KEY_THEME_DARK = "dark"

MS_VALUE_NAME = "AppsUseLightTheme"

WINREG_THEME_KEY = "Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"

DEBUG_NAME = "[DEBUG] "

DEBUG_ERROR_DETECTING_SYSTEM_THEME = DEBUG_NAME + "Error detecting system theme: "


class ThemeHandler:
    def __init__(self):
        self.settings = QSettings(SETTINGS_ORGANIZATION, SETTINGS_APPLICATION)
        self.app = QApplication([])
        self.dark_stylesheet = self.load_stylesheet(DARK_THEME_FILE)
        self.light_stylesheet = self.load_stylesheet(LIGHT_THEME_FILE)
        self.load_theme()

    def load_stylesheet(self, filename):
        file = QFile(filename)
        stylesheet = None
        if file.open(QFile.OpenModeFlag.ReadOnly | QFile.OpenModeFlag.Text):
            try:
                stream = QTextStream(file)
                stylesheet = stream.readAll()
            finally:
                file.close()
        return stylesheet

    def detect_system_theme(self):
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
                self.set_theme(KEY_THEME_DARK)
            else:
                self.set_theme(KEY_THEME_LIGHT)

        except Exception as e:
            print(DEBUG_ERROR_DETECTING_SYSTEM_THEME, e)

    def load_theme(self):
        # Load the saved theme from the settings
        theme = self.settings.value(KEY_THEME, KEY_THEME_LIGHT)

        if theme == KEY_THEME_DARK:
            self.set_theme(KEY_THEME_DARK)
        elif theme == KEY_THEME_LIGHT:
            self.set_theme(KEY_THEME_LIGHT)
        else:
            # If no theme is saved, detect the system-wide color setting
            self.detect_system_theme()

    def set_theme(self, theme):
        if theme == KEY_THEME_DARK:
            stylesheet = self.dark_stylesheet
            theme_value = KEY_THEME_DARK
        else:
            stylesheet = self.light_stylesheet
            theme_value = KEY_THEME_LIGHT

        if stylesheet:
            self.app.setStyleSheet(stylesheet)
            self.settings.setValue(KEY_THEME, theme_value)
