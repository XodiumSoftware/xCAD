from tkinter import ttk as tkttk

import sv_ttk
from AFCConstants import UI_ICON_PATH
from AFCDatabase import Database as AFCDatabase
from AFCHandlers import UIHandler as AFCUIHandler
from AFCUtils import Utils as AFCUtils


class PrimaryUI(AFCUIHandler):
    """A class used to represent a ui module."""

    def __init__(self) -> None:
        """Initialize the class."""
        super().__init__()
        self.title("AutoFrameCAD")
        self.theme("dark")
        self.visible(True)
        self.resizable(True, True)
        # NOTE: Adjust when tk 8.7/9.0 is released,
        # since it will have native svg support.
        self.iconphoto(True, AFCUtils.svg2png(str(UI_ICON_PATH)))
        self.geometry(f"{1200}x{800}")
        self.minsize(1200, 800)
        self.events({"<Control-w>": lambda _: self.quit()})
        self.config(padx=10, pady=10)
        self.matrix(
            matrix=[
                [
                    tkttk.Label(text="Structura Engineering", anchor="center"),
                    None,
                ],
                [
                    tkttk.Button(
                        text="Add Data",
                        command=AFCDatabase().add_data,
                    ),
                    tkttk.Button(
                        text="Switch Theme", command=sv_ttk.toggle_theme
                    ),
                ],
            ],
            grid_options={"sticky": "nsew"},
        )
