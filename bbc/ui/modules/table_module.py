from constants import DATABASE_PATH, DEBUG_NAME, TABLES
from PySide6.QtCore import Qt
from PySide6.QtSql import QSqlDatabase, QSqlQuery, QSqlTableModel
from PySide6.QtWidgets import (
    QDoubleSpinBox,
    QHeaderView,
    QLineEdit,
    QSpinBox,
    QStyledItemDelegate,
    QTableView,
    QVBoxLayout,
    QWidget,
)


class TableModule(QWidget):
    def __init__(self, table_index, margins=None, alignment=None, parent=None):
        """
        Initialize the TableModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.alignment = alignment
        self.setup_table_module(table_index)

    def setup_table_module(self, table_index):
        """
        Setup the TableModule.
        """
        layout = QVBoxLayout(self)

        table_data = next(
            (table for table in TABLES if table["index"] == table_index), None
        )

        if table_index:
            table = self.create_table_module(table_data)
            layout.addWidget(table)

        else:
            print(DEBUG_NAME + f'"index" {table_index} not found in TABLES')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if self.alignment is not None:
            layout.setAlignment(*self.alignment)

        self.setLayout(layout)

    def create_table_module(self, table_data):
        """
        Create a table module.
        """
        table = QTableView()
        table.setStyleSheet(table_data["stylesheet"])
        table.setSortingEnabled(table_data["sorting"])
        table.setAlternatingRowColors(table_data["alternating_row_colors"])

        font = table.font()
        font.setBold(True)

        hor_header = table.horizontalHeader()
        hor_header.setVisible(True)
        hor_header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        hor_header.setFont(font)

        ver_header = table.verticalHeader()
        ver_header.setVisible(True)
        ver_header.setSectionResizeMode(QHeaderView.ResizeMode.Fixed)
        ver_header.setFont(font)

        table_name = table_data["desc"]
        model = QSqlTableModel()

        db = QSqlDatabase.addDatabase("QSQLITE")
        db.setDatabaseName(DATABASE_PATH)
        if db.open():
            query = QSqlQuery(db)
            query.exec(f"SELECT * FROM {table_name}")
            model.setQuery(query)
            model.setEditStrategy(QSqlTableModel.EditStrategy.OnManualSubmit)
            db.close()

        else:
            print(DEBUG_NAME + f"failed to open {DATABASE_PATH}")

        table.setModel(model)

        delegate = CustomDelegate()
        # TODO: make this be 1,3,5,7,etc. apply the correct logic in the delegate.
        table.setItemDelegateForColumn(1, delegate)

        column_count = model.columnCount()
        for column in range(0, column_count, 2):
            table.hideColumn(column)

        return table


class CustomDelegate(QStyledItemDelegate):
    def __init__(self, parent=None):
        """
        Initialize the CustomDelegate.
        """
        super().__init__(parent)

    def createEditor(self, parent, option, index):
        """
        Create an editor.
        """
        flags_index = index.sibling(index.row(), 2)
        flags = flags_index.data(Qt.ItemDataRole.UserRole)

        editable = flags[0]
        widget_type = flags[1]

        if editable:
            if widget_type == "QSpinBox":
                editor = QSpinBox(parent)

                return editor

            elif widget_type == "QDoubleSpinBox":
                editor = QDoubleSpinBox(parent)

                return editor

            elif widget_type == "QLineEdit":
                editor = QLineEdit(parent)

                return editor

            else:
                print(DEBUG_NAME + f"widget_type {widget_type} not found")

        else:
            print(DEBUG_NAME + f"column {index.column()} not editable")

        return super().createEditor(parent, option, index)

    def setEditorData(self, editor, index):
        """
        Set the editor data.
        """
        if index.column() == 1:
            flags_index = index.sibling(index.row(), 2)
            flags = flags_index.data(Qt.ItemDataRole.UserRole)

            editable = flags[0]

            if editable:
                data = index.data(Qt.ItemDataRole.DisplayRole)
                editor.setValue(data)

    def setModelData(self, editor, model, index):
        """
        Set the model data.
        """
        value = editor.value()
        model.setData(index, value, Qt.ItemDataRole.EditRole)

    def updateEditorGeometry(self, editor, option, index):
        """
        Update the editor geometry.
        """
        editor.setGeometry(option.rect)
