"""This module contains the database functionality."""

from collections.abc import Iterator
from contextlib import contextmanager
from pathlib import Path

import sqlalchemy as sql
import sqlalchemy.orm as sqlo
from sqlalchemy.orm import Session


class Database:
    """A class used to represent a database module."""

    base = sqlo.declarative_base()

    def __init__(self: "Database", path: Path) -> None:
        """Initialize the class.

        Args:
            path: The path to the database file.
        """
        self.engine = sql.create_engine(str(f"sqlite:///{path}"))
        self.base.metadata.create_all(self.engine)
        self.session = sqlo.sessionmaker(bind=self.engine)

    @contextmanager
    def _db_session(self: "Database") -> Iterator[Session]:
        """Context manager for a database session.

        Returns:
            The database session.
        """
        session = self.session()
        try:
            yield session
            session.commit()
        except Exception:
            session.rollback()
            raise
        finally:
            session.close()

    def _add_data(
        self: "Database",
        table: sqlo.DeclarativeMeta,
        data: dict[str, None | int | float | str | bytes],
    ) -> None:
        """Add data to the database.

        Args:
            table: The table to add the data to.
            data: The data to be added.
        """
        with self._db_session() as session:
            for key, value in data.items():
                record = table(key=key, value=value)
                session.merge(record)

    add_data = _add_data

    def _delete_data(
        self: "Database",
        table: sqlo.DeclarativeMeta,
        key: str,
    ) -> None:
        """Delete data from the database.

        Args:
            table: The table to delete the data from.
            key: The key of the data to be deleted.
        """
        with self._db_session() as session:
            record = session.query(table).filter_by(key=key).first()
            if record is not None:
                session.delete(record)

    delete_data = _delete_data

    def _get_data(
        self: "Database",
        table: sqlo.DeclarativeMeta,
        key: str,
    ) -> str:
        """Get data from the database.

        Args:
            table: The table to get the data from.
            key: The key to get the data for.

        Returns:
            The data from the database.
        """
        with self._db_session() as session:
            record = session.query(table).filter_by(key=key).first()
            return record.value if record is not None else "NULL"

    get_data = _get_data
