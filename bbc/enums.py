from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QFormLayout,
    QGridLayout,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
    QWidget,
)


class ModuleType(Enum):
    """An enumeration of the module types."""

    WIDGET = QWidget
    LABEL = QLabel
    CHECKBOX = QCheckBox
    DOUBLESPINBOX = QDoubleSpinBox
    INPUTFIELD = QLineEdit
    BUTTON = QPushButton


class LayoutType(Enum):
    """An enumeration of the layout types."""

    HBOX = QHBoxLayout
    VBOX = QVBoxLayout
    GRID = QGridLayout
    FORM = QFormLayout


class AlignmentType(Enum):
    """An enumeration of the alignment types."""

    ALIGNLEADING = Qt.AlignmentFlag.AlignLeading
    ALIGNLEFT = Qt.AlignmentFlag.AlignLeft
    ALIGNRIGHT = Qt.AlignmentFlag.AlignRight
    ALIGNTRAILING = Qt.AlignmentFlag.AlignTrailing
    ALIGNHCENTER = Qt.AlignmentFlag.AlignHCenter
    ALIGNVCENTER = Qt.AlignmentFlag.AlignVCenter
    ALIGNJUSTIFY = Qt.AlignmentFlag.AlignJustify
    ALIGNABSOLUTE = Qt.AlignmentFlag.AlignAbsolute
    ALIGNHORIZONTALMASK = Qt.AlignmentFlag.AlignHorizontal_Mask
    ALIGNTOP = Qt.AlignmentFlag.AlignTop
    ALIGNBOTTOM = Qt.AlignmentFlag.AlignBottom
    ALIGNCENTER = Qt.AlignmentFlag.AlignCenter
    ALIGNBASELINE = Qt.AlignmentFlag.AlignBaseline
    ALIGNVERTICALMASK = Qt.AlignmentFlag.AlignVertical_Mask


class SizePolicyType(Enum):
    """An enumeration of the size policy types."""

    MINIMUM = QSizePolicy.Policy.Minimum
    MAXIMUM = QSizePolicy.Policy.Maximum
    FIXED = QSizePolicy.Policy.Fixed
    PREFERRED = QSizePolicy.Policy.Preferred
    EXPANDING = QSizePolicy.Policy.Expanding
    MINIMUM_EXPANDING = QSizePolicy.Policy.MinimumExpanding
    IGNORED = QSizePolicy.Policy.Ignored


class OrientationType(Enum):
    """An enumeration of the orientation types."""

    HORIZONTAL = Qt.Orientation.Horizontal
    VERTICAL = Qt.Orientation.Vertical
