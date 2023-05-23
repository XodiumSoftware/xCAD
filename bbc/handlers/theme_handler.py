import os

from PySide6.QtCore import QObject, QSettings, Slot
from PySide6.QtWidgets import QApplication

THEME_DARK = "dark"
THEME_LIGHT = "light"
THEME_FOLDER_PATH = os.path.join("bbc/themes/")
THEME_FILE_PATHS = {
    THEME_DARK: THEME_FOLDER_PATH + os.path.join("dark_theme.css"),
    THEME_LIGHT: THEME_FOLDER_PATH + os.path.join("light_theme.css"),
}
THEME_TEXT = {
    THEME_DARK: "Dark",
    THEME_LIGHT: "Light",
}


class ThemeHandler(QObject):
    def __init__(self, parent=None):
        super().__init__(parent)
        self._app = QApplication.instance()
        self._settings = QSettings("YourOrganization", "YourApplication")
        self._current_theme = None

    @Slot()
    def toggleTheme(self):
        if self._current_theme == THEME_DARK:
            self.setTheme(THEME_LIGHT)
        else:
            self.setTheme(THEME_DARK)

    def setTheme(self, theme_name):
        if theme_name in THEME_FILE_PATHS:
            self._current_theme = theme_name
            theme_path = THEME_FILE_PATHS[theme_name]
            style_sheet = self._loadStyleSheet(theme_path)
            self._app.setStyleSheet(style_sheet)
            self._settings.setValue("theme", theme_name)
            self._updateButtonText()

    def loadSavedTheme(self):
        saved_theme = str(self._settings.value("theme"))
        if saved_theme is not None:
            self.setTheme(saved_theme)

    def _updateButtonText(self):
        theme_text = THEME_TEXT.get(self._current_theme, "")
        button_toggle_theme.setText(f"Toggle {theme_text} Theme")

    @staticmethod
    def _loadStyleSheet(file_path):
        try:
            with open(file_path, "r") as file:
                return file.read()
        except IOError:
            return ""


if __name__ == "__main__":
    import sys

    from PySide6.QtWidgets import QMainWindow, QPushButton, QVBoxLayout, QWidget

    app = QApplication(sys.argv)

    theme_handler = ThemeHandler()
    theme_handler.loadSavedTheme()

    # Create the main window
    window = QMainWindow()
    central_widget = QWidget()
    layout = QVBoxLayout(central_widget)
    button_toggle_theme = QPushButton()
    theme_handler._updateButtonText()  # Update the initial text
    layout.addWidget(button_toggle_theme)
    window.setCentralWidget(central_widget)
    window.show()

    # Connect the theme button to the theme handler
    button_toggle_theme.clicked.connect(theme_handler.toggleTheme)

    sys.exit(app.exec())
