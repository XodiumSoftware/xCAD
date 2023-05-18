from PySide6.QtCore import Qt
from PySide6.QtGui import QFont
from PySide6.QtWidgets import (
    QApplication,
    QComboBox,
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
    ("General", "Enabled", "dropdown", DROPDOWN_LIST_GENERAL),
    ("Display", "High", "input", []),
    ("Sound", "On", "dropdown", DROPDOWN_LIST_SOUND),
]
HORIZONTAL_HEADER_LABELS = ["Parameter", "Value"]


class SettingsListWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initUI()
        self.setup_settings()

    def initUI(self):
        self.layout: QLayout = QVBoxLayout(self)
        self.table_widget = QTableWidget()
        self.layout.addWidget(self.table_widget)

    def add_setting(self, setting_name, setting_value, setting_type, options):
        row_count = self.table_widget.rowCount()
        self.table_widget.insertRow(row_count)

        setting_item = QTableWidgetItem(setting_name)
        self.table_widget.setItem(row_count, 0, setting_item)

        if setting_type == "dropdown":
            value_item = QComboBox()
            value_item.addItems(options)
            value_item.setCurrentText(setting_value)
            self.table_widget.setCellWidget(row_count, 1, value_item)
        else:
            value_item = QLineEdit(setting_value)
            self.table_widget.setCellWidget(row_count, 1, value_item)

    def remove_setting(self, setting_name):
        items = self.table_widget.findItems(setting_name, Qt.MatchFlag.MatchExactly)
        if items:
            for item in items:
                row = item.row()
                self.table_widget.removeRow(row)

    def setup_settings(self):
        self.table_widget.setColumnCount(len(HORIZONTAL_HEADER_LABELS) + 1)

        for col, label in enumerate(HORIZONTAL_HEADER_LABELS):
            header_item = QTableWidgetItem(label)
            self.table_widget.setHorizontalHeaderItem(col, header_item)

        for setting in SETTINGS_LIST:
            self.add_setting(*setting[0:4])

        # Resize rows to fit the content
        self.table_widget.resizeRowsToContents()


app = QApplication([])
widget = SettingsListWidget()
widget.show()
app.exec()
