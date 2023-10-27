from PySide6.QtWidgets import QGridLayout, QWidget


class MatrixHandler(QWidget):
    """A class to handle the matrices."""

    def __init__(self, matrix) -> None:
        """Initialize the class.

        Args:
            matrix (Enum): A matrix.
        """
        super().__init__()

        self.matrix(matrix)

    def matrix(self, matrix) -> None:
        """Handle the matrix.

        Args:
            matrix (Enum): A matrix.
        """
        layout = QGridLayout()

        self.setLayout(layout)
