import argparse
from pathlib import Path

from constants import *
from handlers.theme_handler_2 import ThemeHandler
from PySide6.QtWidgets import QApplication


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

    app = QApplication([])
    widget = ThemeHandler(args.theme, args.preferences)
    widget.show()
    app.exec()


if __name__ == "__main__":
    main()
