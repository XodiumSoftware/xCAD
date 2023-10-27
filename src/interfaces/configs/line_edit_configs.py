from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy, QVBoxLayout


class TestLineEditConfig(Enum):
    """A class used to represent a line edit widget"""

    Placeholder = "Test"
    Layout = QVBoxLayout
    Margins = None
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QLineEdit { font-size: 12px; }"
