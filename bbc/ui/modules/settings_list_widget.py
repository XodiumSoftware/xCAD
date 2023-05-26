from constants import SETTINGS_LIST
from handlers.db_handler import SettingsDatabaseHandler
from handlers.events_handler import EventsHandler
from PySide6.QtCore import QAbstractTableModel, Qt, Signal
from PySide6.QtGui import QFont, QFontMetrics
from PySide6.QtWidgets import (
    QAbstractItemView,
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
        super().__init__(parent)
        self.settings_list = settings_list

    def rowCount(self, parent=None):
        return sum(len(group["settings"]) + 1 for group in self.settings_list)

    def columnCount(self, parent=None):
        return 2

    def data(self, index, role=Qt.ItemDataRole.DisplayRole):
        if role == Qt.ItemDataRole.DisplayRole or role == Qt.ItemDataRole.EditRole:
            row = index.row()
            column = index.column()

            if row < len(self.settings_list):
                if column == 0:
                    return self.settings_list[row]["group"]["name"]
            else:
                row -= len(self.settings_list)
                group_index = 0
                while row >= len(self.settings_list[group_index]["settings"]):
                    row -= len(self.settings_list[group_index]["settings"])
                    group_index += 1

                setting = self.settings_list[group_index]["settings"][row]
                if column == 0:
                    return setting[0]
                elif column == 1:
                    return setting[1]

        return None

    def setData(self, index, value, role=Qt.ItemDataRole.EditRole):
        if role == Qt.ItemDataRole.EditRole:
            row = index.row()
            column = index.column()

            if row >= len(self.settings_list):
                row -= len(self.settings_list)
                group_index = 0
                while row >= len(self.settings_list[group_index]["settings"]):
                    row -= len(self.settings_list[group_index]["settings"])
                    group_index += 1

                setting = self.settings_list[group_index]["settings"][row]
                if column == 1:
                    setting[1] = value
                    self.dataChanged.emit(index, index)
                    return True

        return False

    def flags(self, index):
        flags = super().flags(index)
        if index.column() == 1:
            flags |= Qt.ItemFlag.ItemIsEditable
        return flags


class WidgetDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):
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
    def __init__(self, model, parent=None):
        super().__init__(parent)
        self.setModel(model)
        self.setSpan(0, 0, 1, model.columnCount())
        self.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        self.horizontalHeader().setStretchLastSection(True)
        self.verticalHeader().setVisible(False)
        self.setSelectionBehavior(QAbstractItemView.SelectionBehavior.SelectRows)
        self.setShowGrid(False)
        self.setFocusPolicy(Qt.FocusPolicy.NoFocus)
        self.setEditTriggers(QAbstractItemView.EditTrigger.AllEditTriggers)

        self.setStyleSheet(
            "QTableView::item:selected { background-color: transparent; }"
        )

    def setSpan(self, row, column, rowSpan, columnSpan):
        if rowSpan > 1:
            super().setSpan(row, column, rowSpan, columnSpan)

    def resizeEvent(self, event):
        super().resizeEvent(event)
        self.updateHeaderFont()

    def updateHeaderFont(self):
        header = self.horizontalHeader()
        font = header.font()
        font_metrics = QFontMetrics(font)
        max_group_width = 0

        for group in SETTINGS_LIST:
            group_name = group["group"]["name"]
            group_width = font_metrics.width(group_name)
            if group_width > max_group_width:
                max_group_width = group_width

        font.setBold(True)
        header_font = QFontMetrics(font)

        for section in range(header.count()):
            logical_index = header.logicalIndex(section)
            is_group_header = logical_index % 2 == 0
            if is_group_header:
                header.setSectionResizeMode(logical_index, QHeaderView.ResizeMode.Fixed)
                header.setSectionResizeMode(
                    logical_index + 1, QHeaderView.ResizeMode.Stretch
                )
                header.resizeSection(logical_index, max_group_width + 20)
                header.setFont(logical_index, header_font.font())
            else:
                header.setSectionResizeMode(
                    logical_index, QHeaderView.ResizeMode.Stretch
                )
                header.setDefaultSectionSize(header_font.height() + 10)


class SettingsListWidget(QWidget):
    save_changes_signal = Signal(dict)
    discard_changes_signal = Signal()

    def __init__(self, current_theme):
        super().__init__()
        self.db_handler = SettingsDatabaseHandler()

        self.events_handler = EventsHandler(current_theme)
        self.events_handler.save_changes_signal.connect(self.save_setting_changes)
        self.events_handler.discard_changes_signal.connect(self.discard_setting_changes)

        self.setting_model = SettingsTableModel(SETTINGS_LIST)

        self.init_settings_list_widget()

    def init_settings_list_widget(self):
        self.layout: QVBoxLayout = QVBoxLayout(self)

        self.table_view = MergingTableView(self.setting_model)
        self.layout.addWidget(self.table_view)

        self.delegate = WidgetDelegate(self)
        self.table_view.setItemDelegateForColumn(1, self.delegate)

    def save_setting_changes(self, setting_name, *args):
        setting_value = args[0] if args else None
        self.save_changes_signal.emit({setting_name: setting_value})

    def discard_setting_changes(self):
        self.discard_changes_signal.emit()

    def get_total_columns_width(self):
        total_width = 0
        for column in range(self.setting_model.columnCount()):
            total_width += self.table_view.columnWidth(column)
        return total_width
