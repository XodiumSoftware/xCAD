from typing import Callable, Optional, Tuple

from constants import (
    BUTTONS,
    CHECKBOXES,
    DOUBLESPINBOXES,
    INPUTFIELDS,
    LABELS,
    MATRICES,
    AlignmentType,
    LayoutType,
    ModuleType,
    SizePolicyType,
)
from PySide6.QtCore import QSettings, Slot
from PySide6.QtGui import QIcon


class ModuleHandler(ModuleType.Widget.value):
    """A class to handle the modules."""

    def __init__(
        self,
        matrix_index: int,
        matrix_margins: Optional[Tuple[int, int, int, int]] = None,
        parent: Optional[ModuleType.Widget.value] = None,
    ) -> None:
        """Initialize the ModuleHandler."""
        super().__init__(parent)
        self._settings = QSettings()
        self._module_visibility = {}

        self.create_modules_from_matrix(matrix_index, matrix_margins)

    def create_modules_from_matrix(
        self,
        matrix_index: int,
        matrix_margins: Optional[Tuple[int, int, int, int]] = None,
    ):
        """Create modules from a matrix."""
        module_matrix_data = next(
            (data for data in MATRICES if data["index"] == matrix_index),
            None,
        )
        if module_matrix_data:
            module_matrix_pos = module_matrix_data.get("module_matrix_pos", [])
            layout = LayoutType.Grid.value(self)
            layout.setContentsMargins(*self.setup_module_margins(matrix_margins))

            for row, row_modules in enumerate(module_matrix_pos):
                for column, module_args in enumerate(row_modules):
                    (
                        module_layout_type,
                        module_type,
                        module_index,
                        module_margins,
                        module_alignment,
                        module_size_policy,
                    ) = module_args

                    module_container = LayoutType(module_layout_type).value()
                    module_container.setContentsMargins(
                        *self.setup_module_margins(module_margins)
                    )

                    if module_alignment is not None:
                        module_container.setAlignment(
                            AlignmentType(module_alignment).value
                        )

                    module_data = self.setup_module_data(module_type, module_index)

                    if module_data:
                        module = self.setup_module_properties(module_type, module_data)
                        if module:
                            if module_size_policy is not None:
                                size_policy_x, size_policy_y = module_size_policy
                                module.setSizePolicy(
                                    size_policy_x.value, size_policy_y.value
                                )

                            module_container.addWidget(module)

                            layout.addLayout(module_container, row, column)

                        else:
                            raise ValueError(
                                f'"{module_type}" is not a valid module type'
                            )
                    else:
                        raise ValueError(f"{module_type}_{module_index}: not found")

        else:
            raise ValueError(
                f"Module index {matrix_index} not found in MODULE_MATRICES"
            )

    def setup_module(
        self,
        module_layout_type: LayoutType,
        module_type: ModuleType,
        module_index: int,
        module_margins: Optional[Tuple[int, int, int, int]] = None,
        module_alignment: Optional[AlignmentType] = None,
        module_size_policy: Optional[Tuple[SizePolicyType, SizePolicyType]] = None,
    ) -> None:
        """Setup the module."""
        layout = LayoutType(module_layout_type).value()
        layout.setContentsMargins(*self.setup_module_margins(module_margins))

        if module_alignment is not None:
            layout.setAlignment(module_alignment.value)
        module_data = self.setup_module_data(module_type, module_index)

        if module_data:
            module = self.setup_module_properties(module_type, module_data)
            if module:
                if module_size_policy is not None:
                    size_policy_x, size_policy_y = module_size_policy
                    module.setSizePolicy(size_policy_x.value, size_policy_y.value)
                layout.addWidget(module)
            else:
                raise ValueError(f'"{module_type}" is not a valid module type')
        else:
            raise ValueError(f"{module_type}_{module_index}: not found")

        self.setLayout(layout)

    @staticmethod
    def setup_module_data(module_type: ModuleType, module_index: int) -> Optional[dict]:
        """Setup the module data."""
        module_data_dict = {
            ModuleType.Label: LABELS,
            ModuleType.CheckBox: CHECKBOXES,
            ModuleType.DoubleSpinBox: DOUBLESPINBOXES,
            ModuleType.LineEdit: INPUTFIELDS,
            ModuleType.PushButton: BUTTONS,
        }
        module_list = module_data_dict.get(module_type)

        if module_list is not None and module_index < len(module_list):
            return module_list[module_index]

        return None

    @staticmethod
    def setup_module_properties(
        module_type: ModuleType, module_data: dict
    ) -> ModuleType.Widget.value:
        """Setup the module properties."""
        module = ModuleType.Widget.value()

        if module_type == ModuleType.Label:
            module = ModuleType.Label.value()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setText(module_data["title"])

        elif module_type == ModuleType.CheckBox:
            module = ModuleType.CheckBox.value()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setText(module_data["title"])

        elif module_type == ModuleType.DoubleSpinBox:
            module = ModuleType.DoubleSpinBox.value()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setSuffix(module_data["suffix"])

        elif module_type == ModuleType.LineEdit:
            module = ModuleType.LineEdit.value()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setPlaceholderText(module_data["placeholder"])

        elif module_type == ModuleType.PushButton:
            module = ModuleType.PushButton.value()
            module.setObjectName(str((module_type, module_data["index"])))

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

        return module

    @staticmethod
    def setup_module_margins(
        module_margins: Optional[Tuple[int, int, int, int]]
    ) -> Tuple[int, int, int, int]:
        """Set the margins of the layout."""
        if module_margins is None:
            return (0, 0, 0, 0)
        return module_margins

    def module_connection(
        self, module_type: ModuleType, module_index: int, target_method: Callable
    ) -> None:
        """Connect the module signal to the target method."""
        module = self.findChild(
            ModuleType.Widget.value, str((module_type, module_index))
        )

        if isinstance(module, ModuleType.PushButton.value):
            module.clicked.connect(target_method)

        else:
            raise ValueError(f"{module_type}_{module_index}: not found")

    @Slot(str, int)
    def toggle_module_visibility(
        self, module_type: ModuleType, module_index: int
    ) -> None:
        """Toggle the module visibility."""
        module = self.findChild(
            ModuleType.Widget.value, str((module_type, module_index))
        )

        if isinstance(module, ModuleType.Widget.value):
            module.setVisible(not module.isVisible())
        else:
            raise ValueError(
                f"{module_type}_{module_index}: not found or not supported for visibility toggling"
            )
