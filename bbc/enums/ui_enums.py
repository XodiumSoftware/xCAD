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
