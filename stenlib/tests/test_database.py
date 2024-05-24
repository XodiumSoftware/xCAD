"""This module contains unit tests for the Database class."""

import unittest
from pathlib import Path

from stenlib.database import Database


class TestDatabase(unittest.TestCase):
    """A class to test the Database class."""

    def setUp(self: "TestDatabase") -> None:
        """Sets up the test."""
        self.db_path: Path = Path("tests/database/test_database.db")
        self.db: Database = Database(self.db_path)

    def test_add_data(self: "TestDatabase") -> None:
        """Tests the add_data method."""
        table = self.db.base.metadata.tables["table_name"]
        self.db.add_data(
            table,
            {
                "key1": "value1",
                "key2": "value2",
            },
        )
        with self.db.db_session() as session:
            record1 = session.query(table).filter_by(key="key1").first()
            record2 = session.query(table).filter_by(key="key2").first()
            if record1 is None:
                raise AssertionError
            if record2 is None:
                raise AssertionError
            if record1.value != "value1":
                raise AssertionError
            if record2.value != "value2":
                raise AssertionError

    def test_set_data(self: "TestDatabase") -> None:
        """Tests the set_data method."""
        table = self.db.base.metadata.tables["table_name"]
        self.db.set_data(
            table,
            {
                "key1": "value1",
                "key2": "value2",
            },
        )
        with self.db.db_session() as session:
            record1 = session.query(table).filter_by(key="key1").first()
            record2 = session.query(table).filter_by(key="key2").first()
            if record1 is None:
                raise AssertionError
            if record2 is None:
                raise AssertionError
            if record1.value != "value1":
                raise AssertionError
            if record2.value != "value2":
                raise AssertionError

    def test_delete_data(self: "TestDatabase") -> None:
        """Tests the delete_data method."""
        table = self.db.base.metadata.tables["table_name"]
        key = "key1"
        self.db.set_data(
            table,
            {
                "key1": "value1",
                "key2": "value2",
            },
        )
        self.db.delete_data(table, key)
        with self.db.db_session() as session:
            record = session.query(table).filter_by(key=key).first()
            if record is not None:
                raise AssertionError

    def test_get_data(self: "TestDatabase") -> None:
        """Tests the get_data method."""
        table = self.db.base.metadata.tables["table_name"]
        key, value = "key1", "value1"
        self.db.set_data(table, {key: value})
        result = self.db.get_data(table, key)
        if result != value:
            raise AssertionError


if __name__ == "__main__":
    unittest.main()
