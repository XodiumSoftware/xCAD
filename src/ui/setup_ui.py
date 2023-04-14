from PySide6.QtCore import QMargins, QPoint
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import QApplication, QLabel, QStyleFactory, QWidget

from constants import (
    COPYRIGHT_LABEL,
    COPYRIGHT_LABEL_SIZE,
    COPYRIGHT_LABEL_STYLE,
    UI_CONTENTS_MARGINS,
    UI_GROUPBOX_FONT_TYPE,
    UI_ICON_PATH,
    UI_STYLE,
    UI_TITLE,
)
from handlers.handler import Handler


class SetupUI(QWidget):
    def __init__(self):
        super().__init__()
        self.key_handler = Handler()

    def setup_ui(self):
        """
        This function sets up the user interface for a PyQt5 application by creating a vertical layout,
        setting the window title and icon, creating a label for displaying copyright information, adding
        the label to the layout, and adjusting the size of the window.
        """
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.margins = QMargins(*UI_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)
        self.setStyle(QStyleFactory.create(UI_STYLE))

        self.copyright_label()

        self.key_handler.key_pressed.connect(self.on_key_pressed)

        self.adjustSize()

    def on_key_pressed(self, key):
        print(f"ClassA received key press event for key code: {key}")

    def copyright_label(self):
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL)
        self.crlabel.setFont(QFont(UI_GROUPBOX_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)

    def center_window(self):
        """
        This function centers a window on the screen.
        """
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        window_center = self.rect().center()
        window_top_left = QPoint(
            center_point.x() - window_center.x(), center_point.y() - window_center.y()
        )
        self.move(window_top_left)

    def show(self):
        """
        This function calls the parent class's show method and then centers the window.
        """
        super().show()
        self.center_window()
