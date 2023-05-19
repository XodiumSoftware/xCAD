from constants import (
    MAIN_UI_BUTTON_SIZE,
    THEME_BUTTON_ICON_DEFAULT_PATH,
    VIEWER_UI_BUTTON_ICON_LIGHT_PATH,
)
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QHBoxLayout, QPushButton, QWidget


class ButtonWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initButtonWidget()

    def initButtonWidget(self):
        # Create the layout for the widget
        button_layout = QHBoxLayout(self)

        # Create and add buttons to the layout
        self.addPushButton(button_layout, "ThemeButton", THEME_BUTTON_ICON_DEFAULT_PATH)
        button_layout.addStretch(1)
        self.addPushButton(
            button_layout, "ViewerButton", VIEWER_UI_BUTTON_ICON_LIGHT_PATH
        )

    def addPushButton(self, layout, object_name, icon_path):
        # Create the push button
        button = QPushButton(self)
        button.setObjectName(object_name)
        button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        button.setIcon(QIcon(icon_path))

        # Add the button to the layout
        layout.addWidget(button)

        # Connect the clicked signal to the EventsHandler.on_button_clicked_event method
        button.clicked.connect(self.on_button_clicked_event)

    def on_button_clicked_event(self):
        # Handle button click event
        pass
