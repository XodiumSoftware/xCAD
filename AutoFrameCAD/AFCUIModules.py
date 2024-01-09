from tkinter import Tk as tkTk
from tkinter import ttk as tkttk

from AFCDataclasses import EventsDataclass as AFCEventsDataclass
from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCEvents import Events as AFCEvents
from sv_ttk import SunValleyTtkTheme as SVTtk_SetTheme


class MainUIModule(tkTk):
    """A class used to represent a ui module."""

    def __init__(self, ui: AFCUIDataclass, event: AFCEventsDataclass) -> None:
        """Initialize the class.

        Args:
            ui (AFCUIDataclass): A configuration.
            event (AFCEventsDataclass): An event handler.
        """
        super().__init__()
        self.deiconify() if ui.PRIMARY.VISIBILITY else self.withdraw()
        self.geometry(f'{ui.PRIMARY.GEOM_X}x{ui.PRIMARY.GEOM_Y}')
        # NOTE: Adjust when tk 8.7 is released,
        # since it will have native svg support.
        # self.iconphoto(ui.icon_default, ui.icon)
        self.minsize(ui.PRIMARY.GEOM_X, ui.PRIMARY.GEOM_Y)
        self.resizable(ui.PRIMARY.RESIZABLE, ui.PRIMARY.RESIZABLE)
        self.title(ui.PRIMARY.TITLE)

        tkttk.Button(
            self,
            text='Click me!',
            command=lambda: SVTtk_SetTheme.toggle_theme(),
        ).pack()  # NOTE: This is a test button.

        AFCEvents.exit_on_key_press(self, event.KEYS)

        SVTtk_SetTheme.set_theme(ui.PRIMARY.THEME)
