from tkinter import Tk as tkTk
from tkinter import ttk as tkttk

from AFCDataclasses import EventsDataclass as AFCEventsDataclass
from AFCDataclasses import MainUIDataclass as AFCMainUIDataclass
from AFCEvents import Events as AFCEvents
from AFCHandlers import ThemeHandler as AFCThemeHandler


class MainUIModule(tkTk):
    """A class used to represent a ui module."""

    def __init__(self, configs: AFCMainUIDataclass) -> None:
        """Initialize the class.

        Args:
            configs (AFCMainUIDataclass): A configuration.
        """
        super().__init__()
        self.deiconify() if configs.INIT_VISIBILITY else self.withdraw()
        self.geometry(f'{configs.INIT_SIZE[0]}x{configs.INIT_SIZE[1]}')
        # NOTE: Adjust when tk 8.7 is released,
        # since it will have native svg support.
        # self.iconphoto(configs.icon_default, configs.icon)
        self.minsize(configs.INIT_SIZE[0], configs.INIT_SIZE[1])
        self.resizable(configs.RESIZABLE, configs.RESIZABLE)
        self.title(configs.TITLE)
        # BUG: Its centering on dual monitors not the primary one.
        # Events.center_window(self)
        AFCEvents.exit_on_key_press(self, AFCEventsDataclass())
        AFCThemeHandler.set_theme(AFCMainUIDataclass())

        # NOTE: This is a test button.
        button = tkttk.Button(self, text='Click me!')
        button.pack()
