import sys

from PySide6.QtCore import Qt, Signal
from PySide6.QtGui import QStandardItem
from PySide6.QtWidgets import QDoubleSpinBox, QLabel, QPushButton, QStyledItemDelegate


class StandardItemDelegate(QStandardItem):
    def data(self, role=Qt.ItemDataRole.DisplayRole):
        """
        Return the data for the given role.
        """
        if role == Qt.ItemDataRole.DisplayRole:
            return ""

        return super().data(role)


class ItemDelegate(QStyledItemDelegate):
    on_button_clicked = Signal(int)

    def __init__(self, parent=None):
        """
        Initialize the ItemDelegate.
        """
        super().__init__(parent)

    def createEditor(self, parent, option, index):
        """
        Create an editor widget for the given index.
        """
        if index.column() in (0, 1):
            return None

        if index.column() == 2:
            if index.row() == 0:
                editor = QPushButton(parent)
                saved_data = index.data(Qt.ItemDataRole.EditRole)
                if saved_data is not None:
                    editor.setText("Select")
                    editor.setStyleSheet("font-style: italic;")
                    # editor.clicked.connect(self.on_button_clicked)
                return editor

            elif index.row() in (1, 2):
                editor = QDoubleSpinBox(parent)
                max_double_value = sys.float_info.max
                editor.setRange(0, max_double_value)
                editor.setDecimals(0)
                editor.setSuffix(" mm")
                return editor

            elif index.row() in (3, 4):
                editor = QLabel(parent)
                decimals = 0
                value = index.model().data(index, role=Qt.ItemDataRole.EditRole)
                if index.row() == 3:
                    suffix = " m2"
                    text = "{:.{}f}{}".format(float(value), decimals, suffix)
                    editor.setText(text)
                    return editor

                elif index.row() == 4:
                    suffix = " m1"
                    text = "{:.{}f}{}".format(float(value), decimals, suffix)
                    editor.setText(text)
                    return editor

        return super().createEditor(parent, option, index)

    def setEditorData(self, editor, index):
        """
        Set the data to be displayed and edited by the editor from the data model.
        """
        if isinstance(editor, QDoubleSpinBox):
            value = index.model().data(index, role=Qt.ItemDataRole.EditRole)
            editor.setValue(float(value))

        else:
            super().setEditorData(editor, index)

    def setModelData(self, editor, model, index):
        """
        Set the data to be displayed and edited by the editor from the data model.
        """
        if isinstance(editor, QDoubleSpinBox):
            value = editor.value()
            model.setData(index, value, role=Qt.ItemDataRole.EditRole)

        else:
            super().setModelData(editor, model, index)
