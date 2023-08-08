from typing import Optional, Tuple

from PySide6.QtGui import QGuiApplication
from PySide6.QtWidgets import QWidget


class UIHandler:
    """A class to handle the UI."""

    @staticmethod
    def center_ui_on_screen_handler(ui: QWidget) -> None:
        """Centers the window on the primary screen."""
        screen_geometry = QGuiApplication.primaryScreen().geometry().center()
        ui_center = ui.geometry().center()
        ui_top_left = screen_geometry - ui_center
        ui.move(ui_top_left)

    @staticmethod
    def set_ui_size(ui: QWidget, size: Optional[Tuple[int, int]] = None) -> None:
        """Sets the size of the UI."""
        if size is None:
            ui.resize(ui.sizeHint())
        else:
            width, height = size
            ui.resize(width, height)

    @staticmethod
    def toggle_ui_visibility(ui: QWidget, target_ui: QWidget) -> None:
        """Toggles the visibility of the UI."""
        ui.setVisible(not ui.isVisible())
        target_ui.setVisible(not target_ui.isVisible())
