from pathlib import Path

# General
# =============================================================================
BASE_DIR = Path(__file__).resolve().parent
# =============================================================================

# Database
# =============================================================================
DATABASE_FOLDER_PATH = BASE_DIR / "db"
DATABASE_PATH = DATABASE_FOLDER_PATH / "AFCDatabase.sqlite"
# =============================================================================

# Json
# =============================================================================
JSON_FOLDER_PATH = BASE_DIR / "json"
# =============================================================================

# Icons
# =============================================================================
ICONS_FOLDER_PATH = BASE_DIR / "icons"
UI_ICON_PATH = ICONS_FOLDER_PATH / "ui.svg"
# =============================================================================
