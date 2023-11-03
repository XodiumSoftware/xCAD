from dataclasses import dataclass

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


@dataclass
class DoubleSpinBoxTypeHints:
    """A class used to represent double spinbox type hints."""

    stylesheet: str
    min_value: float
    max_value: float
    default_value: float
    step: float
    suffix: str
    layout: QLayout
    alignment: Qt.AlignmentFlag
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class DefaultDoubleSpinBoxConfig(DoubleSpinBoxTypeHints):
    """A class used to represent a double spinbox config."""

    def __init__(self):
        super().__init__(
            stylesheet="QDoubleSpinBox { font-size: 12px; }",
            min_value=0.0,
            max_value=100.0,
            default_value=0.0,
            step=0.1,
            suffix="%",
            layout=QVBoxLayout(),
            alignment=Qt.AlignmentFlag.AlignBottom,
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
        )
