import functools

from constants import BUTTONS
from handlers.events_handler import EventsHandler
from PySide6.QtGui import QIcon, Qt
from PySide6.QtWidgets import QHBoxLayout, QPushButton, QWidget


class ButtonWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initButtonWidget()

    def initButtonWidget(self):
        # Create the layout for the widget
        button_layout = QHBoxLayout(self)
        button_layout.setContentsMargins(0, 0, 0, 0)
        self.setLayout(button_layout)

        # Create and add the first button aligned to the left
        if len(BUTTONS) > 0:
            self.addPushButton(
                button_layout, BUTTONS[0], alignment=Qt.AlignmentFlag.AlignLeft
            )

        # Add stretch in the middle
        button_layout.addStretch(1)

        # Create and add the second button aligned to the right
        if len(BUTTONS) > 1:
            self.addPushButton(
                button_layout, BUTTONS[1], alignment=Qt.AlignmentFlag.AlignRight
            )

    def addPushButton(self, layout, button_data, alignment):
        # Create the push button
        button = QPushButton(self)
        button.setObjectName(button_data["title"])
        button.setFixedSize(*button_data["size"])
        button.setIcon(QIcon(button_data["icon_path"]))
        button.setProperty("index", button_data["index"])

        # Set button alignment
        button_layout = QHBoxLayout()
        button_layout.setAlignment(alignment)
        button_layout.addWidget(button)
        button_layout.setContentsMargins(5, 5, 5, 5)

        # Add the button layout to the main layout
        layout.addLayout(button_layout)

        # Connect the clicked signal
        button.clicked.connect(
            functools.partial(
                EventsHandler().on_button_clicked_event, button_data["index"]
            )
        )
