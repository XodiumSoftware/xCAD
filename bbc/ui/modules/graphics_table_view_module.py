import pandas as pd
from constants import DEBUG_NAME, TABLES
from PySide6.QtCore import QSettings, Qt
from PySide6.QtWidgets import (
    QHeaderView,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

# TODOLATER: make the table expand to fill the space in the window.
# TODOLATER: make the row_groups be dynamic.


class GraphicsTableViewModule(QWidget):
    def __init__(self, table_index, parent=None):
        """
        Initialize the tableModule.
        """
        super().__init__(parent)
        self._settings = QSettings()
        self.setup_table_module(table_index)

    def setup_table_module(self, table_index):
        """
        Setup the tableModule.
        """
        layout = QVBoxLayout(self)

        table_data = next(
            (table for table in TABLES if table["index"] == table_index),
            None,
        )

        if table_data:
            table = self.create_table_module(table_data)
            layout.addWidget(table)

        else:
            print(DEBUG_NAME + f'"index" {table_index} not found in TABLES')

        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def create_table_module(self, table_data):
        """
        Create a table module.
        """
        table = QTableWidget(self)

        columns = table_data["data"][0]["columns"][0]
        row_group = table_data["data"][0]["row_group_1"]

        table.setColumnCount(len(columns))
        table.setRowCount(len(row_group))

        for column_index, column in enumerate(columns):
            header_item = QTableWidgetItem(column)
            table.setHorizontalHeaderItem(column_index, header_item)

        for row_index, row_values in enumerate(row_group):
            item = QTableWidgetItem(row_values[0, 0])
            table.setItem(row_index, 0, item)

            for column_index, cell_data in enumerate(row_values[1:]):
                cell_value, cell_type, cell_editable = cell_data

                item = QTableWidgetItem(str(cell_value))

                if cell_type == 0:
                    item.setData(Qt.EditRole, cell_value)
                elif cell_type == 1:
                    item.setData(Qt.EditRole, str(cell_value))
                elif cell_type == 2:
                    item.setData(Qt.EditRole, float(cell_value))
                elif cell_type == 3:
                    item.setData(Qt.EditRole, cell_value)

                item.setFlags(
                    item.flags() | Qt.ItemIsEditable if cell_editable else item.flags()
                )

                table.setItem(row_index, column_index + 1, item)

        table.resizeColumnsToContents()
        table.resizeRowsToContents()
        table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        table.setSortingEnabled(True)

        return table
