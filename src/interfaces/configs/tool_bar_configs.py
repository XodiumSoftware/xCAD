from dataclasses import dataclass

from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


@dataclass
class ToolBarTypeHints:
    """A class used to represent tool bar type hints."""

    title: str
    stylesheet: str
    layout: QLayout
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class MainUIToolBarConfig(ToolBarTypeHints):
    """A class used to represent a tool bar config."""

    def __init__(self):
        super().__init__(
            title="TODO: implement this.",
            stylesheet="color : white;",
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
        )
