from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QInputDialog, QPushButton

from interfaces.configs.input_dialog_configs import InputDialogTypeHints


class InputDialogModule(QInputDialog):
    """A class to represent a input dialog module."""

    def __init__(
        self, configs: InputDialogTypeHints, input_module: QPushButton
    ) -> None:
        """Initialize the input dialog module.

        Args:
            configs (InputDialogTypeHints): The input dialog configs.
            input_module (QPushButton): The input module.
        """
        super().__init__()
        self.setup_props(configs, input_module)

    def setup_props(
        self, configs: InputDialogTypeHints, input_module: QPushButton
    ) -> None:
        """Setup the input dialog.

        Args:
            configs (InputDialogTypeHints): The input dialog configs.
            input_module (QPushButton): The input module.
        """
        self.setWindowIcon(QIcon(configs.Icon_path))

        if configs.Size is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(*configs.Size)

        data = [type_name for type_name, _ in configs.Data]
        current_type = input_module.text()

        selected_type, _ = self.getItem(
            self,
            configs.Title,
            configs.Text,
            data,
            data.index(current_type),
            False,
        )

        input_module.setText(selected_type)
