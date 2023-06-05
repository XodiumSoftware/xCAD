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
            ordered_data = sorted(table_data["data"], key=lambda x: x[0])
            table_data["data"] = ordered_data
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
        table_widget.sortItems(0, Qt.SortOrder.DescendingOrder)

        for row, row_data in enumerate(table_data["data"]):
            item_parameter = QTableWidgetItem(row_data[0])
            item_value = QTableWidgetItem(row_data[1])

            table_widget.setItem(row, 0, item_parameter)
            table_widget.setItem(row, 1, item_value)

        return table_widget
