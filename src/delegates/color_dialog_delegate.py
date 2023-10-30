from PySide6.QtGui import QColor, QIcon, QPalette
from PySide6.QtWidgets import QColorDialog, QPushButton


# TODO
class ColorDialogDelegate(QColorDialog):
    """A class to represent a color dialog delegate."""

    def __init__(self, module_data: dict, input_module: QPushButton) -> None:
        """Initialize the color dialog delegate."""
        super().__init__()
        self.properties(module_data, input_module)

    def properties(self, module_data: dict, input_module: QPushButton) -> None:
        """Setup the color dialog delegate."""
        self.setWindowTitle(module_data["title"])
        self.setWindowIcon(QIcon(module_data["icon_path"]))

        if module_data["size"] is None:
            self.setFixedSize(self.sizeHint())
        else:
            self.setFixedSize(module_data["size"])

        selected_color = self.getColor(
            QColor(input_module.palette().color(QPalette.ColorRole.Window))
        )

        if selected_color.isValid():
            hex_color = selected_color.name(QColor.NameFormat.HexRgb)
            input_module.setStyleSheet(
                f"background-color: {hex_color};" "border: 1px solid lightgray;"
            )
