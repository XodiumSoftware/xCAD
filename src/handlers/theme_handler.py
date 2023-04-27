import os.path
import platform
from enum import Enum

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from constants import *

app = QApplication([])


class Theme(Enum):
    LIGHT = "light"
    DARK = "dark"
    DEFAULT = LIGHT or DARK  # FIXME: should be LIGHT or DARK and now its NONE.


class ThemeHandler(QObject):
    theme_changed = Signal()

    def __init__(self):
        """
        Initializes a new instance of the class.
        """
        super().__init__()
        self.current_theme = Theme.DARK
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

        if self.current_theme == Theme.LIGHT:
            file_path = os.path.join(THEME_DIR_PATH, LIGHT_THEME_FILE_PATH)
        elif self.current_theme == Theme.DARK:
            file_path = os.path.join(THEME_DIR_PATH, DARK_THEME_FILE_PATH)
        elif self.current_theme == Theme.DEFAULT:
            system_default_theme = self.ms_system_default_theme_handler()
            if system_default_theme == Theme.LIGHT:
                file_path = os.path.join(THEME_DIR_PATH, LIGHT_THEME_FILE_PATH)
            elif system_default_theme == Theme.DARK:
                file_path = os.path.join(THEME_DIR_PATH, DARK_THEME_FILE_PATH)
            else:
                app.setStyleSheet("")
                return
        else:
            return

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
            theme_file_path = os.path.join(THEME_SETTINGS_PATH)
            try:
                with open(theme_file_path, "r") as f:
                    theme_name = f.read().strip()
            except Exception:
                theme_name = None
            if theme_name:
                try:
                    self.current_theme = Theme(theme_name)
                except ValueError:
                    pass
            if not self.current_theme:
                system_default_theme = self.ms_system_default_theme_handler()
                if (
                    system_default_theme == Theme.LIGHT
                    or system_default_theme == Theme.DARK
                ):
                    self.current_theme = system_default_theme
                else:
                    self.current_theme = Theme.LIGHT
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
