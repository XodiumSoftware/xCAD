import os

from PySide6.QtCore import Qt
from PySide6.QtGui import QColor
from PySide6.QtWidgets import (
    QCheckBox,
    QComboBox,
    QDoubleSpinBox,
    QLabel,
    QLineEdit,
    QPushButton,
)

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
# - QLabel
# - QPushButton
# - QLineEdit
# - QDoubleSpinBox
# - QComboBox
# - QCheckBox
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
        "index": 1,
        "desc": "FRAME_DATA",
        "stylesheet": "QCheckBox { font-size: 12px; }",
        "sorting": True,
        "alternating_row_colors": True,
        "columns": ["Parameter", "Flag_0", "Value", "Flag_1"],
        "rows": [
            [
                "Structure",
                [False, QLabel],
                "Select",
                [False, QPushButton],
            ],
            [
                "Length (mm)",
                [False, QLabel],
                6000,
                [True, QDoubleSpinBox],
            ],
            [
                "Height (mm)",
                [False, QLabel],
                3000,
                [True, QDoubleSpinBox],
            ],
            [
                "Area (m2)",
                [False, QLabel],
                None,
                [False, QLabel],
            ],
            [
                "Perimeter (m1)",
                [False, QLabel],
                None,
                [False, QLabel],
            ],
        ],
    },
    {
        "index": 2,
        "desc": "OBJECT_ASSEMBLY_DATA",
        "stylesheet": "QCheckBox { font-size: 12px; }",
        "sorting": True,
        "alternating_row_colors": True,
        "columns": ["Parameter", "Flag_0", "Value", "Flag_1"],
        "rows": [
            [
                "Thickness",
                [False, QLabel],
                60,
                [True, QLineEdit],
            ],
            [
                "Pen color",
                [False, QLabel],
                "255, 255, 255",
                [True, QLineEdit],
            ],
            [
                "Pen thickness",
                [False, QLabel],
                1,
                [True, QLineEdit],
            ],
            [
                "Pen style",
                [False, QLabel],
                PEN_STYLES,
                [True, QComboBox],
            ],
            [
                "Fill pattern",
                [False, QLabel],
                FILL_PATTERNS,
                [True, QComboBox],
            ],
            [
                "Fill pattern scale",
                [False, QLabel],
                1,
                [True, QLineEdit],
            ],
            [
                "Fill pattern angle",
                [False, QLabel],
                0,
                [True, QLineEdit],
            ],
            [
                "Fill",
                [False, QLabel],
                True,
                [True, QCheckBox],
            ],
            [
                "Fill color",
                [False, QLabel],
                "255, 0, 0",
                [True, QLineEdit],
            ],
            [
                "Fill opacity",
                [False, QLabel],
                0.5,
                [True, QLineEdit],
            ],
        ],
    },
]
# ====================================================================================================

# LabelModule
# ====================================================================================================
LABELS = [
    {
        "index": 0,
        "title": "© 2023 Qerimi Engineering. All rights reserved.",
        "stylesheet": "QLabel { font-size: 12px; font-style: italic; }",
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
    },
]
# ====================================================================================================

# ButtonModule
# ====================================================================================================
BUTTONS = [
    {
        "index": 0,
        "icon_path": None,
        "size": [None, None],
        "title": ["AutoFrameCAD", "Click me!"],
        "stylesheets": [
            {
                "font-size": "32px",
                "font-weight": "bold",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            },
            {
                "font-size": "8px",
                "font-weight": "normal",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            },
        ],
    },
    {
        "index": 1,
        "icon_path": os.path.join(ICONS_FOLDER_PATH, "viewer_icon_light.png"),
        "size": [30, 30],
        "title": ["ViewerButton"],
        "stylesheets": [
            {
                "font-size": "12px",
                "font-weight": "normal",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            }
        ],
    },
    {
        "index": 2,
        "icon_path": None,
        "size": [30, 30],
        "title": ["Save"],
        "stylesheets": [
            {
                "font-size": "8px",
                "font-weight": "normal",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            }
        ],
    },
    {
        "index": 3,
        "icon_path": None,
        "size": [30, 30],
        "title": ["Discard"],
        "stylesheets": [
            {
                "font-size": "8px",
                "font-weight": "normal",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            }
        ],
    },
    {
        "index": 4,
        "icon_path": None,
        "size": [30, 30],
        "title": ["Reset"],
        "stylesheets": [
            {
                "font-size": "12px",
                "font-weight": "normal",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            }
        ],
    },
    {
        "index": 5,
        "icon_path": os.path.join(ICONS_FOLDER_PATH, "home_icon_light.png"),
        "size": [30, 30],
        "title": ["Startup page"],
        "stylesheets": [
            {
                "font-size": "12px",
                "font-weight": "normal",
                "font-style": "normal",
                "text-decoration": "none",
                "color": "#000000",
                "line-spacing": "6px",
            }
        ],
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


# GraphicsViewModule
# ====================================================================================================
GRAPHIC_VIEWS = [
    {
        "index": 1,
        "data": [
            {
                "draw_order": 0,
                "thickness": 60,
                "pen_color": QColor(255, 255, 255),
                "pen_thickness": 1,
                "pen_style": Qt.PenStyle.SolidLine,
                "fill_pattern": Qt.BrushStyle.SolidPattern,
                "fill_pattern_scale": 1.0,
                "fill_pattern_angle": None,
                "fill_color": QColor(255, 0, 0),
                "fill": True,
                "fill_opacity": 0.5,
            },
            {
                "draw_order": 1,
                "thickness": 170,
                "pen_color": QColor(255, 255, 255),
                "pen_thickness": 1,
                "pen_style": Qt.PenStyle.DashLine,
                "fill_pattern": Qt.BrushStyle.DiagCrossPattern,
                "fill_pattern_scale": 10.0,
                "fill_pattern_angle": None,
                "fill_color": QColor(0, 255, 0),
                "fill": True,
                "fill_opacity": 1.0,
            },
            {
                "draw_order": 2,
                "thickness": 12,
                "pen_color": QColor(0, 0, 255),
                "pen_thickness": 1,
                "pen_style": Qt.PenStyle.SolidLine,
                "fill_pattern": Qt.BrushStyle.BDiagPattern,
                "fill_pattern_scale": 1.0,
                "fill_pattern_angle": 90,
                "fill_color": QColor(0, 0, 255),
                "fill": True,
                "fill_opacity": 1.0,
            },
        ],
    },
]

# ====================================================================================================
