from functools import partial

from constants import BUTTONS, CHECKBOXES, DEBUG_NAME, INPUTFIELDS, LABELS, SPINBOXES
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtCore import Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QLabel,
    QLineEdit,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class ModuleHandler(QWidget):
    on_button_clicked = Signal(int)

    def __init__(
        self,
        module_type,
        module_index,
        margins=None,
        alignment=None,
        parent=None,
    ):
        """
        Initialize the ModuleHandler widget.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()
        self.setup_module(module_type, module_index, margins, alignment)

    def setup_module(self, module_type, module_index, margins, alignment):
        """
        Set up the module based on its type and index.
        """
        layout = QVBoxLayout(self)
        module_data = self.get_module_data(module_type, module_index)

        if module_data:
            module = self.create_module(module_type, module_data)
            if module:
                layout.addWidget(module)
            else:
                print(DEBUG_NAME + f'"{module_type}" is not a valid module type')
        else:
            print(DEBUG_NAME + f'"index" {module_index} not found')

        layout.setContentsMargins(*margins) if margins else layout.setContentsMargins(
            0, 0, 0, 0
        )
        layout.setAlignment(alignment) if alignment else None
        self.setLayout(layout)

    def get_module_data(self, module_type, module_index):
        """
        Get the data for the module based on its type and index.
        """
        if module_type == "Label":
            module_list = LABELS
        elif module_type == "Checkbox":
            module_list = CHECKBOXES
        elif module_type == "SpinBox":
            module_list = SPINBOXES
        elif module_type == "InputField":
            module_list = INPUTFIELDS
        elif module_type == "Button":
            module_list = BUTTONS
        else:
            module_list = []

        module_data = next(
            (module for module in module_list if module["index"] == module_index), None
        )
        return module_data

    def create_module(self, module_type, module_data):
        """
        Create the module widget based on its type and data.
        """
        if module_type == "Label":
            module = QLabel(module_data["title"])
            module.setStyleSheet(module_data["stylesheet"])
        elif module_type == "Checkbox":
            module = QCheckBox(module_data["title"])
            module.setStyleSheet(module_data["stylesheet"])
        elif module_type == "SpinBox":
            module = QDoubleSpinBox()
            module.setMinimum(module_data["min_value"])
            module.setMaximum(module_data["max_value"])
            module.setValue(module_data["default_value"])
            module.setSingleStep(module_data["step"])
            module.setStyleSheet(module_data["stylesheet"])
            module.setSuffix(module_data["suffix"])
        elif module_type == "InputField":
            module = QLineEdit()
            module.setPlaceholderText(module_data["placeholder"])
            module.setStyleSheet(module_data["stylesheet"])
        elif module_type == "Button":
            module = QPushButton()
            if module_data["icon_path"]:
                icon = QIcon(module_data["icon_path"])
                module.setIcon(icon)
            else:
                module.setText(module_data["title"])
            module.setStyleSheet(module_data["stylesheet"])
            module.clicked.connect(
                partial(self.on_button_clicked.emit, module_data["index"])
            )
        else:
            module = None
            print(DEBUG_NAME + f'"{module_type}" is not a valid module type')
        return module

    def toggle_module(self, module_type, module_index):
        """
        Toggle the visibility state of the module.
        """
        self.visibility_handler.toggle_visibility_state(self, module_type, module_index)
