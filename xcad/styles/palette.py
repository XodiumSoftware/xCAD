"""This module contains the palette functionality."""

from PySide6.QtGui import QColor, QPalette

from xcad.__config__ import DARK_MODE, LIGHT_MODE

# Dark palette colors
# =============================================================================
DARK_BASE_COLOR: dict[QPalette.ColorRole, tuple[int, int, int, int]] = {
    QPalette.ColorRole.WindowText: (228, 231, 235, 255),
    QPalette.ColorRole.Button: (32, 33, 36, 255),
    QPalette.ColorRole.Text: (239, 241, 241, 255),
    QPalette.ColorRole.ButtonText: (138, 180, 247, 255),
    QPalette.ColorRole.Base: (32, 33, 36, 255),
    QPalette.ColorRole.Window: (32, 33, 36, 255),
    QPalette.ColorRole.Highlight: (138, 180, 247, 255),
    QPalette.ColorRole.HighlightedText: (32, 33, 36, 255),
    QPalette.ColorRole.Link: (32, 33, 36, 255),
    QPalette.ColorRole.AlternateBase: (41, 43, 46, 255),
    QPalette.ColorRole.ToolTipBase: (228, 231, 235, 255),
    QPalette.ColorRole.ToolTipText: (41, 42, 45, 255),
    QPalette.ColorRole.LinkVisited: (197, 138, 248, 255),
    QPalette.ColorRole.Light: (63, 64, 66, 255),
    QPalette.ColorRole.Midlight: (63, 64, 66, 255),
    QPalette.ColorRole.Dark: (228, 231, 235, 255),
    QPalette.ColorRole.Mid: (63, 64, 66, 255),
    QPalette.ColorRole.Shadow: (63, 64, 66, 255),
}

DARK_DISABLED_COLOR: dict[QPalette.ColorRole, tuple[int, int, int, int]] = {
    QPalette.ColorRole.WindowText: (105, 113, 119, 255),
    QPalette.ColorRole.Text: (105, 113, 119, 255),
    QPalette.ColorRole.ButtonText: (63, 64, 66, 255),
    QPalette.ColorRole.Highlight: (83, 87, 91, 255),
    QPalette.ColorRole.HighlightedText: (105, 113, 119, 255),
    QPalette.ColorRole.Link: (105, 113, 119, 255),
    QPalette.ColorRole.LinkVisited: (105, 113, 119, 255),
}

DARK_INACTIVE_COLOR: dict[QPalette.ColorRole, tuple[int, int, int, int]] = {
    QPalette.ColorRole.Highlight: (57, 61, 65, 255),
}
# =============================================================================

# Light palette colors
# =============================================================================
LIGHT_BASE_COLOR: dict[QPalette.ColorRole, tuple[int, int, int, int]] = {
    QPalette.ColorRole.WindowText: (77, 81, 87, 255),
    QPalette.ColorRole.Button: (248, 249, 250, 255),
    QPalette.ColorRole.Text: (77, 81, 87, 255),
    QPalette.ColorRole.ButtonText: (0, 129, 219, 255),
    QPalette.ColorRole.Base: (248, 249, 250, 255),
    QPalette.ColorRole.Window: (248, 249, 250, 255),
    QPalette.ColorRole.Highlight: (0, 129, 219, 255),
    QPalette.ColorRole.HighlightedText: (248, 249, 250, 255),
    QPalette.ColorRole.Link: (248, 249, 250, 255),
    QPalette.ColorRole.AlternateBase: (233, 236, 239, 255),
    QPalette.ColorRole.ToolTipBase: (255, 255, 255, 255),
    QPalette.ColorRole.ToolTipText: (77, 81, 87, 255),
    QPalette.ColorRole.LinkVisited: (102, 0, 152, 255),
    QPalette.ColorRole.ToolTipText: (255, 255, 255, 255),
    QPalette.ColorRole.ToolTipBase: (77, 81, 87, 255),
    QPalette.ColorRole.Light: (218, 220, 224, 255),
    QPalette.ColorRole.Midlight: (218, 220, 224, 255),
    QPalette.ColorRole.Dark: (77, 81, 87, 255),
    QPalette.ColorRole.Mid: (218, 220, 224, 255),
    QPalette.ColorRole.Shadow: (218, 220, 224, 255),
}

LIGHT_DISABLED_COLOR: dict[QPalette.ColorRole, tuple[int, int, int, int]] = {
    QPalette.ColorRole.WindowText: (186, 189, 194, 255),
    QPalette.ColorRole.Text: (186, 189, 194, 255),
    QPalette.ColorRole.ButtonText: (218, 220, 224, 255),
    QPalette.ColorRole.Highlight: (218, 220, 224, 255),
    QPalette.ColorRole.HighlightedText: (186, 189, 194, 255),
    QPalette.ColorRole.Link: (186, 189, 194, 255),
    QPalette.ColorRole.LinkVisited: (186, 189, 194, 255),
}

LIGHT_INACTIVE_COLOR: dict[QPalette.ColorRole, tuple[int, int, int, int]] = {
    QPalette.ColorRole.Highlight: (228, 230, 242, 255),
}
# =============================================================================


def create_palette(theme: str = DARK_MODE) -> QPalette:
    """Create a palette.

    Args:
        theme: The theme to use (DARK_MODE | LIGHT_MODE).
            Defaults to DARK_MODE.
    """
    _palette = QPalette()

    if theme == DARK_MODE:
        base_color = DARK_BASE_COLOR
        disabled_color = DARK_DISABLED_COLOR
        inactive_color = DARK_INACTIVE_COLOR
    elif theme == LIGHT_MODE:
        base_color = LIGHT_BASE_COLOR
        disabled_color = LIGHT_DISABLED_COLOR
        inactive_color = LIGHT_INACTIVE_COLOR
    else:
        err_msg = f"Invalid theme: {theme}"
        raise ValueError(err_msg)

    for role, color in base_color.items():
        _palette.setColor(role, QColor(*color))

    for role, color in disabled_color.items():
        _palette.setColor(QPalette.ColorGroup.Disabled, role, QColor(*color))

    for role, color in inactive_color.items():
        _palette.setColor(QPalette.ColorGroup.Inactive, role, QColor(*color))

    return _palette
