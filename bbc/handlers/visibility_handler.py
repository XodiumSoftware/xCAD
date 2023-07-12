import weakref
from typing import Optional, Type

from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QObject
from PySide6.QtGui import QCloseEvent
from PySide6.QtWidgets import QMainWindow, QWidget


class VisibilityHandler(SignalHandler, QObject):
    def __new__(cls, *args: QMainWindow) -> "VisibilityHandler":
        """
        Create a new VisibilityHandler instance.
        """
        instance: VisibilityHandler = super().__new__(cls)
        instance._uis = []
        for arg in args:
            if isinstance(arg, QMainWindow):
                instance._uis.append(weakref.ref(arg))
                arg.closeEvent = instance.handle_close_event
        return instance

    def handle_close_event(self, event: QCloseEvent) -> None:
        """
        Handle close event of all UIs
        """
        self._uis = [ui for ui in self._uis if ui() is not None]
        for ui in self._uis:
            ui_instance: Optional[QMainWindow] = ui()
            if ui_instance is not None:
                event.accept()

        all_visible = all(
            ui().isVisible()
            for ui in self._uis
            if isinstance(
                ui(), QWidget
            )  # FIXME: .isVisible() "(function) isVisible: Unknown"
        )
        self.visibilityChanged.emit(all_visible)

    def toggle_visibility(
        self, current_ui: Type[QWidget], target_ui: Type[QWidget]
    ) -> None:
        """
        Toggle visibility of target_ui_type and hide current_ui
        """
        for ui_ref in self._uis:
            ui_instance: Optional[QWidget] = ui_ref()
            if ui_instance is not None:
                if isinstance(ui_instance, target_ui):
                    ui_instance.setVisible(True)
                elif isinstance(ui_instance, current_ui):
                    ui_instance.setVisible(False)
