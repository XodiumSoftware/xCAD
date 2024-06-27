"""This module contains configuration settings."""

from pathlib import Path

from dalmatia import Utils

# General
# =============================================================================
BASE_DIR: Path = Path(__file__).resolve().parent
UTF: str = "utf-8"
# =============================================================================

# Icons
# =============================================================================
ICON_DIR: Path = Utils.forge.dir(BASE_DIR / "icons")
DARK_MODE_ICON: Path = ICON_DIR / "dark_mode_icon.svg"
LIGHT_MODE_ICON: Path = ICON_DIR / "light_mode_icon.svg"
# =============================================================================

# .so Lib files
# =============================================================================
LIB_DIR: Path = Utils.forge.dir(BASE_DIR / "build")
UTILS_LIB_FILE: Path = LIB_DIR / "test.so"
# =============================================================================

# Database
# =============================================================================
DATABASE_DIR: Path = Utils.forge.dir(BASE_DIR / "database")
DATABASE_FILE: Path = Utils.forge.file(DATABASE_DIR / "dardania.db")

USR_THEME_KEY: str = "usr_theme"
TREE_STATE_KEY: str = "tree_state"
SPLITTER_STATE_KEY: str = "splitter_state"

LIGHT_MODE: str = "light"
DARK_MODE: str = "dark"

PREFERENCES_DATA: dict[str, None | int | float | str | bytes] = {
    USR_THEME_KEY: DARK_MODE,
}
# =============================================================================

# Themes
# =============================================================================
THEMES: dict[str, str] = {DARK_MODE: LIGHT_MODE, LIGHT_MODE: DARK_MODE}
THEME_ICONS: dict[str, str] = {
    DARK_MODE: str(DARK_MODE_ICON),
    LIGHT_MODE: str(LIGHT_MODE_ICON),
}
# =============================================================================

# UI
# =============================================================================
WINDOW_TITLE: str = "Dardania"
WINDOW_ICON: Path = ICON_DIR / "illyrion.svg"
WINDOW_MIN_SIZE: tuple[int, int] = 1200, 800
# =============================================================================
