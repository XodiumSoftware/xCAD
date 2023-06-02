from constants import BUTTONS
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QPushButton, QVBoxLayout, QWidget


class ButtonModule(QWidget):
    def __init__(self, button_index, parent=None):
        """
        Initialize the ButtonModule.
        """
        super().__init__(parent)
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
            layout.addWidget(button)

        self.setLayout(layout)

    def create_button_module(self, button_data):
        """
        Create a button module.
        """
        button = QPushButton()
        button.setFixedSize(*button_data["size"])
        if button_data["icon_path"]:
            button.setIcon(QIcon(button_data["icon_path"]))
        else:
            button.setText(button_data["title"])
        # button.clicked.connect(button_data["action"])
        return button
