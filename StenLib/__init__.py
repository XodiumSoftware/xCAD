from StenLib.converter import Converter
from StenLib.forger import Forger
from StenLib.generator import Generator
from StenLib.logger import Logger
from StenLib.wrapper import Wrapper


class Utils:
    """A class that contains utility functions."""

    (
        convert,
        forge,
        generate,
        log,
        wrap,
    ) = (
        Converter,
        Forger,
        Generator,
        Logger,
        Wrapper,
    )
