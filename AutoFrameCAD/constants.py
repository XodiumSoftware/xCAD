from pathlib import Path

from StenLib import Utils

# General
# =============================================================================
BASE_DIR = Path(__file__).resolve().parent
UTILS = Utils
# =============================================================================

# Icons
# =============================================================================
ICON_DIR = UTILS.forge.dir(BASE_DIR / "icons")
UI_ICON_FILE = ICON_DIR / "ui.svg"
# =============================================================================

# .so Lib files
# =============================================================================
LIB_DIR = UTILS.forge.dir(BASE_DIR / "build")
UTILS_LIB_FILE = LIB_DIR / "test.so"
# =============================================================================

# Database
# =============================================================================
DATABASE_DIR = UTILS.forge.dir(BASE_DIR / "database")
DATABASE_FILE = UTILS.forge.file(DATABASE_DIR / "autoframecad.sqlite")
# =============================================================================
