"""This module contains the database tables."""

import sqlalchemy as sql
from dalmatium import Utils


class UIStateTable(Utils.db.base):
    """A class used to represent a table module."""

    __tablename__ = "ui_state"
    key = sql.Column(sql.String, primary_key=True)
    value = sql.Column(sql.String)
