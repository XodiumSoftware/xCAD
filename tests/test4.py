from typing import Dict, Optional

from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QDoubleSpinBox,
    QGridLayout,
    QHBoxLayout,
    QLabel,
    QLayout,
    QLineEdit,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class MainWindow(QWidget):
    def __init__(self) -> None:
        super().__init__()

        self.main_layout = self._setup_module_layout("Grid")
        self.setLayout(self.main_layout)
        self._setup_module_grid_pos()

    def _setup_module_grid_pos(self) -> None:
        module_grid_pos_matrix = [
            [0, 3, 4, 1],
            [0, 4, 3, 1],
            [0, 2, None, 1],
        ]

        for row in range(len(module_grid_pos_matrix)):
            for column in range(len(module_grid_pos_matrix[row])):
                module_type = module_grid_pos_matrix[row][column]
                module = self._setup_module(module_type)
                if module is not None:
                    self.main_layout.addWidget(
                        module, row, column, 1, 1
                    )  # BUG: Says "Expected 1 positional argument"? should accept 5 as mentioned in the docs. BTW code runs fine though.

    def _setup_module_layout(self, module_layout_type: str) -> QLayout:
        module_layouts: Dict[str, QLayout] = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
        }

        return module_layouts.get(module_layout_type, QGridLayout())

    def _setup_module(self, module_type: int) -> Optional[QWidget]:
        if module_type is None:
            module = QWidget()
        elif module_type == 0:
            module = QLabel()
            module.setText("Label")
        elif module_type == 1:
            module = QCheckBox()
        elif module_type == 2:
            module = QDoubleSpinBox()
            module.setValue(0.0)
        elif module_type == 3:
            module = QPushButton()
            module.setText("Button")
        elif module_type == 4:
            module = QLineEdit()
            module.setPlaceholderText("InputField")
        else:
            module = None

        return module


app = QApplication([])
window = MainWindow()
window.show()
app.exec()
