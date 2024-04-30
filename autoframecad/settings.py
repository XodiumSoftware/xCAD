"""This module contains the settings."""

from autoframecad.db_tables import PreferencesTable
from stenlib import Utils


class Preferences:
    """A class used to represent a preferences module."""

    def __init__(self: "Preferences") -> None:
        """Initialize the class."""
        self.db = Utils.database()
        self.table = PreferencesTable
        self.db.add_data(
            self.table,
            [
                {"key": "usr_theme", "value": "dark"},
                {"key": "usr_lang", "value": "en_INT"},
            ],
        )
