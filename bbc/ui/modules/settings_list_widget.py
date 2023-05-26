from constants import COLUMN_HEADER_LABELS
from PySide6.QtCore import QAbstractTableModel, QModelIndex, Qt
from PySide6.QtWidgets import (
    QCheckBox,
    QComboBox,
    QLineEdit,
    QPushButton,
    QSpinBox,
    QTableView,
    QWidget,
)


class SettingsListWidget(QWidget):
    def __init__(self, settings_list, parent=None):
        super().__init__(parent)
        self.model = SettingsTableModel(settings_list)
        self.view = QTableView()
        self.view.setModel(self.model)

    def get_total_columns_width(self):
        total_width = 0
        for column in range(self.model.columnCount()):
            header_data = self.model.headerData(
                column, Qt.Orientation.Horizontal, Qt.ItemDataRole.SizeHintRole
            )
            if header_data is not None:
                total_width += len(header_data)
        return total_width


class SettingsTableModel(QAbstractTableModel):
    def __init__(self, settings_list):
        super().__init__()
        self.settings_list = settings_list

    def rowCount(self, parent=QModelIndex()):
        return sum(len(group["settings"]) + 1 for group in self.settings_list)

    def columnCount(self, parent=QModelIndex()):
        return 2

    def data(self, index, role=Qt.ItemDataRole.DisplayRole):
        if not index.isValid():
            return None

        row = index.row()
        col = index.column()
        group_index, setting_index = self.get_setting_indices(row)

        if role == Qt.ItemDataRole.DisplayRole:
            if col == 0:
                if setting_index == -1:
                    return self.settings_list[group_index]["group"]["name"]
                else:
                    return self.settings_list[group_index]["settings"][setting_index][0]
            elif col == 1:
                if setting_index != -1:
                    setting_type = self.settings_list[group_index]["settings"][
                        setting_index
                    ][1]
                    if setting_type == "dropdown":
                        return self.create_dropdown_widget(
                            self.settings_list[group_index]["settings"][setting_index][
                                2
                            ]
                        )
                    elif setting_type == "input_text":
                        return self.create_input_text_widget()
                    elif setting_type == "input_int":
                        return self.create_input_int_widget()
                    elif setting_type == "checkbox":
                        return self.create_checkbox_widget()
                    elif setting_type == "button":
                        return self.create_button_widget()

        return None

    def headerData(self, section, orientation, role=Qt.ItemDataRole.DisplayRole):
        if role == Qt.ItemDataRole.DisplayRole:
            if orientation == Qt.Orientation.Horizontal:
                return COLUMN_HEADER_LABELS[section]
        return None

    def get_setting_indices(self, row):
        count = 0
        for group_index, group in enumerate(self.settings_list):
            count += 1  # Group header
            if row < count:
                return group_index, -1
            count += len(group["settings"])  # Settings
            if row < count:
                return group_index, row - count + len(group["settings"])
        return -1, -1

    def create_dropdown_widget(self, options):
        widget = QComboBox()
        widget.addItems(options)
        return widget

    def create_input_text_widget(self):
        widget = QLineEdit()
        return widget

    def create_input_int_widget(self):
        widget = QSpinBox()
        return widget

    def create_checkbox_widget(self):
        widget = QCheckBox()
        return widget

    def create_button_widget(self):
        widget = QPushButton("Button")
        return widget
