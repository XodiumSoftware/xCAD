import os
import platform

from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *


class ThemeHandler:
    def __init__(self, app):
        self.app = app
        self.theme_button = QPushButton()
        self.theme_button.setProperty("current_theme", "light")
        self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_LIGHT_PATH))
        self.theme_button.setSizePolicy(
            QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
        )
        self.theme_button.clicked.connect(self.toggle_theme)
        self.apply_default_theme()

    def check_theme_settings(self):
        """
        Checks if there is a theme_settings.txt in the data folder containing
        the parameter "default". If not, creates it with the default contents.
        """
        settings_path = os.path.join(THEME_SETTINGS_PATH)
        if not os.path.exists(settings_path):
            with open(settings_path, "w") as f:
                f.write("light\n")

    def apply_theme_stylesheet(self, theme):
        """
        Applies the stylesheet corresponding to the given theme.
        """
        css_path = os.path.join(THEME_DIR_PATH, theme + ".css")
        if os.path.exists(css_path):
            with open(css_path, "r") as f:
                stylesheet = f.read()
                self.app.setStyleSheet(stylesheet)

    def check_system_theme(self):
        """
        Checks the Microsoft Windows system default theme light/dark.
        Returns "light" or "dark".
        """
        if platform.system() == "Windows":
            try:
                registry_key = "HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"
                value_name = "SystemUsesLightTheme"
                import winreg

                key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, registry_key)
                value, _ = winreg.QueryValueEx(key, value_name)
                return "light" if value == 0 else "dark"
            except Exception:
                pass
        return None

    def apply_default_theme(self):
        """
        Sets the application theme to "light" or "dark" based on the Microsoft
        Windows system default theme.
        """
        system_theme = self.check_system_theme()
        if system_theme:
            theme = system_theme
        else:
            self.check_theme_settings()
            with open(os.path.join(THEME_SETTINGS_PATH), "r") as f:
                theme = f.read().strip()
        self.apply_theme_stylesheet(theme)
        self.set_theme_button_icon(theme)

    def set_theme_button_icon(self, theme):
        """
        Sets the icon of the theme button based on the current theme.
        """
        if theme == "light":
            self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_LIGHT_PATH))
        elif theme == "dark":
            self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DARK_PATH))
        else:
            self.theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DEFAULT_PATH))

    def toggle_theme(self):
        """
        Toggles the application theme between "light", "dark", and "default".
        """
        current_theme = self.app.property("current_theme")
        if current_theme == "light":
            theme = "dark"
        elif current_theme == "dark":
            theme = "default"
        else:
            theme = "light"
        self.app.setProperty("current_theme", theme)
        self.apply_theme_stylesheet(theme)
        self.set_theme_button_icon(theme)
