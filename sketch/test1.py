from functools import partial

from PySide6.QtCore import QSettings
from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QStackedWidget,
    QVBoxLayout,
    QWidget,
)


class MyWidget(QWidget):
    def __init__(self):
        super().__init__()

        self.resize(600, 400)

        # Load the setting value from QSettings
        settings = QSettings()
        layout_visible = settings.value("layout_visibility", defaultValue=0, type=int)
        print(layout_visible)

        # Create a stacked widget to manage the containers
        self.stacked_widget = QStackedWidget()

        # Create the container 0 widget
        container0_widget = QWidget()
        container0_layout = QVBoxLayout(container0_widget)
        container0_label = QLabel("Container 0")
        container0_button = QPushButton("Toggle Container 0 Visibility")
        container0_layout.addWidget(container0_label)
        container0_layout.addWidget(container0_button)

        # Create the container 1 widget
        container1_widget = QWidget()
        container1_layout = QVBoxLayout(container1_widget)
        container1_label = QLabel("Container 1")
        container1_button = QPushButton("Toggle Container 1 Visibility")
        container1_layout.addWidget(container1_label)
        container1_layout.addWidget(container1_button)

        # Create the container 2 widget
        container2_widget = QWidget()
        container2_layout = QVBoxLayout(container2_widget)
        container2_label = QLabel("Container 2")
        container2_button = QPushButton("Toggle Container 2 Visibility")
        container2_layout.addWidget(container2_label)
        container2_layout.addWidget(container2_button)

        # Add the containers to the stacked widget
        self.stacked_widget.addWidget(container0_widget)
        self.stacked_widget.addWidget(container1_widget)
        self.stacked_widget.addWidget(container2_widget)

        # Set the initial visibility state of the containers
        self.stacked_widget.setCurrentIndex(layout_visible)

        # Create a layout for the main widget
        main_layout = QVBoxLayout(self)
        main_layout.addWidget(self.stacked_widget)

        # Connect button clicks to toggle container visibility
        container0_button.clicked.connect(partial(self.setContainerVisibility, 1))
        container1_button.clicked.connect(partial(self.setContainerVisibility, 2))
        container2_button.clicked.connect(partial(self.setContainerVisibility, 0))

    def setContainerVisibility(self, container_index):
        current_index = self.stacked_widget.currentIndex()
        if current_index == container_index:
            return

        self.stacked_widget.setCurrentIndex(container_index)
        print(container_index)
        self.saveVisibilityState(container_index)

    def saveVisibilityState(self, value):
        settings = QSettings()
        settings.setValue("layout_visibility", value)


if __name__ == "__main__":
    app = QApplication([])
    widget = MyWidget()
    widget.show()
    app.exec()
