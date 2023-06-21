# from constants import DEBUG_NAME, TABLES
# from PySide6.QtCore import QAbstractTableModel, QEvent, Qt
# from PySide6.QtGui import QFont, QMouseEvent
# from PySide6.QtWidgets import (
#     QCheckBox,
#     QComboBox,
#     QDoubleSpinBox,
#     QHeaderView,
#     QLabel,
#     QLineEdit,
#     QPushButton,
#     QStyledItemDelegate,
#     QTableView,
#     QVBoxLayout,
#     QWidget,
# )


# class CellDelegate(QStyledItemDelegate):
#     def createEditor(self, parent, option, index):
#         """
#         Create an editor for the given index.
#         """
#         table_data = TableModule.get_table_data(index.data(index))
#         if table_data is not None:
#             flag_data = table_data.iloc[index.row(), index.column() + 1]

#             if isinstance(flag_data, list) and len(flag_data) >= 2:
#                 cell_type = flag_data[1]
#                 editor = None

#                 if cell_type == QLabel:
#                     editor = QLabel(parent)

#                 elif cell_type == QPushButton:
#                     editor = QPushButton(parent)

#                 elif cell_type == QLineEdit:
#                     editor = QLineEdit(parent)

#                 elif cell_type == QDoubleSpinBox:
#                     editor = QDoubleSpinBox(parent)
#                     editor.setDecimals(0)
#                     editor.setSingleStep(1)
#                     editor.setRange(0, 999)

#                 elif cell_type == QComboBox:
#                     editor = QComboBox(parent)

#                 elif cell_type == QCheckBox:
#                     editor = QCheckBox(parent)

#                 else:
#                     print(DEBUG_NAME + f'"{cell_type}" not found in CellDelegate')

#                 if editor is not None:
#                     if flag_data[0]:
#                         if hasattr(editor, "setReadOnly"):
#                             editor.setReadOnly(True)
#                         else:
#                             print(
#                                 DEBUG_NAME
#                                 + f'"{cell_type}" does not support setReadOnly'
#                             )

#                     return editor

#                 else:
#                     print(DEBUG_NAME + f'"{cell_type}" is None')

#             else:
#                 print(DEBUG_NAME + f'"{flag_data}" is not a list or is too short')

#         else:
#             print(DEBUG_NAME + f'"table_data" is None')

#         return super().createEditor(parent, option, index)

#     def editorEvent(self, event, model, option, index):
#         """
#         Handle events that occur in the editor.
#         """
#         if isinstance(event, QMouseEvent):
#             if event.type() == QEvent.Type.MouseButtonRelease:
#                 print(
#                     "Mouse click in cell:", index.row(), index.column()
#                 )  # TODO: Remove after debugging

#         return super().editorEvent(event, model, option, index)


# class PandasModel(QAbstractTableModel):
#     def __init__(self, data, column_names):
#         """
#         Initialize the PandasModel.
#         """
#         QAbstractTableModel.__init__(self)
#         self._data = data
#         self._column_names = column_names

#     def rowCount(self, parent=None):
#         """
#         Return the number of rows in the table.
#         """
#         return self._data.shape[0]

#     def columnCount(self, parent=None):
#         """
#         Return the number of columns in the table.
#         """
#         return (self._data.shape[1] + 1) // 2

#     def data(self, index, role=Qt.ItemDataRole.DisplayRole):
#         """
#         Return the data at the given index.
#         """
#         if index.isValid():
#             column_index = index.column() * 2
#             flag_index = column_index + 1

#             if role == Qt.ItemDataRole.DisplayRole:
#                 return str(self._data.iloc[index.row(), column_index])

#             if role == Qt.ItemDataRole.EditRole and flag_index in TABLES:
#                 print(
#                     "Delegate called for cell:", index.row(), index.column()
#                 )  # TODO: Remove after debugging.
#                 return self._data.iloc[index.row(), flag_index]

#         return None

#     def headerData(self, section, orientation, role=Qt.ItemDataRole.DisplayRole):
#         """
#         Return the header data at the given section.
#         """
#         if role == Qt.ItemDataRole.DisplayRole:
#             if orientation == Qt.Orientation.Horizontal:
#                 column_index = section * 2
#                 return self._column_names[column_index]

#         if (
#             role == Qt.ItemDataRole.FontRole
#             and orientation == Qt.Orientation.Horizontal
#         ):
#             font = QFont()
#             font.setBold(True)
#             return font

#         return super().headerData(section, orientation, role)


# class TableModule(QWidget):
#     def __init__(self, table_index, margins=None, parent=None):
#         """
#         Initialize the table module.
#         """
#         super().__init__(parent)
#         self.margins = margins
#         self.setup_table_module(table_index)

#     def setup_table_module(self, table_index):
#         """
#         Setup the tableModule.
#         """
#         layout = QVBoxLayout(self)

#         table_data, column_names = self.get_table_data(table_index)

#         if table_data is not None:
#             table = self.create_table_module(table_data, column_names)
#             layout.addWidget(table)
#         else:
#             print(DEBUG_NAME + f'"table_index" {table_index} not found in TABLES')

#         if self.margins is not None:
#             layout.setContentsMargins(*self.margins)

#         self.setLayout(layout)

#     def get_table_data(self, table_index):
#         """
#         Get the table data from the TABLES constant.
#         """
#         for table in TABLES:
#             if table.get("table_index") == table_index:
#                 table_data = table.get("table_data")
#                 column_names = table_data.columns.tolist()
#                 return table_data, column_names
#         return None, None

#     def create_table_module(self, table_data, column_names):
#         """
#         Create a table module.
#         """
#         table_view = QTableView()
#         model = PandasModel(table_data, column_names)
#         table_view.setModel(model)
#         table_view.setSortingEnabled(True)

#         header = table_view.horizontalHeader()
#         header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)

#         delegate = CellDelegate()
#         for i in range(len(column_names)):
#             if i % 2 == 1:
#                 table_view.setItemDelegateForColumn(i, delegate)

#         return table_view
