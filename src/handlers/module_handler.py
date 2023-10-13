from enum import Enum
from typing import Any, Callable, Optional

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QCheckBox,
    QGridLayout,
    QRadioButton,
    QSizePolicy,
    QSlider,
    QSpinBox,
    QWidget,
)

from configs.module_configs import (
    Checkboxes,
    DoubleSpinBoxes,
    GraphicsViews,
    Labels,
    LineEdits,
    MessageBoxes,
    PushButtons,
)
from delegates.checkbox_delegate import CheckBoxDelegate
from delegates.doublespinbox_delegate import DoubleSpinBoxDelegate
from delegates.graphics_view_delegate import GraphicsViewDelegate
from delegates.label_delegate import LabelDelegate
from delegates.lineedit_delegate import LineEditDelegate
from delegates.message_box_delegate import MessageBoxDelegate
from delegates.pushbutton_delegate import PushButtonDelegate, QPushButton


class ModuleHandler(QWidget):
    """A class to handle the modules."""

    def __init__(
        self,
        matrix_name: Enum,
        matrix_margins: Optional[tuple[int, int, int, int]] = None,
    ) -> None:
        """Initialize the ModuleHandler."""
        super().__init__()
        self._module_visibility = {}
        self._module_mapping = {}

        self.create_modules_from_matrix(matrix_name, matrix_margins)

    def create_modules_from_matrix(
        self,
        matrix_name: Enum,
        matrix_margins: Optional[tuple[int, int, int, int]] = None,
    ) -> None:
        """Create modules from a matrix."""
        if isinstance(matrix_name, Enum):
            matrix_data: list[list[tuple[Any, ...]]] = matrix_name.value
        else:
            matrix_data: list[list[tuple[Any, ...]]] = matrix_name

        if not isinstance(matrix_data, list) or not all(
            isinstance(row, list) for row in matrix_data
        ):
            raise TypeError("Invalid matrix data")

        if matrix_data:
            layout = QGridLayout(self)
            layout.setContentsMargins(*self.setup_module_margins(self, matrix_margins))

            for row, row_modules in enumerate(matrix_data):
                for column, module_data in enumerate(row_modules):
                    layout.addWidget(
                        self.setup_module_container(*module_data), row, column
                    )

    def setup_module_container(
        self,
        module_layout_type: type[QGridLayout],
        module_enum: type[Enum],
        module_margins: Optional[tuple[int, int, int, int]],
        module_alignment: Optional[Qt.AlignmentFlag],
        module_size_policy: Optional[tuple[QSizePolicy.Policy, QSizePolicy.Policy]],
    ) -> QWidget:
        """Setup the module container layout."""
        module_container = QWidget()

        _, delegate = self.setup_module(module_enum)

        if delegate:
            self._module_mapping[module_enum.name] = delegate

            layout = module_layout_type(module_container)
            layout.setContentsMargins(*self.setup_module_margins(self, module_margins))
            if module_alignment is not None:
                layout.setAlignment(module_alignment)

            if module_size_policy is not None:
                size_policy_x, size_policy_y = module_size_policy
                delegate.setSizePolicy(size_policy_x, size_policy_y)

            layout.addWidget(delegate)

        return module_container

    @staticmethod
    def setup_module(module_enum: type[Enum]) -> tuple[type[Enum], Optional[QWidget]]:
        """Setup the module data and properties."""
        delegate_class = {
            Labels: LabelDelegate,
            Checkboxes: CheckBoxDelegate,
            LineEdits: LineEditDelegate,
            DoubleSpinBoxes: DoubleSpinBoxDelegate,
            PushButtons: PushButtonDelegate,
            GraphicsViews: GraphicsViewDelegate,
            MessageBoxes: MessageBoxDelegate,
        }.get(type(module_enum))

        return (
            module_enum,
            delegate_class(module_enum.value) if delegate_class else None,
        )

    @staticmethod
    def module_connection(module_reference: QWidget, target_method: Callable) -> None:
        """Connect the module signal to the target method."""
        if isinstance(module_reference, (QPushButton, QCheckBox, QRadioButton)):
            module_reference.clicked.connect(target_method)
        elif isinstance(module_reference, QSlider):
            module_reference.valueChanged.connect(target_method)
        elif isinstance(module_reference, QSpinBox):
            module_reference.valueChanged.connect(target_method)
        else:
            raise ValueError(f"{module_reference}: not supported for module connection")

    @staticmethod
    def toggle_module_visibility(module_reference: QWidget) -> None:
        """Toggle the module visibility."""
        module_reference.setVisible(not module_reference.isVisible())
