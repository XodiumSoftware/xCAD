"""This module contains the settings."""

from autoframecad.__config__ import DATABASE_FILE
from autoframecad.db_tables import PreferencesTable
from stenlib import Utils


class Preferences:
    """A class used to represent a preferences module."""

    def __init__(self: "Preferences") -> None:
        """Initialize the class."""
        self.db = Utils.database(DATABASE_FILE)
        self.table = PreferencesTable
        self.db.add_data(
            self.table,
            {
                "usr_theme": "dark",
                "usr_lang": "en_INT",
            },
        )
