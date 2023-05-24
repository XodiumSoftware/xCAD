import os

from PySide6.QtCore import Qt

COLUMN_WIDTH = 200

# General
UI_TITLE = "AFC"
UI_FONT_TYPE = "Arial"
UI_GROUPBOX_FONT_SIZE = 10
UI_ICON_PATH = os.path.join("bbc/icons/ui_icon.png")
UI_CONTENTS_MARGINS = 5, 5, 5, 5
UI_STYLE = "fusion"
UI_GROUPBOX_STYLESHEET = "QGroupBox { border: 0; padding-top: 20; }"
UI_MINIMUM_SIZE = 200, 200
UI_MARGIN_BETWEEN_UI = 2
UI_DESC_LABEL_STYLE = "font-style: bold; font-size: 18px;"

# Copyright label
COPYRIGHT_LABEL = "© 2023 Qerimi Engineering. All rights reserved."
COPYRIGHT_LABEL_SIZE = 8
COPYRIGHT_LABEL_STYLE = "font-style: italic;"

# Main UI
MAIN_UI_GROUPBOX_TITLE = "AutoFrameCAD"
MAIN_UI_BUTTON_SIZE = 30, 30
MAIN_UI_BUTTON_ICON_SIZE = 10, 10

THEME_BUTTON_TOOLTIP = "Toggle Theme"
THEME_BUTTON_ICON_DEFAULT_PATH = os.path.join("bbc/icons/theme_icon_default_light.png")
THEME_BUTTON_ICON_LIGHT_PATH = os.path.join("bbc/icons/theme_icon_light.png")
THEME_BUTTON_ICON_DARK_PATH = os.path.join("bbc/icons/theme_icon_dark.png")

# Config UI
VIEWER_UI_TITLE = "Configurator"
VIEWER_UI_SUFFIX_MM = "mm"
VIEWER_UI_SUFFIX_M2 = "m2"

VIEWER_UI_BUTTON_TOOLTIP = "Toggle Viewer"
VIEWER_UI_BUTTON_ICON_LIGHT_PATH = os.path.join("bbc/icons/viewer_icon_light.png")
VIEWER_UI_BUTTON_ICON_DARK_PATH = os.path.join("bbc/icons/viewer_icon_dark.png")
VIEWER_UI_BUTTON_ICON_FLIPPED_LIGHT_PATH = os.path.join(
    "bbc/icons/viewer_icon_flipped_light.png"
)
VIEWER_UI_BUTTON_ICON_FLIPPED_DARK_PATH = os.path.join(
    "bbc/icons/viewer_icon_flipped_dark.png"
)

# Input bar
INPUT_BAR_WIDTH = 100
INPUT_RANGE = 0, 1e100

# Data
DATA_DIR_FOLDER = os.path.join("bbc/data/")
DATA_DIR_FILE = os.path.join("configurator_inputs.txt")

# Database
DB_DIR = os.path.join("bbc", "data", "db")
DB_FILE = os.path.join(DB_DIR, "inputs.db")
SETTINGS_DATABASE_PATH = os.path.join("bbc/data/settings.sqlite")


# Define constants for the SQL statements
CREATE_TABLE_SQL = """CREATE TABLE IF NOT EXISTS inputs
    (id INTEGER PRIMARY KEY AUTOINCREMENT,
    input_type TEXT,
    input_data TEXT)"""
INSERT_INPUT_SQL = "INSERT INTO inputs (input_type, input_data) VALUES (?, ?)"

# Theme

DARK_THEME_FILE = os.path.join("bbc/themes/dark_theme.css")
LIGHT_THEME_FILE = os.path.join("bbc/themes/light_theme.css")

SETTINGS_ORGANIZATION = "AFC"
SETTINGS_APPLICATION = "CurrentThemeSetting"

KEY_THEME = "theme"
KEY_THEME_LIGHT = "light"
KEY_THEME_DARK = "dark"

