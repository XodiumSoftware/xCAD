import os
import sqlite3
from typing import Any

from StenLib.StenDecorators import ErrorHandler as StenErrorHandler


class Database:
    """A class used to represent a database."""

    def __init__(self, path: str) -> None:
        """Initializes the database object.

        Args:
            path (str): The path to the database.
        """
        self.__path: str = path
        self.__conn: sqlite3.Connection = self.__create__()

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def __create__(self) -> sqlite3.Connection:
        """Creates the database."""
        return sqlite3.connect(self.__path)

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def add_data(self, table: str, data: list[dict[str, Any]]) -> None:
        """Inserts data into the table.

        Args:
            table (str): The name of the table.
            data (list[dict[str, Any]]): A list of dictionaries,
                where each dictionary represents a row of data.
        """
        with self.__conn:
            for row in data:
                id = row.pop('id')
                columns = ', '.join(row.keys())
                placeholders = ', '.join('?' for _ in row)
                self.__conn.execute(
                    f"""CREATE TABLE IF NOT EXISTS {table}
                        (id INTEGER PRIMARY KEY,
                        {', '.join([f'{col} TEXT'
                                    for col in row.keys()])})"""
                )
                self.__conn.execute(
                    f"""INSERT OR REPLACE INTO {table}
                        (id, {columns})
                        VALUES (?, {placeholders})""",
                    (abs(id), *row.values()),
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
        with self.__conn:
            if id is not None:
                self.__conn.execute(
                    f"""DELETE FROM {table}
                            WHERE id = ?""",
                    (id,),
                )
            elif column is not None:
                self.__conn.execute(
                    f"""UPDATE {table}
                            SET {column} = NULL"""
                )
            else:
                self.__conn.execute(f"""DELETE FROM {table}""")

    @StenErrorHandler(sqlite3.Error, FileNotFoundError)
    def get_data(
        self, table: str, id: int | None = None
    ) -> list[dict[Any, Any]]:
        """Gets data from the table.

        Args:
            table (str): The name of the table.
            id (int, optional): The id of the type (uses abs()).
                Defaults to -1.
        """
        self.__conn.row_factory = sqlite3.Row
        with self.__conn:
            if id is not None:
                row = self.__conn.execute(
                    f"""SELECT * FROM {table}
                        WHERE id = ?""",
                    (abs(id),),
                ).fetchone()
                rows = [row] if row else []
            else:
                rows = self.__conn.execute(
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
            with self.__conn:
                self.__conn.execute(f'DROP TABLE IF EXISTS {table}')
        else:
            os.remove(self.__path)
