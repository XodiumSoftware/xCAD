import json
import os
import sqlite3

from constants import DATABASE_PATH

DATA_TABLES = ["FRAME_DATA", "OBJECT_ASSEMBLY_DATA"]


class DataBaseHandler:
    def __init__(self):
        """
        Initialize the database handler.
        """
        super().__init__()
        self.create_database()

    def create_database(self):
        """
        Create the database and tables.
        """
        if not os.path.exists(os.path.dirname(DATABASE_PATH)):
            os.makedirs(os.path.dirname(DATABASE_PATH))

        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        for table_name in DATA_TABLES:
            cursor.execute(
                f"""
                CREATE TABLE IF NOT EXISTS {table_name} (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    data TEXT
                )
                """
            )

        conn.commit()
        conn.close()

    def serialize_data(self, data):
        """
        Serialize the data using JSON.
        """
        serialized_data = json.dumps(data)
        return serialized_data

    def deserialize_data(self, serialized_data):
        """
        Deserialize the serialized data using JSON.
        """
        data = json.loads(serialized_data)
        return data

    def insert_data(self, data):
        """
        Insert data into the specified table.
        """
        conn = sqlite3.connect(DATABASE_PATH)
        serialized_data = self.serialize_data(data)

        cursor = conn.cursor()

        for table_name in DATA_TABLES:
            cursor.execute(
                f"INSERT INTO {table_name} (data) VALUES (?)", (serialized_data,)
            )

        conn.commit()

        conn.close()

    def retrieve_data(self):
        """
        Retrieve data from the specified tables.
        """
        conn = sqlite3.connect(DATABASE_PATH)
        cursor = conn.cursor()

        data_list = []
        for table_name in DATA_TABLES:
            cursor.execute(f"SELECT data FROM {table_name}")
            rows = cursor.fetchall()

            table_data = []

            for row in rows:
                serialized_data = row[0]
                data = self.deserialize_data(serialized_data)
                table_data.append(data)

            data_list.append(table_data)

        conn.close()

        return data_list
