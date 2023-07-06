import re
import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QDoubleSpinBox, QPushButton, QStyledItemDelegate


class ItemDelegate(QStyledItemDelegate):
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

        elif index.column() == 2 and index.row() == 0:
            editor = QPushButton(parent)
            saved_data = index.data(Qt.ItemDataRole.EditRole)
            if saved_data is not None:
                editor.setText(saved_data)
            return editor

        elif index.column() == 2 and index.row() in (1, 2):
            editor = QDoubleSpinBox(parent)
            max_double_value = sys.float_info.max
            editor.setRange(0, max_double_value)
            editor.setDecimals(0)
            editor.setSuffix(" mm")
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
