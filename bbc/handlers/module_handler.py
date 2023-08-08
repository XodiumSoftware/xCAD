from typing import Callable, Dict, Optional, Tuple, Union, cast

from constants import (
    BUTTONS,
    CHECKBOXES,
    DEBUG_NAME,
    GRAPHICS_VIEWS,
    INPUTFIELDS,
    LABELS,
    MATRICES,
    SPINBOXES,
    TABLES,
)
from delegates.graphics_delegate import GraphicsDelegate
from delegates.table_delegate import TableDelegate
from handlers.signal_handler import SignalHandler
from PySide6.QtCore import QSettings, Qt, Slot
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
    def __init__(
        self,
        matrix_index: int,
        matrix_margins: Optional[Tuple[int, int, int, int]] = None,
        parent: Optional[QWidget] = None,
    ) -> None:
        """Initialize the ModuleHandler."""
        super().__init__(parent)

        self._settings = QSettings()

        self._signal_handler = SignalHandler()

        self._module_visibility = {}

        self.create_modules_from_matrix(matrix_index, matrix_margins)

    def create_modules_from_matrix(self, matrix_index, matrix_margins):
        """Create modules from a matrix."""
        module_matrix_data = next(
            (data for data in MATRICES if data["index"] == matrix_index),
            None,
        )
        if module_matrix_data:
            module_matrix_pos = module_matrix_data.get("module_matrix_pos", [])
            layout = QGridLayout(self)
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

                    module_container = self.setup_module_layout(module_layout_type)
                    module_container.setContentsMargins(
                        *self.setup_module_margins(module_margins)
                    )

                    if module_alignment is not None:
                        module_container.setAlignment(
                            self.setup_module_alignment(module_alignment)
                        )

                    module_data = self.setup_module_data(module_type, module_index)

                    if module_data:
                        module = self.setup_module_creation(module_type, module_data)
                        if module:
                            if module_size_policy is not None:
                                (
                                    size_policy_x,
                                    size_policy_y,
                                ) = self.setup_module_size_policy(module_size_policy)
                                module.setSizePolicy(size_policy_x, size_policy_y)

                            module_container.addWidget(module)

                            layout.addLayout(module_container, row, column)

                        else:
                            raise ValueError(
                                f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                            )
                    else:
                        raise ValueError(
                            f"{DEBUG_NAME}{module_type}_{module_index}: not found"
                        )

        else:
            raise ValueError(
                f"{DEBUG_NAME}Module index {matrix_index} not found in MODULE_MATRICES"
            )

    def setup_module(
        self,
        module_layout_type: str,
        module_type: str,
        module_index: int,
        module_margins: Optional[Tuple[int, int, int, int]] = None,
        module_alignment: Optional[str] = None,
        module_size_policy: Optional[Tuple[str, str]] = None,
    ) -> None:
        """Setup the module."""
        layout = self.setup_module_layout(module_layout_type)
        layout.setContentsMargins(*self.setup_module_margins(module_margins))

        if module_alignment is not None:
            layout.setAlignment(
                cast(Qt.AlignmentFlag, self.setup_module_alignment(module_alignment))
            )
        module_data = self.setup_module_data(module_type, module_index)

        print(f"Setting up module: {module_type}_{module_index}")

        if module_data:
            module = self.setup_module_creation(module_type, module_data)
            if module:
                if module_size_policy is not None:
                    size_policy_x, size_policy_y = self.setup_module_size_policy(
                        module_size_policy
                    )
                    module.setSizePolicy(size_policy_x, size_policy_y)
                layout.addWidget(module)
                print(f"Module: {module_type}_{module_index} added to layout")
            else:
                raise ValueError(
                    f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                )
        else:
            raise ValueError(f"{DEBUG_NAME}{module_type}_{module_index}: not found")

        self.setLayout(layout)

    @staticmethod
    def setup_module_layout(module_layout_type):
        """Setup the module layout."""
        module_layouts = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
            "Form": QFormLayout(),
        }

        return module_layouts.get(module_layout_type, QGridLayout())

    @staticmethod
    def setup_module_data(
        module_type: str, module_index: int
    ) -> Optional[Dict[str, Union[str, int, float]]]:
        """Setup the module data."""
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

    @staticmethod
    def setup_module_creation(module_type: str, module_data: dict) -> QWidget:
        """Setup the module creation."""
        module = QWidget()

        if module_type == "Label":
            module = QLabel()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setText(module_data["title"])

        elif module_type == "Checkbox":
            module = QCheckBox()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setText(module_data["title"])

        elif module_type == "SpinBox":
            module = QDoubleSpinBox()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setSuffix(module_data["suffix"])

        elif module_type == "InputField":
            module = QLineEdit()
            module.setObjectName(str((module_type, module_data["index"])))
            module.setPlaceholderText(module_data["placeholder"])

        elif module_type == "Button":
            module = QPushButton()
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
                    QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum
                )

        elif module_type == "GraphicsView":
            module = GraphicsDelegate(module_data)
            module.setObjectName(str((module_type, module_data["index"])))

        elif module_type == "TableView":
            module = TableDelegate(module_data)
            module.setObjectName(str((module_type, module_data["index"])))

        elif module_type != "GraphicsView":
            module.setObjectName(str((module_type, module_data["index"])))
            module.setStyleSheet(module_data["stylesheet"])

        return module

    @staticmethod
    def setup_module_alignment(
        module_alignment: Optional[Union[str, None]]
    ) -> Qt.AlignmentFlag:
        """Set the alignment of the layout."""
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
        return Qt.AlignmentFlag.AlignJustify

    @staticmethod
    def setup_module_margins(
        module_margins: Optional[Tuple[int, int, int, int]]
    ) -> Tuple[int, int, int, int]:
        """Set the margins of the layout."""
        if module_margins is None:
            return (0, 0, 0, 0)
        return module_margins

    @staticmethod
    def setup_module_size_policy(
        module_size_policy: Optional[Tuple[str, str]]
    ) -> Tuple[QSizePolicy.Policy, QSizePolicy.Policy]:
        """Set the size policy for the module."""
        if module_size_policy is not None:
            size_policy_mapping = {
                "SizeMinimum": QSizePolicy.Policy.Minimum,
                "SizeMaximum": QSizePolicy.Policy.Maximum,
                "SizeFixed": QSizePolicy.Policy.Fixed,
                "SizePreferred": QSizePolicy.Policy.Preferred,
                "SizeExpanding": QSizePolicy.Policy.Expanding,
                "SizeMinimumExpanding": QSizePolicy.Policy.MinimumExpanding,
                "SizeIgnored": QSizePolicy.Policy.Ignored,
            }
            size_policy_x = size_policy_mapping.get(
                module_size_policy[0], QSizePolicy.Policy.Expanding
            )
            size_policy_y = size_policy_mapping.get(
                module_size_policy[1], QSizePolicy.Policy.Expanding
            )
            return size_policy_x, size_policy_y
        return QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding

    def module_connection(
        self, module_type: str, module_index: int, target_method: Callable
    ) -> None:
        """Connect the module signal to the target method."""
        module = self.findChild(QWidget, str((module_type, module_index)))

        if isinstance(module, QPushButton):
            module.clicked.connect(target_method)

        else:
            raise ValueError(f"{DEBUG_NAME}{module_type}_{module_index}: not found")

    @Slot(str, int)
    def toggle_module_visibility(self, module_type: str, module_index: int) -> None:
        """Toggle the module visibility."""
        module = self.findChild(QWidget, str((module_type, module_index)))

        if isinstance(module, QWidget):
            module.setVisible(not module.isVisible())
        else:
            raise ValueError(
                f"{DEBUG_NAME}{module_type}_{module_index}: not found or not supported for visibility toggling"
            )
