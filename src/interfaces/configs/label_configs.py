from dataclasses import dataclass

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


@dataclass
class LabelTypeHints:
    """A class used to represent label type hints."""

    title: str
    stylesheet: str
    layout: QLayout
    margin: int
    alignment: Qt.AlignmentFlag
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class CopyrightLabelConfig(LabelTypeHints):
    """A class used to represent a label config."""

    def __init__(self):
        super().__init__(
            title="© 2023 Qerimi Engineering. All rights reserved.",
            stylesheet="QLabel { font-size: 12px; font-style: italic; }",
            layout=QVBoxLayout(),
            margin=0,
            alignment=Qt.AlignmentFlag.AlignBottom,
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
        )
