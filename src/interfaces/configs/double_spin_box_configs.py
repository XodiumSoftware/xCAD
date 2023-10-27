import sys
from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy, QVBoxLayout


class DefaultDoubleSpinBox(Enum):
    """A class used to represent a double spinbox widget"""

    Layout = QVBoxLayout
    Margins = None
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QSpinBox { font-size: 12px; }"
    Min_value = 0
    Max_value = sys.float_info.max
    Default_value = 0
    Step = 0.5
    Suffix = "mm"
