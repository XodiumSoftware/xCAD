from enum import Enum
from typing import Type

from PySide6.QtWidgets import QGridLayout, QWidget

from configs.module_configs import (
    Checkboxes,
    DoubleSpinBoxes,
    Labels,
    LineEdits,
    PushButtons,
)
from modules.check_box_module import CheckBoxModule
from modules.double_spin_box_module import DoubleSpinBoxModule
from modules.label_module import LabelModule
from modules.line_edit_module import LineEditModule
from modules.push_button_module import PushButtonModule
from utils.module_utils import ModuleUtils


class ModuleHandler(ModuleUtils):
    """A class to handle the modules."""

    def __init__(self, matrix: Enum) -> None:
        """Initialize the class.

        Args:
            matrix (Enum): A matrix.
        """
        super().__init__()

        self.matrix(matrix)

    def matrix(self, matrix: Enum) -> None:
        """Handle the matrix.

        Args:
            matrix (Enum): A matrix.
        """
        matrix_data = matrix.value
        layout = QGridLayout()
        for row, row_modules in enumerate(matrix_data):
            for column, module_data in enumerate(row_modules):
                layout.addWidget(self.module_data(module_data), row, column)
        self.setLayout(layout)

    @staticmethod
    def module_data(module: list[Type]) -> QWidget:
        """Handle the module data.

        Args:
            module (Type): A module.
        """
        return {
            Checkboxes: CheckBoxModule,
            DoubleSpinBoxes: DoubleSpinBoxModule,
            Labels: LabelModule,
            LineEdits: LineEditModule,
            PushButtons: PushButtonModule,
        }.get(module, QWidget)()
