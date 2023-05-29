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
        "column_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "column_header_labels": ["Name", "Age", "Country"],
    },
]

SETTINGS_LIST = [
    {
        "settings_list_group_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "settings_list_group_header_title": "Group 1",
        "settings_list_item_font": [QFont("Arial", 8)],
        "settings_list_items": [
            ("John Doe", 30, "USA"),
            ("Jane Smith", 25, "Canada"),
            ("Bob Johnson", 45, "UK"),
            ("Alice Brown", 35, "Australia"),
        ],
    },
    {
        "settings_list_group_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "settings_list_group_header_title": "Group 2",
        "settings_list_item_font": [QFont("Arial", 8)],
        "settings_list_items": [
            ("Michael Williams", 50, "Germany"),
            ("Emma Johnson", 28, "France"),
            ("William Davis", 42, "Spain"),
            ("Olivia Taylor", 32, "Italy"),
        ],
    },
    {
        "settings_list_group_header_font": [QFont("Arial", 10, QFont.Weight.Bold)],
        "settings_list_group_header_title": "Group 3",
        "settings_list_item_font": [QFont("Arial", 8)],
        "settings_list_items": [
            ("James Wilson", 37, "Brazil"),
            ("Sophia Martinez", 31, "Mexico"),
            ("Daniel Anderson", 48, "Argentina"),
            ("Mia Thomas", 29, "Chile"),
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
        self.setup_column_sorting()
        self.set_cell_size()

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

        H_header = self.table_widget.horizontalHeader()
        H_header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        H_header.setFont(COLUMN_HEADER[0]["column_header_font"])

        V_header = self.table_widget.verticalHeader()
        V_header.setFont(COLUMN_HEADER[0]["column_header_font"])

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
                name, age, country = item
                self.table_widget.insertRow(self.table_widget.rowCount())

                name_item = QTableWidgetItem(name)
                name_item.setFont(item_font[0])
                self.table_widget.setItem(
                    self.table_widget.rowCount() - 1, 0, name_item
                )

                age_item = QTableWidgetItem(str(age))
                age_item.setFont(item_font[0])
                self.table_widget.setItem(self.table_widget.rowCount() - 1, 1, age_item)

                country_item = QTableWidgetItem(country)
                country_item.setFont(item_font[0])
                self.table_widget.setItem(
                    self.table_widget.rowCount() - 1, 2, country_item
                )

    def setup_column_sorting(self):
        """
        Setup the column sorting.
        """
        self.table_widget.setSortingEnabled(True)
        self.table_widget.sortItems(0, Qt.SortOrder.AscendingOrder)

    def set_cell_size(self):
        """
        Set the cell size.
        """
        table_width = self.table_widget.viewport().width()
        column_count = self.table_widget.columnCount()
        column_width = table_width // column_count

        for column in range(column_count):
            self.table_widget.setColumnWidth(column, column_width)
