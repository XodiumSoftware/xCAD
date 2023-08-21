import sys

from constants import QSETTINGS_APPLICATION_NAME, QSETTINGS_ORGANIZATION_NAME
from PySide6.QtWidgets import QApplication


def run():
    """Run the application."""
    app = QApplication([])
    app.setOrganizationName(QSETTINGS_ORGANIZATION_NAME)
    app.setApplicationName(QSETTINGS_APPLICATION_NAME)
    # _ = TimberFrameHandler()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
