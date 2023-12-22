from dataclasses import dataclass

from constants import UI_ICON_PATH


@dataclass
class UITypeHints:
    """A class used to represent main UI type hints."""

    background_color: str
    content_margins: tuple[int, int, int, int]
    icon: str
    icon_default: bool
    init_size: tuple[int, int]
    init_visibility: bool
    resizable: bool
    theme: str
    title: str


class MainUIConfig(UITypeHints):
    """A class to represent the main UI."""

    def __init__(self):
        super().__init__(
            background_color='black',
            content_margins=(10, 10, 10, 10),
            icon=UI_ICON_PATH,
            icon_default=True,
            init_size=(600, 400),
            init_visibility=True,
            resizable=True,
            theme='alt',
            title='AFC',
        )
