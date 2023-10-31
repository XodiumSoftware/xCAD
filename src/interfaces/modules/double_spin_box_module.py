from PySide6.QtWidgets import QDoubleSpinBox

from interfaces.configs.double_spin_box_configs import DoubleSpinBoxTypeHints


class DoubleSpinBoxModule(QDoubleSpinBox):
    """A class to represent a label module."""

    def __init__(self, configs: DoubleSpinBoxTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (DoubleSpinBoxTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: DoubleSpinBoxTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (DoubleSpinBoxTypeHints): A configuration.
        """
        self.setStyleSheet(configs.stylesheet)
        self.setMinimum(configs.min_value)
        self.setMaximum(configs.max_value)
        self.setValue(configs.default_value)
        self.setSingleStep(configs.step)
        self.setSuffix(configs.suffix)
        self.setLayout(configs.layout)
        self.setAlignment(configs.alignment)
        self.setSizePolicy(*configs.size_policy)
