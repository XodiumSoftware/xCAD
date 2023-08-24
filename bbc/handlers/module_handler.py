from enum import Enum
from typing import Any, Callable, List, Optional, Tuple

from delegates.graphics_view_delegate import GraphicsViewDelegate
from enums.module_enums import (
    Checkboxes,
    DoubleSpinBoxes,
    GraphicsViews,
    Labels,
    LineEdits,
    PushButtons,
)
from enums.q_enums import AlignmentType, LayoutType, ModuleType, SizePolicyType
from PySide6.QtCore import Slot
from PySide6.QtGui import QIcon


class ModuleHandler(ModuleType.Widget.value):
    """A class to handle the modules."""

    def __init__(
        self,
        matrix_name: Enum,
        matrix_margins: Optional[Tuple[int, int, int, int]] = None,
        parent: Optional[ModuleType.Widget.value] = None,
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
                        module: ModuleType.Widget.value = self.setup_module_properties(
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
    def setup_module_properties(
        module_enum: Enum, module_data: dict
    ) -> ModuleType.Widget.value:
        """Setup the module properties."""
        module = ModuleType.Widget.value()

        if module_enum.__class__ == Labels:
            module = ModuleType.Label.value()
            module.setText(module_data["title"])

        elif module_enum.__class__ == Checkboxes:
            module = ModuleType.CheckBox.value()
            module.setText(module_data["title"])

        elif module_enum.__class__ == DoubleSpinBoxes:
            module = ModuleType.DoubleSpinBox.value()
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setSuffix(module_data["suffix"])

        elif module_enum.__class__ == LineEdits:
            module = ModuleType.LineEdit.value()
            module.setPlaceholderText(module_data["placeholder"])

        elif module_enum.__class__ == PushButtons:
            module = ModuleType.PushButton.value()

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
                    SizePolicyType.Minimum.value, SizePolicyType.Minimum.value
                )
        elif module_enum.__class__ == GraphicsViews:
            module = GraphicsViewDelegate()
        else:
            raise ValueError(f"{module_enum.__class__}: not found")

        return module

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
        if isinstance(module_reference, ModuleType.PushButton.value):
            module_reference.clicked.connect(target_method)
        else:
            raise ValueError(f"{module_enum}: not found")

    @Slot(str, str)
    def toggle_module_visibility(self, module_enum: Enum) -> None:
        """Toggle the module visibility."""
        module_reference = self._module_mapping.get(module_enum.name)
        if isinstance(module_reference, ModuleType.Widget.value):
            module_reference.setVisible(not module_reference.isVisible())
        else:
            raise ValueError(
                f"{module_enum}: not found or not supported for visibility toggling"
            )
