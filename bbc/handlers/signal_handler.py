from PySide6.QtCore import QObject, Signal
from PySide6.QtWidgets import QWidget


class SignalHandler(QObject):
    # FIXME: This signal is not being used correctly.
    structureButtonClicked = Signal()
    toggleModuleSignal = Signal(str, int)
    visibilityChanged = Signal(bool)

    @staticmethod
    def toggle_module(module: QWidget) -> None:  # TODO: move this to module_handler.py
        """
        Toggles the visibility of a module.
        """
        return module.setVisible(not module.isVisible())
