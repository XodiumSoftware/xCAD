from PySide6.QtCore import QObject, Signal


class SignalHandler(QObject):
    """A class used to represent a signal handler."""

    activateStackedModule: Signal = Signal()
