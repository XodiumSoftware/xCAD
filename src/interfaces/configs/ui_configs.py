from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout

from constants import UI_ICON_PATH


class UITypeHints:
    """A class used to represent main UI type hints."""

    Title: str
    Layout: QLayout
    Icon_path: str
    Init_size: tuple[int, int]
    Init_visibility: bool
    Content_margins: tuple[int, int, int, int]
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class MainUIConfig(UITypeHints):
    """A class to represent the main UI."""

    Title = "AFC"
    Layout = QVBoxLayout()
    Icon_path = UI_ICON_PATH
    Init_size = (600, 400)
    Init_visibility = True
    Content_margins = (10, 10, 10, 10)
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
