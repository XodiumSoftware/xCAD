from dataclasses import dataclass

from constants import UI_ICON_PATH


@dataclass
class UIConfig:
    """A class used to represent main UI type hints."""

    background_color: str = 'black'
    content_margins: tuple[int, int, int, int] = (10, 10, 10, 10)
    icon: str = UI_ICON_PATH
    icon_default: bool = True
    init_size: tuple[int, int] = (600, 400)
    init_visibility: bool = True
    resizable: bool = True
    theme: str = 'alt'
    title: str = 'AutoFrameCAD'
