"""This module contains the UI functionality."""

from tkinter import PhotoImage
from tkinter.ttk import Button, Frame, Label, PanedWindow, Treeview

from autoframecad.__config__ import UI_ICON_FILE
from autoframecad.core import CoreUI


class PrimaryUI(CoreUI):
    """A class used to represent a ui module."""

    def __init__(self: "PrimaryUI") -> None:
        """Initialize the class."""
        super().__init__()
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
        self.events({"<Control-q>": lambda _: self.quit()})
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

        header_title = Label(
            header,
            text="BIM Object Configurator",
            font=("", 12, "bold"),
            anchor="center",
        )
        header_title.grid(row=0, column=0, columnspan=2, sticky="ew")

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

        body_props_tree = Treeview(
            body_props,
            columns=("Property", "Value"),
            show="headings",
        )
        body_props_tree.heading("Property", text="Property")
        body_props_tree.heading("Value", text="Value")

        body_props_tree.grid(row=0, column=0, columnspan=2, sticky="nsew")

        body_viewer = Frame(body)

        body.add(body_props)  # type: ignore[assignment]
        body.add(body_viewer)  # type: ignore[assignment]

    def _footer(self: "PrimaryUI") -> None:
        """Create the footer."""
        footer = Frame(self, padding=5)
        footer.grid(row=2, column=0, columnspan=2, sticky="nsew")
        footer.grid_rowconfigure(0, weight=1)
        footer.grid_columnconfigure(0, weight=1)

        footer_copyright = Label(
            footer,
            text="©2023 Structura Engineering",
        )
        footer_copyright.grid(row=0, column=0, sticky="w")

        self.footer_theme_button = Button(
            footer,
            image=self.dark_mode_icon
            if self.get_theme() == "dark"
            else self.light_mode_icon,  # type: ignore[arg-type]
            command=lambda: self.toggle_theme(self.footer_theme_button),
        )
        self.footer_theme_button.grid(row=0, column=1, sticky="e")
