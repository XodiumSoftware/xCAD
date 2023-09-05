from enum import Enum
from typing import Any, Callable, List, Optional

from delegates.checkbox_delegate import CheckBoxDelegate
from delegates.color_dialog_delegate import ColorDialogDelegate
from delegates.doublespinbox_delegate import DoubleSpinBoxDelegate
from delegates.graphics_view_delegate import GraphicsViewDelegate
from delegates.label_delegate import LabelDelegate
from delegates.lineedit_delegate import LineEditDelegate
from delegates.message_box_delegate import MessageBoxDelegate
from delegates.pushbutton_delegate import PushButtonDelegate, QPushButton
from enums.module_enums import (
    Checkboxes,
    ColorDialogs,
    DoubleSpinBoxes,
    GraphicsViews,
    Labels,
    LineEdits,
    MessageBoxes,
    PushButtons,
)
from enums.q_enums import AlignmentType, LayoutType, SizePolicyType
from PySide6.QtCore import Slot
from PySide6.QtWidgets import QLayout, QWidget


class ModuleHandler(QWidget):
    """A class to handle the modules."""

    def __init__(
        self,
        matrix_name: Enum,
        matrix_margins: Optional[tuple[int, int, int, int]] = None,
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
        matrix_margins: Optional[tuple[int, int, int, int]] = None,
    ):
        """Create modules from a matrix."""
        matrix_data: List[List[tuple[Any, ...]]] = matrix_name.value

        if matrix_data:
            layout = LayoutType.Grid.value(self)
            layout.setContentsMargins(*self.setup_module_margins(matrix_margins))

            for row, row_modules in enumerate(matrix_data):
                for column, module_data in enumerate(row_modules):
                    if isinstance(module_data[0], list):
                        for sub_module_data in module_data:
                            module_container = self.setup_module_container(
                                *sub_module_data
                            )
                            if module_container:
                                layout.addLayout(module_container, row, column)
                    else:
                        module_container = self.setup_module_container(*module_data)
                        if module_container:
                            layout.addLayout(module_container, row, column)

    def setup_module_container(
        self,
        module_layout_type: LayoutType,
        module_enum: type[Enum],
        module_margins: Optional[tuple[int, int, int, int]],
        module_alignment: Optional[AlignmentType],
        module_size_policy: Optional[tuple[SizePolicyType, SizePolicyType]],
    ) -> QLayout:
        """Setup the module container layout."""
        module_container = module_layout_type.value(self)

        if module_alignment is not None:
            module_container.setAlignment(module_alignment.value)

        module_container.setContentsMargins(*self.setup_module_margins(module_margins))

        _, delegate = self.setup_module(module_enum)

        if delegate:
            self._module_mapping[module_enum.name] = delegate
            if module_size_policy is not None:
                size_policy_x, size_policy_y = module_size_policy
                delegate.setSizePolicy(size_policy_x.value, size_policy_y.value)

            module_container.addWidget(delegate)

        return module_container

    @staticmethod
    def setup_module(
        module_enum: type[Enum],
    ) -> tuple[Optional[dict[str, Any]], Optional[QWidget]]:
        """Setup the module data and properties."""
        delegate_class = {
            Labels: LabelDelegate,
            Checkboxes: CheckBoxDelegate,
            LineEdits: LineEditDelegate,
            DoubleSpinBoxes: DoubleSpinBoxDelegate,
            PushButtons: PushButtonDelegate,
            GraphicsViews: GraphicsViewDelegate,
            MessageBoxes: MessageBoxDelegate,
            ColorDialogs: ColorDialogDelegate,
        }.get(type(module_enum))

        return (
            module_enum.value,  # type: ignore # TODO: find out why the typing is bugging out. could be an external factor.
            delegate_class(module_enum.value) if delegate_class else None,
        )

    @staticmethod
    def setup_module_margins(
        module_margins: Optional[tuple[int, int, int, int]]
    ) -> tuple[int, int, int, int]:
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
