from functools import partial

from constants import CHECKBOX_STYLE, SETTINGS_LIST
from handlers.db_handler import SettingsDatabaseHandler
from handlers.events_handler import EventsHandler
from PySide6.QtCore import Qt, Signal
from PySide6.QtGui import QColor
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


class SettingsListWidget(QWidget):
    save_changes_signal = Signal(dict)
    discard_changes_signal = Signal()

    def __init__(self, current_theme):
        """
        Initialize the SettingsListWidget.
        """
        super().__init__()
        self.db_handler = SettingsDatabaseHandler()

        self.events_handler = EventsHandler(current_theme)
        self.events_handler.save_changes_signal.connect(self.save_setting_changes)
        self.events_handler.discard_changes_signal.connect(self.discard_setting_changes)

        self.init_settings_list_widget()

    def init_settings_list_widget(self):
        """
        Initialize the settings list widget.
        """
        self.layout: QLayout = QVBoxLayout(self)
        self.table_widget = QTableWidget()
        self.layout.addWidget(self.table_widget)

        self.setting_widgets = {}

        self.setup_settings()
        self.set_column_width()
        self.set_row_height()

    def set_column_width(self):
        """
        Set the column widths.
        """
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
        """
        Get the total columns width.
        """
        total_width = 0
        for col in range(self.table_widget.columnCount()):
            total_width += self.table_widget.columnWidth(col)
        return total_width

    def set_row_height(self):
        """
        Set the row heights.
        """
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
        """
        Add a setting to the settings list widget.
        """
        row_count = self.table_widget.rowCount()
        self.table_widget.insertRow(row_count)

        setting_name = args[0]
        setting_type = args[1]
        options = args[2] if len(args) > 2 else []

        setting_item = QTableWidgetItem(setting_name)
        setting_item.setFlags(setting_item.flags() ^ ~Qt.ItemFlag.ItemIsEnabled)
        self.table_widget.setItem(row_count, 0, setting_item)

        if setting_type == "checkbox":
            checkbox_widget = QCheckBox()
            checkbox_widget.setStyleSheet(CHECKBOX_STYLE)
            checkbox_widget.stateChanged.connect(
                partial(self.save_setting_changes, setting_name)
            )
            self.table_widget.setCellWidget(row_count, 1, checkbox_widget)
            self.setting_widgets[setting_name] = checkbox_widget

        elif setting_type == "dropdown":
            value_widget = QComboBox()
            value_widget.addItems(options)  # Specify the type of options as List[str]
            value_widget.setCurrentText(args[3] if len(args) > 3 else "")
            value_widget.currentTextChanged.connect(
                partial(self.save_setting_changes, setting_name)
            )
            self.table_widget.setCellWidget(row_count, 1, value_widget)
            self.setting_widgets[setting_name] = value_widget

        elif setting_type == "input_text":
            value_widget = QLineEdit()
            value_widget.setText(args[3] if len(args) > 3 else "")
            value_widget.textChanged.connect(
                partial(self.save_setting_changes, setting_name)
            )
            self.table_widget.setCellWidget(row_count, 1, value_widget)
            self.setting_widgets[setting_name] = value_widget

        elif setting_type == "input_int":
            value_widget = QDoubleSpinBox()
            value_widget.setValue(int(args[3]) if len(args) > 3 else 0)
            value_widget.valueChanged.connect(
                partial(self.save_setting_changes, setting_name)
            )
            self.table_widget.setCellWidget(row_count, 1, value_widget)
            self.setting_widgets[setting_name] = value_widget

        elif setting_type == "button":
            button_widget = QPushButton(args[2][0])
            button_widget.clicked.connect(
                partial(self.setting_button_clicked, setting_name)
            )
            self.table_widget.setCellWidget(row_count, 1, button_widget)
            self.setting_widgets[setting_name] = button_widget

    def setting_button_clicked(self, setting_name):
        """
        Handle the setting button click.
        """
        print("Setting button clicked:", setting_name)

    def setup_settings(self):
        """
        Setup the settings based on the SETTINGS_LIST constant.
        """
        for setting_group in SETTINGS_LIST:
            group_label = setting_group["group"]
            group_item = QTableWidgetItem(group_label)
            group_item.setForeground(QColor("gray"))
            group_item.setFlags(group_item.flags() ^ ~Qt.ItemFlag.ItemIsEnabled)
            self.table_widget.insertRow(self.table_widget.rowCount())
            self.table_widget.setItem(self.table_widget.rowCount() - 1, 0, group_item)

            for setting in setting_group["settings"]:
                self.add_setting(*setting)

    def save_setting_changes(self, setting_name, *args):
        """
        Save the changes made to a setting.
        """
        setting_value = args[0] if args else None
        self.save_changes_signal.emit({setting_name: setting_value})

    def discard_setting_changes(self):
        """
        Discard the changes made to all settings.
        """
        self.discard_changes_signal.emit()
