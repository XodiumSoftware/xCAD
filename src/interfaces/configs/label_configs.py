from typing import Tuple

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


class LabelTypeHints:
    """A class used to represent label type hints."""

    Title: str
    Stylesheet: str
    Layout: QLayout
    Margin: int
    Alignment: Qt.AlignmentFlag
    SizePolicy: Tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class CopyrightLabelConfig(LabelTypeHints):
    """A class used to represent a label configuration."""

    Title = "© 2023 Qerimi Engineering. All rights reserved."
    Stylesheet = "QLabel { font-size: 12px; font-style: italic; }"
    Layout = QVBoxLayout()
    Margin = 0
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
