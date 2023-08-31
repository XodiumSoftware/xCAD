import os
from enum import Enum

import darkdetect
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
        "max_value": 1.7e308,
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
        "title": "AutoFrameCAD",
        "stylesheet": "QPushButton {font-size: 36px;font-weight: bold;font-style: normal;border: none;}",
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
