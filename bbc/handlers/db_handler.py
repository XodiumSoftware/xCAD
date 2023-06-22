import os
import sqlite3

import pandas as pd
from constants import DATABASE_PATH
from PySide6.QtSql import QSqlDatabase, QSqlTableModel

DATA_TABLES = ["FRAME_DATA", "OBJECT_ASSEMBLY_DATA"]

INIT_DATA = {
    "Parameter": [
        "Structure",
        "Length (mm)",
        "Height (mm)",
        "Area (m2)",
        "Perimeter (m1)",
    ],
    "Value": [
        "Select",
        6000,
        3000,
        18,
        18,
    ],
}


class DataBaseHandler:
    def __init__(self):
        """
        Initialize the DataBaseHandler.
        """
        super().__init__()

    def setup_database(self):
        """
        Create and populate a database if it doesn't exist.
        """
        if not os.path.exists(os.path.dirname(DATABASE_PATH)):
            os.makedirs(os.path.dirname(DATABASE_PATH))

        db = QSqlDatabase.addDatabase("QSQLITE")
        db.setDatabaseName(DATABASE_PATH)
        db.open()

        model = QSqlTableModel()
        model.setTable("my_table")

        if not model.select():
            conn = sqlite3.connect(DATABASE_PATH)
            df = pd.DataFrame(INIT_DATA)
            df.to_sql(
                "my_table", conn, if_exists="replace", index=True, index_label="Index"
            )
            conn.close()
            model.select()

        return model
