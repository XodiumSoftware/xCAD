from tkinter import Tk as tkTk

import sv_ttk
from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCHandlers import EventHandler as AFCEventHandler
from AFCHandlers import MatrixHandler as AFCMatrixHandler
from AFCUtils import Utils as AFCUtils


class PrimaryUI(tkTk):
    """A class used to represent a ui module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        ui = AFCUIDataclass()

        self.title(ui.PRIMARY.TITLE)
        sv_ttk.set_theme(ui.PRIMARY.THEME)
        if ui.PRIMARY.VISIBILITY:
            self.deiconify()
        else:
            self.withdraw()
        self.resizable(ui.PRIMARY.RESIZABLE, ui.PRIMARY.RESIZABLE)
        self.iconphoto(
            ui.PRIMARY.ICON, AFCUtils.svg2png((ui.PRIMARY.ICON_PATH))
        )
        self.geometry(f'{ui.PRIMARY.GEOM_X}x{ui.PRIMARY.GEOM_Y}')
        self.minsize(ui.PRIMARY.GEOM_X, ui.PRIMARY.GEOM_Y)
        AFCEventHandler(self, ui.PRIMARY.EVENTS)
        AFCMatrixHandler(self, ui.PRIMARY.MATRIX)
