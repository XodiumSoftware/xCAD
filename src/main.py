import sys

import qdarktheme
from PySide6.QtWidgets import QApplication

from ui import UI


def run() -> int:
    """Runs the application."""
    qdarktheme.enable_hi_dpi()
    app = QApplication()
    _ = UI()
    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
