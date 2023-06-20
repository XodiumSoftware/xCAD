from constants import DEBUG_NAME, INPUTFIELDS
from PySide6.QtWidgets import QLineEdit, QVBoxLayout, QWidget


class InputFieldModule(QWidget):
    def __init__(self, input_index, margins=None, parent=None):
        """
        Initialize the InputFieldModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.setup_input_field_module(input_index)

    def setup_input_field_module(self, input_index):
        """
        Setup the InputFieldModule.
        """
        layout = QVBoxLayout(self)

        input_data = next(
            (
                input_field
                for input_field in INPUTFIELDS
                if input_field["index"] == input_index
            ),
            None,
        )

        if input_data:
            input_field = self.create_input_field_module(input_data)
            layout.addWidget(input_field)

        else:
            print(DEBUG_NAME + f'"index" {input_index} not found in INPUTFIELDS')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)

        self.setLayout(layout)

    def create_input_field_module(self, input_data):
        """
        Create an input field module.
        """
        input_field = QLineEdit()
        input_field.setPlaceholderText(input_data["placeholder"])
        input_field.setStyleSheet(input_data["stylesheet"])
        input_field.setSizePolicy(*input_data["size_policy"])

        return input_field
