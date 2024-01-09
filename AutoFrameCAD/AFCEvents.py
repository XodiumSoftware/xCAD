from tkinter import Tk as tkTk


class Events:
    """A class used to represent an event handler."""

    @staticmethod
    def exit_on_key_press(root: tkTk, keys: list[str]) -> None:
        """Bind the keys for exiting the application.

        Args:
            root (tkTk): The root window.
            keys (list[str]): The keys to bind.
        """
        for key in keys:
            root.bind(key, lambda event: event.widget.quit())
