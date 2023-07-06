import sqlite3
import sys

from PySide6.QtCore import Qt
from PySide6.QtGui import QStandardItem, QStandardItemModel
from PySide6.QtWidgets import (
    QApplication,
    QGraphicsScene,
    QGraphicsView,
    QMainWindow,
    QTableView,
    QVBoxLayout,
    QWidget,
)

DEFAULT_TABLE = {
    "columns": ["Parameter", "Value"],
    "rows": [
        ["Length", "6000"],
        ["Height", "2500"],
    ],
}


class MyStandardItemModel(QStandardItemModel):
    def flags(self, index):
        if index.column() == 0:
            return Qt.ItemFlag.ItemIsSelectable | Qt.ItemFlag.ItemIsEnabled
        else:
            return super().flags(index)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Database Content")
        self.setup_ui()
        self.setup_database()
        self.load_data()
        self.setup_table_view()

    def setup_ui(self):
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)
        layout = QVBoxLayout(central_widget)
        self.table_view = QTableView()
        layout.addWidget(self.table_view)
        self.graphics_view = QGraphicsView()
        layout.addWidget(self.graphics_view)
        self.scene = QGraphicsScene()
        self.graphics_view.setScene(self.scene)

    def setup_database(self):
        conn = sqlite3.connect("bbc/sketch/data.db")
        cursor = conn.cursor()

        cursor.execute("SELECT name FROM sqlite_master WHERE type='table'")
        table_names = [row[0] for row in cursor.fetchall()]

        if "OBJECT_TABLE" not in table_names:
            columns = ", ".join(DEFAULT_TABLE["columns"])
            cursor.execute(f"CREATE TABLE IF NOT EXISTS OBJECT_TABLE ({columns})")

            values = ", ".join(
                f"('{row[0]}', '{row[1]}')" for row in DEFAULT_TABLE["rows"]
            )
            cursor.execute(f"INSERT INTO OBJECT_TABLE ({columns}) VALUES {values}")
        else:
            cursor.execute("SELECT COUNT(*) FROM OBJECT_TABLE")
            row_count = cursor.fetchone()[0]

            if row_count == 0:
                columns = ", ".join(DEFAULT_TABLE["columns"])
                values = ", ".join(
                    f"('{row[0]}', '{row[1]}')" for row in DEFAULT_TABLE["rows"]
                )
                cursor.execute(f"INSERT INTO OBJECT_TABLE ({columns}) VALUES {values}")

        conn.commit()
        conn.close()

    def load_data(self):
        conn = sqlite3.connect("bbc/sketch/data.db")
        cursor = conn.cursor()

        cursor.execute("SELECT name FROM sqlite_master WHERE type='table'")
        table_names = [row[0] for row in cursor.fetchall()]

        if "OBJECT_TABLE" not in table_names:
            raise ValueError(
                f"Failed to find table OBJECT_TABLE. Available tables: {table_names}"
            )

        cursor.execute("SELECT * FROM OBJECT_TABLE")
        data = cursor.fetchall()
        print(f"Data from OBJECT_TABLE: {data}")
        self.table_data = data

        conn.close()

    def setup_table_view(self):
        model = MyStandardItemModel()
        model.setHorizontalHeaderLabels(DEFAULT_TABLE["columns"])
        for row in self.table_data:
            items = [QStandardItem(str(value)) for value in row]
            model.appendRow(items)
        self.table_view.setModel(model)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    viewer = MainWindow()
    viewer.show()
    sys.exit(app.exec())
