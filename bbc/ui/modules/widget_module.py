from constants import *
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class WidgetModule(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)

        # Creation of the widget's layout
        wm_layout = QVBoxLayout(self)

        # Add functions to the layout
        wm_layout.addWidget(self.button_setup())
        wm_layout.addWidget(self.widget_setup())

    def widget_setup(self):
        # Creation of a new QWidget object
        widget_setup = QWidget(self)

        # Create a new QFrame object to use as a container for the inner widgets
        inner_container = QFrame(widget_setup)
        inner_container.setObjectName("InnerContainer")
        inner_container_layout = QHBoxLayout(inner_container)
        inner_container_layout.setContentsMargins(*UI_CONTENTS_MARGINS)
        inner_container_layout.setSpacing(10)

        # Create some inner widgets and add them to the inner container layout
        label = QLabel("Hello World", inner_container)
        label.setObjectName("MyLabel")
        inner_container_layout.addWidget(label)

        # Add the inner container to the main widget layout
        wm_layout = QVBoxLayout(widget_setup)
        wm_layout.addWidget(inner_container)

        # Set the stylesheet for the widget
        widget_setup.setStyleSheet(WIDGET_MODULE_STYLESHEET)

        return widget_setup

    def button_setup(self):
        # Create a new QPushButton object
        button = QPushButton("Click Me", self)
        button.setObjectName("MyButton")

        # Connect the clicked signal to the button_clicked function
        button.clicked.connect(self.button_clicked)

        return button

    def button_clicked(self):
        print(DEBUG_NAME + "Button Clicked!")
