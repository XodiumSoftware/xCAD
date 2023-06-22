from constants import DATABASE_PATH, DEBUG_NAME, TABLES
from PySide6.QtSql import QSqlDatabase, QSqlQuery, QSqlQueryModel
from PySide6.QtWidgets import QTableView, QVBoxLayout, QWidget


class TableModule(QWidget):
    def __init__(self, table_index, margins=None, parent=None):
        """
        Initialize the TableModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.setup_table_module(table_index)

    def setup_table_module(self, table_index):
        """
        Setup the TableModule.
        """
        layout = QVBoxLayout(self)

        table_data = next(
            (table for table in TABLES if table["index"] == table_index),
            None,
        )

        if table_index:
            table = self.create_table_module(table_data, table_index, table_data)
            layout.addWidget(table)

        else:
            print(DEBUG_NAME + f'"index" {table_index} not found in TABLES')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)

        self.setLayout(layout)

    def create_table_module(self, table_index):
        """
        Create a table module.
        """
        table = QTableView()
        table.setStyleSheet(table_index["stylesheet"])
        table.setSizePolicy(*table_index["size_policy"])
        table.setSortingEnabled(table_index["sorting"])
        table.setAlternatingRowColors(table_index["alternating_row_colors"])

        table_name = table_index["desc"]
        model = QSqlQueryModel()

        db = QSqlDatabase.addDatabase("QSQLITE")
        db.setDatabaseName(DATABASE_PATH)
        if db.open():
            query = QSqlQuery(db)
            query.exec(f"SELECT * FROM {table_name}")
            model.setQuery(query)
            db.close()

        else:
            print(DEBUG_NAME + f"failed to open {DATABASE_PATH}")

        table.setModel(model)

        return table
