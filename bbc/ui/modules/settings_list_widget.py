from constants import HORIZONTAL_HEADER_LABELS, SETTINGS_DATABASE_PATH, SETTINGS_LIST
from handlers.db_handler import SettingsDatabaseHandler
from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QComboBox,
    QDoubleSpinBox,
    QLayout,
    QLineEdit,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)


class SettingsListWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initSettingsListWidget()

    def initSettingsListWidget(self):
        self.layout: QLayout = QVBoxLayout(self)
        self.table_widget = QTableWidget()
        self.layout.addWidget(self.table_widget)
        self.database = SettingsDatabaseHandler(SETTINGS_DATABASE_PATH)
        self.database.create_table()

        self.setup_settings()

    def add_setting(self, *args):
        row_count = self.table_widget.rowCount()
        self.table_widget.insertRow(row_count)

        setting_name = args[0]
        setting_type = args[1]
        options = args[2] if len(args) > 2 else []

        setting_item = QTableWidgetItem(setting_name)
        self.table_widget.setItem(row_count, 0, setting_item)

        if setting_type == "dropdown":
            value_item = QComboBox()
            value_item.addItems(options)
            value_item.setCurrentText(args[3] if len(args) > 3 else "")
            self.table_widget.setCellWidget(row_count, 1, value_item)
            value_item.currentTextChanged.connect(
                lambda text, param=setting_name: self.save_setting(param, text)
            )
        elif setting_type == "input_text":
            value_item = QLineEdit(args[3] if len(args) > 3 else "")
            self.table_widget.setCellWidget(row_count, 1, value_item)
            value_item.textChanged.connect(
                lambda text, param=setting_name: self.save_setting(param, text)
            )
        elif setting_type == "input_int":
            value_item = QDoubleSpinBox()
            value_item.setValue(float(args[3] if len(args) > 3 else 0))
            self.table_widget.setCellWidget(row_count, 1, value_item)
            value_item.valueChanged.connect(
                lambda value, param=setting_name: self.save_setting(param, value)
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

        # Retrieve settings from the database
        settings = self.database.get_settings()

        for setting in SETTINGS_LIST:
            setting_name, setting_type, options = setting
            self.add_setting(setting_name, setting_type, options)

            # Find the corresponding setting value from the database
            for param, value in settings:
                if param == setting_name:
                    widget = self.findChild(QWidget, setting_name)
                    if widget is not None:
                        if setting_type == "dropdown":
                            combo_box = widget
                            combo_box.setCurrentText(value)  # type: ignore
                        elif setting_type == "input_text":
                            line_edit = widget
                            line_edit.setText(value)  # type: ignore
                        elif setting_type == "input_int":
                            spin_box = widget
                            spin_box.setValue(value)  # type: ignore
                    break

        self.table_widget.resizeRowsToContents()
