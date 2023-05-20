import functools

from constants import BUTTONS
from handlers.events_handler import EventsHandler
from PySide6.QtGui import QIcon, Qt
from PySide6.QtWidgets import (
    QHBoxLayout,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
    QWidget,
)


class ButtonWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initButtonWidget()

    def initButtonWidget(self):
        parent_layout = QVBoxLayout(self)

        # Create and add the first button layout
        button_container_0 = self.addButtonLayout(
            [0, 1], alignment=Qt.AlignmentFlag.AlignHCenter, stretch=0
        )
        parent_layout.addLayout(button_container_0)

        # Create and add the second button layout
        button_container_1 = self.addButtonLayout(
            [2, 3], alignment=Qt.AlignmentFlag.AlignRight, stretch=0
        )
        parent_layout.addLayout(button_container_1)

        # Set the parent layout as the main layout of the widget
        self.setLayout(parent_layout)

        # Return the button containers
        return button_container_0, button_container_1

    def addButtonLayout(self, button_indices, alignment, stretch=0):
        button_layout = QHBoxLayout()
        button_layout.setAlignment(alignment)

        for button_index in button_indices:
            if len(BUTTONS) > button_index:
                button_data = BUTTONS[button_index]

                button = QPushButton(self)
                button.setObjectName(button_data["title"])
                button.setFixedSize(*button_data["size"])

                if button_data["icon_path"] is not None:
                    button.setIcon(QIcon(button_data["icon_path"]))
                else:
                    button.setText(button_data["title"])

                button.setProperty("index", button_data["index"])

                button_layout.addWidget(button, stretch=stretch)
                button.setSizePolicy(
                    QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
                )

                button.clicked.connect(
                    functools.partial(
                        EventsHandler().on_button_clicked_event, button_data["index"]
                    )
                )

        # Create a container layout and add the button layout to it
        button_container = QVBoxLayout()
        button_container.addLayout(button_layout)

        return button_container
