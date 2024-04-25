"""This module contains the UI code for AutoFrameCAD."""

from autoframecad.__config__ import UI_ICON_FILE
from autoframecad.core import CoreUI
from stenlib import Utils


class PrimaryUI(CoreUI):
    """A class used to represent a ui module."""

    def __init__(self: "PrimaryUI") -> None:
        """Initialize the class."""
        super().__init__()
        self.title("AutoFrameCAD")
        self.theme("dark")
        self.visible(state=True)
        self.resizable(width=True, height=True)
        # NOTE: Adjust when tk 8.7/9.0 is released,
        # since it will have native svg support.
        self.iconphoto(
            True,  # type: ignore[default-arg-before-posarg]
            Utils.convert.svg2png(UI_ICON_FILE),  # type: ignore[arg-type]
        )
        self.geometry(f"{1200}x{800}")
        self.minsize(1200, 800)
        self.events({"<Control-w>": lambda _: self.quit()})
        self.config(padx=10, pady=10)
        # self.matrix(
        #     matrix=[
        #         [
        #             tkttk.Label(text="Structura Engineering", anchor="center"),
        #             None,
        #         ],
        #         [
        #             None,
        #             tkttk.Button(
        #                 text="Switch Theme",
        #                 command=self.toggle_theme,
        #             ),
        #         ],
        #     ],
        #     grid_options={"sticky": "nsew"},
        # )
