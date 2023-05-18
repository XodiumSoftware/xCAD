from PySide6.QtCore import QPoint
from PySide6.QtGui import QGuiApplication


class UIHandler:
    def __init__(self):
        pass

    @staticmethod
    def center_ui_on_screen_handler(ui):
        """
        Centers the window on the primary screen.
        """
        screen_geometry = QGuiApplication.primaryScreen().geometry()
        center_point = screen_geometry.center()
        ui_center = ui.geometry().center()
        ui_top_left = QPoint(
            center_point.x() - ui_center.x(),
            center_point.y() - ui_center.y(),
        )
        ui.move(ui_top_left)
