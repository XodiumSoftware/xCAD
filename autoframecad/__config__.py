"""This module contains configuration settings for AutoFrameCAD."""

from pathlib import Path

from stenlib import Utils

# General
# =============================================================================
BASE_DIR: Path = Path(__file__).resolve().parent
# =============================================================================

# Icons
# =============================================================================
ICON_DIR: Path = Utils.forge.dir(BASE_DIR / "icons")
UI_ICON_FILE: Path = ICON_DIR / "ui.svg"
# =============================================================================

# .so Lib files
# =============================================================================
LIB_DIR: Path = Utils.forge.dir(BASE_DIR / "build")
UTILS_LIB_FILE: Path = LIB_DIR / "test.so"
# =============================================================================

# Database
# =============================================================================
DATABASE_DIR: Path = Utils.forge.dir(BASE_DIR / "database")
DATABASE_FILE: Path = Utils.forge.file(DATABASE_DIR / "autoframecad.sqlite")
# =============================================================================
