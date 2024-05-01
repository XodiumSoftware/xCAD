"""This module contains the database tables."""

import sqlalchemy as sql

from stenlib import Utils


class PreferencesTable(Utils.database.base):
    """A class used to represent a table module."""

    __tablename__ = "preferences"
    key = sql.Column(sql.String, primary_key=True)
    value = sql.Column(sql.String)
