"""This module contains the UI functionality."""

from tkinter import Canvas, PhotoImage
from tkinter.ttk import Button, Frame, Label

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

        self.title("AutoFrameCAD")
        self.theme(self.db.get_data(self.table, "usr_theme"))
        self.visible(state=True)
        self.resizable(width=True, height=True)
        self.iconphoto(True, PhotoImage(file=UI_ICON_FILE))  # noqa: FBT003
        self.geometry(f"{1200}x{800}")
        self.minsize(1200, 800)
        self.events({"<Control-w>": lambda _: self.quit()})
        self.config(padx=10, pady=10)

        self._header_frame()
        self._body_frame()
        self._footer_frame()

    def _header_frame(self: "PrimaryUI") -> None:
        """Create the header frame and add a label."""
        self.header_frame = Frame(self)
        self.header_frame.pack(side="top", fill="both", expand=False)

        self.label_header = Label(
            self.header_frame,
            text="BIM Object Configurator",
            font=("", 12, "bold"),
            anchor="center",
        )
        self.label_header.pack(fill="both", expand=True)

    def _body_frame(self: "PrimaryUI") -> None:
        """Create the body frame and add a label."""
        self.body_frame = Frame(self)
        self.body_frame.pack(side="top", fill="both", expand=True)

        self._left_body_frame()
        self._right_body_frame()

    def _left_body_frame(self: "PrimaryUI") -> None:
        """Create the left body frame and add labels and entries."""
        self.left_body_frame = Frame(
            self.body_frame,
            borderwidth=1,
            relief="solid",
        )
        self.left_body_frame.pack(side="left", fill="both", expand=False)

        self.label_left = Label(
            self.left_body_frame,
            text="Properties",
        )
        self.label_left.pack(fill="both", expand=True)

    def _right_body_frame(self: "PrimaryUI") -> None:
        """Create the right body frame and add a label."""
        self.right_body_frame = Frame(
            self.body_frame,
            borderwidth=1,
            relief="solid",
        )
        self.right_body_frame.pack(side="right", fill="both", expand=True)

        self.canvas = Canvas(
            self.right_body_frame,
            background="black",
        )
        self.canvas.pack(fill="both", expand=True)
        self.canvas.update_idletasks()

        # Move grid creation into its own method.
        grid_spacing = 20
        grid_color = "gray"

        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()

        for x in range(0, canvas_height, grid_spacing):
            self.canvas.create_line(x, 0, x, canvas_width, fill=grid_color)

        for y in range(0, canvas_width, grid_spacing):
            self.canvas.create_line(0, y, canvas_height, y, fill=grid_color)

    def _footer_frame(self: "PrimaryUI") -> None:
        """Create the footer frame and add a label."""
        self.footer_frame = Frame(self)
        self.footer_frame.pack(side="top", fill="both", expand=False)
        self.footer_frame.columnconfigure(0, weight=1)

        self.label_footer = Label(
            self.footer_frame,
            text="©2023 Structura Engineering",
        )
        self.label_footer.grid(row=0, column=0, sticky="w")

        self.button_footer = Button(
            self.footer_frame,
            text="Toggle Theme",
            command=lambda: self.toggle_theme(),
        )
        self.button_footer.grid(row=0, column=1, sticky="e", pady=(5, 0))
