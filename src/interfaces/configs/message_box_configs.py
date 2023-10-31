import os
from dataclasses import dataclass
from typing import Optional

from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QMessageBox

from constants import ICONS_FOLDER_PATH


@dataclass
class MessageBoxTypeHints:
    """A class used to represent a message box type hint."""

    title: str
    icon_path: QIcon
    icon_type: QMessageBox.Icon
    size: Optional[list]
    text: str
    standard_buttons: QMessageBox.StandardButton


class QuitMessageBox(MessageBoxTypeHints):
    """A class used to represent a message box config."""

    def __init__(self):
        super().__init__(
            title="Exit?",
            icon_path=QIcon(os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")),
            icon_type=QMessageBox.Icon.Warning,
            size=None,
            text="<b>Are you sure you want to quit the application?</b><br>Any unsaved changes will be lost!",
            standard_buttons=QMessageBox.StandardButton.Yes
            | QMessageBox.StandardButton.No,
        )
