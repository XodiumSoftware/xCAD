from enum import Enum

from PySide6.QtWidgets import QDoubleSpinBox


class DoubleSpinBoxModule(QDoubleSpinBox):
    """A class to represent a label module."""

    def __init__(self, configs: Enum) -> None:
        """Initialize the class.

        Args:
            configs (Enum): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: Enum) -> None:
        """Setup the properties.

        Args:
            configs (Enum): A configuration.
        """
        value = configs.value
        self.setStyleSheet(value["stylesheet"])
        self.setMinimum(value["min_value"])
        self.setMaximum(value["max_value"])
        self.setValue(value["default_value"])
        self.setSingleStep(value["step"])
        self.setSuffix(value["suffix"])
