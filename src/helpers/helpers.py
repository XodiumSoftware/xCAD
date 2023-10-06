from typing import Optional

from PySide6.QtCore import QPoint
from PySide6.QtWidgets import QApplication, QGraphicsView, QWidget

from enums.q_enums import AspectRatioModeTypes, ModuleType


class Helper:
    """Helper class for common functions"""

    @staticmethod
    def center_ui_on_screen(ui: QWidget) -> None:
        """Centers the window on the primary screen."""
        ui.move(
            QApplication.primaryScreen().geometry().center()
            - QPoint(ui.size().width() // 2, ui.size().height() // 2)
        )

    @staticmethod
    def set_ui_size(ui: QWidget, size: Optional[tuple[int, int]] = None) -> None:
        """Sets the size of the UI."""
        ui.resize(*size) if size else ui.resize(ui.sizeHint())

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
        module.setCurrentIndex((module.currentIndex() + 1) % module.count())

    @staticmethod
    def fit_scene_in_view(instance: QGraphicsView) -> None:
        """Fits the scene in the view."""
        instance.fitInView(
            instance.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value
        )
