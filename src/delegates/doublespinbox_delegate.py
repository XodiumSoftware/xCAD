from PySide6.QtWidgets import QDoubleSpinBox


class DoubleSpinBoxDelegate(QDoubleSpinBox):
    """A class to represent a label delegate."""

    def __init__(self, module_data: dict) -> None:
        """Initialize the label delegate."""
        super().__init__()
        self.setup_double_spin_box(module_data)

    def setup_double_spin_box(self, module_data: dict) -> None:
        """Setup the label delegate."""
        self.setStyleSheet(module_data["stylesheet"])
        self.setMinimum(module_data["min_value"])
        self.setMaximum(module_data["max_value"])
        self.setValue(module_data["default_value"])
        self.setSingleStep(module_data["step"])
        self.setSuffix(module_data["suffix"])
