import sys

from PyQt6.QtWidgets import QApplication


class Run:
    def run(self):
        """
        This function initializes a QApplication, creates a MainUi object, an OnPressEvents object, shows
        the MainUi, and runs the application event loop until the application is exited.
        """
        from ui.main_ui import MainUi

        app = QApplication(sys.argv)
        main_ui = MainUi()
        main_ui.show()
        sys.exit(app.exec())


if __name__ == "__main__":
    Run().run()
