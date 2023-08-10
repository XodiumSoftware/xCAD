from PySide6.QtCore import QObject, Signal


class SignalHandler(QObject):
    """A class to handle signals."""

    closeDialog = Signal()
