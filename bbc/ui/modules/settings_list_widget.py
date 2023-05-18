from constants import (
    COLUMN_WIDTH,
    HORIZONTAL_HEADER_LABELS,
    SETTINGS_DATABASE_PATH,
    SETTINGS_LIST,
)
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
        self.setting_widgets = {}

        self.setup_settings()
        self.set_column_width()

    def set_column_width(self):
        for col in range(self.table_widget.columnCount()):
            self.table_widget.setColumnWidth(col, COLUMN_WIDTH)

    def set_row_height(self):
        for row in range(self.table_widget.rowCount()):
            max_height = 0
            for col in range(self.table_widget.columnCount()):
                item = self.table_widget.item(row, col)
                if item is not None:
                    item_height = item.sizeHint().height()
                    max_height = max(max_height, item_height)

                widget = self.table_widget.cellWidget(row, col)
                if widget is not None:
                    widget_height = widget.sizeHint().height()
                    max_height = max(max_height, widget_height)

            # Set the row height to the maximum height
            self.table_widget.setRowHeight(row, max_height)

    def add_setting(self, *args):
        row_count = self.table_widget.rowCount()
        self.table_widget.insertRow(row_count)

        setting_name = args[0]
        setting_type = args[1]
        options = args[2] if len(args) > 2 else []

        setting_item = QTableWidgetItem(setting_name)
        self.table_widget.setItem(row_count, 0, setting_item)

        value_widget = None

        if setting_type == "dropdown":
            value_widget = QComboBox()
            value_widget.addItems(options)
            value_widget.setCurrentText(args[3] if len(args) > 3 else "")
            value_widget.currentTextChanged.connect(
                lambda text, param=setting_name: self.save_setting(param, text)
            )
        elif setting_type == "input_text":
            value_widget = QLineEdit(args[3] if len(args) > 3 else "")
            value_widget.textChanged.connect(
                lambda text, param=setting_name: self.save_setting(param, text)
            )
        elif setting_type == "input_int":
            value_widget = QDoubleSpinBox()
            value_widget.setValue(float(args[3] if len(args) > 3 else 0))
            value_widget.valueChanged.connect(
                lambda value, param=setting_name: self.save_setting(param, value)
            )

        if value_widget is not None:
            self.table_widget.setCellWidget(row_count, 1, value_widget)
            self.setting_widgets[setting_name] = value_widget

    def save_setting(self, parameter, value):
        self.database.insert_setting(parameter, str(value))

    def remove_setting(self, setting_name):
        items = self.table_widget.findItems(setting_name, Qt.MatchFlag.MatchExactly)
        if items:
            for item in items:
                row = item.row()
                self.table_widget.removeRow(row)
                del self.setting_widgets[setting_name]

    def setup_settings(self):
        self.table_widget.setColumnCount(len(HORIZONTAL_HEADER_LABELS))

        header_items = [
            QTableWidgetItem(label) if label else QTableWidgetItem()
            for label in HORIZONTAL_HEADER_LABELS
        ]
        self.table_widget.setHorizontalHeaderLabels(
            [label.text() for label in header_items]
        )

        for setting in SETTINGS_LIST:
            setting_name, setting_type, options = setting
            self.add_setting(setting_name, setting_type, options)

            for param, value in self.database.get_settings():
                if param == setting_name:
                    widget = self.setting_widgets.get(setting_name)
                    if widget is not None:
                        if setting_type == "dropdown":
                            combo_box = widget
                            combo_box.setCurrentText(value)
                        elif setting_type == "input_text":
                            line_edit = widget
                            line_edit.setText(value)
                        elif setting_type == "input_int":
                            spin_box = widget
                            spin_box.setValue(float(value))
                    break

        self.table_widget.resizeRowsToContents()
