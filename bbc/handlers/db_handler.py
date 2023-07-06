import os
import sqlite3

from constants import DATABASE_PATH, TABLES


class DataBaseHandler:
    def __init__(self):
        """
        Initialize the DataBaseHandler.
        """
        super().__init__()

    def setup_database(self):
        """
        Setup the database.
        """
        database_directory = os.path.dirname(os.path.abspath(DATABASE_PATH))
        if not os.path.exists(database_directory):
            os.makedirs(database_directory)
        self.setup_database_model()

    def setup_database_model(self):
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

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

            if not self.table_exists(cursor, table_name_identified):
                create_table_query = (
                    f"CREATE TABLE {table_name_identified} ({', '.join(column_names)})"
                )
                cursor.execute(create_table_query)

                insert_query = f"INSERT INTO {table_name_identified} VALUES ({', '.join(['?'] * len(column_names))})"
                values = [(i,) + tuple(row) for i, row in enumerate(rows)]
                cursor.executemany(insert_query, values)

        conn.commit()
        conn.close()

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
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        table_name_identified = self.validate_and_sanitize_identifier(table_name)

        select_query = f"SELECT * FROM {table_name_identified}"
        cursor.execute(select_query)

        table_data = cursor.fetchall()

        conn.close()

        return table_data

    def save_table_data(self, table_name, table_data):
        """
        Save the data from a table.
        """
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        table_name_identified = self.validate_and_sanitize_identifier(table_name)

        delete_query = f"DELETE FROM {table_name_identified}"
        cursor.execute(delete_query)

        num_columns = len(table_data[0])
        placeholders = ", ".join("?" * num_columns)
        insert_query = f"INSERT INTO {table_name_identified} VALUES ({placeholders})"
        cursor.executemany(insert_query, table_data)

        conn.commit()
        conn.close()

    def discard_table_data(self, table_name):
        """
        Discard the data from a table.
        """
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        table_name_identified = self.validate_and_sanitize_identifier(table_name)

        delete_query = f"DELETE FROM {table_name_identified}"
        cursor.execute(delete_query)

        conn.commit()
        conn.close()

    def reset_table_data(self, table_name):
        """
        Reset the data from a table.
        """
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        table_name_identified = self.validate_and_sanitize_identifier(table_name)

        delete_query = f"DELETE FROM {table_name_identified}"
        cursor.execute(delete_query)

        conn.commit()
        conn.close()

    def validate_and_sanitize_identifier(self, identifier):
        if not identifier.isidentifier():
            raise ValueError(f"Invalid identifier: {identifier}")
        return identifier.replace('"', '""')
