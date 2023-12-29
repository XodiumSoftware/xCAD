from tkinter import Entry, Tk, ttk

from AFCDataclasses import EventsDataclass, MainUIDataclass
from AFCEvents import Events


class MainUIModule(Tk, ttk.Style):
    """A class used to represent a ui module."""

    def __init__(self, configs: MainUIDataclass) -> None:
        """Initialize the class.

        Args:
            configs (MainUIDataclass): A configuration.
        """
        super().__init__()
        self.configure(background=configs.background_color)
        self.deiconify() if configs.init_visibility else self.withdraw()
        self.geometry(f'{configs.init_size[0]}x{configs.init_size[1]}')
        # NOTE: Adjust when tk 8.7 is released,
        # since it will have native svg support.
        # self.iconphoto(configs.icon_default, configs.icon)
        self.minsize(configs.init_size[0], configs.init_size[1])
        self.resizable(configs.resizable, configs.resizable)
        self.theme_use(configs.theme)
        self.title(configs.title)
        # TODO: make this its own module.
        Entry(self).pack()

        # BUG: Its centering on dual monitors not the primary one.
        # Events.center_window(self)
        Events.exit_on_key_press(self, EventsDataclass())
