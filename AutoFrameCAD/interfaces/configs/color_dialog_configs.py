import os
from dataclasses import dataclass

from constants import ICONS_FOLDER_PATH
from PySide6.QtGui import QIcon


@dataclass
class ColorDialogTypeHints:
    """A class used to represent a color dialog type hint."""

    title: str
    icon_path: QIcon
    size: tuple[int, int] | None


class DefaultColorDialogConfig(ColorDialogTypeHints):
    """A class used to represent a color dialog config."""

    def __init__(self):
        super().__init__(
            title="Color picker",
            icon_path=QIcon(os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")),
            size=None,
        )
