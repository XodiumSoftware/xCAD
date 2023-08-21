import os
import sqlite3
from sqlite3 import Error

from constants import DATABASE_PATH


class DataBaseHandler:
    """A class to represent a database handler."""

    def __init__(self) -> None:
        """Initialize the database handler."""
        self.setup_db_dir(os.path.dirname(os.path.abspath(DATABASE_PATH)))
        self._conn = sqlite3.connect(DATABASE_PATH)
        self._c = self._conn.cursor()

    @staticmethod
    def setup_db_dir(dir: str) -> None:
        """Setup the database directory."""
        if not os.path.exists(dir):
            os.makedirs(dir)

    def create_table(self, table_name: str, *columns: str) -> None:
        """Create the database table."""
        self._conn
        print(f"_conn value before using in with statement: {self._conn}")
        columns_str = ", ".join([f"{col} TEXT" for col in columns])
        query = f"""
        CREATE TABLE IF NOT EXISTS {table_name} (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            {columns_str}
        )
        """
        try:
            with self._conn:
                self._c.execute(query)
        except Error as e:
            print(e)

    def insert_data(self, table_name: str, *values) -> None:
        """Insert data into the database."""
        self._conn
        placeholders = ", ".join(["?" for _ in values])
        query = f"""
        INSERT INTO {table_name}
        VALUES (NULL, {placeholders})
        """
        try:
            with self._conn:
                self._c.execute(query, values)
        except Error as e:
            print(e)

    def close_db(self) -> None:
        """Close the database."""
        if self._conn:
            self._conn.close()
