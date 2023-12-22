from tkinter import Tk

from AFCDataclasses import EventsDataclass


class Events:
    """A class used to represent an event handler."""

    @staticmethod
    def exit_on_key_press(root: Tk, configs: EventsDataclass) -> None:
        """Bind the keys for exiting the application."""
        for key in configs.KEYS:
            root.bind(key, lambda event: event.widget.quit())
