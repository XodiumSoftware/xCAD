from constants import (
    CHECKBOX_STYLE,
    HORIZONTAL_HEADER_LABELS,
    SETTINGS_DATABASE_PATH,
    SETTINGS_LIST,
)
from handlers.db_handler import SettingsDatabaseHandler
from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QCheckBox,
    QComboBox,
    QDoubleSpinBox,
    QHeaderView,
    QLayout,
    QLineEdit,
    QPushButton,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)


# TODO: Make checkbox be centered in the column.
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
        self.set_row_height()

    def set_column_width(self):
        total_width = self.get_total_columns_width()
        table_width = self.table_widget.viewport().width()
        if total_width < table_width:
            stretch_factor = table_width / total_width
        else:
            stretch_factor = 1.0

        for col in range(self.table_widget.columnCount()):
            content_width = self.table_widget.columnWidth(col)
            minimum_width = self.table_widget.sizeHintForColumn(col)
            desired_width = max(content_width, minimum_width * stretch_factor)
            self.table_widget.setColumnWidth(col, int(desired_width))

        self.table_widget.horizontalHeader().setSectionResizeMode(
            QHeaderView.ResizeMode.Stretch
        )

    def get_total_columns_width(self):
        total_width = 0
        for col in range(self.table_widget.columnCount()):
            total_width += self.table_widget.columnWidth(col)
        return total_width

    def set_row_height(self):
        max_height = 0
        for row in range(self.table_widget.rowCount()):
            row_height = 0
            for col in range(self.table_widget.columnCount()):
                item = self.table_widget.item(row, col)
                if item is not None:
                    item_height = item.sizeHint().height()
                    row_height = max(row_height, item_height)

                widget = self.table_widget.cellWidget(row, col)
                if widget is not None:
                    widget_height = widget.sizeHint().height()
                    row_height = max(row_height, widget_height)

            max_height = max(max_height, row_height)

        for row in range(self.table_widget.rowCount()):
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
        elif setting_type == "checkbox":
            value_widget = QCheckBox()
            value_widget.setChecked(args[3] if len(args) > 3 else False)
            value_widget.stateChanged.connect(
                lambda state, param=setting_name: self.save_setting(param, bool(state))
            )
            value_widget.setStyleSheet(CHECKBOX_STYLE)
        # TODO: Fix button setting type and link it with the button_widget to handle the on click event.
        elif setting_type == "button":
            value_widget = QPushButton(args[3] if len(args) > 3 else "")
            value_widget.clicked.connect(
                lambda state, param=setting_name: self.save_setting(param, bool(state))
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
                        elif setting_type == "checkbox":
                            check_box = widget
                            check_box.setChecked(bool(value))
                        elif setting_type == "button":
                            button = widget
                            button.setChecked(bool(value))
                    break

        self.table_widget.resizeRowsToContents()
