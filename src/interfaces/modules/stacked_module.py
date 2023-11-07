from PySide6.QtCore import Slot
from PySide6.QtWidgets import QStackedWidget

from interfaces.configs.stacked_configs import StackedTypeHints


class StackedModule(QStackedWidget):
    """A class used to represent a stacked module."""

    def __init__(self, configs: StackedTypeHints) -> None:
        """Initialize the class.

        Args:
            configs (StackedTypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

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

    # TODO

    @Slot()
    def switch_module(self):
        """Go to the next module."""
        self.setCurrentIndex((self.currentIndex() + 1) % self.count())
