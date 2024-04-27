"""This module contains the database functionality."""

from typing import Any

import sqlalchemy as sql
import sqlalchemy.ext.declarative as sqle
import sqlalchemy.orm as sqlo

from autoframecad.__config__ import DATABASE_FILE


class Database:
    """A class used to represent a database module."""

    base = sqlo.declarative_base()

    def __init__(self: "Database") -> None:
        """Initialize the class."""
        self.engine = sql.create_engine(str(f"sqlite:///{DATABASE_FILE}"))
        self.base.metadata.create_all(self.engine)
        self.session = sqlo.sessionmaker(bind=self.engine)

    def add_data(
        self: "Database",
        table: sqle.DeclarativeMeta,
        data: list[dict[str, Any]],
    ) -> None:
        """Add data to the database.

        Args:
            table: The table to add the data to.
            data: The data to be added.
        """
        with self.session() as session:
            for item in data:
                record = table(key=item["key"], value=item["value"])
                session.merge(record)
            session.commit()

    def get_data(
        self: "Database",
        table: sqle.DeclarativeMeta,
        key: str,
    ) -> str:
        """Get data from the database.

        Args:
            table: The table to get the data from.
            key: The key to get the data for.

        Returns:
            The data from the database.
        """
        with self.session() as session:
            record = session.query(table).filter_by(key=key).first()
            return record.value  # type: ignore[return-value]


class PreferencesTable(Database.base):
    """A class used to represent a table module."""

    __tablename__ = "preferences"
    key = sql.Column(sql.String, primary_key=True)
    value = sql.Column(sql.String)
