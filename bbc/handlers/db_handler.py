import os
import sqlite3

from constants import DEBUG_NAME, SETTINGS_DATABASE_PATH
from PySide6.QtCore import QObject, Slot


class DataBaseHandler(QObject):
    def __init__(self):
        super().__init__()
        self.connection = self.create_or_connect_db()

    def create_or_connect_db(self):
        if not os.path.exists(os.path.dirname(SETTINGS_DATABASE_PATH)):
            os.makedirs(os.path.dirname(SETTINGS_DATABASE_PATH))

        connection = sqlite3.connect(SETTINGS_DATABASE_PATH)
        cursor = connection.cursor()

        cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS settings (
                id INTEGER PRIMARY KEY,
                setting_name TEXT,
                setting_value TEXT
            )
            """
        )
        connection.commit()

        return connection

    def execute_db_query(self, query, *params):
        cursor = self.connection.cursor()
        cursor.execute(query, params)
        self.connection.commit()

    def get_db_settings(self):
        cursor = self.connection.cursor()
        cursor.execute("SELECT setting_name, setting_value FROM settings")
        settings = cursor.fetchall()
        return dict(settings)

    @Slot(dict)
    def save_db_settings(self, settings):
        current_settings = self.get_db_settings()

        if settings == current_settings:
            print(DEBUG_NAME + "No changes detected. Skipping save operation.")
            return

        with self.connection:
            self.execute_db_query("DELETE FROM settings")

            for name, value in settings.items():
                self.execute_db_query(
                    "INSERT INTO settings (setting_name, setting_value) VALUES (?, ?)",
                    name,
                    value,
                )

        print(DEBUG_NAME + "Changes saved successfully.")

    @Slot()
    def discard_db_settings(self):
        self.execute_db_query("ROLLBACK")
        print(DEBUG_NAME + "Changes discarded successfully.")

    def close_db_connection(self):
        self.connection.close()
        print(DEBUG_NAME + "Connection closed.")
