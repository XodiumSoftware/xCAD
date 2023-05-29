from PySide6.QtCore import Qt
from PySide6.QtGui import QFont
from PySide6.QtWidgets import (
    QAbstractItemView,
    QHeaderView,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

COLUMN_HEADER = [
    {
        "column_header_stylesheet": "background-color: rgb(230, 230, 230); font: bold 10pt Arial;",
        "column_header_labels": ["Parameters", "Values"],
    },
]

ROW_HEADER = [
    {
        "row_header_stylesheet": "background-color: rgb(230, 230, 230); font: bold 10pt Arial;",
    },
]

SETTINGS_LIST = [
    {
        "settings_list_group_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "settings_list_group_header_title": "Group 1",
        "settings_list_item_font": [QFont("Arial", 8)],
        "settings_list_items": [
            ("John Doe", 30),
            ("Jane Smith", 25),
            ("Bob Johnson", 45),
            ("Alice Brown", 35),
        ],
    },
    {
        "settings_list_group_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "settings_list_group_header_title": "Group 2",
        "settings_list_item_font": [QFont("Arial", 8)],
        "settings_list_items": [
            ("Michael Williams", 50),
            ("Emma Johnson", 28),
            ("William Davis", 42),
            ("Olivia Taylor", 32),
        ],
    },
    {
        "settings_list_group_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "settings_list_group_header_title": "Group 3",
        "settings_list_item_font": [QFont("Arial", 8)],
        "settings_list_items": [
            ("James Wilson", 37),
            ("Sophia Martinez", 31),
            ("Daniel Anderson", 48),
            ("Mia Thomas", 29),
        ],
    },
]


class SettingsListWidget(QWidget):
    def __init__(self):
        super().__init__()
        """
        Initialize the widget.
        """
        self.setup_table()

        self.populate_table()
        self.setup_table_headers()
        self.setup_column_sorting()

    def setup_table(self):
        """
        Setup the table widget.
        """
        self.table_widget = QTableWidget()
        self.table_widget.setColumnCount(len(COLUMN_HEADER[0]["column_header_labels"]))
        self.table_widget.setHorizontalHeaderLabels(
            COLUMN_HEADER[0]["column_header_labels"]
        )
        self.table_widget.setEditTriggers(QAbstractItemView.EditTrigger.NoEditTriggers)
        self.table_widget.setSelectionBehavior(
            QAbstractItemView.SelectionBehavior.SelectRows
        )
        self.table_widget.setCornerButtonEnabled(True)

        layout = QVBoxLayout(self)
        layout.addWidget(self.table_widget)

    def populate_table(self):
        """
        Populate the table with data.
        """
        self.table_widget.clearContents()

        for group_data in SETTINGS_LIST:
            group_name = group_data["settings_list_group_header_title"]
            group_item = QTableWidgetItem(group_name)
            group_item.setFlags(Qt.ItemFlag.NoItemFlags)
            self.table_widget.insertRow(self.table_widget.rowCount())
            self.table_widget.setItem(self.table_widget.rowCount() - 1, 0, group_item)

            item_font = group_data["settings_list_item_font"]

            for item in group_data["settings_list_items"]:
                self.table_widget.insertRow(self.table_widget.rowCount())

                for column, value in enumerate(item):
                    item_text = str(value)
                    item_item = QTableWidgetItem(item_text)
                    item_item.setFont(item_font[0])
                    self.table_widget.setItem(
                        self.table_widget.rowCount() - 1, column, item_item
                    )

                    if column > 0:
                        item_item.setTextAlignment(Qt.AlignmentFlag.AlignCenter)

    def setup_table_headers(self):
        """
        Setup the column headers.
        """
        H_header = self.table_widget.horizontalHeader()
        H_header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        H_header_stylesheet = COLUMN_HEADER[0].get("column_header_stylesheet")
        if H_header_stylesheet:
            H_header.setStyleSheet(H_header_stylesheet)

        V_header = self.table_widget.verticalHeader()
        V_header_stylesheet = ROW_HEADER[0].get("row_header_stylesheet")
        if V_header_stylesheet:
            V_header.setStyleSheet(V_header_stylesheet)

    def setup_column_sorting(self):
        """
        Setup the column sorting.
        """
        self.table_widget.setSortingEnabled(True)
        self.table_widget.sortItems(0, Qt.SortOrder.AscendingOrder)
