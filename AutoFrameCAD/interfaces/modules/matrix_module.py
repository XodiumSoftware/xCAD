from interfaces.configs.matrix_configs import MatrixTypeHints
from PySide6.QtWidgets import QWidget


class MatrixModule(QWidget):
    """A class to handle the matrices."""

    def __init__(self, configs: MatrixTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (MatrixTypeHints): A configuration.
        """
        super().__init__()

        self.matrix(configs)

    def matrix(self, configs: MatrixTypeHints) -> None:
        """Handle the matrix.

        Args:
            configs (MatrixTypeHints): A configuration.
        """
        self.setSizePolicy(*configs.size_policy)
        layout = configs.layout
        for row_idx, row in enumerate(configs.matrix):
            for col_idx, col in enumerate(row):
                for item in col:
                    layout.addWidget(
                        item.module,
                        row_idx,
                        col_idx,
                        item.row_span,
                        item.col_span,
                        item.alignment,
                    )

        self.setLayout(layout)
