from PySide6.QtWidgets import QCheckBox


class CheckBoxDelegate(QCheckBox):
    """A class to represent a check box delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the check box delegate."""
        super().__init__()
        self.setup_check_box(module_data)

    def setup_check_box(self, module_data: dict) -> None:
        """Setup the check box delegate."""
        self.setText(module_data["title"])
        self.setStyleSheet(module_data["stylesheet"])
        self.stateChanged.connect(self.update_check_box)

    def update_check_box(self, state: bool) -> None:
        """Update the check box delegate."""
        self.setChecked(state)
        self.update()
