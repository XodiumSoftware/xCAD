import os
import shutil
import sqlite3
from sqlite3 import Error
from typing import List, Tuple

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
    def create_or_insert_data(
        table_name: str, columns: Tuple[str, ...], *values
    ) -> None:
        """Create the database table and insert data if provided."""
        try:
            with sqlite3.connect(DATABASE_PATH) as conn:
                cursor = conn.cursor()
                columns_str = ", ".join(columns)
                query = f"""
                CREATE TABLE IF NOT EXISTS {table_name} (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    {', '.join(f'{col} TEXT' for col in columns)}
                )
                """
                cursor.execute(query)

                if values:
                    str_values = [str(value) for value in values]
                    placeholders = ", ".join(["?"] * len(str_values))
                    insert_query = f"REPLACE INTO {table_name} ({columns_str}) VALUES ({placeholders})"
                    cursor.execute(insert_query, str_values)

                conn.commit()
        except Error as e:
            print(e)

    @staticmethod
    def retrieve_data(table_name: str, *columns: str) -> List[Tuple[str, ...]]:
        """Retrieve data from the database."""
        data = []
        try:
            with sqlite3.connect(DATABASE_PATH) as conn:
                cursor = conn.cursor()
                query = f"""
                SELECT {', '.join(columns)}
                FROM {table_name}
                """
                cursor.execute(query)
                data = cursor.fetchall()
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
