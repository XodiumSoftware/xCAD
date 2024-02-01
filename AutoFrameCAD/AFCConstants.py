from pathlib import Path

# General
# =============================================================================
BASE_DIR = Path(__file__).resolve().parent
ICONS_FOLDER_PATH = BASE_DIR / 'icons'
ICONS_EXTENSION = '.svg'
DATABASE_FOLDER_PATH = BASE_DIR / 'db'
DATABASE_EXTENSION = '.sqlite'
# =============================================================================

# Database
# =============================================================================
DATABASE_PATH = DATABASE_FOLDER_PATH / f'AFCDatabase{DATABASE_EXTENSION}'
LUMBERTYPES_JSON_PATH = DATABASE_FOLDER_PATH / 'LumberTypes.json'
# =============================================================================

# UI
# =============================================================================
UI_ICON_PATH = ICONS_FOLDER_PATH / f'ui{ICONS_EXTENSION}'
# =============================================================================
