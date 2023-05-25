from constants import SETTINGS_LIST
from handlers.db_handler import SettingsDatabaseHandler
from handlers.events_handler import EventsHandler
from PySide6.QtCore import QAbstractTableModel, Qt, Signal
from PySide6.QtGui import QStandardItem, QStandardItemModel
from PySide6.QtWidgets import QHeaderView, QLayout, QTableView, QVBoxLayout, QWidget


class SettingsTableModel(QAbstractTableModel):
    def __init__(self, settings_list, parent=None):
        super().__init__(parent)
        self.settings_list = settings_list

    def rowCount(self):
        return len(self.settings_list)

    def columnCount(self):
        return 2

    def data(self, index, role=Qt.ItemDataRole.DisplayRole):
        if role == Qt.ItemDataRole.DisplayRole:
            setting = self.settings_list[index.row()]
            if index.column() == 0:
                return setting[0]
            elif index.column() == 1:
                return setting[1]
        return None

    def setData(self, index, value, role=Qt.ItemDataRole.EditRole):
        if role == Qt.ItemDataRole.EditRole:
            setting = self.settings_list[index.row()]
            if index.column() == 1:
                setting[1] = value  # Update setting value
                self.dataChanged.emit(index, index, [Qt.ItemDataRole.DisplayRole])
                return True
        return False

    def flags(self, index):
        flags = super().flags(index)
        if index.column() == 1:
            flags |= Qt.ItemFlag.ItemIsEditable
        return flags


class MergingTableView(QTableView):
    def setSpan(self, row, column, rowSpan, columnSpan):
        if rowSpan == 1:
            super().setSpan(row, column, rowSpan, columnSpan)


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

        # Create the merging table view and set its properties
        self.table_view = MergingTableView()
        self.table_view.horizontalHeader().setSectionResizeMode(
            QHeaderView.ResizeMode.Stretch
        )
        self.table_view.horizontalHeader().setStretchLastSection(True)

        # Add the table view to the layout
        self.layout.addWidget(self.table_view)

        # Initialize the setting model
        self.setting_model = QStandardItemModel(self)
        self.table_view.setModel(self.setting_model)

        # Setup the settings
        self.setup_settings()

    def setup_settings(self):
        """
        Setup the settings based on the SETTINGS_LIST constant.
        """
        self.setting_model.clear()

        for setting_group in SETTINGS_LIST:
            group_label = setting_group["group"]
            group_item = QStandardItem(group_label)
            group_item.setEnabled(False)
            self.setting_model.appendRow(group_item)
            self.table_view.setSpan(
                self.setting_model.rowCount() - 1,
                0,
                1,
                self.setting_model.columnCount(),
            )

            for setting in setting_group["settings"]:
                setting_name = setting[0]
                setting_item = QStandardItem(setting_name)
                setting_item.setEnabled(False)
                value_item = QStandardItem("")  # Create an empty value item
                self.setting_model.appendRow(
                    [setting_item, value_item]
                )  # Use value_item instead of None

                setting_value = setting[1]
                if setting_value is not None:
                    value_item = QStandardItem(setting_value)
                    self.setting_model.setItem(
                        self.setting_model.rowCount() - 1, 1, value_item
                    )

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
