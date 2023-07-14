from functools import partial
from typing import Dict, Optional, Tuple

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

from bbc.constants import DEBUG_NAME


class ModuleHandler:
    @staticmethod
    def init_module(
        module_grid_pos_matrix: list[
            list[
                Optional[Tuple[Optional[int], Optional[str], Optional[Tuple[int, int]]]]
            ]
        ],
        layout: QLayout,
        margins: Optional[Tuple[int, int, int, int]] = None,
    ) -> None:
        for row, row_info in enumerate(module_grid_pos_matrix):
            for column, module_info in enumerate(row_info):
                if module_info is not None:
                    module_type, alignment, span = module_info
                    module = ModuleHandler.init_module_type(module_type)
                    if module is not None:
                        alignment_flag = ModuleHandler.init_module_alignment(alignment)
                        rowspan, columnspan = ModuleHandler.init_module_span(*span)
                        layout.addWidget(
                            module,
                            row,
                            column,
                            rowspan,
                            columnspan,
                            alignment=alignment_flag,
                        )

        if margins is not None:
            layout.setContentsMargins(*margins)

    @staticmethod
    def init_module_margins(
        margins: Optional[Tuple[int, int, int, int]]
    ) -> Tuple[int, int, int, int]:
        if margins is None:
            return 0, 0, 0, 0
        else:
            return margins

    @staticmethod
    def init_module_span(rowspan, columnspan) -> Tuple[int, int]:
        if rowspan == "Auto" or columnspan == "Auto":
            return 1, 1

        return rowspan, columnspan

    @staticmethod
    def init_module_layout(module_layout_type: str) -> QLayout:
        module_layouts: Dict[str, QLayout] = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
            "Form": QFormLayout(),
        }

        return module_layouts.get(module_layout_type, QGridLayout())

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
    def init_module_type(module_type: str, module_data: dict) -> Optional[QWidget]:
        """
        Create the module.
        """
        module_class = {
            "Label": QLabel,
            "Checkbox": QCheckBox,
            "SpinBox": QDoubleSpinBox,
            "InputField": QLineEdit,
            "Button": QPushButton,
            "GraphicsView": QGraphicsView,
            "TableView": QTableView,
        }.get(module_type)

        if not module_class:
            raise ValueError(f'{DEBUG_NAME}"{module_type}" is not a valid module type')

        module = module_class()

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

            if module_data["size"] != None:
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
