from functools import partial

from constants import DEBUG_NAME, RADIO_BUTTONS
from PySide6.QtCore import QSettings, Signal
from PySide6.QtWidgets import QRadioButton, QVBoxLayout, QWidget


class RadioButtonModule(QWidget):
    on_radio_button_clicked = Signal(int)

    def __init__(self, radio_button_index, parent=None):
        """
        Initialize the RadioButtonModule.
        """
        super().__init__(parent)
        self._settings = QSettings()
        self.setup_radio_button_module(radio_button_index)

    def setup_radio_button_module(self, radio_button_index):
        """
        Setup the RadioButtonModule.
        """
        layout = QVBoxLayout(self)

        radio_button_data = next(
            (
                radio_button
                for radio_button in RADIO_BUTTONS
                if radio_button["index"] == radio_button_index
            ),
            None,
        )

        if radio_button_data:
            radio_button = self.create_radio_button_module(
                radio_button_data, radio_button_index
            )
            radio_button.clicked.connect(
                partial(self.on_radio_button_clicked.emit, radio_button_index)
            )
            layout.addWidget(radio_button)

        else:
            print(
                DEBUG_NAME + f'"index" {radio_button_index} not found in RADIO_BUTTONS'
            )

        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def create_radio_button_module(self, radio_button_data):
        """
        Create a radio button module.
        """
        radio_button = QRadioButton(radio_button_data["title"])
        radio_button.setStyleSheet(radio_button_data["stylesheet"])
        radio_button.setSizePolicy(*radio_button_data["size_policy"])

        return radio_button
