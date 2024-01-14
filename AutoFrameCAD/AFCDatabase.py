import os
import sqlite3
from typing import Any

from AFCConstants import TIMBER_TYPES_DB_PATH
from StenLib.StenDecorators import ErrorHandler as StenErrorHandler


class Database:
    """A class used to represent a database."""

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def __init__(self, path: str) -> None:
        """Initializes the database object.

        Args:
            path (str): The path to the database.
        """
        self._path: str = path
        self._conn: sqlite3.Connection = sqlite3.connect(self._path)

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def add_data(self, table: str, data: list[dict[str, Any]]) -> None:
        """Inserts data into the table.

        Args:
            table (str): The name of the table.
            data (list[dict[str, Any]]): The data to be inserted.
        """
        with self._conn:
            cols = ', '.join(col for col in data[0].keys() if col != 'id')
            placeholders = ', '.join('?' for _ in data[0] if _ != 'id')
            self._conn.execute(
                f"""CREATE TABLE IF NOT EXISTS {table}
                    (id INTEGER PRIMARY KEY,
                    {', '.join([f'{col} TEXT'
                                for col in data[0].keys() if col != 'id'])})"""
            )
            self._conn.executemany(
                f"""INSERT OR REPLACE INTO {table}
                    (id, {cols})
                    VALUES (?, {placeholders})""",
                (tuple(row.values()) for row in data),
            )

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def del_data(
        self, table: str, id: int | None = None, column: str | None = None
    ) -> None:
        """Deletes data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type.
            column (str): The name of the column.
        """
        if id is not None and column is not None:
            raise ValueError('id and column cannot be used together')
        with self._conn:
            if id is not None:
                self._conn.execute(
                    f"""DELETE FROM {table}
                            WHERE id = ?""",
                    (id,),
                )
            elif column is not None:
                self._conn.execute(
                    f"""UPDATE {table}
                            SET {column} = NULL"""
                )
            else:
                self._conn.execute(f"""DELETE FROM {table}""")

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def get_data(
        self, table: str, id: int | None = None
    ) -> list[dict[str, Any]]:
        """Gets data from the table.

        Args:
            table (str): The name of the table.
            id (int, optional): The id of the type (uses abs()).
                Defaults to -1.
        """
        self._conn.row_factory = sqlite3.Row
        with self._conn:
            if id is not None:
                row = self._conn.execute(
                    f"""SELECT * FROM {table}
                        WHERE id = ?""",
                    (abs(id),),
                ).fetchone()
                rows = [row] if row else []
            else:
                rows = self._conn.execute(
                    f"""SELECT * FROM {table}"""
                ).fetchall()
        return [dict(row) for row in rows]

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def __delete__(self, table: str | None = None) -> None:
        """`!!!OPERATE WITH CAUTION!!!`: If no arguments are given,
        deletes the database!

        Args:
            table (str, optional): The name of the table. Defaults to None.
        """
        if table:
            with self._conn:
                self._conn.execute(f'DROP TABLE IF EXISTS {table}')
        else:
            os.remove(self._path)


db = Database(TIMBER_TYPES_DB_PATH)
table = 'test_table'
data = [
    {'id': 0, 'name': 'Test', 'value': '123'},
    {'id': 1, 'name': 'Test2', 'value': '456'},
    {'id': 2, 'name': 'Test3', 'value': '789'},
]
db.add_data(table, data)
print(db.get_data(table))
