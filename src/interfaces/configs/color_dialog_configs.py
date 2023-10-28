import os
from typing import Optional

from constants import ICONS_FOLDER_PATH


class ColorDialogTypeHints:
    """A class used to represent a color dialog type hint."""

    Title: str
    Icon_path: str
    Size: Optional[list]


class DefaultColorDialog(ColorDialogTypeHints):
    """A class used to represent a color dialog config."""

    Title = "Color picker"
    Icon_path = os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")
    Size = None
