from typing import Type

from PySide6.QtWidgets import QGridLayout

from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.modules.label_module import LabelModule


class MatrixTypeHints:
    """A class used to represent matrix type hints."""

    Layout: QGridLayout
    Matrix: tuple[list[list[Type]]]


class MainUIMatrixConfig(MatrixTypeHints):
    """A class used to represent a matrix config."""

    Layout = QGridLayout()
    Matrix = (
        [
            [
                LabelModule(CopyrightLabelConfig()),
            ],
        ],
    )
