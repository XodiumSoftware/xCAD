from PySide6.QtWidgets import (
    QFormLayout,
    QGridLayout,
    QHBoxLayout,
    QStackedLayout,
    QVBoxLayout,
)
from StenLib.StenEnumUtils import EnumUtils


class LayoutType(EnumUtils):
    """A class that contains layout types."""

    VBOX = QVBoxLayout
    HBOX = QHBoxLayout
    GRID = QGridLayout
    FORM = QFormLayout
    STACKED = QStackedLayout
