from PyQt6.QtCore import QMargins, QPoint
from PyQt6.QtGui import QIcon
from PyQt6.QtWidgets import (QApplication, QLabel, QStyleFactory, QVBoxLayout,
                             QWidget)

from constants import (COPYRIGHT_LABEL, WINDOW_CONTENTS_MARGINS,
                       WINDOW_ICON_PATH, WINDOW_STYLE, WINDOW_TITLE)


class UiSetup(QWidget):
    def setup_ui(self):
        """
        This function sets up the user interface for a PyQt5 application by creating a vertical layout,
        setting the window title and icon, creating a label for displaying copyright information, adding
        the label to the layout, and adjusting the size of the window.
        """
        self.setWindowTitle(WINDOW_TITLE)
        self.setWindowIcon(QIcon(WINDOW_ICON_PATH))
        self.margins = QMargins(*WINDOW_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)
        self.setStyle(QStyleFactory.create(WINDOW_STYLE))

        self.copyright_label()

        self.adjustSize()

    def copyright_label(self):
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL)

    def center_window(self):
        """
        This function centers a window on the screen.
        """
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        window_center = self.rect().center()
        window_top_left = QPoint(center_point.x() - window_center.x(),
                                 center_point.y() - window_center.y())
        self.move(window_top_left)

    def show(self):
        """
        This function calls the parent class's show method and then centers the window.
        """
        super().show()
        self.center_window()
