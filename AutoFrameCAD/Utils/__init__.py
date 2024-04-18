__pdoc__ = {
    "Utils.tests": False,
}

from Utils.Converter import Converter
from Utils.Forger import Forger
from Utils.Logger import Logger


class Utils:
    """A class that contains utility functions."""

    forge, log, convert = Forger(), Logger(), Converter()
