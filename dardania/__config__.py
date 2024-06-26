"""This module contains configuration settings."""

from pathlib import Path

from dalmatia import Utils

# General
# =============================================================================
BASE_DIR: Path = Path(__file__).resolve().parent
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
USR_THEME: str = "usr_theme"
LIGHT_MODE: str = "light"
DARK_MODE: str = "dark"
PREFERENCES_DATA: dict[str, None | int | float | str | bytes] = {
    USR_THEME: DARK_MODE,
}
ICON_THEMES: dict[str, str] = {
    DARK_MODE: str(DARK_MODE_ICON),
    LIGHT_MODE: str(LIGHT_MODE_ICON),
}
THEMES: dict[str, str] = {DARK_MODE: LIGHT_MODE, LIGHT_MODE: DARK_MODE}
# =============================================================================

# UI
# =============================================================================
WINDOW_TITLE: str = "Dardania"
WINDOW_ICON: Path = ICON_DIR / "illyrion.svg"
WINDOW_MIN_SIZE: tuple[int, int] = 1200, 800
# =============================================================================
