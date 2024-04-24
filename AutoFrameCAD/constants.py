from pathlib import Path

from StenLib import Utils

# General
# =============================================================================
BASE_DIR = Path(__file__).resolve().parent
# =============================================================================

# Icons
# =============================================================================
ICON_DIR = Utils.forge.dir(BASE_DIR / "icons")
UI_ICON_FILE = ICON_DIR / "ui.svg"
# =============================================================================

# .so Lib files
# =============================================================================
LIB_DIR = Utils.forge.dir(BASE_DIR / "build")
UTILS_LIB_FILE = LIB_DIR / "test.so"
# =============================================================================

# Database
# =============================================================================
DATABASE_DIR = Utils.forge.dir(BASE_DIR / "database")
DATABASE_FILE = Utils.forge.file(DATABASE_DIR / "autoframecad.sqlite")
# =============================================================================
