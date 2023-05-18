import os
import sqlite3

SETTINGS_DATABASE_PATH = os.path.join("bbc/data/settings.sqlite")


class SettingsDatabaseHandler:
    def __init__(self, database_path):
        self.database_path = database_path
        self.conn = sqlite3.connect(self.database_path)

    def create_table(self):
        cursor = self.conn.cursor()
        cursor.execute(
            """
        CREATE TABLE IF NOT EXISTS settings (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                parameter TEXT,
                value TEXT
        )
        """
        )
        self.conn.commit()

    def insert_setting(self, parameter, value):
        cursor = self.conn.cursor()
        cursor.execute(
            """
        SELECT id FROM settings WHERE parameter = ?
        """,
            (parameter,),
        )
        existing_setting = cursor.fetchone()

        if existing_setting:
            cursor.execute(
                """
            UPDATE settings SET value = ? WHERE parameter = ?
            """,
                (value, parameter),
            )
        else:
            cursor.execute(
                """
            INSERT INTO settings (parameter, value) VALUES (?, ?)
            """,
                (parameter, value),
            )
        self.conn.commit()

    def get_settings(self):
        cursor = self.conn.cursor()
        cursor.execute("SELECT parameter, value FROM settings")
        settings = cursor.fetchall()
        return settings

    def close(self):
        self.conn.close()
