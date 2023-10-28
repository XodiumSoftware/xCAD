import os
from typing import Optional

from PySide6.QtWidgets import QMessageBox

from constants import ICONS_FOLDER_PATH


class MessageBoxTypeHints:
    """A class used to represent a message box type hint."""

    Title: str
    Icon_path: str
    Icon_type: QMessageBox.Icon
    Size: Optional[list]
    Text: str


class QuitMessageBox(MessageBoxTypeHints):
    """A class used to represent a message box config."""

    Title = "Exit?"
    Icon_path = os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")
    Icon_type = QMessageBox.Icon.Warning
    Size = None
    Text = "<b>Are you sure you want to quit the application?</b><br>Any unsaved changes will be lost!"
