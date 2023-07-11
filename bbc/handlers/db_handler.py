import os
import sqlite3

from constants import TABLES

DATABASE_PATH = os.path.join("bbc/data/database.db")


class DataBaseHandler:
    def __init__(self):
        """
        Initialize the DataBaseHandler.
        """
        self._conn = sqlite3.connect(DATABASE_PATH)
        self._c = self._conn.cursor()

        self.create_directory_if_not_exists(
            os.path.dirname(os.path.abspath(DATABASE_PATH))
        )
        self.setup_database_model()

    @staticmethod
    def create_directory_if_not_exists(directory):
        """
        Create a directory if it does not exist.
        """
        if not os.path.exists(directory):
            os.makedirs(directory)

    def setup_database_model(self):
        """
        Setup the database model.
        """
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
    def table_exists(cursor, table_name):
        """
        Check if a table exists in the SQLite database.
        """
        cursor.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?",
            (table_name,),
        )
        return cursor.fetchone() is not None

    def get_table_data(self, table_name):
        """
        Get all the data from a table.
        """
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)

            select_query = f"SELECT * FROM {table_name_identified}"  # FIXME
            self._c.execute(select_query)

            table_data = self._c.fetchall()

        return table_data

    def save_table_data(self, table_name, table_data):
        """
        Save the data from a table.
        """
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)

            delete_query = f"DELETE FROM {table_name_identified}"  # FIXME
            self._c.execute(delete_query)

            num_columns = len(table_data[0])
            placeholders = ", ".join("?" * num_columns)
            insert_query = (
                f"INSERT INTO {table_name_identified} VALUES ({placeholders})"  # FIXME
            )
            self._c.executemany(insert_query, table_data)

            self._conn.commit()

    def discard_table_data(self, table_name):
        """
        Discard the data from a table.
        """
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)

            delete_query = f"DELETE FROM {table_name_identified}"  # FIXME
            self._c.execute(delete_query)

            self._conn.commit()

    def reset_table_data(self, table_name):
        """
        Reset the data from a table.
        """
        self.discard_table_data(table_name)

    def validate_and_sanitize_identifier(self, identifier):
        """
        Validate and sanitize an identifier.
        """
        if not identifier.isidentifier():
            raise ValueError(f"Invalid identifier: {identifier}")
        return identifier.replace('"', '""')

    def update_data(self, table_name, column_0, column_1, value):
        """
        Update the data from a table.
        """
        with self._conn:
            table_name_identified = self.validate_and_sanitize_identifier(table_name)
            column_0_identified = self.validate_and_sanitize_identifier(column_0)
            column_1_identified = self.validate_and_sanitize_identifier(column_1)

            update_query = f"UPDATE {table_name_identified} SET value = ? WHERE {column_0_identified} = ? AND {column_1_identified} = ?"  # FIXME
            self._c.execute(update_query, (value, column_0, column_1))

            self._conn.commit()

    def execute_query(self, query, params=None):
        """
        Execute a query with optional parameters.
        """
        with self._conn:
            try:
                if params:
                    self._c.execute(query, params)
                else:
                    self._c.execute(query)

                self._conn.commit()
            except sqlite3.Error as e:
                print(f"An error occurred: {e}")

    def execute_select_query(self, query, params=None):
        """
        Execute a select query with optional parameters and return the result.
        """
        with self._conn:
            try:
                if params:
                    self._c.execute(query, params)
                else:
                    self._c.execute(query)

                result = self._c.fetchall()
                return result
            except sqlite3.Error as e:
                print(f"An error occurred: {e}")
                return []
