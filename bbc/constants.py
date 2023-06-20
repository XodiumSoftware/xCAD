import os

import pandas as pd
from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy

# General
# ====================================================================================================
WINREG_THEME_KEY = os.path.join(
    r"SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize"
)
MS_VALUE_NAME = "AppsUseLightTheme"

DEBUG_NAME = "[DEBUG] "

THEME_DARK = "dark"
THEME_LIGHT = "light"
THEME_SYSTEM_DEFAULT = "system_default"

VIEWER_DARK = THEME_DARK
VIEWER_DARK_FLIPPED = VIEWER_DARK
VIEWER_LIGHT = THEME_LIGHT
VIEWER_LIGHT_FLIPPED = VIEWER_LIGHT

THEME_FOLDER_PATH = os.path.join("bbc/themes/")
ICONS_FOLDER_PATH = os.path.join("bbc/icons/")
DATA_FOLDER_PATH = os.path.join("bbc/data/")

QSETTINGS_ORGANIZATION_NAME = "Qerimi_Engineering"
QSETTINGS_APPLICATION_NAME = "AutoFrameCAD"
# ====================================================================================================

# UI
# ====================================================================================================
UI_TITLE = "AFC"
UI_ICON_PATH = os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")
# ====================================================================================================

# DataBaseHandler
# ====================================================================================================
DATABASE_PATH = os.path.join(DATA_FOLDER_PATH + "database.sqlite")
# ====================================================================================================

# TableModule:
# ====================================================================================================
# Editable: True/False
# ====================================================================================================
# Cell Types:
# 0: Label
# 1: Button
# 2: Input Box
# 3: Double Spin Box
# 4: Dropdown list
# 5: Checkbox
# Add more cell types here as needed
# ====================================================================================================

FILL_PATTERNS = [
    Qt.BrushStyle.SolidPattern,  # Solid fill pattern
    Qt.BrushStyle.Dense1Pattern,  # Dense fill pattern 1
    Qt.BrushStyle.Dense2Pattern,  # Dense fill pattern 2
]

PEN_STYLES = [
    Qt.PenStyle.SolidLine,  # Solid line style
    Qt.PenStyle.DashLine,  # Dashed line style
    Qt.PenStyle.DotLine,  # Dotted line style
]

TABLES = [
    {
        "table_index": 0,
        "table_data": pd.DataFrame(
            columns=[
                "Parameters",
                "Flag_0",
                "Values",
                "Flag_1",
            ],
            data=[
                [
                    "Structure",
                    "[False,0]",
                    "Select",
                    "[False,1]",
                ],
                [
                    "Length (mm)",
                    "[False,0]",
                    6000,
                    "[True,3]",
                ],
                [
                    "Height (mm)",
                    "[False,0]",
                    3000,
                    "[True,3]",
                ],
                [
                    "Area (m2)",
                    "[False,0]",
                    None,
                    "[False,2]",
                ],
                [
                    "Perimeter (m1)",
                    "[False,0]",
                    None,
                    "[False,2]",
                ],
            ],
        ),
    },
    {
        "table_data": 1,
        "table_data": pd.DataFrame(
            columns=[
                "Parameters",
                "Flag_0",
                "Values",
                "Flag_1",
            ],
            data=[
                [
                    "Thickness",
                    "[False,0]",
                    60,
                    "[True,2]",
                ],
                [
                    "Pen color",
                    "[False,0]",
                    "255, 255, 255",
                    "[True,2]",
                ],
                [
                    "Pen thickness",
                    "[False,0]",
                    1,
                    "[True,2]",
                ],
                [
                    "Pen style",
                    "[False,0]",
                    PEN_STYLES,
                    "[True,4]",
                ],
                [
                    "Fill pattern",
                    "[False,0]",
                    FILL_PATTERNS,
                    "[True,4]",
                ],
                [
                    "Fill pattern scale",
                    "[False,0]",
                    1,
                    "[True,2]",
                ],
                [
                    "Fill pattern angle",
                    "[False,0]",
                    0,
                    "[True,2]",
                ],
                [
                    "Fill",
                    "[False,0]",
                    True,
                    "[True,5]",
                ],
                [
                    "Fill color",
                    "[False,0]",
                    "255, 0, 0",
                    "[True,2]",
                ],
                [
                    "Fill opacity",
                    "[False,0]",
                    0.5,
                    "[True,2]",
                ],
            ],
        ),
    },
    # Add more tables here as needed
]


# Calculate TABLE_0_M2 and update TABLES
TABLE_0 = TABLES[0]["table_data"]
TABLE_0_M2 = (TABLE_0.loc[1, "Values"] * TABLE_0.loc[2, "Values"]) / (10**6)
TABLES[0]["table_data"].loc[3, "Values"] = TABLE_0_M2

