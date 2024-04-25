"""This module contains utility functions."""

from stenlib.converter import Converter
from stenlib.forger import Forger
from stenlib.wrapper import Wrapper


class Utils:
    """A class that contains utility functions."""

    (
        convert,
        forge,
        wrap,
    ) = (
        Converter,
        Forger,
        Wrapper,
    )
