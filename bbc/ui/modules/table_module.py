from constants import DATABASE_PATH, DEBUG_NAME, TABLES
from delegates.cell_delegate import CellDelegate
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtSql import QSqlDatabase, QSqlQuery, QSqlTableModel
from PySide6.QtWidgets import QHeaderView, QTableView, QVBoxLayout, QWidget


class TableModule(QWidget):
    def __init__(self, module_index, margins=None, alignment=None, parent=None):
        """
        Initialize the TableModule.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(module_index, margins, alignment)

        # self.visibility_handler.load_visibility_state(self, module_index)

    def setup_module(self, module_index, margins, alignment):
        """
        Setup the TableModule.
        """
        layout = QVBoxLayout(self)

        module_data = next(
            (module for module in TABLES if module["index"] == module_index), None
        )

        if module_index:
            module = self.create_module(module_data)
            layout.addWidget(module)
        else:
            print(DEBUG_NAME + f'"index" {module_index} not found in TABLES')

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(alignment)

        self.setLayout(layout)

    def create_module(self, module_data):
        """
        Create a table module.
        """
        module = QTableView()
        module.setStyleSheet(module_data["stylesheet"])
        module.setSortingEnabled(module_data["sorting"])
        module.setAlternatingRowColors(module_data["alternating_row_colors"])

        font = module.font()
        font.setBold(True)

        hor_header = module.horizontalHeader()
        hor_header.setVisible(True)
        hor_header.setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        hor_header.setFont(font)

        ver_header = module.verticalHeader()
        ver_header.setVisible(True)
        ver_header.setSectionResizeMode(QHeaderView.ResizeMode.Fixed)
        ver_header.setFont(font)

        module_name = module_data["desc"]
        model = QSqlTableModel()

        db = QSqlDatabase.addDatabase("QSQLITE")
        db.setDatabaseName(DATABASE_PATH)
        if db.open():
            query = QSqlQuery(db)
            query.exec(f"SELECT * FROM {module_name}")
            model.setQuery(query)
            model.setEditStrategy(QSqlTableModel.EditStrategy.OnManualSubmit)
            db.close()
        else:
            print(DEBUG_NAME + f"failed to open {DATABASE_PATH}")

        module.setModel(model)

        delegate = CellDelegate()
        module.setItemDelegateForColumn(1, delegate)

        column_count = model.columnCount()
        for column in range(0, column_count, 2):
            module.hideColumn(column)

        return module

    def toggle_module(self, module_index):
        """
        Toggle the visibility of the label.
        """
        self.visibility_handler.toggle_visibility_state(self, module_index)
