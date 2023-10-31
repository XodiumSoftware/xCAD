import os
from dataclasses import dataclass

from PySide6.QtGui import QIcon

from constants import ICONS_FOLDER_PATH


@dataclass
class DialogTypeHints:
    """A class used to represent a dialog type hint."""

    title: str
    icon_path: QIcon


class ObjectDialogConfig(DialogTypeHints):
    """A class used to represent a dialog config."""

    def __init__(self):
        super().__init__(
            title="Object dialog",
            icon_path=QIcon(os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")),
        )
