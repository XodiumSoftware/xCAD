from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy, QVBoxLayout


class ToggleStartupPageCheckBoxConfig(Enum):
    """A class used to represent a checkbox widget"""

    Title = "Toggle startup page"
    Layout = QVBoxLayout
    Margins = None
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QCheckBox { font-size: 12px; }"
