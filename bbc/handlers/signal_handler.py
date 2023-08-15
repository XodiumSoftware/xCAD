from PySide6.QtCore import QObject, Signal


class SignalHandler(QObject):
    """A class to handle signals."""

    deleteItemSignal = Signal(int)
    objectDoubleClicked = Signal(int)