# Debugging
DEBUG_SAVE_INPUT_PRINT = "[DEBUG]: SAVING CHANGES:"
DEBUG_SAVED_DATA_PRINT = "[DEBUG]: Saved Data:"
DEBUG_PLACEHOLDER_TEXT_PRINT = "[DEBUG]: Placeholder Text:"

# SettingsListWidget
DROPDOWN_LIST_GENERAL = ["Option 1", "Option 2", "Option 3"]
DROPDOWN_LIST_SOUND = ["On", "Off"]
SETTINGS_LIST = [
    ("Structure", "dropdown", DROPDOWN_LIST_GENERAL),
    ("Wrapping at Inserts", "input_text", []),
    ("Wrapping at Ends", "input_int", []),
    ("Width", "dropdown", DROPDOWN_LIST_SOUND),
    ("Function", "checkbox", []),
    ("Test", "button", []),
]
HORIZONTAL_HEADER_LABELS = ["Parameter", "Value"]
SETTINGS_DATABASE_PATH = os.path.join("bbc/data/settings.sqlite")
CHECKBOX_STYLE = "QCheckBox {margin-left: 100%; margin-right: 100%; padding-left: -10px; padding-right: -10px;}"

# LabelWidget
LABELS = [
    {
        "index": 0,
        "title": "© 2023 Qerimi Engineering. All rights reserved.",
        "stylesheet": "QLabel { font-size: 12px; font-style: italic; }",
        "alignment": Qt.AlignmentFlag.AlignLeft,
    },
    {
        "index": 1,
        "title": "Test 1",
        "stylesheet": "QLabel { font-size: 8px; font-style: italic; }",
        "alignment": Qt.AlignmentFlag.AlignCenter,
    },
    {
        "index": 2,
        "title": "Test 2",
        "stylesheet": "QLabel { font-size: 8px; font-style: italic; }",
        "alignment": Qt.AlignmentFlag.AlignRight,
    },
]

# TODO: Add function that toggles the button icon based on isVisible().
# ButtonWidget
BUTTONS = [
    {
        "index": 0,
        "title": "ThemeButton",
        "size": (30, 30),
        "icon_path": os.path.join("bbc/icons/theme_icon_default_light.png"),
    },
    {
        "index": 1,
        "title": "ViewerButton",
        "size": (30, 30),
        "icon_path": os.path.join("bbc/icons/viewer_icon_light.png"),
    },
    {
        "index": 2,
        "title": "Save",
        "size": (50, 30),
        "icon_path": None,
    },
    {
        "index": 3,
        "title": "Discard",
        "size": (50, 30),
        "icon_path": None,
    },
]  # Dont forget to add the necessary code into the EventHandler.

# ThemeHandler
WINREG_THEME_KEY = os.path.join(
    r"SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize"
)
MS_VALUE_NAME = "AppsUseLightTheme"

DEBUG_NAME = "[DEBUG] "

THEME_DARK = "dark"
THEME_LIGHT = "light"
THEME_SYSTEM_DEFAULT = "system_default"

THEME_FOLDER_PATH = os.path.join("bbc/themes/")
ICONS_FOLDER_PATH = os.path.join("bbc/icons/")

THEME_FILE_PATHS = {
    THEME_DARK: os.path.join(THEME_FOLDER_PATH, "dark_theme.css"),
    THEME_LIGHT: os.path.join(THEME_FOLDER_PATH, "light_theme.css"),
}

ICONS_FILE_PATHS = {
    THEME_DARK: os.path.join(ICONS_FOLDER_PATH, "theme_icon_dark.png"),
    THEME_LIGHT: os.path.join(ICONS_FOLDER_PATH, "theme_icon_light.png"),
    THEME_SYSTEM_DEFAULT
    + "_"
    + THEME_DARK: os.path.join(ICONS_FOLDER_PATH, "theme_icon_system_default_dark.png"),
    THEME_SYSTEM_DEFAULT
    + "_"
    + THEME_LIGHT: os.path.join(
        ICONS_FOLDER_PATH, "theme_icon_system_default_light.png"
    ),
}
