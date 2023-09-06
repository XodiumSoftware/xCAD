import random
import string
from typing import Optional

from enums.q_enums import AspectRatioModeTypes, ModuleType
from PySide6.QtCore import QPoint, QSettings
from PySide6.QtWidgets import QApplication, QGraphicsView, QWidget


class Helper:
    """Helper class for common functions"""

    @staticmethod
    def complex_id_generator(char_len: int = 6) -> str:
        """Generate a complex ID."""
        chars = string.ascii_letters + string.digits
        return "".join(random.choice(chars) for _ in range(char_len))

    @staticmethod
    def settings_manager(
        key: str, value: str, group: Optional[str] = None
    ) -> Optional[str]:
        """Manage the settings."""
        settings = QSettings()
        if group:
            settings.beginGroup(group)

        settings.setValue(key, value)
        settings.sync()

        if group:
            settings.endGroup()

        return str(settings.value(key))

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
