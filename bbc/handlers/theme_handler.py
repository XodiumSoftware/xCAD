import winreg

from constants import *
from PySide6.QtCore import QFile, QSettings, QTextStream
from PySide6.QtWidgets import QApplication


class ThemeHandler:
    def __init__(self):
        """
        Initializes the theme handler.
        """
        print("Initializing theme handler")
        self.settings = QSettings(SETTINGS_ORGANIZATION, SETTINGS_APPLICATION)
        self.app = QApplication([])
        self.dark_stylesheet = self.load_stylesheet_handler(DARK_THEME_FILE)
        self.light_stylesheet = self.load_stylesheet_handler(LIGHT_THEME_FILE)
        print("Finished initializing theme handler")

        self.load_theme_handler()

    def load_stylesheet_handler(self, filename):
        """
        Loads a stylesheet from a file.
        """
        file = QFile(filename)
        stylesheet = ""
        if file.open(QFile.OpenModeFlag.ReadOnly | QFile.OpenModeFlag.Text):
            try:
                stream = QTextStream(file)
                stylesheet = stream.readAll()
            finally:
                file.close()
        return stylesheet

    def detect_system_theme_handler(self):
        """
        Detects the system theme.
        """
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
                self.set_theme_handler(KEY_THEME_DARK)
            else:
                self.set_theme_handler(KEY_THEME_LIGHT)

        except Exception as e:
            print(DEBUG_ERROR_DETECTING_SYSTEM_THEME, e)

    def load_theme_handler(self):
        """
        Loads the theme.
        """
        # Load the saved theme from the settings
        theme = self.settings.value(KEY_THEME, KEY_THEME_LIGHT)

        if theme == KEY_THEME_DARK:
            self.set_theme_handler(KEY_THEME_DARK)
        elif theme == KEY_THEME_LIGHT:
            self.set_theme_handler(KEY_THEME_LIGHT)
        else:
            # If no theme is saved, detect the system-wide color setting
            self.detect_system_theme_handler()

    def set_theme_handler(self, theme):
        """
        Sets the theme.
        """
        if theme == KEY_THEME_DARK:
            stylesheet = self.dark_stylesheet
            theme_value = KEY_THEME_DARK
        else:
            stylesheet = self.light_stylesheet
            theme_value = KEY_THEME_LIGHT

        if stylesheet:
            self.app.setStyleSheet(stylesheet)
            self.settings.setValue(KEY_THEME, theme_value)
