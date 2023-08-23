import os

from q_enums import *

# General
# ====================================================================================================
WINREG_THEME_KEY = os.path.join(
    r"SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize"
)
MS_VALUE_NAME = "AppsUseLightTheme"

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

QUIT_DIALOG_TITLE = "Exit?"
ITEM_PROPERTIES_DIALOG_TITLE = "Item Properties"
COLOR_PICKER_DIALOG_TITLE = "Color Picker"

UIS = [
    {
        "index": 0,
        "name": "MainUI",
        "title": "AFC",
        "icon": UI_ICON_PATH,
        "initial_size": (600, 400),
        "initial_visibility": False,
    },
    {
        "index": 1,
        "name": "ConfiguratorUI",
        "title": "Structure Configurator",
        "icon": UI_ICON_PATH,
        "initial_size": (800, 400),
        "initial_visibility": False,
    },
    {
        "index": 2,
        "name": "Frame2DView",
        "title": "2D Frame Viewer",
        "icon": UI_ICON_PATH,
        "initial_size": (800, 400),
        "initial_visibility": True,
    },
]

# ====================================================================================================

# DataBaseHandler
# ====================================================================================================
DATABASE_PATH = os.path.join(DATA_FOLDER_PATH + "database.db")
MAX_BACKUPS = 5
# ====================================================================================================

# ModuleHandler:
# ====================================================================================================
# Define the matrix data with support for nested containers
# NOTE: Nested containers are not supported yet.
# Each element in module_matrix_pos can contain either a list of widgets
# or another set of "module_args" representing a nested container.
# For nested containers, specify the nested layout as a string.
# ====================================================================================================
MATRICES = [
    {
        "index": 0,
        "module_matrix_pos": [
            [
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    0,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Expanding, SizePolicyType.Expanding),
                ],
            ],
            [
                [
                    LayoutType.VBox,
                    ModuleType.Label,
                    0,
                    (0, 0, 0, 0),
                    AlignmentType.AlignBottom,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
            ],
        ],
    },
    {
        "index": 1,
        "module_matrix_pos": [
            [
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    2,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    3,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    4,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
            ],
            [
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    5,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    1,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
            ],
            [
                [
                    LayoutType.VBox,
                    ModuleType.Label,
                    0,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
            ],
        ],
    },
    {
        "index": 2,
        "module_matrix_pos": [
            [
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    2,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    3,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    4,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
            ],
            [
                [
                    LayoutType.VBox,
                    ModuleType.PushButton,
                    5,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
            ],
            [
                [
                    LayoutType.VBox,
                    ModuleType.Label,
                    0,
                    (0, 0, 0, 0),
                    AlignmentType.AlignCenter,
                    (SizePolicyType.Minimum, SizePolicyType.Minimum),
                ],
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
DOUBLESPINBOXES = [
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
