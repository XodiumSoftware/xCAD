import os

from constants import ICONS_FOLDER_PATH


class DialogTypeHints:
    """A class used to represent a dialog type hint."""

    Title: str
    Icon_path: str


class ObjectDialogConfig(DialogTypeHints):
    """A class used to represent a dialog config."""

    Title = "Object Editor"
    Icon_path = os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")
