from enum import Enum
from typing import Dict, Optional, Type

from PySide6.QtWidgets import QWidget

from utils.module_utils import ModuleUtils


class ModuleHandler(ModuleUtils):
    """A class to handle the modules."""

    def __init__(self, matrix: Enum) -> None:
        """
        Initialize the class.

        Attributes:
            module_mapping (Dict[str, QWidget]):
                A dictionary of module name and module.
            module_visibility (Dict[str, bool]):
                A dictionary of module name and visibility.
        """
        super().__init__()
        self.module_matrix: Dict[str, QWidget] = {}
        self.module_mapping: Dict[str, QWidget] = {}
        self.module_visibility: Dict[str, bool] = {}

        self.handle_matrix(matrix)

    def handle_matrix(self, matrix: Enum) -> None:
        """
        Handle the matrix.

        Args:
            matrix (Enum): A matrix.
        """
        for row in matrix.value:
            for column in row:
                for module in column:
                    if isinstance(module, Enum):
                        self.module_matrix[module.name] = module.value
                    else:
                        self.module_matrix[module.__name__] = module

    def create_module(self) -> None:
        """Handle the module."""
        for module_name, module in self.module_matrix.items():
            self.module_mapping[module_name] = self.add_module(module)

    def handle_module_data(self, module: Type[Enum]) -> Optional[QWidget]:
        """Handle the module data."""
        return {}.get(Type(module))
