import os
import sys

from PySide6.QtCore import QObject, QSettings, Slot
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

THEME_DARK = "dark"
THEME_LIGHT = "light"
THEME_FOLDER_PATH = os.path.join("bbc/themes/")
ICONS_FOLDER_PATH = os.path.join("bbc/icons/")
THEME_FILE_PATHS = {
    THEME_DARK: THEME_FOLDER_PATH + os.path.join("dark_theme.css"),
    THEME_LIGHT: THEME_FOLDER_PATH + os.path.join("light_theme.css"),
}
ICONS_FILE_PATHS = {
    THEME_DARK: ICONS_FOLDER_PATH + os.path.join("theme_icon_dark.png"),
    THEME_LIGHT: ICONS_FOLDER_PATH + os.path.join("theme_icon_light.png"),
}


class ThemeHandler(QObject):
    def __init__(self, parent=None):
        super().__init__(parent)
        self._settings = QSettings("YourOrganization", "YourApplication")
        self._current_theme = "light"
        self._button = QPushButton()

    def init_theme_handler(self):
        # Create the main window
        self.window = QMainWindow()  # Store the main window reference
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

    @Slot()
    def toggle_theme(self):
        if self._current_theme == THEME_DARK:
            self.set_theme(THEME_LIGHT)
        else:
            self.set_theme(THEME_DARK)

    def set_theme(self, theme_name):
        if theme_name in THEME_FILE_PATHS:
            self._current_theme = theme_name
            theme_path = THEME_FILE_PATHS[theme_name]
            style_sheet = self._loadStyleSheet(theme_path)
            self.window.setStyleSheet(style_sheet)
            self._settings.setValue("theme", theme_name)
            self._update_button()

    def load_saved_theme(self):
        saved_theme = str(self._settings.value("theme"))
        if saved_theme is not None:
            self.set_theme(saved_theme)

    def _update_button_icon(self):
        theme_icon_path = ICONS_FILE_PATHS.get(self._current_theme)
        if theme_icon_path:
            icon = QIcon(theme_icon_path)
            self._button.setIcon(icon)

    def _update_button(self):
        self._update_button_icon()

    @staticmethod
    def _loadStyleSheet(file_path):
        try:
            with open(file_path, "r") as file:
                return file.read()
        except IOError:
            return ""


def run():
    app = QApplication([])
    theme_handler = ThemeHandler()
    theme_handler.init_theme_handler()
    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
