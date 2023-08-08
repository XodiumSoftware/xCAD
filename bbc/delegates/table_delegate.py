from typing import Optional

from delegates.item_delegate import ItemDelegate, StandardItemDelegate
from handlers.db_handler import DataBaseHandler
from PySide6.QtGui import QFont, QStandardItem, QStandardItemModel
from PySide6.QtWidgets import QHeaderView, QStyleOptionViewItem, QTableView


class TableDelegate(QTableView):
    def __init__(self, module_data: Optional[dict] = None, parent=None):
        super().__init__(parent)
        """Initialize the TableDelegate."""
        self.module_data = module_data
        self.db_handler = DataBaseHandler()
        self.setup_table_delegate()

    def setup_table_delegate(self) -> None:
        """Setup the TableDelegate."""
        if self.module_data is None:
            return

        self.setSortingEnabled(self.module_data["sorting"])
        self.setAlternatingRowColors(self.module_data["alternating_row_colors"])

        font = QFont()
        font.setBold(True)

        hor_header = self.horizontalHeader()
        hor_header.setVisible(True)
        hor_header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        hor_header.setFont(font)

        ver_header = self.verticalHeader()
        ver_header.setVisible(True)
        ver_header.setSectionResizeMode(QHeaderView.ResizeMode.Fixed)
        ver_header.setFont(font)

        module_name = self.module_data["desc"]
        table_data = self.db_handler.get_table_data(module_name)

        column_names = self.module_data["columns"]

        model = QStandardItemModel(len(table_data), len(column_names))

        for col_idx, col_data in enumerate(column_names, start=1):
            model.setHorizontalHeaderItem(col_idx, QStandardItem(col_data))

        for row_idx, row_data in enumerate(table_data):
            for col_idx, value in enumerate(row_data):
                if col_idx == 1:
                    item = QStandardItem(str(value))
                else:
                    item = StandardItemDelegate(str(value))
                model.setItem(row_idx, col_idx, item)

        self.setModel(model)
        self.hideColumn(0)

        delegate = ItemDelegate(module_name)
        self.setItemDelegate(delegate)

        for row in range(model.rowCount()):
            for column in range(model.columnCount()):
                index = model.index(row, column)
                option = QStyleOptionViewItem()
                editor = delegate.createEditor(self.viewport(), option, index)
                if editor is not None:
                    delegate.setEditorData(editor, index)
                    self.setIndexWidget(index, editor)
