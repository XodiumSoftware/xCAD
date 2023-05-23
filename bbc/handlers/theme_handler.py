import os
import sys
import winreg

from PySide6.QtCore import QObject, QSettings, Slot
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

WINREG_THEME_KEY = os.path.join(
    r"SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize"
)
MS_VALUE_NAME = "AppsUseLightTheme"

DEBUG_NAME = "[DEBUG] "

THEME_DARK = "dark"
THEME_LIGHT = "light"
THEME_SYSTEM_DEFAULT = "system_default"

THEME_FOLDER_PATH = os.path.join("bbc/themes/")
ICONS_FOLDER_PATH = os.path.join("bbc/icons/")

THEME_FILE_PATHS = {
    THEME_DARK: os.path.join(THEME_FOLDER_PATH, "dark_theme.css"),
    THEME_LIGHT: os.path.join(THEME_FOLDER_PATH, "light_theme.css"),
}

ICONS_FILE_PATHS = {
    THEME_DARK: os.path.join(ICONS_FOLDER_PATH, "theme_icon_dark.png"),
    THEME_LIGHT: os.path.join(ICONS_FOLDER_PATH, "theme_icon_light.png"),
    THEME_SYSTEM_DEFAULT
    + "_"
    + THEME_DARK: os.path.join(ICONS_FOLDER_PATH, "theme_icon_system_default_dark.png"),
    THEME_SYSTEM_DEFAULT
    + "_"
    + THEME_LIGHT: os.path.join(
        ICONS_FOLDER_PATH, "theme_icon_system_default_light.png"
    ),
}


class MainUI(QMainWindow):
    def __init__(self):
        super().__init__()


class ThemeHandler:
    def __init__(self):
        """
        Initialize the ThemeHandler.
        """
        self._settings = QSettings("YourOrganization", "YourApplication")
        self._current_theme = THEME_LIGHT
        self._theme_states = [THEME_LIGHT, THEME_DARK, THEME_SYSTEM_DEFAULT]
        self._current_theme_index = 0
        self._button = QPushButton()

    def init_theme_handler(self):
        """
        Initialize the theme handler
        """
        # Create the main window
        self.window = QMainWindow()
        central_widget = QWidget()
        layout = QVBoxLayout(central_widget)

        button_toggle_theme = QPushButton()
        self._button = button_toggle_theme

        self.load_saved_theme()
        self._update_button()

        layout.addWidget(button_toggle_theme)
        self.window.setCentralWidget(central_widget)
        self.window.show()

        # Connect the theme button to the theme handler
        button_toggle_theme.clicked.connect(self.toggle_theme)

    def toggle_theme(self):
        """
        Toggle the theme.
        """
        self._current_theme_index = (self._current_theme_index + 1) % len(
            self._theme_states
        )
        new_theme = self._theme_states[self._current_theme_index]
        self.set_theme(new_theme)

        # Update the system default theme icon if the new theme is THEME_SYSTEM_DEFAULT
        if new_theme == THEME_SYSTEM_DEFAULT:
            system_theme_icon = self.detect_system_theme_handler()
            self._update_system_default_icon(system_theme_icon)

    def set_theme(self, theme_name):
        """
        Set the theme.
        """
        if theme_name in THEME_FILE_PATHS:
            self._current_theme = theme_name
            theme_path = THEME_FILE_PATHS[theme_name]
            style_sheet = self._loadStyleSheet(theme_path)
            self.window.setStyleSheet(style_sheet)
            self._settings.setValue("theme", theme_name)
            self._update_button()

            # Update the system default theme icon
            if theme_name == THEME_SYSTEM_DEFAULT:
                system_theme_icon = self.detect_system_theme_handler()
                self._update_system_default_icon(system_theme_icon)

    def load_saved_theme(self):
        """
        Load the saved theme.
        """
        saved_theme = str(self._settings.value("theme"))
        if saved_theme is not None:
            self.set_theme(saved_theme)

    def detect_system_theme_handler(self):
        try:
            key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, WINREG_THEME_KEY)
            value_name = MS_VALUE_NAME
            value = winreg.QueryValueEx(key, value_name)[0]
            if value == 0:
                return THEME_SYSTEM_DEFAULT + "_" + THEME_DARK
            elif value == 1:
                return THEME_SYSTEM_DEFAULT + "_" + THEME_LIGHT
        except Exception as e:
            print(DEBUG_NAME + "Error detecting system theme:", e)

    def _update_button_icon(self):
        """
        Update the button icon.
        """
        if self._current_theme in ICONS_FILE_PATHS:
            icon_file = ICONS_FILE_PATHS[self._current_theme]
            if icon_file:
                icon = QIcon(icon_file)
                self._button.setIcon(icon)

    def _update_button(self):
        """
        Update the button.
        """
        self._update_button_icon()

    def _update_system_default_icon(self, system_theme_icon):
        """
        Update the system default theme icon.
        """
        if system_theme_icon in ICONS_FILE_PATHS:
            icon_file = ICONS_FILE_PATHS[system_theme_icon]
            if icon_file:
                icon = QIcon(icon_file)
                self._button.setIcon(icon)

    @staticmethod
    def _loadStyleSheet(file_path):
        """
        Load the style sheet.
        """
        try:
            with open(file_path, "r") as file:
                return file.read()
        except IOError:
            return ""


def run():
    """
    Run the ThemeHandler.
    """
    app = QApplication([])
    theme_handler = ThemeHandler()
    theme_handler.init_theme_handler()
    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
