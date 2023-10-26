from enum import Enum
from typing import List

from PySide6.QtWidgets import QGridLayout, QGroupBox, QLayout, QWidget


class MatrixHandler(QWidget):
    """A class to handle the matrices."""

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
        matrix_data: List[List[Enum]] = matrix.value
        layout = QGridLayout()

        for row, row_modules in enumerate(matrix_data):
            for column, module_data in enumerate(row_modules):
                if isinstance(module_data, type) and issubclass(module_data, QGroupBox):
                    layout.addWidget(self.container(self.module()), row, column)
                else:
                    layout.addWidget(self.module(), row, column)

        self.setLayout(layout)

    @staticmethod
    def container(module: QWidget, layout: QLayout = QGridLayout()) -> QGroupBox:
        """Handle the container.

        Args:
            layout (QLayout, optional): A layout. Defaults to QGridLayout().

        Returns:
            QGroupBox: A container widget.
        """
        container = QGroupBox()
        container.setLayout(layout)
        layout.addWidget(module)
        return container

    @staticmethod
    def module() -> QWidget:
        """Handle the module.

        Returns:
            QWidget: A module widget.
        """
        return QWidget()
