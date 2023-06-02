from constants import BUTTONS
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QPushButton, QVBoxLayout, QWidget


class ButtonModule(QWidget):
    def __init__(self, button_index, parent=None):
        super().__init__(parent)
        self.init_button_module(button_index)

    def init_button_module(self, button_index):
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
        button = QPushButton(button_data["title"])
        button.setFixedSize(*button_data["size"])
        button.setStyleSheet(button_data["stylesheet"])
        if button_data["icon_path"]:
            button.setIcon(QIcon(button_data["icon_path"]))
        button.clicked.connect(button_data["action"])
        return button
