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
        # Create a new QWidget object
        button_widget = QWidget()

        # Create a layout for the widget
        button_layout = QHBoxLayout(button_widget)

        # Create the theme button
        theme_button = QPushButton(button_widget)
        theme_button.setObjectName("ThemeButton")
        theme_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DEFAULT_PATH))

        # Create the viewer button
        viewer_button = QPushButton(button_widget)
        viewer_button.setObjectName("ViewerButton")
        viewer_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        viewer_button.setIcon(QIcon(VIEWER_UI_BUTTON_ICON_LIGHT_PATH))

        # Add the buttons to the widget layout
        button_layout.addWidget(theme_button)
        button_layout.addStretch(1)
        button_layout.addWidget(viewer_button)

        # Connect the clicked signal to the EventsHandler.on_button_clicked_event method
        # theme_button.clicked.connect(self.on_button_clicked_event)
        # viewer_button.clicked.connect(self.on_button_clicked_event)

        # Set the fixed height of the button widget to match the height of the buttons
        button_widget.setFixedHeight(theme_button.height() + 10)

        # Return the button widget
        return button_widget
