import sys

import qdarktheme
from PySide6.QtWidgets import QApplication

from constants import QSETTINGS_APPLICATION_NAME, QSETTINGS_ORGANIZATION_NAME
from ui import UI


def run():
    """Run the application."""
    qdarktheme.enable_hi_dpi()
    app = QApplication([])
    app.setOrganizationName(QSETTINGS_ORGANIZATION_NAME)
    app.setApplicationName(QSETTINGS_APPLICATION_NAME)
    _ = UI()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
