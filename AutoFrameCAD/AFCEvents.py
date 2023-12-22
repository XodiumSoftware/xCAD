from tkinter import Tk

from AFCDataclasses import EventsDataclass


class Events:
    """A class used to represent an event handler."""

    @staticmethod
    def center_window(root: Tk) -> None:
        """Center the window on the screen."""
        root.geometry(
            '+{}+{}'.format(
                root.winfo_screenwidth() // 2 - root.winfo_reqwidth() // 2,
                root.winfo_screenheight() // 2 - root.winfo_reqheight() // 2,
            )
        )

    @staticmethod
    def exit_on_key_press(root: Tk, configs: EventsDataclass) -> None:
        """Bind the keys for exiting the application."""
        for key in configs.KEYS:
            root.bind(key, lambda event: event.widget.quit())
