from constants import DEBUG_NAME, TABLES
from PySide6.QtGui import QStandardItem, QStandardItemModel, Qt
from PySide6.QtWidgets import QHeaderView, QTableView, QVBoxLayout, QWidget


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

    def create_table_view_module(
        self, table_data
    ):  # FIXME: This whole function is a mess.
        """
        Create a table view module.
        """
        table_view = QTableView()
        model = QStandardItemModel(self)

        column_headers = table_data["hor_headers"]
        model.setColumnCount(len(column_headers))
        model.setHorizontalHeaderLabels(column_headers)

        containers = table_data.get("containers", [])
        row = 0
        for container in containers:
            container_title = container.get("container_title", "")
            container_data = container.get("container_data", [])

            # Set container header title
            title_item = QStandardItem(container_title)
            model.setItem(row, 0, title_item)
            for column in range(1, len(column_headers)):
                model.setItem(row, column, QStandardItem(""))
            row += 1

            # Add container data to the table
            for item in container_data:
                for column, value in enumerate(item):
                    table_item = QStandardItem(str(value))
                    model.setItem(row, column, table_item)

                row += 1

        table_view.setModel(model)
        table_view.setSortingEnabled(True)
        table_view.setCornerButtonEnabled(True)
        table_view.resizeColumnsToContents()

        header = table_view.horizontalHeader()
        header.setSectionResizeMode(QHeaderView.Stretch)

        # Set span for container header titles
        for i in range(len(column_headers)):
            table_view.setSpan(
                i * (len(container_data) + 1), 0, len(container_data) + 1, 1
            )

        return table_view
