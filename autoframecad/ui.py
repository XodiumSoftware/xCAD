"""This module contains the UI functionality."""

from tkinter import PhotoImage
from tkinter.ttk import Button, Frame, Label, PanedWindow, Treeview

import ifcopenshell  # type: ignore[attr-defined]
import sv_ttk
from PIL import Image, ImageTk

from autoframecad.__config__ import (
    DARK_MODE_ICON_FILE,
    DATABASE_FILE,
    LIGHT_MODE_ICON_FILE,
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

        self.dark_mode_icon = ImageTk.PhotoImage(
            Image.open(DARK_MODE_ICON_FILE).resize((20, 20), Image.LANCZOS),  # type: ignore[assignment]
        )
        self.light_mode_icon = ImageTk.PhotoImage(
            Image.open(LIGHT_MODE_ICON_FILE).resize((20, 20), Image.LANCZOS),  # type: ignore[assignment]
        )

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

        ifc_file = ifcopenshell.open("test.ifc")  # type: ignore[no-untyped-call]

        # TODO: in the type parameter, add the IFC class we want to extract.
        for product in ifc_file.by_type(type="IFCWALL", include_subtypes=True):
            parent_id = body_props_tree.insert(
                "",
                "end",
                values=(product.is_a(), product.GlobalId),
            )
            for prop_set in product.IsDefinedBy:  # type: ignore[attr-defined]
                if prop_set.is_a("IfcRelDefinesByProperties"):
                    for (
                        prop
                    ) in prop_set.RelatingPropertyDefinition.HasProperties:
                        body_props_tree.insert(
                            parent_id,
                            "end",
                            values=(
                                prop.Name,
                                prop.NominalValue.wrappedValue
                                if prop.NominalValue
                                else "",
                            ),
                        )

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
            if sv_ttk.get_theme() == "dark"
            else self.light_mode_icon,  # type: ignore[arg-type]
            command=self._toggle_theme,
        )
        self.footer_theme_button.grid(row=0, column=1, sticky="e")

    def _toggle_theme(self: "PrimaryUI") -> None:
        """Toggle the theme of the UI."""
        sv_ttk.toggle_theme()
        self.db.set_data(self.table, {"usr_theme": sv_ttk.get_theme()})
        self._update_theme_button()

    def _update_theme_button(self: "PrimaryUI") -> None:
        """Update the theme button."""
        if sv_ttk.get_theme() == "dark":
            self.footer_theme_button.config(image=self.dark_mode_icon)  # type: ignore[arg-type]
        else:
            self.footer_theme_button.config(image=self.light_mode_icon)  # type: ignore[arg-type]
