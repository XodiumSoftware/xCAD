import os
import sqlite3 as sql3
from sqlite3 import Error

from constants import DATABASE_PATH


class DBHandler:
    """A class to represent a database handler."""

    @staticmethod
    def setup_db_dir():
        """Setup the database directory."""
        if not os.path.exists(DATABASE_PATH):
            os.makedirs(DATABASE_PATH)

    def _connect(self):
        """Connect to the database."""
        self.setup_db_dir()
        try:
            self._conn = sql3.connect(DATABASE_PATH)
        except Error as e:
            print(e)

    def create_table(self, table_name: str, *columns: str) -> None:
        """Create the database table."""
        self._connect()
        columns_str = ", ".join([f"{col} TEXT" for col in columns])
        query = f"""
        CREATE TABLE IF NOT EXISTS {table_name} (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            {columns_str}
        )
        """
        try:
            with self._conn:
                self._conn.execute(query)
        except Error as e:
            print(e)

    def insert_data(self, table_name: str, *values) -> None:
        """Insert data into the database."""
        self._connect()
        placeholders = ", ".join(["?" for _ in values])
        query = f"""
        INSERT INTO {table_name}
        VALUES (NULL, {placeholders})
        """
        try:
            with self._conn:
                self._conn.execute(query, values)
        except Error as e:
            print(e)

    def close_db(self) -> None:
        """Close the database."""
        if self._conn:
            self._conn.close()
