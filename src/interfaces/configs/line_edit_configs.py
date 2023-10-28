from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


class LineEditTypeHints:
    """A class used to represent test line edit config type hints."""

    Placeholder: str
    Stylesheet: str
    Layout: QLayout
    Alignment: Qt.AlignmentFlag
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class TestLineEditConfig(LineEditTypeHints):
    """A class used to represent a line edit config."""

    Placeholder = "Test"
    Stylesheet = "QLineEdit { font-size: 12px; }"
    Layout = QVBoxLayout()
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
