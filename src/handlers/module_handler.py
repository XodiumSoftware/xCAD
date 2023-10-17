from enum import Enum
from typing import Dict, Type

from PySide6.QtWidgets import QWidget

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

        Attributes:
            module_mapping (Dict[str, QWidget]):
                A dictionary of module name and module.
            module_visibility (Dict[str, bool]):
                A dictionary of module name and visibility.
        """
        super().__init__()
        self.module_matrix: Dict[str, QWidget] = {}
        self.module_visibility: Dict[str, bool] = {}

        self.matrix(matrix)

    def matrix(self, matrix: Enum) -> None:
        """Handle the matrix.

        Args:
            matrix (Enum): A matrix.
        """
        for row in matrix.value:
            for column in row:
                for module in column:
                    if isinstance(module, Enum):
                        self.module_matrix[module.name] = module.value
                    else:
                        self.module_matrix[module] = module

    def module(self) -> None:
        """Handle the module."""
        pass

    @staticmethod
    def module_data(module: Type) -> Type[QWidget]:
        """Handle the module data.

        Args:
            module (Type): A module.

        Returns:
            Type[QWidget]: A module data.
        """
        return {
            Checkboxes: CheckBoxModule,
            DoubleSpinBoxes: DoubleSpinBoxModule,
            Labels: LabelModule,
            LineEdits: LineEditModule,
            PushButtons: PushButtonModule,
        }.get(module, QWidget)
