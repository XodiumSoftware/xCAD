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

    def add_table(self, table: str) -> None:
        """Creates a table with the given name if it does not exist.

        Args:
            table (str): The name of the table.
        """
        try:
            with self.__conn:
                self.__conn.execute(
                    f"""CREATE TABLE IF NOT EXISTS {table}
                        (id INTEGER PRIMARY KEY,
                            type TEXT,
                            dimx int,
                            dimy int)"""
                )
        except sqlite3.Error as e:
            raise e

    def add_data(
        self, table: str, id: int, type: str, dimx: int, dimy: int
    ) -> None:
        """Inserts data into the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type (uses abs()).
            type (str): The type of the object.
            dimx (int): The x dimension of the type (uses abs()).
            dimy (int): The y dimension of the type (uses abs()).
        """
        try:
            with self.__conn:
                self.__conn.execute(
                    f"""INSERT OR REPLACE INTO {table}
                        (id, type, dimx, dimy)
                        VALUES (?, ?, ?, ?)""",
                    (abs(id), type, abs(dimx), abs(dimy)),
                )
        except sqlite3.Error as e:
            raise e

    def del_data(self, table: str, id: int | None = None) -> None:
        """Deletes data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type.
        """
        try:
            with self.__conn:
                if id is None:
                    self.__conn.execute(f"""DELETE FROM {table}""")
                else:
                    self.__conn.execute(
                        f"""DELETE FROM {table}
                            WHERE id = ?""",
                        (id,),
                    )
        except sqlite3.Error as e:
            raise e

    def del_table(self, table: str) -> None:
        """Deletes a table with the given name if it exists.

        Args:
            table (str): The name of the table.
        """
        try:
            with self.__conn:
                self.__conn.execute(f"""DROP TABLE IF EXISTS {table}""")
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

    def __delete__(self) -> None:
        """`!!!OPERATE WITH CAUTION!!!`:
        Deletes the database."""
        try:
            os.remove(self.__path)
        except FileNotFoundError as e:
            raise e


db = Database(TIMBER_TYPES_DB_PATH)
# db.add_table(table='TimberTypes')
db.add_data(table='TimberTypes', id=0, type='SLS', dimx=38, dimy=89)
db.add_data(table='TimberTypes', id=1, type='SLS', dimx=38, dimy=89)
# db.del_data(table='TimberTypes')
# db.del_table(table='TimberTypes')
print(db.get_data(table='TimberTypes'))
# db.__delete__()
