import sys

from PySide6.QtCore import QCoreApplication, QSettings, Qt
from PySide6.QtWidgets import (
    QApplication,
    QHBoxLayout,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Widget Visibility Example")

        # Create the main widget and layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Random names for each group
        names_group1 = ["John", "Alice", "Bob", "Jane", "Michael"]
        names_group2 = ["Olivia", "Charlie", "Emma", "David", "Sophia"]

        # Create the first group of labels
        self.group1_layout = QHBoxLayout()
        self.group1_labels = []
        for i, label_name in enumerate(names_group1):
            label = QLabel()
            label.setText(label_name)
            self.group1_labels.append(label)
            self.group1_layout.addWidget(label)
        self.layout.addLayout(self.group1_layout)

        # Create the second group of labels
        self.group2_layout = QHBoxLayout()
        self.group2_labels = []
        for i, label_name in enumerate(names_group2):
            label = QLabel()
            label.setText(label_name)
            self.group2_labels.append(label)
            self.group2_layout.addWidget(label)
        self.layout.addLayout(self.group2_layout)

        # Create the button
        self.group_button = QPushButton()
        self.layout.addWidget(self.group_button)

        # Connect button signal to slot
        self.group_button.clicked.connect(self.toggle_group)

        # Load visibility state from settings
        self.settings = QSettings("WidgetVisibilityExample", "MainWindow")
        self.current_group = self.settings.value("current_group", 1, int)
        self.show_group()

        # Update button text based on current group
        if self.current_group == 1:
            self.group_button.setText("Show Group 2")
        else:
            self.group_button.setText("Show Group 1")

    def show_group(self):
        group_labels = (
            self.group1_labels if self.current_group == 1 else self.group2_labels
        )
        other_labels = (
            self.group2_labels if self.current_group == 1 else self.group1_labels
        )

        for label in group_labels:
            label.setVisible(True)
        for label in other_labels:
            label.setVisible(False)

        self.settings.setValue("current_group", self.current_group)

    def toggle_group(self):
        if self.current_group == 1:
            self.current_group = 2
            self.group_button.setText("Show Group 1")
        else:
            self.current_group = 1
            self.group_button.setText("Show Group 2")

        self.show_group()

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
