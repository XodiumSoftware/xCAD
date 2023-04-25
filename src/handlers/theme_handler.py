import platform
from enum import *

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class Theme(Enum):
    Default = 0
    Light = 1
    Dark = 2


class ThemeHandler(QObject):
    theme_changed = Signal()

    def __init__(self):
        super().__init__()
        self.current_theme = Theme.Default

    def cycle_theme(self):
        self.current_theme = Theme((self.current_theme.value + 1) % len(Theme))
        self.set_theme()
        self.theme_changed.emit()

    def set_theme(self):
        settings = QSettings()
        settings.setValue("theme", self.current_theme.name)

        palette = QPalette()
        if self.current_theme == Theme.Default:
            palette = QApplication.palette()
        elif self.current_theme == Theme.Light:
            palette.setColor(QPalette.ColorRole.Window, QColor(240, 240, 240))
            palette.setColor(QPalette.ColorRole.WindowText, QColor(0, 0, 0))
        elif self.current_theme == Theme.Dark:
            palette.setColor(QPalette.ColorRole.Window, QColor(53, 53, 53))
            palette.setColor(QPalette.ColorRole.WindowText, QColor(255, 255, 255))

        QApplication.setPalette(palette)

    def load_theme(self):
        settings = QSettings()
        theme_name = settings.value("theme", None)
        if theme_name:
            self.current_theme = Theme[str(theme_name)]

    @staticmethod
    def ms_system_default_theme():
        if platform.system() == "Windows":
            try:
                registry_key = "HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"
                value_name = "SystemUsesLightTheme"
                import winreg

                key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, registry_key)
                value, _ = winreg.QueryValueEx(key, value_name)
                return Theme.Light if value == 0 else Theme.Dark
            except Exception:
                pass
        return None
