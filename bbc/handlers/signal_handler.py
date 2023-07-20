from PySide6.QtCore import QObject, Signal


class SignalHandler(QObject):
    # FIXME: This signal is not being used correctly.
    structureButtonClicked = Signal()
