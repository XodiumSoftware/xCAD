from functools import partial
from typing import Dict, Optional, Tuple, Union

from constants import (
    BUTTONS,
    CHECKBOXES,
    DEBUG_NAME,
    GRAPHICS_VIEWS,
    INPUTFIELDS,
    LABELS,
    SPINBOXES,
    TABLES,
)
from delegates.graphics_delegate import GraphicsDelegate
from delegates.table_delegate import TableDelegate
from handlers.db_handler import DataBaseHandler
from PySide6.QtCore import QSettings, Qt, QTimer, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QBoxLayout,
    QCheckBox,
    QDoubleSpinBox,
    QGraphicsView,
    QGridLayout,
    QHBoxLayout,
    QLabel,
    QLayout,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QTableView,
    QVBoxLayout,
    QWidget,
)


class ModuleHandler(QWidget):
    on_button_clicked = Signal(int)

    def __init__(
        self,
        module_layout_type: str,
        module_type: str,
        module_index: int,
        margins: Optional[Tuple[int, int, int, int]] = None,
        alignment: Optional[str] = None,
        parent: Optional[QWidget] = None,
    ) -> None:
        """
        Initialize the ModuleHandler.
        """
        super().__init__(parent)

        self.db_handler = DataBaseHandler()

        self._settings = QSettings()

        self.module_type = module_type
        self.module_index = module_index

        self._setup_module(
            module_layout_type, module_type, module_index, margins, alignment
        )
        QTimer.singleShot(0, self.load_visibility_state)

    def _setup_module(
        self,
        module_layout_type: str,
        module_type: str,
        module_index: int,
        margins: Optional[Tuple[int, int, int, int]] = None,
        alignment: Optional[str] = None,
    ) -> None:
        """
        Setup the module.
        """
        layout = self._setup_module_layout(module_layout_type)
        module_data = self._setup_module_data(module_type, module_index)

        if module_data:
            module = self._setup_module_creation(module_type, module_data)
            if module:
                layout.addWidget(module)
            else:
                raise ValueError(
                    f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                )
        else:
            raise ValueError(f'{DEBUG_NAME}"index" {module_index} not found')

        layout.setContentsMargins(*(margins or (0, 0, 0, 0)))

        if alignment:
            self.setAlignment(layout, alignment)

        self.setLayout(layout)

    def _setup_module_layout(self, module_layout_type):
        """
        Setup the module layout.
        """
        module_layouts = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
        }.get(module_layout_type)

        if module_layouts is None:
            raise ValueError(f"Invalid layout type: {module_layout_type}")

        return module_layouts

    def _setup_module_data(
        self, module_type: str, module_index: int
    ) -> Optional[Dict[str, Union[str, int, float]]]:
        """
        Get the module data.
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

    def _setup_module_creation(
        self, module_type: str, module_data: dict
    ) -> Optional[QWidget]:
        """
        Create the module.
        """
        module_class = {
            "Label": QLabel,
            "Checkbox": QCheckBox,
            "SpinBox": QDoubleSpinBox,
            "InputField": QLineEdit,
            "Button": QPushButton,
            "GraphicsView": QGraphicsView,
            "TableView": QTableView,
        }.get(module_type)

        if not module_class:
            raise ValueError(f'{DEBUG_NAME}"{module_type}" is not a valid module type')

        module = module_class()

        if module_type != "GraphicsView":
            module.setStyleSheet(module_data["stylesheet"])

        if module_type == "Label":
            module.setText(module_data["title"])

        elif module_type == "Checkbox":
            module.setText(module_data["title"])

        elif module_type == "SpinBox":
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setSuffix(module_data["suffix"])

        elif module_type == "InputField":
            module.setPlaceholderText(module_data["placeholder"])

        elif module_type == "Button":
            if module_data["icon_path"]:
                icon = QIcon(module_data["icon_path"])
                module.setIcon(icon)

            else:
                module.setText(module_data["title"])

            module.setStyleSheet(module_data["stylesheet"])

            if module_data["size"] != None:
                module.setFixedSize(*module_data["size"])

            else:
                module.setSizePolicy(
                    QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum
                )

            module.clicked.connect(
                partial(self.on_button_clicked.emit, module_data["index"])
            )
        elif module_type == "GraphicsView":
            module = GraphicsDelegate(module_data)

        elif module_type == "TableView":
            module = TableDelegate(module_data)

        else:
            raise ValueError(f'{DEBUG_NAME}"{module_type}" is not a valid module type')

        return module

    def setAlignment(self, layout: Union[QLayout, QBoxLayout], alignment: str) -> None:
        """
        Set the alignment of the layout.
        """
        alignment_mapping = {
            "Left": Qt.AlignmentFlag.AlignLeft,
            "Right": Qt.AlignmentFlag.AlignRight,
            "Center": Qt.AlignmentFlag.AlignCenter,
            "Justify": Qt.AlignmentFlag.AlignJustify,
            "Top": Qt.AlignmentFlag.AlignTop,
            "Bottom": Qt.AlignmentFlag.AlignBottom,
        }

        layout.setAlignment(
            alignment_mapping.get(alignment, Qt.AlignmentFlag.AlignJustify)
        )

    def toggle_module(self):
        """
        Toggle the module.
        """
        self.setVisible(not self.isVisible())
        self.save_visibility_state()

    def save_visibility_state(self):
        """
        Save the visibility state of the module.
        """
        visibility_state = self.isVisible()
        self._settings.setValue(
            f"{self.module_type}_{self.module_index}", visibility_state
        )
        print(
            f"Visibility state saved: {self.module_type}_{self.module_index}:{visibility_state}"
        )

    def load_visibility_state(self):
        """
        Load the visibility state of the module.
        """
        visibility_state = self._settings.value(
            f"{self.module_type}_{self.module_index}", True, type=bool
        )
        self.setVisible(bool(visibility_state))
        print(
            f"Visibility state loaded: {self.module_type}_{self.module_index}:{visibility_state}"
        )
