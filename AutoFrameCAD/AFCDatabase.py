import os
import sqlite3
from typing import Any

from AFCConstants import TIMBER_TYPES_DB_PATH


class Database:
    """A class used to represent a database."""

    def __init__(self, path: str) -> None:
        """Initializes the database object.

        Args:
            path (str): The path to the database.
        """
        self.__path = path
        self.__conn = self.__create__()

    def __create__(self) -> sqlite3.Connection:
        """Creates the database."""
        try:
            return sqlite3.connect(self.__path)
        except sqlite3.Error as e:
            raise e

    def add_data(self, table: str, data: list[dict[str, Any]]) -> None:
        """Inserts data into the table.

        Args:
            table (str): The name of the table.
            data (list[dict[str, Any]]): A list of dictionaries,
                where each dictionary represents a row of data.
        """
        try:
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
        except sqlite3.Error as e:
            raise e

    def del_data(
        self, table: str, id: int | None = None, column: str | None = None
    ) -> None:
        """Deletes data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type.
            column (str): The name of the column.
        """
        try:
            with self.__conn:
                if id is None and column is None:
                    self.__conn.execute(f"""DELETE FROM {table}""")
                elif column is not None:
                    self.__conn.execute(
                        f"""UPDATE {table}
                            SET {column} = NULL"""
                    )
                else:
                    self.__conn.execute(
                        f"""DELETE FROM {table}
                            WHERE id = ?""",
                        (id,),
                    )
        except sqlite3.Error as e:
            raise e

    def get_data(
        self, table: str, id: int | None = None
    ) -> list[dict[Any, Any]]:
        """Gets data from the table.

        Args:
            table (str): The name of the table.
            id (int, optional): The id of the type (uses abs()).
                Defaults to -1.
        """
        try:
            self.__conn.row_factory = sqlite3.Row
            with self.__conn:
                if id is None:
                    rows = self.__conn.execute(
                        f"""SELECT * FROM {table}"""
                    ).fetchall()
                    return [dict(row) for row in rows]
                else:
                    row = self.__conn.execute(
                        f"""SELECT * FROM {table}
                        WHERE id = ?""",
                        (abs(id),),
                    ).fetchone()
                    return [dict(row)] if row else []
        except sqlite3.Error as e:
            raise e

    def __delete__(self, table: str | None = None) -> None:
        """`!!!OPERATE WITH CAUTION!!!`: If no arguments are given,
        deletes the database!

        Args:
            table (str, optional): The name of the table. Defaults to None.
        """
        try:
            if table is None:
                os.remove(self.__path)
            else:
                try:
                    with self.__conn:
                        self.__conn.execute(
                            f"""DROP TABLE IF EXISTS {table}"""
                        )
                except sqlite3.Error as e:
                    raise e

        except FileNotFoundError as e:
            raise e


db = Database(TIMBER_TYPES_DB_PATH)
db.add_data(
    table='TimberTypes',
    data=[
        {'id': 0, 'type': 'SLS', 'dimx': '38', 'dimy': '89'},
        {'id': 1, 'type': 'SLS', 'dimx': '38', 'dimy': '140'},
        {'id': 2, 'type': 'SLS', 'dimx': '38', 'dimy': '170'},
    ],
)
# db.del_data(table='TimberTypes', column='dimy')
# db.__delete__(table='TimberTypes')
# db.__delete__()
print(db.get_data(table='TimberTypes'))
