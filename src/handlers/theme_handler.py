import os.path
import platform
from enum import Enum

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *

app = QApplication([])


class Theme(Enum):
    DEFAULT = "default"
    LIGHT = "light"
    DARK = "dark"


# TODO: complete the theme color schemes.
# FIXME: set_theme_handler default theme sets the stylesheet to NONE instead of light/dark.


class ThemeHandler(QObject):
    theme_changed = Signal()

    def __init__(self):
        """
        Initializes a new instance of the class.
        """
        super().__init__()
        self.current_theme = Theme.DEFAULT
        self.load_theme_handler()

    def cycle_theme_handler(self):
        """
        Cycle through all available themes and set the next one as the current theme.
        """
        all_themes = list(Theme)
        current_index = all_themes.index(self.current_theme)
        new_index = (current_index + 1) % len(all_themes)
        self.current_theme = all_themes[new_index]
        self.set_theme_handler()
        return self.current_theme.value

    def set_theme_handler(self):
        """
        Sets the theme handler for the application.
        """
        settings = QSettings()
        settings.setValue("theme", self.current_theme.value)

        if self.current_theme == Theme.DEFAULT:
            app.setStyleSheet("")
        else:
            file_path = os.path.join(
                THEME_DIR_PATH, f"{self.current_theme.value}_theme.css"
            )
            with open(file_path, "r") as f:
                app.setStyleSheet(f.read())

        self.theme_changed.emit()

    def load_theme_handler(self):
        """
        Loads the theme handler for the application.
        """
        settings = QSettings()
        theme_name = settings.value("theme", None)
        if theme_name:
            self.current_theme = Theme(theme_name)
        else:
            self.current_theme = self.ms_system_default_theme_handler() or Theme.DEFAULT
        self.set_theme_handler()

    @staticmethod
    def ms_system_default_theme_handler():
        """
        Returns the system default theme handler.
        """
        if platform.system() == "Windows":
            try:
                registry_key = "HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"
                value_name = "SystemUsesLightTheme"
                import winreg

                key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, registry_key)
                value, _ = winreg.QueryValueEx(key, value_name)
                return Theme.LIGHT if value == 0 else Theme.DARK
            except Exception:
                pass
        return None
