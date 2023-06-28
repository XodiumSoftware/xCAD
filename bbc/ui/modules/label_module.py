from constants import DEBUG_NAME, LABELS
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtWidgets import QLabel, QVBoxLayout, QWidget


class LabelModule(QWidget):
    def __init__(self, module_index, margins=None, alignment=None, parent=None):
        """
        Initialize the LabelWidget.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(module_index, margins, alignment)

        # self.visibility_handler.load_visibility_state(self, module_index)

    def setup_module(self, module_index, margins, alignment):
        """
        Initialize the label widget.
        """
        layout = QVBoxLayout(self)

        module_data = next(
            (module for module in LABELS if module["index"] == module_index), None
        )

        if module_data:
            module = self.create_module(module_data)
            layout.addWidget(module)

        else:
            print(DEBUG_NAME + f'"index" {module_index} not found in LABELS')

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(*alignment)

        self.setLayout(layout)

    def create_module(self, module_data):
        """
        Create the label.
        """
        module = QLabel(module_data["title"])
        module.setStyleSheet(module_data["stylesheet"])

        return module

    # TODO: Can we make it so this func is not needed?
    def visibility_state(self, module_index):
        """
        Toggle the visibility of the label.
        """
        self.visibility_handler.toggle_visibility_state(self, module_index)
