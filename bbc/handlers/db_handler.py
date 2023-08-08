import os
import sqlite3
from typing import Dict, List, Tuple, Union

from constants import DATABASE_PATH, TABLES

CellValue = Union[str, int, float, bool]


class DataBaseHandler:
    def __init__(self):
        """Initialize the DataBaseHandler."""
        self.create_directory_if_not_exists(
            os.path.dirname(os.path.abspath(DATABASE_PATH))
        )
        self._conn = sqlite3.connect(DATABASE_PATH)
        self._c = self._conn.cursor()
        self.setup_database_model()

    @staticmethod
    def create_directory_if_not_exists(directory: str) -> None:
        """Create a directory if it does not exist."""
        if not os.path.exists(directory):
            os.makedirs(directory)

    def setup_database_model(self) -> None:
        """Setup the database model."""
        with self._conn:
            for table_data in TABLES:
                table_name_identified = self.validate_and_sanitize_identifier(
                    table_data["desc"]
                )
                columns = table_data["columns"]
                rows = table_data["rows"]

                column_names = ["Id"] + columns
                column_names = [
                    self.validate_and_sanitize_identifier(column_name)
                    for column_name in column_names
                ]

                if not self.table_exists(self._c, table_name_identified):
                    create_table_query = f"CREATE TABLE {table_name_identified} ({', '.join(column_names)})"
                    self._c.execute(create_table_query)

                    insert_query = f"INSERT INTO {table_name_identified} VALUES ({', '.join(['?'] * len(column_names))})"  # FIXME
                    values = [(i,) + tuple(row) for i, row in enumerate(rows)]
                    self._c.executemany(insert_query, values)

    @staticmethod
    def table_exists(cursor: sqlite3.Cursor, table_name: str) -> bool:
        """Check if a table exists in the SQLite database."""
        cursor.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?",
            (table_name,),
        )
        return cursor.fetchone() is not None

    def get_table_data(self, table_name: str) -> List[Tuple[CellValue, ...]]:
        """Get all the data from a table."""
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)

            select_query = f"SELECT * FROM {table_name_identified}"  # FIXME
            self._c.execute(select_query)

            table_data = self._c.fetchall()

        return table_data

    def validate_and_sanitize_identifier(self, identifier: str) -> str:
        """Validate and sanitize an identifier."""
        if not identifier.isidentifier():
            raise ValueError(f"Invalid identifier: {identifier}")
        return identifier.replace('"', '""')

    def save_table_data_changes(
        self, table_name: str, updated_data: List[Dict[str, CellValue]]
    ) -> None:
        """Save all the data changes from a table."""
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)

            update_query = f"UPDATE {table_name_identified} SET "
            set_columns = []
            values = []

            for row in updated_data:
                for column, value in row.items():
                    set_columns.append(f"{column} = ?")
                    values.append(value)
                update_query += ", ".join(set_columns) + " WHERE Id = ?"
                values.append(row["Id"])

            self._c.execute(update_query, values)

    def discard_table_data_changes(self, table_name: str) -> None:
        """Discard all the data changes from a table."""
        original_data = self.get_table_data(table_name)
        original_data_dict = [
            {"Id": row[0], **dict(zip(TABLES[0]["columns"], row[1:]))}
            for row in original_data
        ]
        self.save_table_data_changes(table_name, original_data_dict)

    def reset_table_data(self, table_name: str) -> None:
        """Reset all the data from a table."""
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)

            for table_data in TABLES:
                if table_data["desc"] == table_name_identified:
                    default_data = table_data["rows"]
                    break
            else:
                raise ValueError(
                    f"Table '{table_name_identified}' not found in TABLES."
                )

            self._c.execute(f"DELETE FROM {table_name_identified}")
            insert_query = f"INSERT INTO {table_name_identified} VALUES ({', '.join(['?'] * len(default_data[0]))})"
            values = [(i,) + tuple(row) for i, row in enumerate(default_data)]
            self._c.executemany(insert_query, values)
