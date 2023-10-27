import os
import sys
from enum import Enum

import darkdetect
from configs.type_configs import LumberTypes
from PySide6.QtWidgets import QMessageBox

from constants import ICONS_FOLDER_PATH


class Labels(Enum):
    """A class used to represent a label widget"""

    Copyright = {
        "title": "© 2023 Qerimi Engineering. All rights reserved.",
        "stylesheet": "QLabel { font-size: 12px; font-style: italic; }",
    }


class Checkboxes(Enum):
    """A class used to represent checkboxes"""

    ToggleStartupPage = {
        "title": "Toggle startup page",
        "stylesheet": "QCheckBox { font-size: 12px; }",
    }


class LineEdits(Enum):
    """A class used to represent input fields"""

    Test = {
        "placeholder": "Test",
        "stylesheet": "QLineEdit { font-size: 12px; }",
    }


class DoubleSpinBoxes(Enum):
    """A class used to represent double spin boxes"""

    SpinBox = {
        "min_value": 0,
        "max_value": sys.float_info.max,
        "default_value": 0,
        "step": 0.5,
        "stylesheet": "QSpinBox { font-size: 12px; }",
        "suffix": "mm",
    }


class PushButtons(Enum):
    """A class used to represent buttons"""

    AutoFrameCAD = {
        "icon_path": None,
        "size": None,
        "title": ("AutoFrameCAD", "Click on title to start!"),
        "stylesheet": (
            "QLabel {font-size: 48px;font-weight: bold;font-style: normal;border: none;}",
            "QLabel {font-size: 12px;font-weight: normal;font-style: normal;border: none;}",
        ),
    }
    Save = {
        "icon_path": None,
        "size": [50, 30],
        "title": "Save",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    }
    Discard = {
        "icon_path": None,
        "size": [50, 30],
        "title": "Discard",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    }
    Reset = {
        "icon_path": None,
        "size": [50, 30],
        "title": "Reset",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    }
    StartupPage = {
        "icon_path": os.path.join(
            ICONS_FOLDER_PATH,
            "home_icon_light.png" if darkdetect.isDark() else "home_icon_dark.png",
        ),
        "size": [30, 30],
        "title": "Startup page",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    }


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
