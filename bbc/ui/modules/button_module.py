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
            layout.addWidget(module)

        else:
            print(DEBUG_NAME + f'"index" {module_index} not found in BUTTONS')

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(alignment)

        self.setLayout(layout)

    def create_module(self, module_data):
        """
        Create button modules.
        """
        module = QPushButton()

        if module_data["icon_path"]:
            icon = QIcon(module_data["icon_path"])
            module.setIcon(icon)
        else:
            module.setText(module_data["title"])

        stylesheet = self.create_stylesheet(module_data["stylesheet"])
        module.setStyleSheet(stylesheet)

        module.clicked.connect(
            partial(self.on_button_clicked.emit, module_data["index"])
        )

        return module

    def create_stylesheet(self, stylesheet_data):
        """
        Create a CSS stylesheet string from the stylesheet data.
        """
        stylesheet = ""

        for style in stylesheet_data:
            for key, value in style.items():
                stylesheet += f"{key}: {value}; "

        return stylesheet

    def toggle_module(self, module_index):
        """
        Toggle the visibility of the label.
        """
        self.visibility_handler.toggle_visibility_state(self, module_index)
