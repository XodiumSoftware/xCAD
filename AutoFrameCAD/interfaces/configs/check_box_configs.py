from dataclasses import dataclass

from PySide6.QtWidgets import QSizePolicy, QVBoxLayout


@dataclass
class CheckBoxTypeHints:
    """A class used to represent checkbox type hints."""

    title: str
    stylesheet: str
    layout: QVBoxLayout
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class ToggleStartupPageCheckBoxConfig(CheckBoxTypeHints):
    """A class used to represent a checkbox config."""

    def __init__(self):
        super().__init__(
            title="Toggle startup page",
            stylesheet="QCheckBox { font-size: 12px; }",
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
        )
