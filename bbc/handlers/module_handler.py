from functools import partial
from typing import Dict, Optional, Tuple, Union

from constants import (
    BUTTONS,
    CHECKBOXES,
    DATABASE_PATH,
    DEBUG_NAME,
    GRAPHIC_VIEWS,
    INPUTFIELDS,
    LABELS,
    SPINBOXES,
    TABLES,
)
from delegates.graphics_delegate import GraphicsDelegate
from PySide6.QtCore import Qt, Signal
from PySide6.QtGui import QIcon, QStandardItem, QStandardItemModel
from PySide6.QtWidgets import (
    QBoxLayout,
    QCheckBox,
    QDoubleSpinBox,
    QGraphicsView,
    QHeaderView,
    QLabel,
    QLayout,
    QLineEdit,
    QPushButton,
    QTableView,
    QVBoxLayout,
    QWidget,
)

from .db_handler import DataBaseHandler
from .visibility_handler import VisibilityHandler


class ModuleHandler(QWidget):
    on_button_clicked = Signal(int)

    def __init__(
        self,
        module_type: str,
        module_index: int,
        margins: Optional[Tuple[int, int, int, int]] = None,
        alignment: Optional[str] = None,
        parent: Optional[QWidget] = None,
    ) -> None:
        """
        Initialize the ModuleHandler.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()
        self.db_handler = DataBaseHandler()
        self.setup_module(module_type, module_index, margins, alignment)

    def setup_module(
        self,
        module_type: str,
        module_index: int,
        margins: Optional[Tuple[int, int, int, int]] = None,
        alignment: Optional[str] = None,
    ) -> None:
        """
        Setup the module.
        """
        layout = QVBoxLayout(self)
        module_data = self.get_module_data(module_type, module_index)

        if module_data:
            module = self.create_module(module_type, module_data)
            if module:
                layout.addWidget(module)
            else:
                raise ValueError(
                    f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                )
        else:
            raise ValueError(f'{DEBUG_NAME}"index" {module_index} not found')

        layout.setContentsMargins(*(margins or (0, 0, 0, 0)))

        if alignment:
            self.setAlignment(layout, alignment)

        self.setLayout(layout)

    def get_module_data(
        self, module_type: str, module_index: int
    ) -> Optional[Dict[str, Union[str, int, float]]]:
        """
        Get the module data.
        """
        module_list = {
            "Label": LABELS,
            "Checkbox": CHECKBOXES,
            "SpinBox": SPINBOXES,
            "InputField": INPUTFIELDS,
            "Button": BUTTONS,
            "GraphicView": GRAPHIC_VIEWS,
            "TableView": TABLES,
        }.get(module_type, [])

        module_data = next(
            (module for module in module_list if module["index"] == module_index), None
        )

        return module_data

    def create_module(self, module_type: str, module_data: dict) -> Optional[QWidget]:
        """
        Create the module.
        """
        module_class = {
            "Label": QLabel,
            "Checkbox": QCheckBox,
            "SpinBox": QDoubleSpinBox,
            "InputField": QLineEdit,
            "Button": QPushButton,
            "GraphicView": QGraphicsView,
            "TableView": QTableView,
        }.get(module_type)

        if not module_class:
            raise ValueError(f'{DEBUG_NAME}"{module_type}" is not a valid module type')

        module = module_class()

        if module_type != "GraphicView":
            module.setStyleSheet(module_data["stylesheet"])

        if module_type == "Label":
            module.setText(module_data["title"])

        elif module_type == "Checkbox":
            module.setText(module_data["title"])

        elif module_type == "SpinBox":
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setSuffix(module_data["suffix"])

        elif module_type == "InputField":
            module.setPlaceholderText(module_data["placeholder"])

        elif module_type == "Button":
            if module_data["icon_path"]:
                icon = QIcon(module_data["icon_path"])
                module.setIcon(icon)

            else:
                module.setText(module_data["title"])

            module.setStyleSheet(module_data["stylesheet"])
            module.clicked.connect(
                partial(self.on_button_clicked.emit, module_data["index"])
            )

        elif module_type == "GraphicView":
            delegate = GraphicsDelegate(module_data)
            module = delegate

        elif module_type == "TableView":
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
            table_data = self.db_handler.get_table_data(module_name)

            model = QStandardItemModel(len(table_data), len(table_data[0]))

            for row_idx, row_data in enumerate(table_data):
                for col_idx, value in enumerate(row_data):
                    model.setItem(row_idx, col_idx, QStandardItem(str(value)))

            module.setModel(model)

            column_count = model.columnCount()
            for column in range(0, column_count, 2):
                module.hideColumn(column)

        else:
            raise ValueError(f'{DEBUG_NAME}"{module_type}" is not a valid module type')

        return module

    def setAlignment(self, layout: Union[QLayout, QBoxLayout], alignment: str) -> None:
        """
        Set the alignment of the layout.
        """
        alignment_mapping = {
            "Left": Qt.AlignmentFlag.AlignLeft,
            "Right": Qt.AlignmentFlag.AlignRight,
            "Center": Qt.AlignmentFlag.AlignCenter,
            "Justify": Qt.AlignmentFlag.AlignJustify,
            "Top": Qt.AlignmentFlag.AlignTop,
            "Bottom": Qt.AlignmentFlag.AlignBottom,
        }

        layout.setAlignment(
            alignment_mapping.get(alignment, Qt.AlignmentFlag.AlignLeft)
        )

    def toggle_module(self, module_type: str, module_index: int) -> None:
        """
        Toggle the module.
        """
        self.visibility_handler.toggle_visibility_state(self, module_type, module_index)
