import json
from pathlib import Path

from constants import *
from PySide6.QtCore import QFile, QIODevice, QTextStream
from PySide6.QtWidgets import QLabel, QPushButton, QVBoxLayout, QWidget

# TODO: Move as much as possible into the constants file.


class ThemeHandler(QWidget):
    THEMES_FOLDER = Path("sketch_code/data")
    PREFERENCES_FILE = "sketch_code/data/preferences.json"

    def __init__(self, theme: str, preferences_file: Path):
        super().__init__()
        self.current_theme = theme
        self.preferences_file = preferences_file
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()
        self.setLayout(layout)

        self.theme_label = QLabel(f"Theme: {self.current_theme}")
        layout.addWidget(self.theme_label)

        self.toggle_button = QPushButton(
            "Toggle Theme"
        )  # TODO: Replace text with icon.
        self.toggle_button.clicked.connect(self.toggle_theme)
        layout.addWidget(self.toggle_button)

        self.load_theme_stylesheet()

    def toggle_theme(self):
        if self.current_theme == THEME_LIGHT:
            new_theme = THEME_DARK
        else:
            new_theme = THEME_LIGHT
        self.save_theme_preference(new_theme)
        self.apply_theme_stylesheet(new_theme)
        self.update_theme_label(new_theme)

    def save_theme_preference(self, theme):
        data = {"theme": theme}
        self.preferences_file.parent.mkdir(parents=True, exist_ok=True)
        with self.preferences_file.open("w") as file:
            json.dump(data, file)

    def get_last_theme_preference(self):
        try:
            with self.preferences_file.open("r") as file:
                data = json.load(file)
                return data.get("theme")
        except FileNotFoundError:
            return THEME_LIGHT

    def update_theme_label(self, theme):
        self.theme_label.setText(f"Theme: {theme}")

    def load_theme_stylesheet(self):
        theme_file = f"{self.current_theme.lower()}_theme.css"
        file_path = self.THEMES_FOLDER / theme_file
        style_sheet = self.read_stylesheet(file_path)
        self.setStyleSheet(style_sheet)

    def apply_theme_stylesheet(self, theme):
        theme_file = f"{theme.lower()}_theme.css"
        file_path = self.THEMES_FOLDER / theme_file
        style_sheet = self.read_stylesheet(file_path)
        self.setStyleSheet(style_sheet)
        self.current_theme = theme

    @staticmethod
    def read_stylesheet(file_path):
        file = QFile(str(file_path))
        if file.open(QIODevice.OpenModeFlag.ReadOnly | QIODevice.OpenModeFlag.Text):
            stream = QTextStream(file)
            stylesheet = stream.readAll()
            file.close()
            return stylesheet
        else:
            print(f"Failed to open stylesheet file: {file_path}")
            return ""
