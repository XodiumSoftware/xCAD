from StenLib.converter import Converter
from StenLib.forger import Forger
from StenLib.logger import Logger
from StenLib.wrapper import Wrapper

__pdoc__ = {
    "StenLib.tests": False,
}


class Utils:
    """A class that contains utility functions."""

    convert, forge, log, wrap = Converter, Forger, Logger, Wrapper
