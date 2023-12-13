from dataclasses import dataclass

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


@dataclass
class LineEditTypeHints:
    """A class used to represent test line edit config type hints."""

    placeholder: str
    stylesheet: str
    layout: QLayout
    alignment: Qt.AlignmentFlag
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class TestLineEditConfig(LineEditTypeHints):
    """A class used to represent a line edit config."""

    def __init__(self):
        super().__init__(
            placeholder="Test",
            stylesheet="QLineEdit { font-size: 12px; }",
            layout=QVBoxLayout(),
            alignment=Qt.AlignmentFlag.AlignBottom,
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
        )
