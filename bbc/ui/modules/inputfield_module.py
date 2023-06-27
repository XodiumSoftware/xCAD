from constants import DEBUG_NAME, INPUTFIELDS
from PySide6.QtWidgets import QLineEdit, QVBoxLayout, QWidget


class InputFieldModule(QWidget):
    def __init__(
        self, input_index, margins=None, alignment=None, visible=None, parent=None
    ):
        """
        Initialize the InputFieldModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.alignment = alignment
        self.visible = visible
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
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if self.alignment is not None:
            layout.setAlignment(*self.alignment)

        if self.visible is not None:
            self.setVisible(self.visible)

        self.setLayout(layout)

    def create_input_field_module(self, input_data):
        """
        Create an input field module.
        """
        input_field = QLineEdit()
        input_field.setPlaceholderText(input_data["placeholder"])
        input_field.setStyleSheet(input_data["stylesheet"])

        return input_field

    def toggle_visibility(self):
        """
        Toggle the visibility of the input field.
        """
        self.setVisible(not self.isVisible())
