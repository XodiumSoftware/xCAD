import sys
import random

from PySide6.QtCore import Qt, QCoreApplication, QSettings
from PySide6.QtWidgets import (
    QApplication,
    QDoubleSpinBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QPushButton,
    QStackedWidget,
    QVBoxLayout,
    QWidget,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Widget Visibility Example")

        # Load visibility state from settings
        self.settings = QSettings("WidgetVisibilityExample", "MainWindow")
        self.visibility_state = self.settings.value("visibility_state", 1, int)

        self.setup_main_window()
        self.setup_groups()
        self.show_group()

        # Update button text based on current group
        if self.visibility_state == 1:
            self.group_button.setText("Show Group 2")
        else:
            self.group_button.setText("Show Group 1")

    def setup_main_window(self):
        # Create the main widget and layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Create the button
        self.group_button = QPushButton()
        self.layout.addWidget(self.group_button)

        # Connect button signal to slot
        self.group_button.clicked.connect(self.toggle_group)

        # Create a stacked widget to hold the groups
        self.stacked_widget = QStackedWidget()
        self.layout.addWidget(self.stacked_widget)

    def setup_groups(self):
        # Random names for each group
        names_group1 = ["John", "Alice", "Bob", "Jane", "Michael"]
        names_group2 = ["Olivia", "Charlie", "Emma", "David", "Sophia"]

        # Create the first group container and layout
        group1_container = QWidget()
        group1_layout = QVBoxLayout(group1_container)

        # Create labels, widgets, and input fields for group 1
        for label_name in names_group1:
            label = QLabel()
            label.setText(label_name)
            group1_layout.addWidget(label)

            widget = QWidget()
            widget.setStyleSheet(
                "background-color: rgb({}, {}, {});".format(
                    random.randint(0, 255),
                    random.randint(0, 255),
                    random.randint(0, 255),
                )
            )
            group1_layout.addWidget(widget)

            input_field = QLineEdit()
            group1_layout.addWidget(input_field)

            double_spin_box = QDoubleSpinBox()
            group1_layout.addWidget(double_spin_box)

        # Add the first group container to the stacked widget
        self.stacked_widget.addWidget(group1_container)

        # Create the second group container and layout
        group2_container = QWidget()
        group2_layout = QVBoxLayout(group2_container)

        # Create labels, widgets, and input fields for group 2
        for label_name in names_group2:
            label = QLabel()
            label.setText(label_name)
            group2_layout.addWidget(label)

            widget = QWidget()
            widget.setStyleSheet(
                "background-color: rgb({}, {}, {});".format(
                    random.randint(0, 255),
                    random.randint(0, 255),
                    random.randint(0, 255),
                )
            )
            group2_layout.addWidget(widget)

            input_field = QLineEdit()
            group2_layout.addWidget(input_field)

            double_spin_box = QDoubleSpinBox()
            group2_layout.addWidget(double_spin_box)

        # Add the second group container to the stacked widget
        self.stacked_widget.addWidget(group2_container)

    def show_group(self):
        self.stacked_widget.setCurrentIndex(self.visibility_state)

    def toggle_group(self):
        if self.visibility_state == 1:
            self.visibility_state = 0
            self.group_button.setText("Show Group 1")
        else:
            self.visibility_state = 1
            self.group_button.setText("Show Group 2")

        self.show_group()
        self.settings.setValue("visibility_state", self.visibility_state)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Escape or (
            event.key() == Qt.Key_Q and event.modifiers() == Qt.ControlModifier
        ):
            QCoreApplication.quit()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
