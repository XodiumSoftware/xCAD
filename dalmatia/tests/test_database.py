"""This module contains unit tests for the Database class."""

import unittest
from pathlib import Path

from sqlalchemy import Column, String

from dalmatia import Utils
from dalmatia.__config__ import TEST_DATABASE_FILE
from dalmatia.database import Database


class TestTable(Utils.database.base):
    """A class to represent a test table."""

    __tablename__ = "test_table"

    key = Column(String(50), primary_key=True)
    value = Column(String(50))


class TestDatabase(unittest.TestCase):
    """A class to test the Database class."""

    @classmethod
    def setUpClass(cls: type["TestDatabase"]) -> None:
        """Sets up the test."""
        cls.db_path: Path = Path(TEST_DATABASE_FILE)
        cls.db: Database = Database(cls.db_path)
        cls.TestTable = TestTable
        cls.db.base.metadata.create_all(cls.db.engine)
        cls.db.base.metadata.reflect(bind=cls.db.engine)

    def test_add_data(self: "TestDatabase") -> None:
        """Tests the add_data method."""
        self.db.add_data(
            self.TestTable,
            {
                "key1": "value1",
                "key2": "value2",
            },
        )
        with self.db.db_session() as session:
            record1 = (
                session.query(self.TestTable).filter_by(key="key1").first()
            )
            record2 = (
                session.query(self.TestTable).filter_by(key="key2").first()
            )
            if record1 is None:
                raise AssertionError
            if record2 is None:
                raise AssertionError

    def test_set_data(self: "TestDatabase") -> None:
        """Tests the set_data method."""
        self.db.set_data(
            self.TestTable,
            {
                "key1": "value1",
                "key2": "value2",
            },
        )
        with self.db.db_session() as session:
            record1 = (
                session.query(self.TestTable).filter_by(key="key1").first()
            )
            record2 = (
                session.query(self.TestTable).filter_by(key="key2").first()
            )
            if record1 is None:
                raise AssertionError
            if record2 is None:
                raise AssertionError

    def test_delete_data(self: "TestDatabase") -> None:
        """Tests the delete_data method."""
        key = "key1"
        self.db.set_data(
            self.TestTable,
            {
                "key1": "value1",
                "key2": "value2",
            },
        )
        self.db.delete_data(self.TestTable, key)
        with self.db.db_session() as session:
            record = session.query(self.TestTable).filter_by(key=key).first()
            if record is not None:
                raise AssertionError

    def test_get_data(self: "TestDatabase") -> None:
        """Tests the get_data method."""
        key, value = "key1", "value1"
        self.db.set_data(self.TestTable, {key: value})
        result = self.db.get_data(self.TestTable, key)
        if result != value:
            raise AssertionError


if __name__ == "__main__":
    unittest.main()
