"""This module contains utility functions."""

from stenlib.database import Database
from stenlib.forger import Forger
from stenlib.wrapper import Wrapper


class Utils:
    """A class that contains utility functions."""

    (
        database,
        forge,
        wrap,
    ) = (
        Database,
        Forger,
        Wrapper,
    )
