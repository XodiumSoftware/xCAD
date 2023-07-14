from functools import partial
from typing import Dict, List, Optional, Tuple, Union

from constants import (
    BUTTONS,
    CHECKBOXES,
    DEBUG_NAME,
    GRAPHICS_VIEWS,
    INPUTFIELDS,
    LABELS,
    SPINBOXES,
    TABLES,
)
from delegates.graphics_delegate import GraphicsDelegate
from delegates.table_delegate import TableDelegate
from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QFormLayout,
    QGraphicsView,
    QGridLayout,
    QHBoxLayout,
    QLabel,
    QLayout,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QTableView,
    QVBoxLayout,
    QWidget,
)


class ModuleHandler:
    @staticmethod
    def init_module(
        module_grid_pos_matrix: List[
            List[
                Optional[Tuple[Optional[int], Optional[str], Optional[Tuple[int, int]]]]
            ]
        ],
        layout: QGridLayout,
        margins: Optional[Tuple[int, int, int, int]] = None,
    ) -> None:
        for row, row_info in enumerate(module_grid_pos_matrix):
            for column, module_info in enumerate(row_info):
                if module_info is not None:
                    (
                        module_type,
                        module_index,
                        module_layout_type,
                        module_span,
                        module_alignment,
                        module_layout_margins,
                    ) = module_info
                    module_data = ModuleHandler.init_module_data(
                        module_type, module_index
                    )
                    if module_data is not None:
                        module = ModuleHandler.init_module_type(module_type)
                        module = ModuleHandler.init_module_properties(
                            module, module_type, module_data
                        )
                        row_span, col_span = ModuleHandler.init_module_span(
                            module_grid_pos_matrix, module_span[0], module_span[1]
                        )
                        layout.addWidget(module, row, column, row_span, col_span)

        layout.setContentsMargins(*ModuleHandler.init_module_margins(margins))

    @staticmethod
    def init_module_margins(
        margins: Optional[Tuple[int, int, int, int]]
    ) -> Tuple[int, int, int, int]:
        if margins is None:
            return 0, 0, 0, 0
        else:
            return margins

    @staticmethod
    def init_module_span(
        module_grid_pos_matrix: List[
            List[
                Optional[Tuple[Optional[int], Optional[str], Optional[Tuple[int, int]]]]
            ]
        ],
        rowspan: Union[int, str],
        columnspan: Union[int, str],
    ) -> Tuple[int, int]:
        if rowspan == "Auto" or columnspan == "Auto":
            total_rows = len(module_grid_pos_matrix)
            total_columns = len(module_grid_pos_matrix[0])
            if rowspan == "Auto":
                rowspan = total_rows
            if columnspan == "Auto":
                columnspan = total_columns

        return int(rowspan), int(columnspan)

    @staticmethod
    def init_module_layout(module_layout_type: str) -> QLayout:
        layouts: Dict[str, QLayout] = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
            "Form": QFormLayout(),
        }

        return layouts.get(module_layout_type, QGridLayout())

    @staticmethod
    def init_module_alignment(module_alignment: Optional[str]) -> Qt.AlignmentFlag:
        alignments: Dict[str, Qt.AlignmentFlag] = {
            "Leading": Qt.AlignmentFlag.AlignLeading,
            "Left": Qt.AlignmentFlag.AlignLeft,
            "Right": Qt.AlignmentFlag.AlignRight,
            "Trailing": Qt.AlignmentFlag.AlignTrailing,
            "HCenter": Qt.AlignmentFlag.AlignHCenter,
            "Justify": Qt.AlignmentFlag.AlignJustify,
            "Absolute": Qt.AlignmentFlag.AlignAbsolute,
            "Horizontal_Mask": Qt.AlignmentFlag.AlignHorizontal_Mask,
            "Top": Qt.AlignmentFlag.AlignTop,
            "Bottom": Qt.AlignmentFlag.AlignBottom,
            "Center": Qt.AlignmentFlag.AlignCenter,
            "Baseline": Qt.AlignmentFlag.AlignBaseline,
            "Vertical_Mask": Qt.AlignmentFlag.AlignVertical_Mask,
        }

        return alignments.get(module_alignment, Qt.AlignmentFlag.AlignJustify)

    @staticmethod
    def init_module_data(
        module_type: str, module_index: int
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
            "GraphicsView": GRAPHICS_VIEWS,
            "TableView": TABLES,
        }.get(module_type, [])

        module_data = next(
            (module for module in module_list if module["index"] == module_index), None
        )

        return module_data

    @staticmethod
    def init_module_type(module_type: str) -> Optional[QWidget]:
        """
        Create the module.
        """
        module_types = {
            "Label": QLabel,
            "Checkbox": QCheckBox,
            "SpinBox": QDoubleSpinBox,
            "InputField": QLineEdit,
            "Button": QPushButton,
            "GraphicsView": QGraphicsView,
            "TableView": QTableView,
        }

        return module_types.get(module_type, QWidget)

    @staticmethod
    def init_module_properties(
        module: QWidget, module_type: str, module_data: dict
    ) -> QWidget:
        if module_type != "GraphicsView":
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

            if module_data["size"] is not None:
                module.setFixedSize(*module_data["size"])
            else:
                module.setSizePolicy(
                    QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum
                )

            module.clicked.connect(
                partial(self.onButtonModuleClicked.emit, module_data["index"])
            )

        elif module_type == "GraphicsView":
            module = GraphicsDelegate(module_data)

        elif module_type == "TableView":
            module = TableDelegate(module_data)

        else:
            raise ValueError(f'{DEBUG_NAME}"{module_type}" is not a valid module type')

        return module
