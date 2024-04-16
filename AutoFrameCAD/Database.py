import logging
import sqlite3
from pathlib import Path

from Constants import DATABASE_PATH
from Utils import Utils


class Database:
    """A class used to represent a database."""

    def __init__(self, path: Path = DATABASE_PATH) -> None:
        """Initializes the database object.

        Args:
            path (Path): The path to the database file.
                defaults to DATABASE_PATH.
        """
        try:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.touch(exist_ok=True)

            self._conn: sqlite3.Connection = sqlite3.connect(path)
            self._curs: sqlite3.Cursor = self._conn.cursor()
        except (sqlite3.Error, FileNotFoundError) as e:
            logging.error(f"Error: {e}")

    def exec_sql(
        self, sql: str, params: tuple[str | int | float | bytes, ...] = ()
    ) -> None:
        """Executes an sql statement.

        Args:
            sql (str): The sql statement.
            params (tuple[str | int | float | bytes, ...]): The parameters.
        """
        try:
            with self._conn:
                self._curs.execute(sql, params)
        except sqlite3.Error as e:
            logging.error(f"Error: {e}")

    def add_data(self) -> None:
        """Inserts data into the table."""
        data = Utils.import_json()
        try:
            if data:
                for table, rows in data.items():
                    table = Utils.sanitizer(table)
                    with self._conn:
                        cols_with_types = ", ".join(
                            [
                                f"{k} {Utils.get_sql_type(v)}"
                                for k, v in rows[0].items()
                                if k != "id"
                            ]
                        )
                        create_table_sql = f"""CREATE TABLE IF NOT EXISTS
                                                {table}
                                                (id INTEGER PRIMARY KEY,
                                                {cols_with_types})"""
                        self._curs.execute(create_table_sql)

                        for row in rows:
                            cols = ", ".join(row.keys())
                            placeholders = ", ".join("?" * len(row))
                            insert_sql = f"""INSERT OR REPLACE INTO {table}
                                            ({cols})
                                            VALUES ({placeholders})"""
                            self._curs.execute(insert_sql, tuple(row.values()))
        except (sqlite3.Error, FileNotFoundError) as e:
            logging.error(f"Error: {e}")

    def del_data(self, table: str, id: int | None = None) -> None:
        """Deletes data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type.
        """
        try:
            sql = f"DELETE FROM {table}"
            params = (id,) if id is not None else ()
            self.exec_sql(sql, params)
        except sqlite3.Error as e:
            logging.error(f"Error: {e}")

    def get_data(
        self, table: str, id: int | None = None
    ) -> list[tuple[str, int | float | str | bytes | None]]:
        """Gets data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type. Defaults to None.
                If None, returns all rows.
        """
        sql = f"SELECT * FROM {table}"
        params = (id,) if id is not None else ()
        self.exec_sql(sql, params)
        return self._curs.fetchall()

    def __del__(self) -> None:
        """Closes the database connection."""
        try:
            self._conn.close()
        except sqlite3.Error as e:
            logging.error(f"Error: {e}")
