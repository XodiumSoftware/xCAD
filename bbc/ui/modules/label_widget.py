from constants import LABELS
from PySide6.QtWidgets import QLabel, QVBoxLayout, QWidget


class LabelWidget(QWidget):
    def __init__(self, label_index, parent=None):
        """
        Initialize the LabelWidget.
        """
        super().__init__(parent)
        self.init_label_widget(label_index)

    def init_label_widget(self, label_index):
        """
        Initialize the label widget.
        """
        layout = QVBoxLayout(self)

        label_data = next(
            (label for label in LABELS if label["index"] == label_index), None
        )

        if label_data:
            label = self.create_label(label_data)
            layout.addWidget(label)

        self.setLayout(layout)

    def create_label(self, label_data):
        """
        Create the label.
        """
        label = QLabel(label_data["title"])
        label.setStyleSheet(label_data["stylesheet"])
        label.setAlignment(label_data["alignment"])
        # Apply any additional properties or configurations to the label here
        return label
