from functools import partial

from constants import BUTTONS, DEBUG_NAME
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtCore import Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QPushButton, QVBoxLayout, QWidget


class ButtonModule(QWidget):
    on_button_clicked = Signal(int)

    def __init__(self, module_index, margins=None, alignment=None, parent=None):
        """
        Initialize the ButtonModule.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(module_index, margins, alignment)

        # self.visibility_handler.load_visibility_state(self, module_index)

    def setup_module(self, module_index, margins, alignment):
        """
        Setup the ButtonModule.
        """
        layout = QVBoxLayout(self)

        module_data = next(
            (module for module in BUTTONS if module["index"] == module_index),
            None,
        )

        if module_data:
            module = self.create_module(module_data)
            module.clicked.connect(partial(self.on_button_clicked.emit, module_index))
            layout.addWidget(module)

        else:
            print(DEBUG_NAME + f'"index" {module_index} not found in BUTTONS')

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(*alignment)

        self.setLayout(layout)

    def create_module(self, module_data):
        """
        Create a button module.
        """
        module = QPushButton()

        if module_data["size"] is not None:
            module.setFixedSize(*module_data["size"])

        if module_data["icon_path"]:
            module.setIcon(QIcon(module_data["icon_path"]))

        else:
            module.setText(module_data["title"])

        if module_data["stylesheet"]:
            module.setStyleSheet(module_data["stylesheet"])

        return module

    # TODO: Can we make it so this func is not needed?
    def visibility_state(self, module_index):
        """
        Toggle the visibility of the label.
        """
        self.visibility_handler.toggle_visibility_state(self, module_index)
