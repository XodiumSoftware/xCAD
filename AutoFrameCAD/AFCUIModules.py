from tkinter import Tk as tkTk

from AFCDataclasses import EventsDataclass as AFCEventsDataclass
from AFCDataclasses import MatricesDataclass as AFCMatricesDataclass
from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCEvents import Events as AFCEvents
from AFCHandlers import MatrixHandler as AFCMatrixHandler
from sv_ttk import SunValleyTtkTheme as SVTtk_SetTheme


class PrimaryUIModule(tkTk):
    """A class used to represent a ui module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        ui = AFCUIDataclass()
        event = AFCEventsDataclass()
        matrix = AFCMatricesDataclass()

        self.setup(ui, event, matrix)

    def setup(
        self,
        ui: AFCUIDataclass,
        event: AFCEventsDataclass,
        matrix: AFCMatricesDataclass,
    ):
        """Setup the ui.

        Args:
            ui (AFCUIDataclass): The ui to use.
            event (AFCEventsDataclass): The event to use.
            matrix (AFCMatricesDataclass): The matrix to use.
        """
        self.deiconify() if ui.PRIMARY.VISIBILITY else self.withdraw()
        self.geometry(f'{ui.PRIMARY.GEOM_X}x{ui.PRIMARY.GEOM_Y}')
        # NOTE: Adjust when tk 8.7 is released,
        # since it will have native svg support.
        # self.iconphoto(ui.icon_default, ui.icon)
        self.minsize(ui.PRIMARY.GEOM_X, ui.PRIMARY.GEOM_Y)
        self.resizable(ui.PRIMARY.RESIZABLE, ui.PRIMARY.RESIZABLE)
        self.title(ui.PRIMARY.TITLE)

        AFCEvents.exit_on_key_press(self, event.KEYS)
        AFCMatrixHandler(matrix.PRIMARY)

        SVTtk_SetTheme.set_theme(ui.PRIMARY.THEME)
