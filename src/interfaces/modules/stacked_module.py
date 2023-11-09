from PySide6.QtCore import Slot
from PySide6.QtWidgets import QStackedWidget

from interfaces.configs.stacked_configs import StackedTypeHints
from interfaces.handlers.signal_handler import SignalHandler


class StackedModule(QStackedWidget):
    """A class used to represent a stacked module."""

    def __init__(self, configs: StackedTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (StackedTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)
        self.signal = SignalHandler()
        self.signal.activateStackedModule.connect(self.switch_stack)
        print(f"stacked module: {self.signal}")

    def setup_props(self, configs: StackedTypeHints) -> None:
        """Setup the properties.

        Args:
            configs (StackedTypeHints): A configuration.
        """
        if isinstance(configs.module_stack, tuple):
            for module in configs.module_stack:
                self.addWidget(module)
        else:
            self.addWidget(configs.module_stack)

    @Slot()
    def switch_stack(self):
        """Go to the next module."""
        self.setCurrentIndex((self.currentIndex() + 1) % self.count())
        print(f"switched to: {self.currentIndex()}")
