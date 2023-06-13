import sys

from constants import QSETTINGS_APPLICATION_NAME, QSETTINGS_ORGANIZATION_NAME
from PySide6.QtWidgets import QApplication
from ui.main_ui import MainUI


def run():
    """
    Initializes a QApplication object and a MainUI object,
    shows the MainUI object,
    and starts the application event loop.
    """
    app = QApplication([])
    app.setOrganizationName(QSETTINGS_ORGANIZATION_NAME)
    app.setApplicationName(QSETTINGS_APPLICATION_NAME)
    main_ui = MainUI()
    main_ui.show()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
