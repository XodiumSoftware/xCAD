import sys

from interfaces.configs.ui_configs import MainUIConfig
from interfaces.modules.ui_module import MainUIModule
from PySide6.QtWidgets import QApplication


def run() -> int:
    """Runs the application."""
    app = QApplication([])
    _ = MainUIModule(MainUIConfig())
    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
