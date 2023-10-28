import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


class DoubleSpinBoxTypeHints:
    """A class used to represent double spinbox type hints."""

    Stylesheet: str
    Min_value: float
    Max_value: float
    Default_value: float
    Step: float
    Suffix: str
    Layout: QLayout
    Alignment: Qt.AlignmentFlag
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class DefaultDoubleSpinBoxConfig(DoubleSpinBoxTypeHints):
    """A class used to represent a double spinbox config."""

    Stylesheet = "QSpinBox { font-size: 12px; }"
    Min_value = 0
    Max_value = sys.float_info.max
    Default_value = 0
    Step = 0.5
    Suffix = "mm"
    Layout = QVBoxLayout()
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
