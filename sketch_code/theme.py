import json
import os

from PySide6.QtCore import QFile, QIODevice, QTextStream
from PySide6.QtWidgets import QApplication, QLabel, QPushButton, QVBoxLayout, QWidget

THEME_LIGHT = "Light"
THEME_DARK = "Dark"


class MyWidget(QWidget):
    THEMES_FOLDER = "sketch_code/themes/"
    PREFERENCES_FILE = "preferences.json"

    def __init__(self):
        super().__init__()
        self.current_theme = self.get_last_theme_preference()
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()
        self.setLayout(layout)

        self.theme_label = QLabel(f"Theme: {self.current_theme}")
        layout.addWidget(self.theme_label)

        self.toggle_button = QPushButton("Toggle Theme")
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

    def get_preferences_file_path(self):
        folder_path = os.path.join(os.getcwd(), self.THEMES_FOLDER)
        os.makedirs(folder_path, exist_ok=True)
        file_path = os.path.join(folder_path, self.PREFERENCES_FILE)
        return file_path

    def save_theme_preference(self, theme):
        data = {"theme": theme}
        file_path = self.get_preferences_file_path()
        with open(file_path, "w") as file:
            json.dump(data, file)

    def get_last_theme_preference(self):
        file_path = self.get_preferences_file_path()
        try:
            with open(file_path, "r") as file:
                data = json.load(file)
                return data.get("theme")
        except FileNotFoundError:
            return THEME_LIGHT

    def update_theme_label(self, theme):
        self.theme_label.setText(f"Theme: {theme}")

    def load_theme_stylesheet(self):
        theme_file = f"{self.current_theme.lower()}_theme.css"
        style_sheet = self.read_stylesheet(theme_file)
        self.setStyleSheet(style_sheet)

    def apply_theme_stylesheet(self, theme):
        theme_file = f"{theme.lower()}_theme.css"
        style_sheet = self.read_stylesheet(theme_file)
        self.setStyleSheet(style_sheet)
        self.current_theme = theme

    @staticmethod
    def read_stylesheet(file_name):
        file = QFile(file_name)
        if file.open(QIODevice.OpenModeFlag.ReadOnly | QIODevice.OpenModeFlag.Text):
            stream = QTextStream(file)
            style_sheet = stream.readAll()
            file.close()
            return style_sheet
        else:
            print(f"Failed to open stylesheet file: {file_name}")
            return ""


if __name__ == "__main__":
    app = QApplication([])
    widget = MyWidget()
    widget.show()
    app.exec()
