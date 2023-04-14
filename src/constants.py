# These are variables that store values related to the user interface of a Timber Frame Constructions
# CAD software. They include the title of the main window, the title of a group box, the path to the
# main window icon, the margins of the main window contents, the texts and size of buttons in the main
# window, the window style, the path to the icons of the main window buttons, and the copyright label.
# These variables can be used to customize the appearance and functionality of the software.
UI_TITLE = "TFCCAD"
MAIN_UI_GROUPBOX_TITLE = "Timber Frame Constructions CAD"
TFCC_UI_GROUPBOX_TITLE = "Timber Frame Constructions Creator"
UI_GROUPBOX_FONT_TYPE = "Arial"
UI_GROUPBOX_FONT_SIZE = 10
UI_ICON_PATH = "src/icons/ui_icon.png"
UI_CONTENTS_MARGINS = (1, 1, 1, 1)
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
UI_STYLE = "fusion"
COPYRIGHT_LABEL = "© 2023 Qerimi Engineering. All rights reserved."
COPYRIGHT_LABEL_SIZE = 8
COPYRIGHT_LABEL_STYLE = "font-style: italic;"
UI_GROUPBOX_STYLESHEET = "QGroupBox { border: 0; padding-top: 20; }"
ICON_TO_BUTTON_MARGIN = 10
TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0 = (
    "Frame Length",
    "Frame Height",
    "Profile Type",
    "Profile Length",
    "Profile Width",
    "Plate Material Type",
    "Plate Material Thickness",
)
TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1 = (
    "6000",
    "2500",
    "SLS",
    "170",
    "38",
    "OSBIII",
    "18",
)
TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2 = ("mm", "mm", "", "mm", "mm", "", "mm")
BACK_BUTTON = "Back"
SAVE_BUTTON = "Save"
SAVE_UI_TEXT = "Changes Saved"
DATA_DIR_FOLDER = "data"
DATA_DIR_FILE = "input_values.txt"
ON_BACK_BUTTON_PRESSED_DESC = (
    "Save Changes",
    "Do you want to save the changes before going back?",
)
