import os
from enum import Enum

from PySide6.QtWidgets import QMessageBox

from constants import ICONS_FOLDER_PATH
from interfaces.configs.type_configs_OLD import LumberTypes


class GraphicsViews(Enum):
    """A class used to represent graphics views"""

    StructureView = {}


class MessageBoxes(Enum):
    """A class used to represent message boxes"""

    QuitMessage = {
        "title": "Exit?",
        "icon_path": os.path.join(ICONS_FOLDER_PATH + "ui_icon.png"),
        "icon_type": QMessageBox.Icon.Warning,
        "size": None,
        "text": "<b>Are you sure you want to quit the application?</b><br>Any unsaved changes will be lost!",
    }


class ColorDialogs(Enum):
    """A class used to represent color dialogs"""

    ColorDialog = {
        "title": "Color picker",
        "icon_path": os.path.join(ICONS_FOLDER_PATH + "ui_icon.png"),
        "size": None,
    }


class InputDialogs(Enum):
    """A class used to represent input dialogs"""

    LumberDialog = {
        "title": "Select Lumber Type",
        "icon_path": os.path.join(ICONS_FOLDER_PATH + "ui_icon.png"),
        "size": None,
        "text": "Choose a lumber type:",
        "data": LumberTypes.get_all_content(),
    }


class Dialogs(Enum):
    """A class used to represent dialogs"""

    ObjectDialog = {
        "title": "Object Editor",
        "icon_path": os.path.join(ICONS_FOLDER_PATH + "ui_icon.png"),
    }
