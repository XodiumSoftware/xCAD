import os

# General
# =============================================================================
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ICONS_FOLDER_PATH = os.path.join(BASE_DIR, 'icons')
ICONS_EXTENSION = '.svg'
DATABASE_FOLDER_PATH = os.path.join(BASE_DIR, 'db')
DATABASE_EXTENSION = '.sqlite'
# =============================================================================

# Database
# =============================================================================
DATABASE_PATH = os.path.join(
    DATABASE_FOLDER_PATH, 'AFCDatabase' + DATABASE_EXTENSION
)
LUMBERTYPES_JSON_PATH = os.path.join(DATABASE_FOLDER_PATH, 'LumberTypes.json')
# =============================================================================

# UI
# =============================================================================
UI_ICON_PATH = os.path.join(ICONS_FOLDER_PATH, 'ui' + ICONS_EXTENSION)
# =============================================================================
