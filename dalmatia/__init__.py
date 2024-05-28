"""This module contains utility functions."""

from dalmatia.database import Database
from dalmatia.forger import Forger
from dalmatia.wrapper import Wrapper


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
