import os
import sqlite3

from constants import DATA_TABLES, DATABASE, DATABASE_PATH
from PySide6.QtSql import QSqlDatabase


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
        if not os.path.exists(os.path.dirname(DATABASE_PATH)):
            os.makedirs(os.path.dirname(DATABASE_PATH))

        db = QSqlDatabase.addDatabase(DATABASE)
        db.setDatabaseName(DATABASE_PATH)
        db.open()

        self.setup_database_model()

    def setup_database_model(self):
        """
        Create and populate a database if it doesn't exist.
        """
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        for table_data in DATA_TABLES:
            table_name = table_data["table_name"]
            columns = table_data["columns"]
            rows = table_data["rows"]

            if not self.table_exists(cursor, table_name):
                column_names = ["Id"] + columns
                create_table_query = "CREATE TABLE {table_name} ({columns})".format(
                    table_name=table_name, columns=", ".join(column_names)
                )
                cursor.execute(create_table_query)

                for i, row in enumerate(rows):
                    column_count = len(columns)
                    values_placeholder = ", ".join(["?"] * (column_count + 1))
                    insert_query = "INSERT INTO {table_name} VALUES ({values})".format(
                        table_name=table_name, values=values_placeholder
                    )
                    values = [i] + [str(val) for val in row]
                    cursor.execute(insert_query, tuple(values))

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
