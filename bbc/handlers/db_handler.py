# import os
# import sqlite3

# from constants import DATABASE_PATH, DEBUG_NAME, INITIAL_GRAPHICS_OBJECT_DATA
# from PySide6.QtCore import QObject, Slot


# class DataBaseHandler(QObject):
#     def __init__(self):
#         super().__init__()
#         self.connection = self.create_or_connect_db()

#     def create_or_connect_db(self):
#         if not os.path.exists(os.path.dirname(DATABASE_PATH)):
#             os.makedirs(os.path.dirname(DATABASE_PATH))

#         connection = sqlite3.connect(DATABASE_PATH)
#         cursor = connection.cursor()

#         cursor.execute(
#             "CREATE TABLE IF NOT EXISTS GraphicsObjectData ("
#             "id INTEGER PRIMARY KEY,"
#             "parameter TEXT,"
#             "value TEXT)"
#         )

#         cursor.execute("SELECT COUNT(*) FROM GraphicsObjectData")
#         count = cursor.fetchone()[0]

#         if count == 0:
#             cursor.executemany(
#                 "INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)",
#                 [
#                     (data["parameter"], data["value"])
#                     for data in INITIAL_GRAPHICS_OBJECT_DATA
#                 ],
#             )
#             connection.commit()
#         else:
#             pass

#         return connection

#     def execute_db_query(self, query, *params):
#         cursor = self.connection.cursor()
#         cursor.execute(query, params)
#         self.connection.commit()
#         return cursor.fetchall()

#     def get_db_data(self):
#         cursor = self.connection.cursor()
#         cursor.execute("SELECT parameter, value FROM GraphicsObjectData")
#         settings = cursor.fetchall()
#         return dict(settings)

#     @Slot(dict)
#     def save_db_data(self, settings):
#         current_settings = self.get_db_data()

#         if settings == current_settings:
#             print(DEBUG_NAME + "No changes detected. Skipping save operation.")
#             return

#         with self.connection:
#             self.execute_db_query("DELETE FROM settings")

#             for name, value in settings.items():
#                 self.execute_db_query(
#                     "INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)",
#                     name,
#                     value,
#                 )

#         print(DEBUG_NAME + "Changes saved successfully.")

#     @Slot()
#     def discard_db_data(self):
#         self.execute_db_query("ROLLBACK")
#         print(DEBUG_NAME + "Changes discarded successfully.")

#     def close_db_data(self):
#         self.connection.close()
#         print(DEBUG_NAME + "Connection closed.")
