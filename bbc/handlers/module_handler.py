from functools import partial
from typing import Dict, Optional, Tuple, Union, cast

from constants import (
    BUTTONS,
    CHECKBOXES,
    DEBUG_NAME,
    GRAPHICS_VIEWS,
    INPUTFIELDS,
    LABELS,
    MODULE_MATRICES,
    SPINBOXES,
    TABLES,
)
from delegates.graphics_delegate import GraphicsDelegate
from delegates.table_delegate import TableDelegate
from PySide6.QtCore import QSettings, Qt, QTimer, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QFormLayout,
    QGridLayout,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
    QWidget,
)


class ModuleHandler(QWidget):
    onButtonModuleClicked = Signal(int)

    def __init__(
        self,
        matrix_index: int,
        parent: Optional[QWidget] = None,
    ) -> None:
        """
        Initialize the ModuleHandler.
        """
        super().__init__(parent)

        self._settings = QSettings()

        self._matrix_index = matrix_index

        self._module_visibility_state = {}

        QTimer.singleShot(0, self.load_module_visibility_state)

        self.create_modules_from_matrix()

    def create_modules_from_matrix(self) -> None:
        """
        Create modules based on the module matrix position corresponding to the matrix_index.
        """
        module_matrix_data = next(
            (data for data in MODULE_MATRICES if data["index"] == self._matrix_index),
            None,
        )

        if module_matrix_data:
            module_matrix_pos = module_matrix_data.get("module_matrix_pos", [])
            for row in module_matrix_pos:
                for module_args in row:
                    (
                        module_layout_type,
                        module_type,
                        module_index,
                        module_margins,
                        module_alignment,
                    ) = module_args
                    self.setup_module(
                        module_layout_type,
                        module_type,
                        module_index,
                        module_margins,
                        module_alignment,
                    )
        else:
            raise ValueError(
                f"{DEBUG_NAME}Module index {self._matrix_index} not found in MODULE_MATRICES"
            )

    def setup_module(
        self,
        module_layout_type: str,
        module_type: str,
        module_index: int,
        module_margins: Optional[Tuple[int, int, int, int]] = None,
        module_alignment: Optional[str] = None,
    ) -> None:
        """
        Setup the module.
        """
        layout = self.setup_module_layout(module_layout_type)
        layout.setContentsMargins(*self.setup_module_margins(module_margins))

        if module_alignment is not None:
            layout.setAlignment(
                cast(Qt.AlignmentFlag, self.setup_module_alignment(module_alignment))
            )
        module_data = self.setup_module_data(module_type, module_index)

        if module_data:
            module = self.setup_module_creation(module_type, module_data)
            if module:
                layout.addWidget(module)
            else:
                raise ValueError(
                    f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                )
        else:
            raise ValueError(f"{DEBUG_NAME}{module_type}_{module_index}: not found")

        self.setLayout(layout)

        module_key = f"{module_type}_{module_index}"
        self._module_visibility_state[module_key] = self.isVisible()

    def setup_module_layout(self, module_layout_type):
        """
        Setup the module layout.
        """
        module_layouts = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
            "Form": QFormLayout(),
        }

        return module_layouts.get(module_layout_type, QGridLayout())

    def setup_module_data(
        self, module_type: str, module_index: int
    ) -> Optional[Dict[str, Union[str, int, float]]]:
        """
        Setup the module data.
        """
        module_list = {
            "Label": LABELS,
            "Checkbox": CHECKBOXES,
            "SpinBox": SPINBOXES,
            "InputField": INPUTFIELDS,
            "Button": BUTTONS,
            "GraphicsView": GRAPHICS_VIEWS,
            "TableView": TABLES,
        }.get(module_type, [])

        module_data = next(
            (module for module in module_list if module["index"] == module_index), None
        )

        return module_data

    def setup_module_creation(self, module_type: str, module_data: dict) -> QWidget:
        """
        Setup the module creation.
        """
        module = QWidget()

        if module_type == "Label":
            module = QLabel()
            module.setText(module_data["title"])

        elif module_type == "Checkbox":
            module = QCheckBox()
            module.setText(module_data["title"])

        elif module_type == "SpinBox":
            module = QDoubleSpinBox()
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setSuffix(module_data["suffix"])

        elif module_type == "InputField":
            module = QLineEdit()
            module.setPlaceholderText(module_data["placeholder"])

        elif module_type == "Button":
            module = QPushButton()
            if module_data["icon_path"]:
                icon = QIcon(module_data["icon_path"])
                module.setIcon(icon)
            else:
                module.setText(module_data["title"])
            module.setStyleSheet(module_data["stylesheet"])
            if module_data["size"] is not None:
                module.setFixedSize(*module_data["size"])
            else:
                module.setSizePolicy(
                    QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum
                )
            module.clicked.connect(
                partial(self.onButtonModuleClicked.emit, module_data["index"])
            )

        elif module_type == "GraphicsView":
            module = GraphicsDelegate(module_data)

        elif module_type == "TableView":
            module = TableDelegate(module_data)

        elif module_type != "GraphicsView":
            module.setStyleSheet(module_data["stylesheet"])

        return module

    def setup_module_alignment(
        self, module_alignment: Optional[str]
    ) -> Optional[Qt.AlignmentFlag]:
        """
        Set the alignment of the layout.
        """
        if module_alignment is not None:
            alignment_mapping = {
                "AlignLeading": Qt.AlignmentFlag.AlignLeading,
                "AlignLeft": Qt.AlignmentFlag.AlignLeft,
                "AlignRight": Qt.AlignmentFlag.AlignRight,
                "AlignTrailing": Qt.AlignmentFlag.AlignTrailing,
                "AlignHCenter": Qt.AlignmentFlag.AlignHCenter,
                "AlignVCenter": Qt.AlignmentFlag.AlignVCenter,
                "AlignJustify": Qt.AlignmentFlag.AlignJustify,
                "AlignAbsolute": Qt.AlignmentFlag.AlignAbsolute,
                "AlignHorizontalMask": Qt.AlignmentFlag.AlignHorizontal_Mask,
                "AlignTop": Qt.AlignmentFlag.AlignTop,
                "AlignBottom": Qt.AlignmentFlag.AlignBottom,
                "AlignAlignCenter": Qt.AlignmentFlag.AlignCenter,
                "AlignBaseline": Qt.AlignmentFlag.AlignBaseline,
                "AlignVerticalMask": Qt.AlignmentFlag.AlignVertical_Mask,
            }
            return alignment_mapping.get(
                module_alignment, Qt.AlignmentFlag.AlignJustify
            )
        else:
            return None

    def setup_module_margins(
        self, module_margins: Optional[Tuple[int, int, int, int]]
    ) -> Tuple[int, int, int, int]:
        if module_margins is None:
            return (0, 0, 0, 0)
        else:
            return module_margins

    def toggle_module(self):
        """
        Toggle the module.
        """
        self.setVisible(not self.isVisible())
        self.save_module_visibility_state()

    def save_module_visibility_state(self):
        """
        Save the visibility state of the modules.
        """
        for module_key, visible in self._module_visibility_state.items():
            self._settings.setValue(module_key, visible)

    def load_module_visibility_state(self):
        """
        Load the visibility state of the modules.
        """
        for module_key in self._module_visibility_state.keys():
            visibility_state = self._settings.value(module_key, True, type=bool)
            self._module_visibility_state[module_key] = bool(visibility_state)
            self.setVisible(bool(visibility_state))
