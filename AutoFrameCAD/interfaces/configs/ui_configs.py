from dataclasses import dataclass

# from constants import UI_ICON_PATH


@dataclass
class UITypeHints:
    """A class used to represent main UI type hints."""

    title: str
    init_size: tuple[int, int]
    init_visibility: bool
    content_margins: tuple[int, int, int, int]


class MainUIConfig(UITypeHints):
    """A class to represent the main UI."""

    def __init__(self):
        super().__init__(
            title='AFC',
            init_size=(600, 400),
            init_visibility=True,
            content_margins=(10, 10, 10, 10),
        )
