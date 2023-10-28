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
        self.setStyleSheet(configs.Stylesheet)
        self.setMinimum(configs.Min_value)
        self.setMaximum(configs.Max_value)
        self.setValue(configs.Default_value)
        self.setSingleStep(configs.Step)
        self.setSuffix(configs.Suffix)
        self.setLayout(configs.Layout)
        self.setAlignment(configs.Alignment)
        self.setSizePolicy(*configs.SizePolicy)
