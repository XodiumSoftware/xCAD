# type: ignore
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class UIHandler:
    @staticmethod
    def center_ui_on_screen_handler(ui):
        """
        Centers the window on the primary screen.
        """
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        ui_center = ui.rect().center()
        ui_top_left = QPoint(
            center_point.x() - ui_center.x(),
            center_point.y() - ui_center.y(),
        )
        ui.move(ui_top_left)
