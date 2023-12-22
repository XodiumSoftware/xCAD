import tkinter as tk
from tkinter import ttk

from interfaces.configs.ui_configs import UIConfig


class MainUIModule(tk.Tk, ttk.Style):
    """A class used to represent a ui module."""

    def __init__(self, configs: UIConfig) -> None:
        """Initialize the class.

        Args:
            configs (UIConfig): A configuration.
        """
        super().__init__()
        self.configure(background=configs.background_color)
        self.deiconify() if configs.init_visibility else self.withdraw()
        self.geometry(f'{configs.init_size[0]}x{configs.init_size[1]}')
        self.iconphoto(configs.icon_default, tk.PhotoImage(file=configs.icon))
        self.minsize(configs.init_size[0], configs.init_size[1])
        self.resizable(configs.resizable, configs.resizable)
        self.theme_use(configs.theme)
        self.title(configs.title)
