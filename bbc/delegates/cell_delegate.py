from constants import DEBUG_NAME
from PySide6.QtCore import Qt
from PySide6.QtWidgets import QDoubleSpinBox, QLineEdit, QSpinBox, QStyledItemDelegate


class CellDelegate(QStyledItemDelegate):
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
                if isinstance(editor, (QSpinBox, QDoubleSpinBox)):
                    editor.setValue(data)

                elif isinstance(editor, QLineEdit):
                    editor.setText(data)

    def setModelData(self, editor, model, index):
        """
        Set the model data.
        """
        if isinstance(editor, (QSpinBox, QDoubleSpinBox)):
            value = editor.value()
            model.setData(index, value, Qt.ItemDataRole.EditRole)

        elif isinstance(editor, QLineEdit):
            value = editor.text()
            model.setData(index, value, Qt.ItemDataRole.EditRole)
