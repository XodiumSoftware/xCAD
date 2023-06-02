from constants import CHECKBOXES
from PySide6.QtWidgets import QCheckBox, QVBoxLayout, QWidget


class CheckBoxModule(QWidget):
    def __init__(self, checkbox_index, parent=None):
        super().__init__(parent)
        self.init_checkbox_module(checkbox_index)

    def init_checkbox_module(self, checkbox_index):
        layout = QVBoxLayout(self)

        checkbox_data = next(
            (
                checkbox
                for checkbox in CHECKBOXES
                if checkbox["index"] == checkbox_index
            ),
            None,
        )

        if checkbox_data:
            checkbox = self.create_checkbox_module(checkbox_data)
            layout.addWidget(checkbox)

        self.setLayout(layout)

    def create_checkbox_module(self, checkbox_data):
        checkbox = QCheckBox(checkbox_data["title"])
        checkbox.setChecked(checkbox_data["checked"])
        checkbox.setStyleSheet(checkbox_data["stylesheet"])
        checkbox.setSizePolicy(*checkbox_data["size_policy"])
        return checkbox
