from io import BytesIO
from tkinter import Tk as tkTk

import cairosvg
from AFCDataclasses import EventsDataclass as AFCEventsDataclass
from AFCDataclasses import MatricesDataclass as AFCMatricesDataclass
from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCEvents import Events as AFCEvents
from AFCHandlers import MatrixHandler as AFCMatrixHandler
from PIL import Image, ImageTk
from sv_ttk import SunValleyTtkTheme as SVTtk_SetTheme


class PrimaryUIModule(tkTk):
    """A class used to represent a ui module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        ui, event, matrix = (
            AFCUIDataclass(),
            AFCEventsDataclass(),
            AFCMatricesDataclass(),
        )

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
        # NOTE: Adjust when tk 8.7/9.0 is released,
        # since it will have native svg support.
        self.iconphoto(ui.PRIMARY.ICON, self.svg2png(ui.PRIMARY.ICON_PATH))
        self.minsize(ui.PRIMARY.GEOM_X, ui.PRIMARY.GEOM_Y)
        self.resizable(ui.PRIMARY.RESIZABLE, ui.PRIMARY.RESIZABLE)
        self.title(ui.PRIMARY.TITLE)

        AFCEvents.exit_on_key_press(self, event.KEYS)
        AFCMatrixHandler(matrix.PRIMARY)

        SVTtk_SetTheme.set_theme(ui.PRIMARY.THEME)

    @staticmethod
    def svg2png(path: str):
        """Convert a svg to a photoimage.

        Args:
            path (str): The file path name to use.
        """
        return ImageTk.PhotoImage(
            Image.open(BytesIO(cairosvg.svg2png(url=path)))  # type: ignore
        )
