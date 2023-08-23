from typing import List, Optional, Tuple

from enums.q_enums import ModuleType
from PySide6.QtCore import QPoint
from PySide6.QtWidgets import QApplication, QWidget


class UIHandler:
    """A class to handle the UI."""

    @staticmethod
    def center_ui_on_screen_handler(ui: QWidget) -> None:
        """Centers the window on the primary screen."""
        screen_center = QApplication.primaryScreen().geometry().center()
        ui_size = ui.size()
        ui.move(screen_center - QPoint(ui_size.width() // 2, ui_size.height() // 2))

    @staticmethod
    def set_ui_size(ui: QWidget, size: Optional[Tuple[int, int]] = None) -> None:
        """Sets the size of the UI."""
        if size is None:
            ui.resize(ui.sizeHint())
        else:
            width, height = size
            ui.resize(width, height)

    @staticmethod
    def toggle_ui_visibility(uis: List[QWidget]) -> None:
        """Toggles the visibility of UI(s)."""
        for ui in uis:
            ui.setVisible(not ui.isVisible())
            if ui.isVisible():
                UIHandler.center_ui_on_screen_handler(ui)

    @staticmethod
    def switch_modules(module: ModuleType.StackedWidget.value) -> None:
        """Switches the modules."""
        current_index = module.currentIndex()
        new_index = (current_index + 1) % module.count()
        module.setCurrentIndex(new_index)
