import sys

from PySide6.QtWidgets import QApplication

from experimental import MainUI


def run():
    """
    Initializes QApplication and MainUi object,
    then runs the application event loop until the application is exited.
    """
    app = QApplication(sys.argv)
    main_ui = MainUI()
    main_ui.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    run()
