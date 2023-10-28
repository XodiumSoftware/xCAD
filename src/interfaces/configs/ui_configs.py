from constants import UI_ICON_PATH

# TODO: this file


class MainUITypeHints:
    """A class used to represent main UI type hints."""

    TITLE: str
    ICON: str
    INIT_SIZE: tuple[int, int]
    INIT_VISIBILITY: bool
    MARGINS: tuple[int, int, int, int]
    TOOLBAR: str
    STATUSBAR: str


class MainUIConfig(MainUITypeHints):
    """A class to represent the main UI."""

    TITLE = "AFC"
    ICON = UI_ICON_PATH
    INIT_SIZE = (600, 400)
    INIT_VISIBILITY = True
    MARGINS = (10, 10, 10, 10)
    TOOLBAR = "TODO: implement this."  # TODO: add functionality to this.
    STATUSBAR = "TODO: implement this."  # TODO: add functionality to this.
