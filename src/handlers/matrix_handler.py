from typing import List, Type

from PySide6.QtWidgets import QGridLayout, QStackedWidget, QWidget

from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.modules.label_module import LabelModule

# TODO: this file


class MainUIMatrixConfig:
    """A class used to represent the main UI matrix config"""

    Matrix = [
        [
            [
                LabelModule(CopyrightLabelConfig()),
            ],
        ],
    ]


class MatrixHandler(QWidget):
    """A class to handle the matrices."""

    def __init__(self, matrix: List[List[List[Type]]]) -> None:
        """Initialize the class.

        Args:
            matrix (type): A matrix.
        """
        super().__init__()

        self.matrix(matrix)

    def matrix(self, matrix: List[List[List[Type]]]) -> None:
        """Handle the matrix.

        Args:
            matrix (type): A matrix.
        """
        layout = QGridLayout()
        for row_idx, row in enumerate(matrix):
            for col_idx, col in enumerate(row):
                for item in col:
                    layout.addWidget(item, row_idx, col_idx)
        self.setLayout(layout)

    @staticmethod
    def switch_modules_on_event(module: QStackedWidget) -> None:
        """Switches the current module in a QStackedWidget."""
        module.setCurrentIndex((module.currentIndex() + 1) % module.count())
