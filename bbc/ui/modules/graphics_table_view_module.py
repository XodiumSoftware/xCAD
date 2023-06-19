from constants import DEBUG_NAME, TABLES
from PySide6.QtCore import QSettings
from PySide6.QtWidgets import (
    QHeaderView,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

# TODO: make the table expand to fill the space in the window.


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
        rows = table_data["data"][0]["row_group_1"][0]  # TODO: make this dynamic

        table.setColumnCount(len(columns))

        for column_index, column in enumerate(columns):
            header_item = QTableWidgetItem(column)
            table.setHorizontalHeaderItem(column_index, header_item)

        for row_index, rows in enumerate(rows):
            # TODO: use the constant and ask for it if you dont have it.
            # TODO: set row group.
            # TODO: set row group header being "row_group_1" or "row_group_2" etc.
            # TODO: set row group header color blue.
            # TODO: set the rows in the row group.
            pass  # TODO: remove this when content has been added.

        table.resizeColumnsToContents()
        table.resizeRowsToContents()
        table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        table.setSortingEnabled(True)

        return table
