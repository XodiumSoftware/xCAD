from tkinter import Tk as tkTk

from AFCDataclasses import EventsDataclass as AFCEventsDataclass


class Events:
    """A class used to represent an event handler."""

    @staticmethod
    def exit_on_key_press(root: tkTk, configs: AFCEventsDataclass) -> None:
        """Bind the keys for exiting the application.

        Args:
            root (tkTk): The root window.
            configs (AFCEventsDataclass): A configuration.
        """
        for key in configs.KEYS:
            root.bind(key, lambda event: event.widget.quit())
