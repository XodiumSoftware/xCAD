from typing import Callable

from PySide6.QtCore import Slot


@Slot()
def print_message():
    print("Button clicked!")


@Slot()
def print_message2():
    print("Button clicked2!")


@Slot()
def print_message3():
    print("Button clicked3!")


# TODO: figure out if we can assign multiple obj to one signal.


class SignalHandler:
    """A class used to represent a signal handler."""

    clicked_signal: Callable = print_message
    clicked_signal2: Callable = print_message2
    clicked_signal3: Callable = print_message3
