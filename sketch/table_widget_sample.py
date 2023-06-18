import re
import sys
from functools import partial

from PySide6.QtCore import QAbstractTableModel, QModelIndex, QSettings, QSize, Qt
from PySide6.QtGui import QColor, QPainter, QPen
from PySide6.QtWidgets import (
    QApplication,
    QDoubleSpinBox,
    QHeaderView,
    QPushButton,
    QStyledItemDelegate,
    QTableView,
    QVBoxLayout,
    QWidget,
)

# TODO: add something that designs the table grid for example cell color, cell borders, table borders, etc.


class DoubleSpinBoxDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):
        editor = QDoubleSpinBox(parent)
        editor.setFrame(False)
        editor.setRange(0, 999)
        editor.setDecimals(0)
        editor.setSingleStep(1)
        return editor

    def setEditorData(self, editor, index):
        value = index.model().data(index, Qt.EditRole)
        editor.setValue(float(value))

    def setModelData(self, editor, model, index):
        value = editor.value()
        model.setData(index, value, Qt.EditRole)


class CustomTableModel(QAbstractTableModel):
    group_key = "Group 1"

    def __init__(self, data, parent=None):
        super().__init__(parent)
        self._data = data
        self.header_labels = ["Parameter", "Value"]
        self.sort_order = [Qt.AscendingOrder] * len(self.header_labels)

        settings = QSettings()
        self.sort_column = settings.value("SortColumn", 0, type=int)
        self.editing_row = -1

    def rowCount(self, parent=QModelIndex()):
        return len(self._data)

    def columnCount(self, parent=QModelIndex()):
        return len(self.header_labels)

    def data(self, index, role=Qt.DisplayRole):
        if not index.isValid():
            return None

        row = index.row()
        col = index.column()

        if role == Qt.DisplayRole:
            return self._data[row][col]
        elif role == Qt.BackgroundRole:
            if self._data[row][0] == self.group_key:
                return QColor(192, 192, 192)  # TODO change color to something blue.
        elif role == Qt.EditRole and col == 1:
            return self._data[row][col]
        elif role == Qt.ItemDataRole:
            if self._data[row][0] == self.group_key:
                return QSize(self.columnCount(), 1)
        elif role == Qt.ItemIsEditable and col == 1:
            return True

        return None

    def setData(self, index, value, role=Qt.EditRole):
        if index.isValid() and role == Qt.EditRole:
            row = index.row()
            col = index.column()
            self._data[row][col] = value
            self.dataChanged.emit(index, index, [Qt.EditRole])
            return True

        return False

    def flags(self, index):
        if not index.isValid():
            return Qt.ItemIsEnabled

        col = index.column()
        if col == 0:
            if self._data[index.row()][0] == self.group_key:
                return Qt.ItemIsEnabled | Qt.ItemIsEditable

            else:
                return Qt.ItemIsEnabled

        elif col == 1:
            if self._data[index.row()][1] == None:
                return Qt.ItemIsEnabled
            else:
                return Qt.ItemIsEnabled | Qt.ItemIsEditable

        return Qt.ItemIsEnabled

    def headerData(self, section, orientation, role=Qt.DisplayRole):
        if role == Qt.DisplayRole and orientation == Qt.Horizontal:
            return self.header_labels[section]

        elif role == Qt.DisplayRole and orientation == Qt.Vertical:
            return section + 1

        return None

    def insertRow(self, row, parent=QModelIndex()):
        self.beginInsertRows(parent, row, row)
        self._data.insert(row, ["New Group", None])
        self.endInsertRows()
        return True

    def removeRow(self, row, parent=QModelIndex()):
        if row < 0 or row >= len(self._data):
            return False

        self.beginRemoveRows(parent, row, row)
        del self._data[row]
        self.endRemoveRows()
        return True

    def sort(self, column, order):
        self.layoutAboutToBeChanged.emit()
        self.sort_column = column
        self.sort_order[column] = order
        self._data.sort(
            key=partial(self.sort_key, column), reverse=order == Qt.DescendingOrder
        )
        self.layoutChanged.emit()

        settings = QSettings()
        settings.setValue("SortColumn", column)

    def sort_key(self, column, item):
        return item[column]

    def editorEvent(self, event, model, option, index):
        if event.type() == event.MouseButtonPress and event.button() == Qt.LeftButton:
            if index.isValid() and index.column() == 0:
                self.editing_row = index.row()
                self.dataChanged.emit(index, index, [Qt.EditRole])
                return True

        return super().editorEvent(event, model, option, index)
 
    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setPen(QPen(Qt.black))
        painter.setBrush(Qt.NoBrush)

        for row in range(self.model.rowCount()):
            for col in range(self.model.columnCount()):
                rect = self.table_view.visualRect(self.model.index(row, col))
                painter.drawRect(rect)

        table_rect = self.table_view.viewport().rect()
        painter.drawRect(table_rect)

        return super().paintEvent(event)


class TableViewWidget(QWidget):
    def __init__(self):
        super().__init__()

        # FIXME: cell not editable after changing group name in the cell.
        self.model = CustomTableModel(
            [
                [CustomTableModel.group_key, None],
                ["Length", "0"],
                ["Height", "0"],
            ],
            parent=self,
        )
        self.table_view = QTableView()
        self.table_view.setModel(self.model)
        self.table_view.setItemDelegateForColumn(1, DoubleSpinBoxDelegate())
        self.table_view.setEditTriggers(
            QTableView.SelectedClicked | QTableView.DoubleClicked
        )
        self.table_view.setAlternatingRowColors(True)

        header = self.table_view.horizontalHeader()
        header.setSectionResizeMode(QHeaderView.Stretch)
        header.setStretchLastSection(False)

        vertical_header = self.table_view.verticalHeader()
        vertical_header.setSectionResizeMode(QHeaderView.Fixed)
        vertical_header.setDefaultSectionSize(24)

        self.table_view.setVerticalHeader(vertical_header)

        self.table_view.setSortingEnabled(True)
        self.table_view.sortByColumn(
            self.model.sort_column, self.model.sort_order[self.model.sort_column]
        )

        self.add_group_button = QPushButton("+")
        self.add_group_button.clicked.connect(self.model.insertRow)

        self.remove_group_button = QPushButton("-")
        self.remove_group_button.clicked.connect(self.model.removeRow)

        layout = QVBoxLayout(self)
        layout.addWidget(self.table_view)
        layout.addWidget(self.add_group_button)
        layout.addWidget(self.remove_group_button)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Escape or (
            event.modifiers() & Qt.ControlModifier and event.key() == Qt.Key_Q
        ):
            QApplication.quit()
        else:
            super().keyPressEvent(event)


def run():
    app = QApplication([])
    widget = TableViewWidget()
    widget.show()
    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
