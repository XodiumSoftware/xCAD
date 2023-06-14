from constants import DEBUG_NAME, TABLES
from PySide6.QtGui import QStandardItem, QStandardItemModel
from PySide6.QtWidgets import QTableView, QVBoxLayout, QWidget


class TableViewModule(QWidget):
    def __init__(self, table_index, parent=None):
        """
        Initialize the TableViewModule.
        """
        super().__init__(parent)
        self.setup_table_view_module(table_index)

    def setup_table_view_module(self, table_index):
        """
        Setup the TableViewModule.
        """
        layout = QVBoxLayout(self)

        table_data = next(
            (table for table in TABLES if table["index"] == table_index),
            None,
        )

        if table_data:
            table_view = self.create_table_view_module(table_data)
            layout.addWidget(table_view)

        else:
            print(DEBUG_NAME + f'"index" {table_index} not found in TABLES')

        self.setLayout(layout)

    def create_table_view_module(self, table_data):
        """
        Create a table view module.
        """
        table_view = QTableView()
        model = QStandardItemModel(self)

        column_headers = table_data["headers"]
        model.setHorizontalHeaderLabels(column_headers)

        for row, item in enumerate(table_data["data"]):
            for column, value in enumerate(item):
                table_item = QStandardItem(str(value))
                model.setItem(row, column, table_item)

        table_view.setModel(model)
        table_view.setSortingEnabled(True)
        table_view.setCornerButtonEnabled(True)
        table_view.resizeColumnsToContents()

        return table_view
