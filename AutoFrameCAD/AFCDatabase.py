import json
import sqlite3
from pathlib import Path

from AFCDecorators import ErrorHandler as AFCErrorHandler
from AFCUtils import Utils as AFCUtils


class Database:
    """A class used to represent a database."""

    @AFCErrorHandler(sqlite3.Error, FileNotFoundError)
    def __init__(self, path: Path) -> None:
        """Initializes the database object.

        Args:
            path (Path): The path to the database.
        """
        self._conn: sqlite3.Connection = sqlite3.connect(path)
        self._curs: sqlite3.Cursor = self._conn.cursor()

    @AFCErrorHandler(sqlite3.Error)
    def _exec_sql(self, sql: str, id: int | None = None) -> None:
        """Executes a sql.

        Args:
            sql (str): The sql to be executed.
            id (int): The id of the type. Defaults to None.
        """
        with self._conn:
            if id is None:
                self._curs.execute(sql)
            else:
                self._curs.execute(sql + ' WHERE id=?', (id,))

    @AFCErrorHandler(sqlite3.Error)
    def _get_sql_type(self, value: int | float | str | bytes | None) -> str:
        """Gets the sql type of a value.

        Args:
            value (int | float | str | bytes): The value to be checked.
        """
        if value is None:
            return 'NULL'
        return {
            int: 'INTEGER',
            float: 'REAL',
            str: 'TEXT',
            bytes: 'BLOB',
        }.get(type(value), 'NULL')

    @AFCErrorHandler(FileNotFoundError, json.JSONDecodeError)
    def _open_json(
        self, path: Path
    ) -> dict[str, list[dict[str, None | int | float | str | bytes]]]:
        """Opens a json file.

        Args:
            path (Path): The path to the json file.
        """
        with open(path, 'r') as _file:
            return json.load(_file)

    @AFCErrorHandler(sqlite3.Error)
    def add_data(self, path: Path) -> None:
        """Inserts data into the table.

        Args:
            path (Path): The path to the json file.
        """
        for _table, _rows in self._open_json(path).items():
            _table = AFCUtils.sanitize_str(_table)
            with self._conn:
                _cols_with_types = ', '.join(
                    [
                        f'{k} {self._get_sql_type(v)}'
                        for k, v in _rows[0].items()
                        if k != 'id'
                    ]
                )
                _create_table_sql = f"""CREATE TABLE IF NOT EXISTS {_table}
                                        (id INTEGER PRIMARY KEY,
                                        {_cols_with_types})"""
                self._curs.execute(_create_table_sql)

                for _row in _rows:
                    _cols = ', '.join(_row.keys())
                    _placeholders = ', '.join('?' * len(_row))
                    _insert_sql = f"""INSERT OR REPLACE INTO {_table} ({_cols})
                                    VALUES ({_placeholders})"""
                    self._curs.execute(_insert_sql, tuple(_row.values()))

    @AFCErrorHandler(sqlite3.Error)
    def del_data(self, table: str, id: int | None = None) -> None:
        """Deletes data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type.
        """
        self._exec_sql(f'DELETE FROM {table}', id)

    @AFCErrorHandler(sqlite3.Error)
    def get_data(
        self, table: str, id: int | None = None
    ) -> list[tuple[str, None | int | float | str | bytes]]:
        """Gets data from the table.

        Args:
            table (str): The name of the table.
            id (int): The id of the type. Defaults to None.
                If None, returns all rows.
        """
        self._exec_sql(f'SELECT * FROM {table}', id)
        return self._curs.fetchall()

    @AFCErrorHandler(sqlite3.Error)
    def __del__(self) -> None:
        """Closes the database connection."""
        self._conn.close()
