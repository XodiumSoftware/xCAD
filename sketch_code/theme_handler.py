import argparse
import json
import sys
from pathlib import Path

from constants import *
from PySide6.QtCore import QFile, QIODevice, QTextStream
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

# TODO: Move as much as possible into the constants file.


class MainUI(QMainWindow):
    def __init__(
        self, theme=THEME_LIGHT, preferences_file=Path.cwd() / PREFERENCES_FILE
    ):
        super().__init__()

        # Create an instance of the ThemeHandler class with the required constructor arguments.
        self.theme_label = QLabel("Theme: ")
        self.theme_handler = ThemeHandler(theme, preferences_file, self.theme_label)

        self.init_ui(theme)

    def init_ui(self, theme):
        layout = QVBoxLayout()
        central_widget = QWidget()  # Create a central widget to hold the layout
        central_widget.setLayout(layout)
        self.setCentralWidget(
            central_widget
        )  # Set the central widget for the QMainWindow

        layout.addWidget(self.theme_label)

        self.toggle_button = QPushButton(
            "Toggle Theme"
        )  # TODO: Replace text with icon.
        self.toggle_button.clicked.connect(self.theme_handler.toggle_theme)
        layout.addWidget(self.toggle_button)

        self.theme_handler.load_theme_stylesheet(theme)


class ThemeHandler(QWidget):
    def __init__(self, theme: str, preferences_file: Path, theme_label: QLabel):
        super().__init__()
        self.preferences_file = preferences_file
        self.current_theme = self.get_last_theme_preference() or theme
        self.theme_label = theme_label

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

    def load_theme_stylesheet(self, theme):
        theme_file = f"{self.current_theme.lower()}_theme.css"
        file_path = THEMES_FOLDER / theme_file
        style_sheet = self.read_stylesheet(file_path)
        self.setStyleSheet(style_sheet)
        print("Loading theme stylesheet:", theme)

    def apply_theme_stylesheet(self, theme):
        theme_file = f"{theme.lower()}_theme.css"
        file_path = THEMES_FOLDER / theme_file
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


def main():
    parser = argparse.ArgumentParser(description="Toggle themes.")
    parser.add_argument(
        "--theme",
        dest="theme",
        default=THEME_LIGHT,
        choices=[THEME_LIGHT, THEME_DARK],
        help=f"Initial theme: {THEME_LIGHT} or {THEME_DARK}. Default: {THEME_LIGHT}.",
    )
    parser.add_argument(
        "--preferences",
        dest="preferences",
        default=Path.cwd() / PREFERENCES_FILE,
        type=Path,
        help=f"Preferences file. Default: {Path.cwd() / PREFERENCES_FILE}.",
    )
    args = parser.parse_args()

    app = QApplication(sys.argv)
    widget = MainUI(theme=args.theme, preferences_file=args.preferences)
    widget.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
