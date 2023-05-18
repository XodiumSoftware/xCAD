import os
import sqlite3
import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QComboBox,
    QDoubleSpinBox,
    QLayout,
    QLineEdit,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

DROPDOWN_LIST_GENERAL = ["Option 1", "Option 2", "Option 3"]
DROPDOWN_LIST_SOUND = ["On", "Off"]
SETTINGS_LIST = [
    ("General", "dropdown", DROPDOWN_LIST_GENERAL),
    ("Display", "input_text", []),
    ("Weight", "input_int", []),
    ("Sound", "dropdown", DROPDOWN_LIST_SOUND),
]
HORIZONTAL_HEADER_LABELS = ["Parameter", "Value"]
SETTINGS_DATABASE_PATH = os.path.join("bbc/data/settings.sqlite")


class SettingsListWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initUI()

    def initUI(self):
        self.layout: QLayout = QVBoxLayout(self)
        self.table_widget = QTableWidget()
        self.layout.addWidget(self.table_widget)
        self.database = SettingsDatabase(SETTINGS_DATABASE_PATH)
        self.database.create_table()

        self.setup_settings()

    def add_setting(self, *args):
        row_count = self.table_widget.rowCount()
        self.table_widget.insertRow(row_count)

        for col, arg in enumerate(args):
            if col == 0:
                setting_item = QTableWidgetItem(arg)
                self.table_widget.setItem(row_count, col, setting_item)
            elif col == 1:
                setting_type = arg
                options = args[col + 1] if col + 1 < len(args) else []

                if setting_type == "dropdown":
                    value_item = QComboBox()
                    value_item.addItems(options)
                    value_item.setCurrentText(
                        args[col + 2] if col + 2 < len(args) else ""
                    )
                    self.table_widget.setCellWidget(row_count, col, value_item)
                    value_item.currentTextChanged.connect(
                        lambda text, param=arg: self.save_setting(param, text)
                    )
                elif setting_type == "input_text":
                    value_item = QLineEdit(args[col + 2] if col + 2 < len(args) else "")
                    self.table_widget.setCellWidget(row_count, col, value_item)
                    value_item.textChanged.connect(
                        lambda text, param=arg: self.save_setting(param, text)
                    )
                elif setting_type == "input_int":
                    value_item = QDoubleSpinBox()
                    value_item.setValue(
                        float(args[col + 2] if col + 2 < len(args) else 0)
                    )
                    self.table_widget.setCellWidget(row_count, col, value_item)
                    value_item.valueChanged.connect(
                        lambda value, param=arg: self.save_setting(param, value)
                    )

    def save_setting(self, parameter, value):
        self.database.insert_setting(parameter, str(value))

    def remove_setting(self, setting_name):
        items = self.table_widget.findItems(setting_name, Qt.MatchFlag.MatchExactly)
        if items:
            for item in items:
                row = item.row()
                self.table_widget.removeRow(row)

    def setup_settings(self):
        self.table_widget.setColumnCount(len(HORIZONTAL_HEADER_LABELS))

        for col, label in enumerate(HORIZONTAL_HEADER_LABELS):
            if label:
                header_item = QTableWidgetItem(label)
            else:
                header_item = QTableWidgetItem()
            self.table_widget.setHorizontalHeaderItem(col, header_item)

        for setting in SETTINGS_LIST:
            self.add_setting(*setting)

        self.table_widget.resizeRowsToContents()


class SettingsDatabase:
    def __init__(self, database_path):
        self.database_path = database_path

    def create_table(self):
        conn = sqlite3.connect(self.database_path)
        cursor = conn.cursor()

        # Create the settings table if it doesn't exist
        cursor.execute(
            """
        CREATE TABLE IF NOT EXISTS settings (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                parameter TEXT,
                value TEXT
        )
        """
        )

        conn.commit()
        conn.close()

    def insert_setting(self, parameter, value):
        conn = sqlite3.connect(self.database_path)
        cursor = conn.cursor()

        # Insert the setting into the table
        cursor.execute(
            """
        INSERT INTO settings (parameter, value) VALUES (?, ?)
        """,
            (parameter, value),
        )

        conn.commit()
        conn.close()


def main():
    app = QApplication(sys.argv)
    widget = SettingsListWidget()
    widget.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
