import sqlite3

from constants import DEBUG_NAME
from constants import SETTINGS_DATABASE_PATH as SETTINGS_DATABASE_PATH
from PySide6.QtCore import QObject, Signal, Slot


class SettingsDatabaseHandler(QObject):
    save_changes_signal = Signal()
    discard_changes_signal = Signal()

    def __init__(self, database_path):
        super().__init__()
        self.database_path = database_path
        self.conn = sqlite3.connect(self.database_path)
        self.create_db_table()
        self.save_changes_signal.connect(self.save_db_changes_slot)
        self.discard_changes_signal.connect(self.discard_db_changes_slot)

    def create_db_table(self):
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

    def insert_db_setting(self, parameter, value):
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

    def delete_db_setting(self, parameter):
        cursor = self.conn.cursor()
        cursor.execute(
            """
        DELETE FROM settings WHERE parameter = ?
        """,
            (parameter,),
        )
        print(DEBUG_NAME + f"Discarded changes for parameter: {parameter}")

    def get_db_settings(self):
        cursor = self.conn.cursor()
        cursor.execute("SELECT parameter, value FROM settings")
        settings = cursor.fetchall()
        return settings

    def save_db_changes(self):
        self.conn.commit()
        print(DEBUG_NAME + "Changes saved to the database.")

    def close(self):
        self.conn.close()

    @Slot()
    def save_db_changes_slot(self):
        self.save_db_changes()
        # Additional code for handling the save action, if needed

    @Slot()
    def discard_db_changes_slot(self):
        parameter_to_discard = (
            "example_parameter"  # Provide the parameter you want to discard
        )
        self.delete_db_setting(parameter_to_discard)
        print(DEBUG_NAME + f"Discarded changes for parameter: {parameter_to_discard}")
        # Additional code for handling the discard action, if needed