# Calculate TABLE_0_M1 and update TABLES
TABLE_0_M1 = (
    TABLE_0.loc[1, "Values"]
    + TABLE_0.loc[1, "Values"]
    + TABLE_0.loc[2, "Values"]
    + TABLE_0.loc[2, "Values"]
) / (10**3)
TABLES[0]["table_data"].loc[4, "Values"] = TABLE_0_M1
# ====================================================================================================

# LabelModule
# ====================================================================================================
LABELS = [
    {
        "index": 0,
        "title": "© 2023 Qerimi Engineering. All rights reserved.",
        "stylesheet": "QLabel { font-size: 12px; font-style: italic; }",
        "alignment": (Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignBottom),
        "size_policy": (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
    },
]
# ====================================================================================================

# CheckBoxModule
# ====================================================================================================
CHECKBOXES = [
    {
        "index": 0,
        "title": "Toggle startup page",
        "stylesheet": "QCheckBox { font-size: 12px; }",
        "size_policy": (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
    },
]
# ====================================================================================================

# InputFieldModule
# ====================================================================================================
INPUTFIELDS = [
    {
        "index": 0,
        "placeholder": "Test",
        "stylesheet": "QLineEdit { font-size: 12px; }",
        "size_policy": (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
    },
]
# ====================================================================================================

# SpinBoxModule
# ====================================================================================================
SPINBOXES = [
    {
        "index": 0,
        "minium": 0,
        "maximum": 1.7e308,
        "default": 0,
        "step": 0.5,
        "stylesheet": "QSpinBox { font-size: 12px; }",
        "size_policy": (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
    },
]
# ====================================================================================================

# ButtonModule
# ====================================================================================================
BUTTONS = [
    {
        "index": 0,
        "title": "ThemeButton",
        "stylesheet": None,
        "size": (30, 30),
        "icon_path": os.path.join(
            ICONS_FOLDER_PATH + "theme_icon_system_default_light.png"
        ),
    },
    {
        "index": 1,
        "title": "ViewerButton",
        "stylesheet": None,
        "size": (30, 30),
        "icon_path": os.path.join(ICONS_FOLDER_PATH + "viewer_icon_light.png"),
    },
    {
        "index": 2,
        "title": "Save",
        "stylesheet": None,
        "size": (50, 30),
        "icon_path": None,
    },
    {
        "index": 3,
        "title": "Discard",
        "stylesheet": None,
        "size": (50, 30),
        "icon_path": None,
    },
    {
        "index": 4,
        "title": "AutoFrameCAD",
        "stylesheet": "QPushButton { font-size: 30px; font-style: italic; font-weight: bold; border: none;}",
        "size": None,
        "icon_path": None,
    },
    {
        "index": 5,
        "title": "Startup page",
        "stylesheet": None,
        "size": (30, 30),
        "icon_path": os.path.join(ICONS_FOLDER_PATH + "home_icon_light.png"),
    },
]
# ====================================================================================================


# ThemeHandler
# ====================================================================================================
THEME_FILE_PATHS = {
    THEME_DARK: os.path.join(THEME_FOLDER_PATH, "dark_theme.css"),
    THEME_LIGHT: os.path.join(THEME_FOLDER_PATH, "light_theme.css"),
}

ICONS_FILE_PATHS = {
    "theme": {
        THEME_DARK: os.path.join(ICONS_FOLDER_PATH, "theme_icon_dark.png"),
        THEME_LIGHT: os.path.join(ICONS_FOLDER_PATH, "theme_icon_light.png"),
        THEME_SYSTEM_DEFAULT
        + "_"
        + THEME_DARK: os.path.join(
            ICONS_FOLDER_PATH, "theme_icon_system_default_dark.png"
        ),
        THEME_SYSTEM_DEFAULT
        + "_"
        + THEME_LIGHT: os.path.join(
            ICONS_FOLDER_PATH, "theme_icon_system_default_light.png"
        ),
    },
    "viewer": {
        VIEWER_DARK: os.path.join(ICONS_FOLDER_PATH, "viewer_icon_dark.png"),
        VIEWER_DARK_FLIPPED: os.path.join(
            ICONS_FOLDER_PATH, "viewer_icon_flipped_dark.png"
        ),
        VIEWER_LIGHT: os.path.join(ICONS_FOLDER_PATH, "viewer_icon_light.png"),
        VIEWER_LIGHT_FLIPPED: os.path.join(
            ICONS_FOLDER_PATH, "viewer_icon_flipped_light.png"
        ),
    },
}
# ====================================================================================================
