from PySide6.QtCore import Signal, Slot


class SignalHandler:
    """A class used to represent a signal handler."""

    clicked_signal: Signal = Signal()


@Slot()
def print_message():
    print("Button clicked!")


SignalHandler.clicked_signal = print_message
