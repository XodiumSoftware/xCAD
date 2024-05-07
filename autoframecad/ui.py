"""This module contains the UI functionality."""

from tkinter import PhotoImage
from tkinter.ttk import Button, Frame, Label, PanedWindow, Treeview

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
        header = Frame(self, padding=5)
        header.grid(row=0, column=0, columnspan=2, sticky="nsew")
        header.grid_rowconfigure(0, weight=1)
        header.grid_columnconfigure(0, weight=1)

        Label(
            header,
            text="BIM Object Configurator",
            font=("", 12, "bold"),
            anchor="center",
        ).grid(row=0, column=0, columnspan=2, sticky="ew")

    def _body(self: "PrimaryUI") -> None:
        """Create the body."""
        body = PanedWindow(self, orient="horizontal")
        body.grid(row=1, column=0, columnspan=2, sticky="nsew")
        body.grid_rowconfigure(0, weight=1)
        body.grid_columnconfigure(0, weight=1)
        body.grid_columnconfigure(1, weight=1)

        body_props = Frame(body, padding=5)
        body_props.grid_rowconfigure(0, weight=1)
        body_props.grid_columnconfigure(0, weight=1)

        properties = {
            "Object": "Wall",
            "Position": "0, 0, 0",
            "Dimensions": "10 x 10 x 10",
        }
        tree = Treeview(
            body_props,
            columns=("Property", "Value"),
            show="headings",
        )
        tree.heading("Property", text="Property")
        tree.heading("Value", text="Value")
        for key, value in properties.items():
            tree.insert("", "end", values=(key, value))
        tree.grid(row=0, column=0, columnspan=2, sticky="nsew")

        body_viewer = Frame(body)

        body.add(body_props)  # type: ignore[assignment]
        body.add(body_viewer)  # type: ignore[assignment]

    def _footer(self: "PrimaryUI") -> None:
        """Create the footer."""
        footer = Frame(self, padding=5)
        footer.grid(row=2, column=0, columnspan=2, sticky="nsew")
        footer.grid_rowconfigure(0, weight=1)
        footer.grid_columnconfigure(0, weight=1)

        Label(
            footer,
            text="©2023 Structura Engineering",
        ).grid(row=0, column=0, sticky="w")

        Button(
            footer,
            text="Toggle Theme",
            command=self.toggle_theme,
        ).grid(row=0, column=1, sticky="e")
