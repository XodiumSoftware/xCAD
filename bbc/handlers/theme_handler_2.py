from PySide6.QtCore import QFile, QSettings, QTextStream
from PySide6.QtWidgets import QApplication

DARK_THEME_FILE = "bbc/data/themes/dark.css"
LIGHT_THEME_FILE = "bbc/data/themes/light.css"

SETTINGS_ORGANIZATION = "MyApp"
SETTINGS_APPLICATION = "ThemeSettings"

KEY_THEME = "theme"
KEY_THEME_LIGHT = "light"
KEY_THEME_DARK = "dark"


class ThemeHandler:
    def __init__(self):
        self.settings = QSettings(SETTINGS_ORGANIZATION, SETTINGS_APPLICATION)
        self.app = QApplication([])
        self.dark_stylesheet = self.load_stylesheet(DARK_THEME_FILE)
        self.light_stylesheet = self.load_stylesheet(LIGHT_THEME_FILE)
        self.load_theme()

    def load_stylesheet(self, filename):
        file = QFile(filename)
        if file.open(QFile.OpenModeFlag.ReadOnly | QFile.OpenModeFlag.Text):
            stream = QTextStream(file)
            stylesheet = stream.readAll()
            file.close()
            return stylesheet

    def load_theme(self):
        theme = self.settings.value(KEY_THEME, KEY_THEME_LIGHT)
        if theme == KEY_THEME_DARK:
            self.set_dark_theme()
        else:
            self.set_light_theme()

    def set_dark_theme(self):
        if self.dark_stylesheet:
            self.app.setStyleSheet(self.dark_stylesheet)
            self.settings.setValue(KEY_THEME, KEY_THEME_DARK)

    def set_light_theme(self):
        if self.light_stylesheet:
            self.app.setStyleSheet(self.light_stylesheet)
            self.settings.setValue(KEY_THEME, KEY_THEME_LIGHT)
