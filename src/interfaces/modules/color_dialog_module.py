from PySide6.QtGui import QColor, QIcon, QPalette
from PySide6.QtWidgets import QColorDialog, QPushButton

from interfaces.configs.color_dialog_configs import ColorDialogTypeHints


class ColorDialogModule(QColorDialog):
    """A class to represent a color dialog module."""

    def __init__(
        self, configs: ColorDialogTypeHints, input_module: QPushButton
    ) -> None:
        """Initialize the color dialog module.

        Args:
            configs (ColorDialogTypeHints): The color dialog configs.
            input_module (QPushButton): The input module.
        """
        super().__init__()
        self.properties(configs, input_module)

    def properties(
        self, configs: ColorDialogTypeHints, input_module: QPushButton
    ) -> None:
        """Setup the color dialog module.

        Args:
            configs (ColorDialogTypeHints): The color dialog configs.
            input_module (QPushButton): The input module.
        """
        self.setWindowTitle(configs.Title)
        self.setWindowIcon(QIcon(configs.Icon_path))

        if configs.Size is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(*configs.Size)

        selected_color = self.getColor(
            QColor(input_module.palette().color(QPalette.ColorRole.Window))
        )

        if selected_color.isValid():
            hex_color = selected_color.name(QColor.NameFormat.HexRgb)
            input_module.setStyleSheet(
                f"background-color: {hex_color};" "border: 1px solid lightgray;"
            )
