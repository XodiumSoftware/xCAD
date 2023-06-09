from PySide6.QtCore import QPoint, QSettings
from PySide6.QtGui import QGuiApplication


class UIHandler:
    def __init__(self, main_ui):
        """
        Initialize the UIHandler.
        """
        self._settings = QSettings()
        self._main_ui = main_ui

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

    def ui_size_handler(self, ui, width, height):
        """
        Set the UI size.
        """
        ui.resize(width, height)
