import tkinter as tk

from interfaces.configs.ui_configs import UITypeHints


class MainUIModule(tk.Tk):
    """A class used to represent a ui module."""

    def __init__(self, configs: UITypeHints) -> None:
        """Initialize the class.

        Args:
            configs (UITypeHints): A configuration.
        """
        super().__init__()
        self.setup_props(configs)

    def setup_props(self, configs: UITypeHints) -> None:
        """Setup the properties.

        Args:
            configs (UITypeHints): A configuration.
        """

    def setup_actions(self):
        """Setup the actions."""
        # TODO: Implement the equivalent of,
        # Events.quit_on_key_press_event for tkinter.
