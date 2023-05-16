import argparse
from pathlib import Path

from constants import *
from PySide6.QtWidgets import QApplication
from theme_handler_2 import ThemeHandler

if __name__ == "__main__":
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
        default=Path.cwd() / ThemeHandler.PREFERENCES_FILE,
        type=Path,
        help=f"Preferences file. Default: {Path.cwd() / ThemeHandler.PREFERENCES_FILE}.",
    )
    args = parser.parse_args()

    app = QApplication([])
    widget = ThemeHandler(args.theme, args.preferences)
    widget.show()
    app.exec()
