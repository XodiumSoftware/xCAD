from enum import Enum

from constants import UI_ICON_PATH


class UIs(Enum):
    """A class used to represent the UIs."""

    MainUI = {
        "title": "AFC",
        "icon": UI_ICON_PATH,
        "initial_size": (600, 400),
        "initial_visibility": True,
    }
    ConfiguratorUI = {
        "title": "Structure Configurator",
        "icon": UI_ICON_PATH,
        "initial_size": (800, 400),
        "initial_visibility": True,
    }
    Frame2DView = {
        "title": "2D Frame Viewer",
        "icon": UI_ICON_PATH,
        "initial_size": (800, 400),
        "initial_visibility": True,
    }
