from constants import QSETTINGS
from PySide6.QtCore import QPoint, QSettings, QTimer
from PySide6.QtGui import QGuiApplication


class UIHandler:
    def __init__(self, main_ui):
        """
        Initialize the UIHandler.
        """
        self._settings = QSettings(QSETTINGS)
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

    def delayed_center_ui_on_screen(self):
        """
        Delayed centering of the UI on the screen.
        """
        self._main_ui.setup_main_ui()
        self.center_ui_on_screen_handler(self._main_ui)

    def ui_size_handler(self, ui, width, height):
        """
        Set the UI size.
        """
        ui.resize(width, height)

    def toggle_ui_state_handler(self, state):
        """
        Toggle the state of the UI.
        """
        self._settings.setValue("checkbox_state", state)
        QTimer.singleShot(0, lambda: self.delayed_center_ui_on_screen())
