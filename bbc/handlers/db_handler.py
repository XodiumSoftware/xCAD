import os
import sqlite3
from sqlite3 import Error
from typing import List, Tuple

from constants import DATABASE_PATH


class DataBaseHandler:
    """A class to represent a database handler."""

    @staticmethod
    def setup_db_dir() -> None:
        """Setup the database directory."""
        os.makedirs(os.path.dirname(os.path.abspath(DATABASE_PATH)), exist_ok=True)

    @staticmethod
    def connection() -> Tuple[sqlite3.Connection, sqlite3.Cursor]:
        """Open the database connection and return connection and cursor."""
        conn = sqlite3.connect(DATABASE_PATH)
        return conn, conn.cursor()

    @staticmethod
    def insert_data(table: str, *values: dict) -> None:
        """Insert data into the database table, creating the table if it doesn't exist."""
        _db_handler = DataBaseHandler
        _db_handler.setup_db_dir()
        try:
            conn, cursor = DataBaseHandler.connection()

            cursor.execute(
                f"SELECT name FROM sqlite_master WHERE type='table' AND name=?",
                (table,),
            )
            if cursor.fetchone() is None:
                table_creation_query = f"CREATE TABLE {table} ("

                for i, key in enumerate(values[0]):
                    column_name = str(key).split(".")[-1]
                    if i == 0:
                        table_creation_query += f"{column_name} TEXT PRIMARY KEY, "
                    else:
                        table_creation_query += f"{column_name} TEXT, "
                table_creation_query = table_creation_query[:-2] + ")"
                cursor.execute(table_creation_query)

            for val in values:
                columns = []
                values_to_insert = []
                for key, value in val.items():
                    column_name = str(key).split(".")[-1]
                    columns.append(column_name)
                    values_to_insert.append(str(value))
                query = f"INSERT OR REPLACE INTO {table} ({', '.join(columns)}) VALUES ({', '.join(['?'] * len(values_to_insert))})"
                cursor.execute(query, tuple(values_to_insert))
            conn.commit()
        except Error as e:
            print(e)

    @staticmethod
    def retrieve_data(table: str) -> List[dict]:
        """Retrieve data from the database for a given table."""
        _db_handler = DataBaseHandler
        _db_handler.setup_db_dir()
        data = []
        try:
            _, cursor = DataBaseHandler.connection()
            cursor.execute(f"SELECT * FROM {table}")
            rows = cursor.fetchall()
            columns = [desc[0] for desc in cursor.description]

            for row in rows:
                data.append({column: value for column, value in zip(columns, row)})

        except Error as e:
            print(e)

        return data
