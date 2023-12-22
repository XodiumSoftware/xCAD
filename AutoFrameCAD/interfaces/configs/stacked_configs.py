from dataclasses import dataclass

from interfaces.configs.matrix_configs import (
    MainUIMenuConfig,
    MainUIStartUpMatrixConfig,
)
from interfaces.modules.matrix_module import MatrixModule
from PySide6.QtWidgets import QWidget


@dataclass
class StackedTypeHints:
    """A class used to represent stacked widget type hints."""

    module_stack: tuple[QWidget, ...]


class MainUIStackModule(StackedTypeHints):
    """A class to represent the main UI stacked module."""

    def __init__(self):
        super().__init__(
            module_stack=(
                MatrixModule(MainUIStartUpMatrixConfig()),
                MatrixModule(MainUIMenuConfig()),
            ),
        )
