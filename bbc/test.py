import os
import sqlite3
import sys

import pandas as pd
from PySide6.QtCore import QSettings, Qt
from PySide6.QtGui import QFont
from PySide6.QtSql import QSqlDatabase, QSqlTableModel
from PySide6.QtWidgets import (
    QApplication,
    QComboBox,
    QDoubleSpinBox,
    QHeaderView,
    QLabel,
    QMainWindow,
    QPushButton,
    QStyledItemDelegate,
    QTableView,
    QVBoxLayout,
    QWidget,
)

INIT_DATA = {
    "Parameter": [
        "Structure",
        "Length (mm)",
        "Height (mm)",
        "Area (m2)",
        "Perimeter (m1)",
    ],
    "Value": [
        "Select",
        6000,
        3000,
        18,
        18,
    ],
}


class CellDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):
        source_index = index.model().mapToSource(index)
        source_column = source_index.column()
        source_row = source_index.row()

        if source_column == 2:
            if source_row == 0:
                editor = QComboBox(parent)
                editor.addItem("Option 1")
                editor.addItem("Option 2")
                return editor
            elif source_row in (1, 2):
                editor = QDoubleSpinBox(parent)
                editor.setRange(0, 1.79769e308)
                editor.setDecimals(0)
                editor.setSingleStep(1)
                return editor
            elif source_row in (3, 4):
                editor = QLabel(parent)
                return editor

        return None


class DataBaseHandler:
    def __init__(self, database_file):
        self.database_file = database_file

    def setup_database(self):
        """
        Create and populate a database if it doesn't exist.
        """
        db = QSqlDatabase.addDatabase("QSQLITE")
        db.setDatabaseName(self.database_file)
        db.open()

        model = QSqlTableModel()
        model.setTable("my_table")

        if not model.select():
            conn = sqlite3.connect(self.database_file)
            df = pd.DataFrame(INIT_DATA)
            df.to_sql(
                "my_table", conn, if_exists="replace", index=True, index_label="Index"
            )
            conn.close()
            model.select()

        return model


class TableViewWidget(QWidget):
    def __init__(self, model, settings):
        super().__init__()
        self.model = model
        self.settings = settings

        self.setup_ui()

    def setup_ui(self):
        layout = QVBoxLayout(self)

        self.table_view = QTableView()
        self.table_view.setModel(self.model)
        self.table_view.setWordWrap(True)
        self.table_view.horizontalHeader().setVisible(True)
        self.table_view.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.table_view.verticalHeader().setVisible(True)
        self.table_view.verticalHeader().setSectionResizeMode(QHeaderView.Fixed)
        self.table_view.hideColumn(0)
        self.table_view.setSortingEnabled(True)

        font = QFont()
        font.setBold(True)
        self.table_view.horizontalHeader().setFont(font)
        self.table_view.verticalHeader().setFont(font)

        delegate = CellDelegate()
        self.table_view.setItemDelegate(delegate)

        column_sort_index = self.settings.value(
            "column_sort_index",
            0,
            type=int,
        )
        column_sort_order = self.settings.value(
            "column_sort_order",
            Qt.AscendingOrder,
            type=int,
        )
        self.table_view.horizontalHeader().setSortIndicator(
            column_sort_index, Qt.SortOrder(column_sort_order)
        )

        layout.addWidget(self.table_view)


class MainWindow(QMainWindow):
    def __init__(self):
        """
        Initialize the window and set its properties.
        """
        super().__init__()

        self.setWindowTitle("My Application")
        self.resize(500, 400)

        self.settings = QSettings("MyCompany", "MyApplication")

        self.database_dir = os.path.join(os.path.dirname(__file__), "data")
        self.database_file = os.path.join(self.database_dir, "test_database.sqlite")

        if not os.path.exists(self.database_dir):
            os.makedirs(self.database_dir)

        self.setup_database()
        self.setup_ui()
        self.update_window_title()

    def setup_database(self):
        """
        Create and populate a database if it doesn't exist.
        """
        db_handler = DataBaseHandler(self.database_file)
        self.model = db_handler.setup_database()

    def setup_ui(self):
        """
        Create and set up the window's widgets.
        """
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        layout = QVBoxLayout(central_widget)

        self.table_widget = TableViewWidget(self.model, self.settings)

        save_button = QPushButton("Save Changes")
        save_button.clicked.connect(self.save_changes)

        discard_button = QPushButton("Discard Changes")
        discard_button.clicked.connect(self.discard_changes)

        reset_button = QPushButton("Reset Data")
        reset_button.clicked.connect(self.reset_data)

        layout.addWidget(self.table_widget)
        layout.addWidget(save_button)
        layout.addWidget(discard_button)
        layout.addWidget(reset_button)

        self.model.dataChanged.connect(self.update_window_title)

    def update_window_title(self):
        """
        Update the window's title to reflect whether there are unsaved changes.
        """
        unsaved_changes = self.model.isDirty()
        window_title = "My Application"
        if unsaved_changes:
            window_title += " *"
        self.setWindowTitle(window_title)

    def save_changes(self):
        """
        Save the changes and update the window title.
        """
        self.model.submitAll()
        self.update_window_title()

    def discard_changes(self):
        """
        Discard the changes and update the window title.
        """
        self.model.revertAll()
        self.update_window_title()

    def reset_data(self):
        """
        Reset the data to its initial state and update the window title.
        """
        conn = sqlite3.connect(self.database_file)
        df = pd.DataFrame(INIT_DATA)
        df.to_sql(
            "my_table", conn, if_exists="replace", index=True, index_label="Index"
        )
        conn.close()

        self.model.select()
        self.update_window_title()

    def keyPressEvent(self, event):
        """
        Handle key press events.
        """
        if event.key() == Qt.Key_Escape or (
            event.key() == Qt.Key_Q and event.modifiers() & Qt.ControlModifier
        ):
            self.close()

    def closeEvent(self, event):
        """
        Handle the close event and save the column sorting state to settings.
        """
        sort_index = (
            self.table_widget.table_view.horizontalHeader().sortIndicatorSection()
        )
        sort_order = (
            self.table_widget.table_view.horizontalHeader().sortIndicatorOrder()
        )
        self.settings.setValue("column_sort_index", sort_index)
        self.settings.setValue("column_sort_order", int(sort_order.value))

        event.accept()


if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec())
