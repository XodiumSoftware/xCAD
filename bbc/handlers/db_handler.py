import os
import sqlite3

from constants import DATABASE_PATH, TABLES


class DataBaseHandler:
    def __init__(self):
        """
        Initialize the DataBaseHandler.
        """
        self.create_directory_if_not_exists(
            os.path.dirname(os.path.abspath(DATABASE_PATH))
        )
        self._conn = sqlite3.connect(DATABASE_PATH)
        self._c = self._conn.cursor()
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
                table_name = table_data["desc"]
                columns = table_data["columns"]
                rows = table_data["rows"]

                if not self.table_exists(table_name):
                    self.create_table(table_name, columns)
                    self.insert_data_into_table(table_name, columns, rows)

    def table_exists(self, table_name):
        """
        Check if a table exists in the SQLite database.
        """
        self._c.execute(
            "SELECT name FROM sqlite_master WHERE type='table' AND name=?",
            (table_name,),
        )
        return self._c.fetchone() is not None

    def create_table(self, table_name, columns):
        """
        Create a table in the SQLite database.
        """
        column_names = ["Id"] + columns
        create_table_query = f"CREATE TABLE {table_name} ({', '.join(column_names)})"
        self._c.execute(create_table_query)

    def insert_data_into_table(self, table_name, columns, rows):
        """
        Insert data into a table in the SQLite database.
        """
        column_names = ["Id"] + columns
        insert_query = (
            f"INSERT INTO {table_name} VALUES ({', '.join(['?'] * len(column_names))})"
        )
        self._c.executemany(insert_query, rows)

    def get_table_data(self, table_name):
        """
        Get all the data from a table.
        """
        with self._conn:
            select_query = f"SELECT * FROM {table_name}"
            self._c.execute(select_query)

            table_data = self._c.fetchall()

        return table_data
