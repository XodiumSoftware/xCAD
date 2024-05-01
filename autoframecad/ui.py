"""This module contains the UI functionality."""

from tkinter import PhotoImage
from tkinter.ttk import Button, Label

from autoframecad.__config__ import (
    DATABASE_FILE,
    PREFERENCES_DATA,
    UI_ICON_FILE,
)
from autoframecad.core import CoreUI
from autoframecad.db_tables import PreferencesTable
from stenlib import Utils


class PrimaryUI(CoreUI):
    """A class used to represent a ui module."""

    def __init__(self: "PrimaryUI") -> None:
        """Initialize the class."""
        super().__init__()
        self.db = Utils.database(DATABASE_FILE)
        self.table = PreferencesTable
        self.db.add_data(self.table, PREFERENCES_DATA)

        self._setup()

    def _setup(self: "PrimaryUI") -> None:
        """Setup the class."""
        self.title("AutoFrameCAD")
        self.theme(self.db.get_data(self.table, "usr_theme"))
        self.visible(state=True)
        self.resizable(width=True, height=True)
        self.iconphoto(True, PhotoImage(file=UI_ICON_FILE))  # noqa: FBT003
        self.geometry(f"{1200}x{800}")
        self.minsize(1200, 800)
        self.events({"<Control-w>": lambda _: self.quit()})
        self.config(padx=5, pady=5)

        self.grid_rowconfigure(1, weight=1)
        self.grid_columnconfigure(1, weight=1)

        self._header()
        self._body()
        self._footer()

    def _header(self: "PrimaryUI") -> None:
        """Create the header."""
        Label(
            self,
            text="BIM Object Configurator",
            font=("", 12, "bold"),
            anchor="center",
        ).grid(row=0, column=0, padx=5, pady=5, columnspan=2)

    def _body(self: "PrimaryUI") -> None:
        """Create the body."""
        Label(
            self,
            text="Properties",
        ).grid(row=1, column=0, padx=5, pady=5, sticky="n")

    def _footer(self: "PrimaryUI") -> None:
        """Create the footer."""
        Label(
            self,
            text="©2023 Structura Engineering",
        ).grid(row=2, column=0, padx=5, pady=5)

        Button(
            self,
            text="Toggle Theme",
            command=self.toggle_theme,
        ).grid(row=2, column=1, padx=5, pady=5, sticky="e")
