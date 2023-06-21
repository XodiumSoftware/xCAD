from constants import DEBUG_NAME, LABELS
from PySide6.QtWidgets import QLabel, QVBoxLayout, QWidget


class LabelModule(QWidget):
    def __init__(self, label_index, margins=None, parent=None):
        """
        Initialize the LabelWidget.
        """
        super().__init__(parent)
        self.margins = margins
        self.setup_label_module(label_index)

    def setup_label_module(self, label_index):
        """
        Initialize the label widget.
        """
        layout = QVBoxLayout(self)

        label_data = next(
            (label for label in LABELS if label["index"] == label_index), None
        )

        if label_data:
            label = self.create_label_module(label_data)
            layout.addWidget(label)

        else:
            print(DEBUG_NAME + f'"index" {label_index} not found in LABELS')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)

        self.setLayout(layout)

    def create_label_module(self, label_data):
        """
        Create the label.
        """
        label = QLabel(label_data["title"])
        label.setStyleSheet(label_data["stylesheet"])
        label.setAlignment(label_data["alignment"])
        label.setSizePolicy(*label_data["size_policy"])

        return label
