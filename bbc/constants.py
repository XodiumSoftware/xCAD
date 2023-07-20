import os

from PySide6.QtCore import Qt
from PySide6.QtGui import QColor

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
UI_ICON_PATH = os.path.join(ICONS_FOLDER_PATH + "ui_icon.png")

COLOR_PICKER_TITLE = "Color Picker"

UIS = [
    {
        "index": 0,
        "name": "MainUI",
        "title": "AFC",
        "icon": UI_ICON_PATH,
        "initial_size": (600, 400),
        "initial_visibility": True,
    },
    {
        "index": 1,
        "name": "ConfiguratorUI",
        "title": "Structure Configurator",
        "icon": UI_ICON_PATH,
        "initial_size": (800, 400),
        "initial_visibility": False,
    },
]

# ====================================================================================================

# DataBaseHandler
# ====================================================================================================
DATABASE_PATH = os.path.join(DATA_FOLDER_PATH + "database.db")
# ====================================================================================================

# ModuleHandler:
# ====================================================================================================
MATRICES = [
    {
        "index": 0,
        "module_matrix_pos": [
            [
                (
                    "VBox",
                    "Button",
                    0,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeExpanding", "SizeExpanding"),
                ),
                # Add more columns here...
            ],
            [
                (
                    "VBox",
                    "Label",
                    0,
                    (0, 0, 0, 0),
                    "AlignBottom",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                # Add more columns here...
            ],
            # Add more rows here...
        ],
    },
    {
        "index": 1,
        "module_matrix_pos": [
            [
                (
                    "VBox",
                    "TableView",
                    1,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeExpanding", "SizeExpanding"),
                ),
                (
                    "VBox",
                    "GraphicsView",
                    0,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeExpanding", "SizeExpanding"),
                ),
                # Add more columns here...
            ],
            [
                (
                    "VBox",
                    "Button",
                    5,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                (
                    "VBox",
                    "Button",
                    1,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                # Add more columns here...
            ],
            [
                (
                    "VBox",
                    "Button",
                    2,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                (
                    "VBox",
                    "Button",
                    3,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                (
                    "VBox",
                    "Button",
                    4,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                # Add more columns here...
            ],
            [
                (
                    "VBox",
                    "Label",
                    0,
                    (0, 0, 0, 0),
                    "AlignCenter",
                    ("SizeMinimum", "SizeMinimum"),
                ),
                # Add more columns here...
            ]
            # Add more rows here...
        ],
    },
]
# ====================================================================================================

# TableModule:
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
        "index": 0,
        "desc": "FRAME_DATA",
        "stylesheet": "QCheckBox { font-size: 12px; }",
        "sorting": True,
        "alternating_row_colors": True,
        "columns": ["Parameter", "Value"],
        "rows": [
            ["Structure", True],
            ["Length", 6000],
            ["Height", 3000],
            ["Area", ((6000 * 3000) / 1000000)],
            ["Perimeter", (((6000 + 3000) * 2) / 1000)],
        ],
    },
    {
        "index": 1,
        "desc": "OBJECT_ASSEMBLY_DATA",
        "stylesheet": "QCheckBox { font-size: 12px; }",
        "sorting": True,
        "alternating_row_colors": True,
        "columns": ["Parameter", "Value"],
        "rows": [
            ["Thickness", 60],
            ["Pen color", "255, 255, 255"],
            ["Pen thickness", 1],
            ["Pen style", ",".join(str(style) for style in PEN_STYLES)],
            ["Fill pattern", ",".join(str(pattern) for pattern in FILL_PATTERNS)],
            ["Fill pattern scale", 1],
            ["Fill pattern angle", 0],
            ["Fill", True],
            ["Fill color", "255, 0, 0"],
            ["Fill opacity", 0.5],
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
        "min_value": 0,
        "max_value": 1.7e308,
        "default_value": 0,
        "step": 0.5,
        "stylesheet": "QSpinBox { font-size: 12px; }",
        "suffix": "mm",
    },
]
# ====================================================================================================

# ButtonModule
# ====================================================================================================
BUTTONS = [
    {
        "index": 0,
        "icon_path": None,
        "size": None,
        "title": "AutoFrameCAD",
        "stylesheet": "QPushButton {font-size: 36px;font-weight: bold;font-style: normal;border: none;}",
    },
    {
        "index": 1,
        "icon_path": os.path.join(ICONS_FOLDER_PATH, "viewer_icon_light.png"),
        "size": [30, 30],
        "title": "ViewerButton",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    },
    {
        "index": 2,
        "icon_path": None,
        "size": [50, 30],
        "title": "Save",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    },
    {
        "index": 3,
        "icon_path": None,
        "size": [50, 30],
        "title": "Discard",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    },
    {
        "index": 4,
        "icon_path": None,
        "size": [50, 30],
        "title": "Reset",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
    },
    {
        "index": 5,
        "icon_path": os.path.join(ICONS_FOLDER_PATH, "home_icon_light.png"),
        "size": [30, 30],
        "title": "Startup page",
        "stylesheet": "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
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
GRAPHICS_VIEWS = [
    {
        "index": 0,
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

# AFCCMD
# ====================================================================================================
LAYER_PROPERTIES = {
    "KBG_SLS": {
        "Color": 1,
        "Linetype": "Continuous",
        "LinetypeScale": 1,
        "Lineweight": -1,
    }
}

OBJECT_PROPERTIES = {
    "rectangle": {
        "TrueColor": None,
        "Layer": "KBG_SLS",
        "Linetype": "ByLayer",
        "LinetypeScale": 1,
        "Lineweight": -1,
        "Transparency": -1,
        "Hyperlinks": None,
        "RecordGraphicsModified": True,
        "Thickness": 0,
        "Material": "ByLayer",
    },
}
# ====================================================================================================
