# General
UI_TITLE = "TFCCAD"
UI_FONT_TYPE = "Arial"
UI_GROUPBOX_FONT_SIZE = 10
UI_ICON_PATH = "src/icons/ui_icon.png"
UI_CONTENTS_MARGINS = (1, 1, 1, 1)
UI_STYLE = "fusion"
UI_GROUPBOX_STYLESHEET = "QGroupBox { border: 0; padding-top: 20; }"

COPYRIGHT_LABEL = "© 2023 Qerimi Engineering. All rights reserved."
COPYRIGHT_LABEL_SIZE = 8
COPYRIGHT_LABEL_STYLE = "font-style: italic;"

# Main UI
MAIN_UI_GROUPBOX_TITLE = "Timber Frame Constructions CAD"
MAIN_UI_BUTTON_TEXTS = (
    "TFC Creator",
    "Calculator",
    "COMING SOON",
    "COMING SOON",
    "COMING SOON",
)
MAIN_UI_ICON_PATHS = (
    "src/icons/tfcc_icon_light.png",
    "src/icons/calc_icon_light.png",
    "src/icons/coming-soon_icon_light.png",
    "src/icons/coming-soon_icon_light.png",
    "src/icons/coming-soon_icon_light.png",
)
MAIN_UI_BUTTON_HEIGHT = 50
MAIN_UI_BUTTON_WIDTH = MAIN_UI_BUTTON_HEIGHT

# Config UI
CONFIG_UI_TITLE = "Configurator"
CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0 = (
    "Frame Length:",
    "Frame Height:",
    "Profile Type:",
    "Profile Length:",
    "Profile Width:",
    "Plate Material Type:",
    "Plate Material Thickness:",
)
CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1 = (
    "6000",
    "2500",
    "SLS",
    "170",
    "38",
    "OSBIII",
    "18",
)
CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2 = ("mm", "mm", "", "mm", "mm", "", "mm")

# Others
ICON_TO_BUTTON_MARGIN = 10

BACK_BUTTON = "Back"
ON_BACK_BUTTON_PRESSED_DESC = (
    "Save Changes",
    "Do you want to save the changes before going back?",
)

SAVE_BUTTON = "Save"
SAVE_UI_TEXT = "[DEBUG]: Changes Saved"

DATA_DIR_FOLDER = "src/data"
DATA_DIR_FILE = "input_values.txt"
