from tkinter import ttk as tkttk


class LayoutHandler:
    """A class used to represent a layout."""

    def __init__(self, layout: list) -> None:
        """Initialize the class.

        Args:
            layout (list): The layout to use.
        """
        self.layout(layout, sticky='nsew')

    def layout(self, layout: list, sticky: str, pos: int = 0) -> None:
        """Layout the widgets.

        Args:
            layout (list): The layout to use.
            pos (int, optional): The position to start from. Defaults to 0.
        """
        for i, item in enumerate(layout):
            if isinstance(item, list):
                self.layout(item, sticky, pos + 1)
            elif isinstance(item, tkttk.Widget):
                item.grid(row=pos, column=i, sticky=sticky)
