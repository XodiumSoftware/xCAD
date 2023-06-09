from PySide6.QtCore import QSettings
from PySide6.QtWidgets import QApplication, QLabel, QPushButton, QVBoxLayout, QWidget


class MyWidget(QWidget):
    def __init__(self):
        super().__init__()

        # Load the setting value from QSettings
        settings = QSettings()
        widget_visible = settings.value(
            "widget_visibility", defaultValue=False, type=bool
        )

        # Create a QLabel widget and set its visibility based on the loaded setting
        self.widget = QLabel("My Widget")
        self.widget.setVisible(bool(widget_visible))  # Ensure a boolean value is passed

        # Create a button to toggle visibility
        self.toggle_button = QPushButton("Toggle Visibility")
        self.toggle_button.clicked.connect(self.toggleVisibility)

        # Create a layout and add the widgets to it
        layout = QVBoxLayout()
        layout.addWidget(self.widget)
        layout.addWidget(self.toggle_button)
        self.setLayout(layout)

        # Save the visibility state of the widget when it changes
        self.toggle_button.clicked.connect(self.saveVisibilityState)

    def toggleVisibility(self):
        current_visibility = self.widget.isVisible()
        self.widget.setVisible(not current_visibility)

    def saveVisibilityState(self):
        settings = QSettings()
        settings.setValue("widget_visibility", self.widget.isVisible())


if __name__ == "__main__":
    app = QApplication([])
    widget = MyWidget()
    widget.show()
    app.exec()
