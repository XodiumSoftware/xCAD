from PySide6.QtWidgets import QStyledItemDelegate


class ItemDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):
        if index.column() in (0, 1):
            return None
        return super().createEditor(parent, option, index)
