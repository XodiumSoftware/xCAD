from constants import DEBUG_NAME, TABLES
from PySide6.QtCore import QAbstractTableModel, Qt
from PySide6.QtGui import QDoubleValidator, QFont
from PySide6.QtWidgets import (
    QDoubleSpinBox,
    QHeaderView,
    QLineEdit,
    QStyledItemDelegate,
    QTableView,
    QVBoxLayout,
    QWidget,
)


class CellDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):
        cell_type = index.data(Qt.ItemDataRole.UserRole)
        if cell_type == "LineEdit":
            editor = QLineEdit(parent)

        elif cell_type == "DoubleSpinBox":
            editor = QDoubleSpinBox(parent)
            editor.setDecimals(2)
            editor.setSingleStep(0.1)
            editor.setRange(0, 100)
            editor.setValidator(QDoubleValidator(0, 100, 2, parent))

        else:
            print(DEBUG_NAME + f'"{cell_type}" not found in CellDelegate')

        return editor


class PandasModel(QAbstractTableModel):
    def __init__(self, data, column_names):
        """
        Initialize the PandasModel.
        """
        QAbstractTableModel.__init__(self)
        self._data = data
        self._column_names = column_names

    def rowCount(self, parent=None):
        """
        Return the number of rows in the table.
        """
        return self._data.shape[0]

    def columnCount(self, parent=None):
        """
        Return the number of columns in the table.
        """
        return (self._data.shape[1] + 1) // 2

    def data(self, index, role=Qt.ItemDataRole.DisplayRole):
        """
        Return the data at the given index.
        """
        if index.isValid():
            column_index = index.column() * 2
            flag_index = index.column() * 2 + 1

            if role == Qt.ItemDataRole.DisplayRole:
                return str(self._data.iloc[index.row(), column_index])

            if flag_index in TABLES:
                if role == Qt.ItemDataRole.EditRole:
                    flag_value = self._data.iloc[index.row(), flag_index][0]
                    return flag_value

                return flag_index

        return None

    def headerData(self, section, orientation, role=Qt.ItemDataRole.DisplayRole):
        """
        Return the header data at the given section.
        """
        if role == Qt.ItemDataRole.DisplayRole:
            if orientation == Qt.Orientation.Horizontal:
                column_index = section * 2
                return self._column_names[column_index]

        if (
            role == Qt.ItemDataRole.FontRole
            and orientation == Qt.Orientation.Horizontal
        ):
            font = QFont()
            font.setBold(True)
            return font

        return super().headerData(section, orientation, role)


class TableModule(QWidget):
    def __init__(self, table_index, margins=None, parent=None):
        """
        Initialize the table module.
        """
        super().__init__(parent)
        self.margins = margins
        self.setup_table_module(table_index)

    def setup_table_module(self, table_index):
        """
        Setup the tableModule.
        """
        layout = QVBoxLayout(self)

        table_data, column_names = self.get_table_data(table_index)

        if table_data is not None:
            table = self.create_table_module(table_data, column_names)
            layout.addWidget(table)
        else:
            print(DEBUG_NAME + f'"table_index" {table_index} not found in TABLES')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)

        self.setLayout(layout)

    def get_table_data(self, table_index):
        """
        Get the table data from the TABLES constant.
        """
        for table in TABLES:
            if table.get("table_index") == table_index:
                table_data = table.get("table_data")
                column_names = table_data.columns.tolist()
                return table_data, column_names
        return None, None

    def create_table_module(self, table_data, column_names):
        """
        Create a table module.
        """
        table_view = QTableView()
        model = PandasModel(table_data, column_names)
        table_view.setModel(model)
        table_view.setSortingEnabled(True)

        header = table_view.horizontalHeader()
        header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)

        return table_view
