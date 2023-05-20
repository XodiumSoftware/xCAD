import functools

from constants import BUTTONS
from handlers.events_handler import EventsHandler
from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QHBoxLayout,
    QPushButton,
    QSizePolicy,
    QSpacerItem,
    QWidget,
)


class ButtonWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.button_container_0 = None
        self.button_container_1 = None
        self.initButtonWidget()

    def initButtonWidget(self):
        # Create the first button layout with an expanding spacing
        button_container_0 = self.createButtonLayout(
            [0, 1], alignment=Qt.AlignmentFlag.AlignLeft, spacing=-1
        )

        # Create the second button layout with spacing of 0
        button_container_1 = self.createButtonLayout(
            [2, 3], alignment=Qt.AlignmentFlag.AlignRight, spacing=0
        )

        # Create a container widget for each button layout
        self.button_container_0 = QWidget()
        self.button_container_0.setLayout(button_container_0)

        self.button_container_1 = QWidget()
        self.button_container_1.setLayout(button_container_1)

    def createButtonLayout(self, button_indices, alignment, spacing):
        container_widget = QWidget()
        button_layout = QHBoxLayout(container_widget)
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

                button_layout.addWidget(button)

                if button_index != button_indices[-1]:
                    if spacing == -1:
                        spacer_item = QSpacerItem(
                            button.sizeHint().width(),
                            button.sizeHint().height(),
                            QSizePolicy.Policy.Expanding,
                            QSizePolicy.Policy.Minimum,
                        )
                        button_layout.addItem(spacer_item)
                    else:
                        button_layout.addSpacing(spacing)

                button.clicked.connect(
                    functools.partial(
                        EventsHandler().on_button_clicked_event, button_data["index"]
                    )
                )

        return button_layout
