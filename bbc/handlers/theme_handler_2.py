from PySide6.QtCore import QFile, QSettings, QTextStream
from PySide6.QtWidgets import QApplication

DARK_THEME_FILE = "bbc/data/themes/dark.css"
LIGHT_THEME_FILE = "bbc/data/themes/light.css"

SETTINGS_ORGANIZATION = "AFC"
SETTINGS_APPLICATION = "CurrentThemeSetting"

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
        stylesheet = None
        if file.open(QFile.OpenModeFlag.ReadOnly | QFile.OpenModeFlag.Text):
            try:
                stream = QTextStream(file)
                stylesheet = stream.readAll()
            finally:
                file.close()
        return stylesheet

    def load_theme(self):
        theme = self.settings.value(KEY_THEME, KEY_THEME_LIGHT)
        if theme == KEY_THEME_DARK:
            self.set_theme(KEY_THEME_DARK)
        else:
            self.set_theme(KEY_THEME_LIGHT)

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
