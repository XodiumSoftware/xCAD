from PySide6.QtCore import QObject, Signal


class SignalHandler(QObject):
    """A class to handle signals."""

    # FIXME: This signal is not being used correctly.
    structureButtonClicked = Signal()
