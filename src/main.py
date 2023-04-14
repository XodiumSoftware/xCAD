from PySide6.QtWidgets import QApplication

from ui.main_ui import MainUi


def run():
    """Initializes QApplication and MainUi object,
    then runs the application event loop until the application is exited."""

    app = QApplication()
    main_ui = MainUi()
    main_ui.show()
    app.exec()


if __name__ == "__main__":
    run()
