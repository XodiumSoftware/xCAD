from typing import Optional

from PySide6.QtCore import QPoint
from PySide6.QtWidgets import QApplication, QGraphicsView, QWidget

from enums.q_enums import AspectRatioModeTypes, ModuleType


class Helper:
    """Helper class for common functions"""

    @staticmethod
    def center_ui_on_screen(ui: QWidget) -> None:
        """Centers the window on the primary screen."""
        screen_center = QApplication.primaryScreen().geometry().center()
        ui_size = ui.size()
        ui.move(screen_center - QPoint(ui_size.width() // 2, ui_size.height() // 2))

    @staticmethod
    def set_ui_size(ui: QWidget, size: Optional[tuple[int, int]] = None) -> None:
        """Sets the size of the UI."""
        if size is None:
            ui.resize(ui.sizeHint())
        else:
            width, height = size
            ui.resize(width, height)

    @staticmethod
    def toggle_ui_visibility(uis: list[QWidget]) -> None:
        """Toggles the visibility of UI(s)."""
        for ui in uis:
            ui.setVisible(not ui.isVisible())
            if ui.isVisible():
                Helper.center_ui_on_screen(ui)

    @staticmethod
    def switch_modules(module: ModuleType.StackedWidget.value) -> None:
        """Switches the modules."""
        current_index = module.currentIndex()
        new_index = (current_index + 1) % module.count()
        module.setCurrentIndex(new_index)

    @staticmethod
    def fit_scene_in_view(instance: QGraphicsView) -> None:
        """Fits the scene in the view."""
        instance.fitInView(
            instance.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value
        )
