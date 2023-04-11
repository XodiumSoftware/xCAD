from PyQt6.QtCore import QMargins, QPoint
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import QApplication, QStyleFactory, QVBoxLayout, QWidget

from constants import (WINDOW_CONTENTS_MARGINS, WINDOW_ICON_PATH, WINDOW_STYLE,
                       WINDOW_TITLE)


class UiSetup(QWidget):
    def __init__(self):
        """
        This function initializes a user interface with a copyright label and a vertical layout.
        """
        super().__init__()

        self.setup_ui()

        self.main_layout = QVBoxLayout(self)

        self.adjustSize()

    def setup_ui(self):
        """
        This function sets up the user interface of a main window in a Python program.
        """
        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(WINDOW_ICON_PATH))
        self.margins = QMargins(*WINDOW_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)
        self.setStyle(QStyleFactory.create(WINDOW_STYLE))

    def center_window(self):
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        window_center = self.rect().center()
        window_top_left = QPoint(center_point.x() - window_center.x(),
                                 center_point.y() - window_center.y())
        self.move(window_top_left)

    def show(self):
        super().show()
        self.center_window()
