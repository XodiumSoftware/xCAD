from functools import partial

from constants import BUTTONS, DEBUG_NAME
from PySide6.QtCore import Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QPushButton, QVBoxLayout, QWidget


class ButtonModule(QWidget):
    on_button_clicked = Signal(int)

    def __init__(
        self, button_index, margins=None, alignment=None, visible=None, parent=None
    ):
        """
        Initialize the ButtonModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.alignment = alignment
        self.visible = visible
        self.setup_button_module(button_index)

    def setup_button_module(self, button_index):
        """
        Setup the ButtonModule.
        """
        layout = QVBoxLayout(self)

        button_data = next(
            (button for button in BUTTONS if button["index"] == button_index),
            None,
        )

        if button_data:
            button = self.create_button_module(button_data)
            button.clicked.connect(partial(self.on_button_clicked.emit, button_index))
            layout.addWidget(button)

        else:
            print(DEBUG_NAME + f'"index" {button_index} not found in BUTTONS')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if self.alignment is not None:
            layout.setAlignment(*self.alignment)

        self.setLayout(layout)

    def create_button_module(self, button_data):
        """
        Create a button module.
        """
        button = QPushButton()

        if button_data["size"] is not None:
            button.setFixedSize(*button_data["size"])

        if button_data["icon_path"]:
            button.setIcon(QIcon(button_data["icon_path"]))

        else:
            button.setText(button_data["title"])

        if button_data["stylesheet"]:
            button.setStyleSheet(button_data["stylesheet"])

        return button

    def toggle_visibility(self):
        """
        Toggle the visibility of the button.
        """
        self.setVisible(not self.isVisible())
