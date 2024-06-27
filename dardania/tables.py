"""This module contains the database tables."""

import sqlalchemy as sql
from dalmatia import Utils


class UIStateTable(Utils.database.base):
    """A class used to represent a table module."""

    __tablename__ = "ui_state"
    key = sql.Column(sql.String, primary_key=True)
    value = sql.Column(sql.String)
