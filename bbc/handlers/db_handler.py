import os
import shutil
import sqlite3
from enum import Enum
from sqlite3 import Error
from typing import List, Tuple, Union

from constants import DATABASE_PATH, MAX_BACKUPS


class DataBaseHandler:
    """A class to represent a database handler."""

    @staticmethod
    def setup_db_dir() -> None:
        """Setup the database directory."""
        os.makedirs(os.path.dirname(os.path.abspath(DATABASE_PATH)), exist_ok=True)

    @staticmethod
    def open_connection() -> Tuple[sqlite3.Connection, sqlite3.Cursor]:
        """Open the database connection and return connection and cursor."""
        conn = sqlite3.connect(DATABASE_PATH)
        return conn, conn.cursor()

    @staticmethod
    def close_connection(conn: sqlite3.Connection) -> None:
        """Close the database connection."""
        conn.close()

    @staticmethod
    def insert_data(enum_classes: Union[Enum, List[Enum]]) -> None:
        """Create the database table(s) and insert data from Enum(s)."""
        _db_handler = DataBaseHandler()
        enum_classes = (
            enum_classes if isinstance(enum_classes, list) else [enum_classes]
        )

        try:
            _db_handler.setup_db_dir()
            with sqlite3.connect(DATABASE_PATH) as conn:
                cursor = conn.cursor()

                for enum_class in enum_classes:
                    table_name = enum_class.__name__

                    columns_str = ", ".join(
                        f"{name} TEXT" for name, _ in enum_class.__members__.items()
                    )
                    query = f"""
                    CREATE TABLE IF NOT EXISTS {table_name} (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                        {columns_str}
                    )
                    """
                    cursor.execute(query)

                    for name, value in enum_class.__members__.items():
                        select_query = f"SELECT COUNT(*) FROM {table_name} WHERE {name} IS NOT NULL"
                        cursor.execute(select_query)
                        count = cursor.fetchone()[0]
                        if count == 0:
                            if isinstance(value.value, list):
                                insert_query = (
                                    f"INSERT INTO {table_name} ({name}) VALUES (?)"
                                )
                                values = [(str(item),) for item in value.value]
                                cursor.executemany(insert_query, values)
                            else:
                                insert_query = (
                                    f"INSERT INTO {table_name} ({name}) VALUES (?)"
                                )
                                cursor.execute(insert_query, (str(value.value),))

                    conn.commit()
        except Error as e:
            print(e)

    @staticmethod
    def retrieve_data(enum_classes: Union[Enum, List[Enum]]) -> List[Tuple[int, int]]:
        """Retrieve data from the database based on Enum(s)."""
        _db_handler = DataBaseHandler()
        enum_classes = (
            enum_classes if isinstance(enum_classes, list) else [enum_classes]
        )
        data = []

        try:
            _db_handler.setup_db_dir()
            with sqlite3.connect(DATABASE_PATH) as conn:
                cursor = conn.cursor()

                for enum_class in enum_classes:
                    table_name = enum_class.__name__
                    select_query = f"SELECT * FROM {table_name}"
                    cursor.execute(select_query)
                    data.extend(cursor.fetchall())

        except Error as e:
            print(e)

        return data

    @staticmethod
    def backup_database(backup_path: str) -> None:
        """Create a backup of the database file."""
        try:
            existing_backups = sorted(
                [
                    f
                    for f in os.listdir()
                    if f.startswith(backup_path) and f.endswith(".bak")
                ]
            )
            backup_number = 0
            while f"{backup_path}.bak{backup_number}" in existing_backups:
                backup_number += 1

            while len(existing_backups) >= MAX_BACKUPS:
                os.remove(existing_backups[0])
                existing_backups.pop(0)

            backup_file_name = f"{backup_path}.bak{backup_number}"
            shutil.copy(DATABASE_PATH, backup_file_name)
        except Error as e:
            print(e)
