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

DATA = [
    ("John Doe", 30, "USA"),
    ("Jane Smith", 25, "Canada"),
    ("Bob Johnson", 45, "UK"),
    ("Alice Brown", 35, "Australia"),
]

HEADER_LABELS = ["Name", "Age", "Country"]
HEADER_STYLE = ["Arial", 10, QFont.Weight.Bold]
CELL_STYLE = ["Arial", 8, None]


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
        self.style_cells()
        self.style_header()
        self.setup_header_sorting()

    def populate_table(self):
        """
        Populate the table.
        """
        for row, (name, age, country) in enumerate(DATA):
            self.table_widget.insertRow(row)
            self.table_widget.setItem(row, 0, QTableWidgetItem(name))
            self.table_widget.setItem(row, 1, QTableWidgetItem(str(age)))
            self.table_widget.setItem(row, 2, QTableWidgetItem(country))

            for column in range(1, self.table_widget.columnCount()):
                item = self.table_widget.item(row, column)
                item.setTextAlignment(Qt.AlignmentFlag.AlignCenter)

            self.table_widget.setRowHeight(row, 20)

    def style_cells(self):
        """
        Style the cells.
        """
        cell_font = QFont(CELL_STYLE)
        for row in range(self.table_widget.rowCount()):
            for column in range(self.table_widget.columnCount()):
                item = self.table_widget.item(row, column)
                item.setFont(cell_font)

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
        self.table_widget.setSortingEnabled(True)
        self.table_widget.sortItems(0, Qt.SortOrder.AscendingOrder)
