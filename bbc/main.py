# import argparse
import sys

# from commands.afc_cmd import AFCCMD
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

    # afc_cmd = AFCCMD()
    # afc_cmd.draw_rectangle((0, 0), (10, 10), "C:\\Users\\User\\Desktop\\test.dwg")

    # parser = argparse.ArgumentParser(
    #     description="Draw a rectangle in an AutoCAD drawing."
    # )
    # parser.add_argument("x1", type=float, help="X coordinate of the first corner point")
    # parser.add_argument("y1", type=float, help="Y coordinate of the first corner point")
    # parser.add_argument(
    #     "x2", type=float, help="X coordinate of the second corner point"
    # )
    # parser.add_argument

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
