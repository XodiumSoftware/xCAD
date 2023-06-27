from constants import DATABASE_PATH, DEBUG_NAME, TABLES
from PySide6.QtSql import QSqlDatabase, QSqlQuery, QSqlQueryModel
from PySide6.QtWidgets import QHeaderView, QTableView, QVBoxLayout, QWidget


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
            (table for table in TABLES if table["index"] == table_index), None
        )

        if table_index:
            table = self.create_table_module(table_data)
            layout.addWidget(table)

        else:
            print(DEBUG_NAME + f'"index" {table_index} not found in TABLES')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)

        self.setLayout(layout)

    def create_table_module(self, table_data):
        """
        Create a table module.
        """
        table = QTableView()
        table.setStyleSheet(table_data["stylesheet"])
        table.setSizePolicy(*table_data["size_policy"])
        table.setSortingEnabled(table_data["sorting"])
        table.setAlternatingRowColors(table_data["alternating_row_colors"])

        font = table.font()
        font.setBold(True)

        hor_header = table.horizontalHeader()
        hor_header.setVisible(True)
        hor_header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        hor_header.setFont(font)

        ver_header = table.verticalHeader()
        ver_header.setVisible(True)
        ver_header.setSectionResizeMode(QHeaderView.ResizeMode.Fixed)
        ver_header.setFont(font)

        table_name = table_data["desc"]
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

        column_count = model.columnCount()
        for column in range(0, column_count, 2):
            table.hideColumn(column)

        return table
