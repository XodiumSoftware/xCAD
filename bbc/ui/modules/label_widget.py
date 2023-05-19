from constants import LABELS
from PySide6.QtWidgets import QLabel, QVBoxLayout, QWidget


class LabelWidget(QWidget):
    def __init__(self, label_index, parent=None):
        super().__init__(parent)
        self.initLabelWidget(label_index)

    def initLabelWidget(self, label_index):
        layout = QVBoxLayout(self)

        label_data = next(
            (label for label in LABELS if label["index"] == label_index), None
        )

        if label_data:
            label = self.createLabel(label_data)
            layout.addWidget(label)

        self.setLayout(layout)

    def createLabel(self, label_data):
        label = QLabel(label_data["title"])
        label.setStyleSheet(label_data["stylesheet"])
        label.setAlignment(label_data["alignment"])
        # Apply any additional properties or configurations to the label here
        return label
