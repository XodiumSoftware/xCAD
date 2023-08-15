from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QFormLayout,
    QGraphicsItem,
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


class GraphicsItemFlagTypes(Enum):
    """An enumeration of the graphics item flag types."""

    ISMOVABLE = QGraphicsItem.GraphicsItemFlag.ItemIsMovable
    ISSELECTABLE = QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
    ISFOCUSABLE = QGraphicsItem.GraphicsItemFlag.ItemIsFocusable
    CLIPSTOSHAPE = QGraphicsItem.GraphicsItemFlag.ItemClipsToShape
    CLIPSCHILDRENTOSHAPE = QGraphicsItem.GraphicsItemFlag.ItemClipsChildrenToShape
    IGNORESTRANSFORMATIONS = QGraphicsItem.GraphicsItemFlag.ItemIgnoresTransformations
    IGNORESPARENTOPACITY = QGraphicsItem.GraphicsItemFlag.ItemIgnoresParentOpacity
    DOESNTPROPAGATEOPACITYTOCHILDREN = (
        QGraphicsItem.GraphicsItemFlag.ItemStacksBehindParent
    )
    STACKSBEHINDPARENT = QGraphicsItem.GraphicsItemFlag.ItemStacksBehindParent
    USESEXTENEDSTYLEOPTION = QGraphicsItem.GraphicsItemFlag.ItemUsesExtendedStyleOption
    HASNOCONTENTS = QGraphicsItem.GraphicsItemFlag.ItemHasNoContents
    SENDSGEOMETRYCHANGES = QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
    ACCEPTSINPUTMETHOD = QGraphicsItem.GraphicsItemFlag.ItemAcceptsInputMethod
    NEGATIVEZSTACKSBEHINDPARENT = (
        QGraphicsItem.GraphicsItemFlag.ItemNegativeZStacksBehindParent
    )
    ISPANEL = QGraphicsItem.GraphicsItemFlag.ItemIsPanel
    CONTAINSCHILDRENINSHAPE = QGraphicsItem.GraphicsItemFlag.ItemContainsChildrenInShape


class BrushStyleTypes(Enum):
    """An enumeration of the brush style types."""

    NOBRUSH = Qt.BrushStyle.NoBrush
    SOLIDPATTERN = Qt.BrushStyle.SolidPattern
    DENSE1PATTERN = Qt.BrushStyle.Dense1Pattern
    DENSE2PATTERN = Qt.BrushStyle.Dense2Pattern
    DENSE3PATTERN = Qt.BrushStyle.Dense3Pattern
    DENSE4PATTERN = Qt.BrushStyle.Dense4Pattern
    DENSE5PATTERN = Qt.BrushStyle.Dense5Pattern
    DENSE6PATTERN = Qt.BrushStyle.Dense6Pattern
    DENSE7PATTERN = Qt.BrushStyle.Dense7Pattern
    HORIZONTALPATTERN = Qt.BrushStyle.HorPattern
    VERTICALPATTERN = Qt.BrushStyle.VerPattern
    CROSSPATTERN = Qt.BrushStyle.CrossPattern
    BDIAGONALPATTERN = Qt.BrushStyle.BDiagPattern
    FDIAGONALPATTERN = Qt.BrushStyle.FDiagPattern
    DIAGCROSSPATTERN = Qt.BrushStyle.DiagCrossPattern
    LINEARPATTERN = Qt.BrushStyle.LinearGradientPattern
    RADIALPATTERN = Qt.BrushStyle.RadialGradientPattern
    CONICALPATTERN = Qt.BrushStyle.ConicalGradientPattern
    TEXTUREPATTERN = Qt.BrushStyle.TexturePattern


class PenStyleTypes(Enum):
    """An enumeration of the pen style types."""

    NOPEN = Qt.PenStyle.NoPen
    SOLIDLINE = Qt.PenStyle.SolidLine
    DASHLINE = Qt.PenStyle.DashLine
    DOTLINE = Qt.PenStyle.DotLine
    DASHDOTLINE = Qt.PenStyle.DashDotLine
    DASHDOTDOTLINE = Qt.PenStyle.DashDotDotLine
    CUSTOMDASHLINE = Qt.PenStyle.CustomDashLine
