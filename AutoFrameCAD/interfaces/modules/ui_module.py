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
        self.title(configs.title)
        self.geometry(f'{configs.init_size[0]}x{configs.init_size[1]}')
        if configs.init_visibility:
            self.deiconify()
        else:
            self.withdraw()
        self.minsize(400, 300)
        self.resizable(configs.resizable, configs.resizable)
        self.iconphoto(configs.icon_default, tk.PhotoImage(file=configs.icon))
