from dataclasses import dataclass
from typing import Type

from PySide6.QtWidgets import QGridLayout

from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.modules.label_module import LabelModule


@dataclass
class MatrixTypeHints:
    """A class used to represent matrix type hints."""

    layout: QGridLayout
    matrix: tuple[list[list[Type]]]


class MainUIMatrixConfig(MatrixTypeHints):
    """A class used to represent a matrix config."""

    def __init__(self):
        super().__init__(
            layout=QGridLayout(),
            matrix=(
                [
                    [LabelModule(CopyrightLabelConfig())],
                ],
            ),
        )
