from PySide6.QtWidgets import QStackedWidget, QWidget

from interfaces.configs.matrix_configs import MatrixTypeHints


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
        layout = configs.Layout
        for row_idx, row in enumerate(configs.Matrix):
            for col_idx, col in enumerate(row):
                for item in col:
                    layout.addWidget(item, row_idx, col_idx)
        self.setLayout(layout)

    @staticmethod
    def switch_modules_on_event(module: QStackedWidget) -> None:
        """Switches the current module in a QStackedWidget."""
        module.setCurrentIndex((module.currentIndex() + 1) % module.count())
