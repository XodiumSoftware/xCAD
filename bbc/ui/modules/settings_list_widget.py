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

# TODO: Move the constants to "constants.py".
# TODO: Make the cells have different setting_types.
# TODO: define the setting_types.
# TODO: group_name be bold.
# TODO: group_name be centered.
# TODO: group header have background color.
# TODO: column header have background color.
# TODO: group be foldable to hide/show the items within.
# TODO: Make the content be saved in the SQLite database based on the save/discard button.
# TODO: get the if saved data from the database and display it.
# TODO: change the DATA items content to the appropriate content and dont forget to remove the 3rd column.
# TODO: rename the column to an appropriate name based on the items.

DATA = [
    {
        "group_name": "Group 1",
        "items": [
            ("John Doe", 30, "USA"),
            ("Jane Smith", 25, "Canada"),
            ("Bob Johnson", 45, "UK"),
            ("Alice Brown", 35, "Australia"),
        ],
    },
    {
        "group_name": "Group 2",
        "items": [
            ("Michael Williams", 50, "Germany"),
            ("Emma Johnson", 28, "France"),
            ("William Davis", 42, "Spain"),
            ("Olivia Taylor", 32, "Italy"),
        ],
    },
    {
        "group_name": "Group 3",
        "items": [
            ("James Wilson", 37, "Brazil"),
            ("Sophia Martinez", 31, "Mexico"),
            ("Daniel Anderson", 48, "Argentina"),
            ("Mia Thomas", 29, "Chile"),
        ],
    },
]

HEADER_LABELS = ["Name", "Age", "Country"]
HEADER_STYLE = ["Arial", 10, QFont.Weight.Bold]
CELL_STYLE = ["Arial", 8]


class SettingsListWidget(QWidget):
    def __init__(self):
        """
        Initialize the SettingsListWidget.
        """
        super().__init__()

        self.table_widget = QTableWidget()
        self.table_widget.setColumnCount(len(HEADER_LABELS))
        self.table_widget.setHorizontalHeaderLabels(HEADER_LABELS)
        self.table_widget.setEditTriggers(QAbstractItemView.EditTrigger.NoEditTriggers)
        self.table_widget.setSelectionBehavior(
            QAbstractItemView.SelectionBehavior.SelectRows
        )

        layout = QVBoxLayout(self)
        layout.addWidget(self.table_widget)

        self.populate_table()
        self.style_header()
        self.setup_header_sorting()
        self.set_cell_size()

    def populate_table(self):
        """
        Populate the table with data.
        """
        for group_data in DATA:
            group_name = group_data["group_name"]
            group_items = group_data["items"]

            group_item = QTableWidgetItem(
                group_name
            )  # FIXME: This making the items be a NoneType which is a problem since i wont be able to assign properties to it.
            group_item.setFlags(Qt.ItemFlag.NoItemFlags)
            self.table_widget.insertRow(self.table_widget.rowCount())
            self.table_widget.setItem(self.table_widget.rowCount() - 1, 0, group_item)

            for item in group_items:
                name, age, country = item
                self.table_widget.insertRow(self.table_widget.rowCount())

                name_item = QTableWidgetItem(name)
                self.table_widget.setItem(
                    self.table_widget.rowCount() - 1, 0, name_item
                )

                age_item = QTableWidgetItem(str(age))
                self.table_widget.setItem(self.table_widget.rowCount() - 1, 1, age_item)

                country_item = QTableWidgetItem(country)
                self.table_widget.setItem(
                    self.table_widget.rowCount() - 1, 2, country_item
                )

        self.style_cells()

    def style_cells(self):
        """
        Style the cells.
        """
        cell_font = QFont(*CELL_STYLE)
        for row in range(self.table_widget.rowCount()):
            for column in range(self.table_widget.columnCount()):
                item = self.table_widget.item(row, column)
                item.setFont(
                    cell_font
                )  # FIXME: AttributeError: 'NoneType' object has no attribute 'setFont'
                if column >= 2:
                    item.setTextAlignment(
                        Qt.AlignmentFlag.AlignHCenter
                    )  # FIXME: AttributeError: 'NoneType' object has no attribute 'setTextAlignment'

    def style_header(self):
        """
        Style the header.
        """
        header = self.table_widget.horizontalHeader()
        header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        header_font = QFont(HEADER_STYLE)
        header_font.setBold(True)
        header.setFont(header_font)

    def setup_header_sorting(self):
        """
        Setup the header sorting.
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
