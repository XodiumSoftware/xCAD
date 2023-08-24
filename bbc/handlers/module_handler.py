from enum import Enum
from typing import Any, Callable, List, Optional, Tuple, Type

from delegates.checkbox_delegate import CheckBoxDelegate
from delegates.doublespinbox_delegate import DoubleSpinBoxDelegate
from delegates.graphics_view_delegate import GraphicsViewDelegate
from delegates.label_delegate import LabelDelegate
from delegates.lineedit_delegate import LineEditDelegate
from delegates.pushbutton_delegate import PushButtonDelegate, QPushButton
from enums.module_enums import (
    Checkboxes,
    DoubleSpinBoxes,
    GraphicsViews,
    Labels,
    LineEdits,
    PushButtons,
)
from enums.q_enums import AlignmentType, LayoutType
from PySide6.QtCore import Slot
from PySide6.QtWidgets import QWidget


class ModuleHandler(QWidget):
    """A class to handle the modules."""

    def __init__(
        self,
        matrix_name: Enum,
        matrix_margins: Optional[Tuple[int, int, int, int]] = None,
        parent: Optional[QWidget] = None,
    ) -> None:
        """Initialize the ModuleHandler."""
        super().__init__(parent)
        self._module_visibility = {}
        self._module_mapping = {}

        self.create_modules_from_matrix(matrix_name, matrix_margins)

    def create_modules_from_matrix(
        self,
        matrix_name: Enum,
        matrix_margins: Optional[Tuple[int, int, int, int]] = None,
    ):
        """Create modules from a matrix."""
        matrix_data: List[List[Tuple[Any, ...]]] = matrix_name.value

        if matrix_data:
            layout = LayoutType.Grid.value(self)
            layout.setContentsMargins(*self.setup_module_margins(matrix_margins))

            for row, row_modules in enumerate(matrix_data):
                for column, (
                    module_layout_type,
                    module_enum,
                    module_margins,
                    module_alignment,
                    module_size_policy,
                ) in enumerate(row_modules):
                    module_container = LayoutType(module_layout_type).value()

                    module_container = LayoutType(module_layout_type).value()
                    module_container.setContentsMargins(
                        *self.setup_module_margins(module_margins)
                    )
                    if module_alignment is not None:
                        module_container.setAlignment(
                            AlignmentType(module_alignment).value
                        )

                    module_data: Optional[dict] = self.setup_module_data(module_enum)

                    if module_data:
                        module: QWidget = self.setup_module_properties(
                            module_enum, module_data
                        )
                        if module:
                            self._module_mapping[module_enum.name] = module
                            if module_size_policy is not None:
                                size_policy_x, size_policy_y = module_size_policy
                                module.setSizePolicy(
                                    size_policy_x.value, size_policy_y.value
                                )

                            module_container.addWidget(module)

                            layout.addLayout(module_container, row, column)

    @staticmethod
    def setup_module_data(module_enum: Enum) -> Optional[dict[str, Any]]:
        """Setup the module data."""
        module_class_mapping = {
            Labels: Labels,
            Checkboxes: Checkboxes,
            LineEdits: LineEdits,
            DoubleSpinBoxes: DoubleSpinBoxes,
            PushButtons: PushButtons,
            GraphicsViews: GraphicsViews,
        }

        module_class = module_enum.__class__
        if module_class in module_class_mapping:
            module_data = module_class_mapping[module_class](module_enum).value
            return module_data if module_data is not None else None

        return None

    @staticmethod
    def setup_module_properties(module_enum: Type[Enum], module_data: dict) -> QWidget:
        """Setup the module properties."""
        delegate_mapping = {
            Labels: LabelDelegate,
            Checkboxes: CheckBoxDelegate,
            DoubleSpinBoxes: DoubleSpinBoxDelegate,
            LineEdits: LineEditDelegate,
            PushButtons: PushButtonDelegate,
            GraphicsViews: GraphicsViewDelegate,
        }

        module_class = module_enum.__class__
        delegate_class = delegate_mapping.get(module_class)

        if delegate_class is not None:
            return delegate_class(module_data)
        else:
            raise ValueError(f"{module_class}: not found")

    @staticmethod
    def setup_module_margins(
        module_margins: Optional[Tuple[int, int, int, int]]
    ) -> Tuple[int, int, int, int]:
        """Set the margins of the layout."""
        if module_margins is None:
            return (0, 0, 0, 0)
        return module_margins

    def module_connection(self, module_enum: Enum, target_method: Callable) -> None:
        """Connect the module signal to the target method."""
        module_reference = self._module_mapping.get(module_enum.name)
        if isinstance(module_reference, QPushButton):
            module_reference.clicked.connect(target_method)
        else:
            raise ValueError(f"{module_enum}: not found")

    @Slot(str, str)
    def toggle_module_visibility(self, module_enum: Enum) -> None:
        """Toggle the module visibility."""
        module_reference = self._module_mapping.get(module_enum.name)
        if isinstance(module_reference, QWidget):
            module_reference.setVisible(not module_reference.isVisible())
        else:
            raise ValueError(
                f"{module_enum}: not found or not supported for visibility toggling"
            )
