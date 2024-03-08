from io import BytesIO
from pathlib import Path
from tkinter import Tk as tkTk

import cairosvg  # type: ignore
import sv_ttk
from AFCConstants import DATABASE_PATH
from AFCDatabase import Database as AFCDatabase
from AFCDataclasses import EventsDataclass as AFCEventsDataclass
from AFCDataclasses import MatrixDataclass as AFCMatrixDataclass
from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCEvents import Events as AFCEvents
from AFCHandlers import MatrixHandler as AFCMatrixHandler
from PIL import Image, ImageTk


class PrimaryUIModule(tkTk):
    """A class used to represent a ui module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        ui, event, matrix = (
            AFCUIDataclass(),
            AFCEventsDataclass(),
            AFCMatrixDataclass(),
        )

        self.setup(ui, event, matrix)

    def setup(
        self,
        ui: AFCUIDataclass,
        event: AFCEventsDataclass,
        matrix: AFCMatrixDataclass,
    ):
        """Setup the ui.

        Args:
            ui (AFCUIDataclass): The ui to use.
            event (AFCEventsDataclass): The event to use.
            matrix (AFCMatrixDataclass): The matrix to use.
        """
        if ui.PRIMARY.VISIBILITY:
            self.deiconify()
        else:
            self.withdraw()
        self.geometry(f'{ui.PRIMARY.GEOM_X}x{ui.PRIMARY.GEOM_Y}')
        self.iconphoto(ui.PRIMARY.ICON, self.svg2png((ui.PRIMARY.ICON_PATH)))
        self.minsize(ui.PRIMARY.GEOM_X, ui.PRIMARY.GEOM_Y)
        self.resizable(ui.PRIMARY.RESIZABLE, ui.PRIMARY.RESIZABLE)
        self.title(ui.PRIMARY.TITLE)

        db = AFCDatabase(DATABASE_PATH)
        # TODO: Make it so that it will load all of them.
        db.add_data('LumberTypes.json')

        AFCEvents.exit_on_key_press(self, event.EXIT_KEYS)
        AFCMatrixHandler(self, matrix.PRIMARY)

        sv_ttk.set_theme(ui.PRIMARY.THEME)

    # NOTE: Adjust when tk 8.7/9.0 is released,
    # since it will have native svg support.
    @staticmethod
    def svg2png(path: Path):
        """Convert a svg to a photoimage.

        Args:
            path (Path): The file path name to use.
        """
        return ImageTk.PhotoImage(
            Image.open(BytesIO(cairosvg.svg2png(url=str(path))))  # type: ignore
        )
