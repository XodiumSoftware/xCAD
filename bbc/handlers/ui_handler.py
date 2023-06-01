from PySide6.QtCore import QPoint, QTimer
from PySide6.QtGui import QGuiApplication


class UIHandler:
    def __init__(self):
        """
        Initialize the UIHandler.
        """
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

    def delayed_center_ui_on_screen(self, ui):
        """
        Delayed centering of the UI on the screen.
        """
        ui.setup_main_ui()
        self.center_ui_on_screen_handler(ui)

    def toggle_ui_visibility_state(self, ui, visibility_state):
        """
        Toggle the UI visibility state.
        """
        ui._settings.setValue("checkbox_state", visibility_state)
        QTimer.singleShot(0, lambda: self.delayed_center_ui_on_screen(ui))
