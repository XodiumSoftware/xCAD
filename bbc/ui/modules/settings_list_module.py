from PySide6.QtCore import Qt
from PySide6.QtWidgets import QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget

TABLES = [
    {
        "index": 0,
        "headers": ["Parameters", "Values"],
        "data": [
            ["Name", "John Doe"],
            ["Age", "30"],
            ["Country", "USA"],
        ],
    },
]


class TableModule(QWidget):
    def __init__(self, table_index, parent=None):
        """
        Initialize the TableWidgetModule.
        """
        super().__init__(parent)
        self.setup_table_module(table_index)

    def setup_table_module(self, table_index):
        """
        Setup the TableWidgetModule.
        """
        layout = QVBoxLayout(self)

        table_data = next(
            (table for table in TABLES if table["index"] == table_index),
            None,
        )

        if table_data:
            table_widget = self.create_table_module(table_data)
            layout.addWidget(table_widget)

        self.setLayout(layout)

    def create_table_module(self, table_data):
        """
        Create a table widget module.
        """
        table_widget = QTableWidget(self)
        table_widget.setColumnCount(len(table_data["headers"]))
        table_widget.setRowCount(len(table_data["data"]))
        table_widget.setHorizontalHeaderLabels(table_data["headers"])

        table_widget.setCornerButtonEnabled(True)

        table_widget.setSortingEnabled(True)
        table_widget.sortItems(0, Qt.SortOrder.AscendingOrder)

        for row, row_data in enumerate(table_data["data"]):
            for col, item_data in enumerate(row_data):
                item = QTableWidgetItem(item_data)
                table_widget.setItem(row, col, item)

        return table_widget
