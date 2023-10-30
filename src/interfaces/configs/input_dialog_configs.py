import os
from typing import Optional

from PySide6.QtWidgets import QMessageBox

from constants import ICONS_FOLDER_PATH
from data.types_data import LumberTypes


class InputDialogTypeHints:
    """A class used to represent a input dialog type hint."""

    Title: str
    Icon_path: str
    Icon_type: QMessageBox.Icon
    Size: Optional[list]
    Text: str
    Data: list


class LumberTypeConfig(InputDialogTypeHints):
    """A class used to represent a input dialog config."""

    Title = "Select Lumber Type"
    Icon_path = os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")
    Size = None
    Text = "Choose a lumber type:"
    Data = LumberTypes.get_all_content()
