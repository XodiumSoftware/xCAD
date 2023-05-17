from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *


class WidgetModule(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)

        # Creation of the widget's layout
        wm_layout = QVBoxLayout(self)

        # Add functions to the layout
        wm_layout.addWidget(self.widget_setup())

    def widget_setup(self):
        # Creation of a new QWidget object
        widget_setup = QWidget(self)

        # Create a new QFrame object to use as a container for the inner widgets
        inner_container = QFrame(widget_setup)
        inner_container.setObjectName("InnerContainer")
        inner_container_layout = QHBoxLayout(inner_container)
        inner_container_layout.setContentsMargins(10, 10, 10, 10)
        inner_container_layout.setSpacing(10)

        # Create some inner widgets and add them to the inner container layout
        label = QLabel("Hello World", inner_container)
        label.setObjectName("MyLabel")
        inner_container_layout.addWidget(label)

        button = QPushButton("Click Me", inner_container)
        button.setObjectName("MyButton")
        inner_container_layout.addWidget(button)

        # Add the inner container to the main widget layout
        wm_layout = QVBoxLayout(widget_setup)
        wm_layout.addWidget(inner_container)

        # Set the stylesheet for the widget
        widget_setup.setStyleSheet(
            """
            QWidget {
                background-color: #F0F0F0;
            }

            #InnerContainer {
                background-color: white;
                border: 1px solid black;
                border-radius: 5px;
                padding: 10px;
            }

            QLabel#MyLabel {
                font-size: 24px;
                font-weight: bold;
            }

            QPushButton#MyButton {
                background-color: blue;
                color: white;
                padding: 10px;
                border-radius: 5px;
            }

            QPushButton#MyButton:hover {
                background-color: #0070C0;
            }
        """
        )

        return widget_setup
