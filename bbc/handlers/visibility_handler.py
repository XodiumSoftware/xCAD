import weakref
from functools import partial

from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QObject
from PySide6.QtWidgets import QMainWindow


class VisibilityHandler(QObject):
    def __init__(self, parent=None):
        """
        Visibility handler for UIs
        """
        super().__init__(parent)
        self._uis = []

        self._signal_handler = SignalHandler()

    def add_ui(self, ui):
        """
        Add UI to the list of UIs
        """
        if isinstance(ui, QMainWindow):
            self._uis.append(weakref.ref(ui))

    def handle_close_event(self, handler):
        """
        Handle close event of all UIs
        """
        self._uis = [ui for ui in self._uis if ui() is not None]
        for ui in self._uis:
            ui_instance = ui()
            if ui_instance is not None:
                ui_instance.closeEvent = partial(handler, ui_instance)

        all_visible = all(ui().isVisible() for ui in self._uis if ui() is not None)
        self._signal_handler.visibilityChanged.emit(all_visible)

    def toggle_visibility(self, current_ui, target_ui_type):
        """
        Toggle visibility of target_ui_type and hide current_ui
        """
        for ui_ref in self._uis:
            ui_instance = ui_ref()
            if ui_instance is not None:
                if isinstance(ui_instance, target_ui_type):
                    ui_instance.setVisible(True)
                elif ui_instance == current_ui:
                    ui_instance.setVisible(False)
