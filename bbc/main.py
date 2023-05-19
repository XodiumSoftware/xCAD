import sys

from PySide6.QtWidgets import QApplication
from ui.main_ui import MainUI


def run():
    """
    Initializes a QApplication object and a MainUI object,
    shows the MainUI object,
    and starts the application event loop.
    """
    app = QApplication([])
    main_ui = MainUI(app)
    main_ui.show()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
