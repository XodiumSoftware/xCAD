from constants import DEBUG_NAME, GRAPHIC_VIEWS
from delegates.graphics_delegate import GraphicsDelegate
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtWidgets import QVBoxLayout, QWidget


class GraphicsViewModule(QWidget):
    def __init__(self, module_index, margins=None, alignment=None, parent=None):
        """
        Initialize the GraphicsView.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(module_index, margins, alignment)

        # self.visibility_handler.load_visibility_state(self, module_index)

    def setup_module(self, module_index, margins, alignment):
        """
        Initialize the graphics view widget.
        """
        layout = QVBoxLayout(self)

        module_data = next(
            (module for module in GRAPHIC_VIEWS if module["index"] == module_index),
            None,
        )

        if module_data:
            module = self.create_module(module_data)
            layout.addWidget(module)

        else:
            print(DEBUG_NAME + f'"index" {module_index} not found in ITEM_DATA')

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(alignment)

        self.setLayout(layout)

    def create_module(self, module_data):
        """
        Setup the GraphicsView.
        """
        module = GraphicsDelegate(module_data)

        return module

    # def toggle_module(self, module_index):
    #     """
    #     Toggle the visibility of the label.
    #     """
    #     self.visibility_handler.toggle_visibility_state(self, module_index)
