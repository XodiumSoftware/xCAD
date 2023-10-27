import sys

import qdarktheme
from PySide6.QtWidgets import QApplication

from interfaces.modules.main_ui_module import MainUIModule


def run() -> int:
    """Runs the application."""
    qdarktheme.enable_hi_dpi()
    app = QApplication()
    _ = MainUIModule()
    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
