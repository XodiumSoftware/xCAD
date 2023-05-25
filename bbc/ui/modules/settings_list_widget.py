from constants import SETTINGS_LIST
from handlers.db_handler import SettingsDatabaseHandler
from handlers.events_handler import EventsHandler
from PySide6.QtCore import QAbstractTableModel, Qt, Signal
from PySide6.QtGui import QFont, QStandardItem, QStandardItemModel
from PySide6.QtWidgets import (
    QCheckBox,
    QComboBox,
    QHeaderView,
    QLineEdit,
    QPushButton,
    QSpinBox,
    QStyledItemDelegate,
    QTableView,
    QVBoxLayout,
    QWidget,
)


class SettingsTableModel(QAbstractTableModel):
    def __init__(self, settings_list, parent=None):
        """
        Initialize the SettingsTableModel.
        """
        super().__init__(parent)
        self.settings_list = settings_list

    def rowCount(self, parent=None):
        """
        Return the number of rows.
        """
        return len(self.settings_list)

    def columnCount(self, parent=None):
        """
        Return the number of columns.
        """
        return 2

    def data(self, index, role=Qt.ItemDataRole.DisplayRole):
        """
        Return the data.
        """
        if role == Qt.ItemDataRole.DisplayRole:
            setting = self.settings_list[index.row()]
            if index.column() == 0:
                return setting[0]
            elif index.column() == 1:
                return setting[1]
        return None

    def setData(self, index, value, role=Qt.ItemDataRole.EditRole):
        """
        Set the data.
        """
        if role == Qt.ItemDataRole.EditRole:
            setting = self.settings_list[index.row()]
            if index.column() == 1:
                setting[1] = value
                self.dataChanged.emit(index, index)
                return True
        return False

    def flags(self, index):
        """
        Return the flags.
        """
        flags = super().flags(index)
        if index.column() == 1:
            flags |= Qt.ItemFlag.ItemIsEditable
        return flags


class WidgetDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):
        """
        Create the editor.
        """
        setting = index.data(Qt.ItemDataRole.UserRole + 1)
        setting_type = setting[2]
        if setting_type == "dropdown":
            editor = QComboBox(parent)
            dropdown_values = setting[3]
            editor.addItems(dropdown_values)
        elif setting_type == "input_text":
            editor = QLineEdit(parent)
        elif setting_type == "input_int":
            editor = QSpinBox(parent)
            min_value, max_value = setting[3]
            editor.setRange(min_value, max_value)
        elif setting_type == "checkbox":
            editor = QCheckBox(parent)
        elif setting_type == "button":
            editor = QPushButton(parent)
            editor.setText(setting[3])
        else:
            editor = super().createEditor(parent, option, index)

        return editor

    def setEditorData(self, editor, index):
        """
        Set the editor data.
        """
        value = index.data()
        if isinstance(editor, QComboBox):
            editor.setCurrentText(value)
        elif isinstance(editor, QLineEdit):
            editor.setText(value)
        elif isinstance(editor, QSpinBox):
            editor.setValue(int(value))
        elif isinstance(editor, QCheckBox):
            editor.setChecked(bool(value))
        elif isinstance(editor, QPushButton):
            editor.setText(value)
        else:
            super().setEditorData(editor, index)

    def setModelData(self, editor, model, index):
        """
        Set the model data.
        """
        if isinstance(editor, QComboBox):
            value = editor.currentText()
        elif isinstance(editor, QLineEdit):
            value = editor.text()
        elif isinstance(editor, QSpinBox):
            value = editor.value()
        elif isinstance(editor, QCheckBox):
            value = editor.isChecked()
        elif isinstance(editor, QPushButton):
            value = editor.text()
        else:
            return super().setModelData(editor, model, index)

        model.setData(index, value)


class MergingTableView(QTableView):
    def setSpan(self, row, column, rowSpan, columnSpan):
        """
        Set the span.
        """
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
        Initialize the SettingsListWidget.
        """
        self.layout: QVBoxLayout = QVBoxLayout(self)

        self.table_view = MergingTableView()
        self.table_view.horizontalHeader().setSectionResizeMode(
            QHeaderView.ResizeMode.Stretch
        )
        self.table_view.horizontalHeader().setStretchLastSection(True)

        self.layout.addWidget(self.table_view)

        self.setting_model = QStandardItemModel(self)
        self.table_view.setModel(self.setting_model)

        self.setup_settings()

        self.delegate = WidgetDelegate(self)
        self.table_view.setItemDelegateForColumn(1, self.delegate)

    def setup_settings(self):
        """
        Setup the settings.
        """
        self.setting_model.clear()

        header_font = QFont()
        header_font.setBold(True)

        for setting_group in SETTINGS_LIST:
            group_label = setting_group["group"]
            group_item = QStandardItem(group_label)
            group_item.setEnabled(False)
            group_item.setFont(header_font)
            group_item.setTextAlignment(Qt.AlignmentFlag.AlignCenter)
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
                value_item = QStandardItem("")
                self.setting_model.appendRow([setting_item, value_item])
                value_item.setData(setting, Qt.ItemDataRole.UserRole + 1)

                setting_value = setting[1]
                if setting_value is not None:
                    value_item = QStandardItem(setting_value)
                    self.setting_model.setItem(
                        self.setting_model.rowCount() - 1, 1, value_item
                    )

        self.table_view.resizeColumnsToContents()

    def get_total_columns_width(self):
        """
        Return the total columns width.
        """
        total_width = 0
        for column in range(self.setting_model.columnCount()):
            total_width += self.table_view.columnWidth(column)
        return total_width

    def save_setting_changes(self, setting_name, *args):
        """
        Save the changes.
        """
        setting_value = args[0] if args else None
        self.save_changes_signal.emit({setting_name: setting_value})

    def discard_setting_changes(self):
        """
        Discard the changes.
        """
        self.discard_changes_signal.emit()
