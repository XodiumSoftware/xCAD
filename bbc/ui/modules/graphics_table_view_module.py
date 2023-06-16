from handlers.db_handler import DataBaseHandler
from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QDoubleSpinBox,
    QHeaderView,
    QLineEdit,
    QTableWidget,
    QTableWidgetItem,
)


class GraphicsTableViewModule(QTableWidget):
    def __init__(self, graphics_view, parent=None):
        """
        Initialize the table view module.
        """
        super().__init__(parent)
        self.graphics_view = graphics_view
        self.setup_table_view()

    def setup_table_view(self):
        """
        Setup the table view.
        """
        header_labels = ["Parameters", "Value"]
        self.setColumnCount(len(header_labels))
        self.setHorizontalHeaderLabels(header_labels)
        self.setEditTriggers(QTableWidget.AllEditTriggers)

        self.populate_table()
        self.set_column_properties()

    def populate_table(self):
        """
        Populate the table with the data from the database.
        """
        data_handler = DataBaseHandler()
        db_data = data_handler.get_db_data()

        self.setRowCount(len(db_data))
        for row, (parameter, value) in enumerate(db_data.items()):
            parameter_item = QTableWidgetItem(parameter)
            parameter_item.setFlags(parameter_item.flags() & ~Qt.ItemIsEditable)

            value_item = QTableWidgetItem(str(value))
            value_item.setFlags(value_item.flags() | Qt.ItemIsEditable)

            self.setItem(row, 0, parameter_item)
            self.setItem(row, 1, value_item)

    def set_column_properties(self):
        """
        Set the column properties.
        """
        self.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.verticalHeader().setVisible(True)

        for row in range(self.rowCount()):
            thickness_item = self.item(row, 1)
            if thickness_item is not None:
                thickness_text = thickness_item.text()
                try:
                    thickness_value = float(thickness_text)
                    if thickness_value.is_integer():
                        spin_box = QDoubleSpinBox()
                        spin_box.setRange(0, 999)
                        spin_box.setSingleStep(1)
                        spin_box.setValue(thickness_value)
                        self.setCellWidget(row, 1, spin_box)
                    else:
                        line_edit = QLineEdit()
                        line_edit.setText(thickness_text)
                        self.setCellWidget(row, 1, line_edit)
                except ValueError:
                    line_edit = QLineEdit()
                    line_edit.setText(thickness_text)
                    self.setCellWidget(row, 1, line_edit)
