from dataclasses import dataclass

from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


@dataclass
class StatusBarTypeHints:
    """A class used to represent status bar type hints."""

    status_tip: str
    stylesheet: str
    layout: QLayout
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class MainUIStatusBarConfig(StatusBarTypeHints):
    """A class used to represent a status bar config."""

    def __init__(self):
        super().__init__(
            status_tip="TODO: implement this.",
            stylesheet="color: #fff;",
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
        )
