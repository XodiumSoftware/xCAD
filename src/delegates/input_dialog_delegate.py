from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QInputDialog, QPushButton


class InputDialogDelegate(QInputDialog):
    """A class to represent a input dialog delegate."""

    def __init__(self, module_data: dict, input_module: QPushButton) -> None:
        """Initialize the input dialog delegate."""
        super().__init__()
        self.setup_input_dialog(module_data, input_module)

    def setup_input_dialog(self, module_data: dict, input_module: QPushButton) -> None:
        """Setup the input dialog."""
        self.setWindowIcon(QIcon(module_data["icon_path"]))

        if module_data["size"] is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(module_data["size"])

        data = [type_name for type_name, _ in module_data["data"]]
        current_type = input_module.text()

        selected_type, _ = self.getItem(
            self,
            module_data["title"],
            module_data["text"],
            data,
            data.index(current_type),
            False,
        )

        input_module.setText(selected_type)
