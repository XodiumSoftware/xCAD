import sqlite3

from constants import DEBUG_NAME, SETTINGS_DATABASE_PATH
from PySide6.QtCore import QObject, Slot


class SettingsDatabaseHandler(QObject):
    def __init__(self):
        """
        Initialize the SettingsDatabaseHandler.
        """
        self.db_name = SETTINGS_DATABASE_PATH
        self.connection = self.create_or_connect_db()

    def create_or_connect_db(self):
        """
        Create or connect to the database.
        """
        connection = sqlite3.connect(self.db_name)
        cursor = connection.cursor()

        cursor.execute(
            """CREATE TABLE IF NOT EXISTS settings
                          (id INTEGER PRIMARY KEY, setting_name TEXT, setting_value TEXT)"""
        )
        connection.commit()

        return connection

    def get_db_settings(self):
        """
        Get the settings from the database.
        """
        cursor = self.connection.cursor()
        cursor.execute("SELECT setting_name, setting_value FROM settings")
        settings = cursor.fetchall()
        return dict(settings)

    def save_db_settings(self, settings):
        """
        Save the settings to the database.
        """
        current_settings = self.get_db_settings()

        if settings == current_settings:
            print(DEBUG_NAME + "No changes detected. Skipping save operation.")
            return

        cursor = self.connection.cursor()
        cursor.execute("DELETE FROM settings")

        for name, value in settings.items():
            cursor.execute(
                "INSERT INTO settings (setting_name, setting_value) VALUES (?, ?)",
                (name, value),
            )

        self.connection.commit()
        print(DEBUG_NAME + "Settings saved successfully.")

    def close_db_connection(self):
        """
        Close the database connection.
        """
        self.connection.close()
        print(DEBUG_NAME + "Connection closed.")

    @Slot(dict)
    def save_db_changes(self, settings):
        pass

    @Slot()
    def discard_db_changes(self, settings):
        pass
