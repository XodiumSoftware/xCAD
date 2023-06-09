from functools import partial

from PySide6.QtCore import QSettings
from PySide6.QtWidgets import QApplication, QLabel, QPushButton, QVBoxLayout, QWidget


class MyWidget(QWidget):
    def __init__(self):
        super().__init__()

        self.resize(600, 400)

        # Load the setting value from QSettings
        settings = QSettings()
        layout_visible = settings.value("layout_visibility", defaultValue=0, type=int)

        # Create the container 0 widget
        self.container0_widget = QWidget()
        container0_layout = QVBoxLayout(self.container0_widget)
        container0_label = QLabel("Container 0")
        container0_button = QPushButton("Toggle Container 0 Visibility")
        container0_layout.addWidget(container0_label)
        container0_layout.addWidget(container0_button)

        # Create the container 1 widget
        self.container1_widget = QWidget()
        container1_layout = QVBoxLayout(self.container1_widget)
        container1_label = QLabel("Container 1")
        container1_button = QPushButton("Toggle Container 1 Visibility")
        container1_layout.addWidget(container1_label)
        container1_layout.addWidget(container1_button)

        # Create the container 2 widget
        self.container2_widget = QWidget()
        container2_layout = QVBoxLayout(self.container2_widget)
        container2_label = QLabel("Container 2")
        container2_button = QPushButton("Toggle Container 2 Visibility")
        container2_layout.addWidget(container2_label)
        container2_layout.addWidget(container2_button)

        # Set the initial visibility state of the containers
        self.container0_widget.setVisible(layout_visible == 0)
        self.container1_widget.setVisible(layout_visible == 1)
        self.container2_widget.setVisible(layout_visible == 2)

        # Create a layout for the main widget
        main_layout = QVBoxLayout(self)
        main_layout.addWidget(self.container0_widget)
        main_layout.addWidget(self.container1_widget)
        main_layout.addWidget(self.container2_widget)

        # Connect button clicks to toggle container visibility
        container0_button.clicked.connect(partial(self.toggleContainerVisibility, 0))
        container1_button.clicked.connect(partial(self.toggleContainerVisibility, 1))
        container2_button.clicked.connect(partial(self.toggleContainerVisibility, 2))

    def toggleContainerVisibility(self, container_index):
        containers = [
            self.container0_widget,
            self.container1_widget,
            self.container2_widget,
        ]

        # Hide all containers except the clicked one
        for index, container_widget in enumerate(containers):
            container_widget.setVisible(index == container_index)

        self.saveVisibilityState(container_index)

    def saveVisibilityState(self, value):
        settings = QSettings()
        settings.setValue("layout_visibility", value)


if __name__ == "__main__":
    app = QApplication([])
    widget = MyWidget()
    widget.show()
    app.exec()
