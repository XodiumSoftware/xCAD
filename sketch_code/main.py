import argparse
import sys
from pathlib import Path

from constants import *
from PySide6.QtWidgets import QApplication
from ui.main_ui import MainUI


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
    widget = MainUI()
    widget.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
