from PySide6.QtWidgets import QVBoxLayout, QWidget


class TableModule(QWidget):
    def __init__(self, table_index, parent=None):
        """
        Initialize the table module.
        """
        super().__init__(parent)
        self.setup_table_module(table_index)

    def setup_table_module(self, table_index):
        """
        Setup the tableModule.
        """
        layout = QVBoxLayout(self)

        # table_data = next(
        #     (table for table in TABLES if table["index"] == table_index),
        #     None,
        # )

        # if table_data:
        #     table = self.create_table_module(table_data)
        #     layout.addWidget(table)

        # else:
        #     print(DEBUG_NAME + f'"index" {table_index} not found in TABLES')

        layout.setContentsMargins(
            0, 0, 0, 0
        )  # TODOLATER: define this in the class. (do it for every module).

        self.setLayout(layout)

    def create_table_module(self):
        """
        Create a table module.
        """

        return 
