from constants import DEBUG_NAME, INPUTFIELDS
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtWidgets import QLineEdit, QVBoxLayout, QWidget


class InputFieldModule(QWidget):
    def __init__(self, module_index, margins=None, alignment=None, parent=None):
        """
        Initialize the InputFieldModule.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(module_index, margins, alignment)

        # self.visibility_handler.load_visibility_state(self, module_index)

    def setup_module(self, module_index, margins, alignment):
        """
        Setup the InputFieldModule.
        """
        layout = QVBoxLayout(self)

        module_data = next(
            (module for module in INPUTFIELDS if module["index"] == module_index),
            None,
        )

        if module_data:
            module = self.create_module(module_data)
            layout.addWidget(module)

        else:
            print(DEBUG_NAME + f'"index" {module_index} not found in INPUTFIELDS')

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(alignment)

        self.setLayout(layout)

    def create_module(self, module_data):
        """
        Create an input field module.
        """
        module = QLineEdit()
        module.setPlaceholderText(module_data["placeholder"])
        module.setStyleSheet(module_data["stylesheet"])

        return module

    def toggle_module(self, module_index):
        """
        Toggle the visibility of the label.
        """
        self.visibility_handler.toggle_visibility_state(self, module_index)
