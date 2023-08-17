from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtGui import QPainter
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QFormLayout,
    QGraphicsItem,
    QGraphicsView,
    QGridLayout,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QStackedWidget,
    QVBoxLayout,
    QWidget,
)


class ModuleType(Enum):
    Widget = QWidget
    StackedWidget = QStackedWidget
    Label = QLabel
    CheckBox = QCheckBox
    DoubleSpinBox = QDoubleSpinBox
    LineEdit = QLineEdit
    PushButton = QPushButton


class LayoutType(Enum):
    HBox = QHBoxLayout
    VBox = QVBoxLayout
    Grid = QGridLayout
    Form = QFormLayout


class AlignmentType(Enum):
    AlignLeading = Qt.AlignmentFlag.AlignLeading
    AlignLeft = Qt.AlignmentFlag.AlignLeft
    AlignRight = Qt.AlignmentFlag.AlignRight
    AlignTrailing = Qt.AlignmentFlag.AlignTrailing
    AlignHCenter = Qt.AlignmentFlag.AlignHCenter
    AlignVCenter = Qt.AlignmentFlag.AlignVCenter
    AlignJustify = Qt.AlignmentFlag.AlignJustify
    AlignAbsolute = Qt.AlignmentFlag.AlignAbsolute
    AlignHorizontalMask = Qt.AlignmentFlag.AlignHorizontal_Mask
    AlignTop = Qt.AlignmentFlag.AlignTop
    AlignBottom = Qt.AlignmentFlag.AlignBottom
    AlignCenter = Qt.AlignmentFlag.AlignCenter
    AlignBaseline = Qt.AlignmentFlag.AlignBaseline
    AlignVerticalMask = Qt.AlignmentFlag.AlignVertical_Mask


class SizePolicyType(Enum):
    Minimum = QSizePolicy.Policy.Minimum
    Maximum = QSizePolicy.Policy.Maximum
    Fixed = QSizePolicy.Policy.Fixed
    Preferred = QSizePolicy.Policy.Preferred
    Expanding = QSizePolicy.Policy.Expanding
    MinimumExpanding = QSizePolicy.Policy.MinimumExpanding
    Ignored = QSizePolicy.Policy.Ignored


class OrientationType(Enum):
    Horizontal = Qt.Orientation.Horizontal
    Vertical = Qt.Orientation.Vertical


class GraphicsItemFlagTypes(Enum):
    IsMovable = QGraphicsItem.GraphicsItemFlag.ItemIsMovable
    IsSelectable = QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
    IsFocusable = QGraphicsItem.GraphicsItemFlag.ItemIsFocusable
    ClipsToShape = QGraphicsItem.GraphicsItemFlag.ItemClipsToShape
    ClipsChildrenToShape = QGraphicsItem.GraphicsItemFlag.ItemClipsChildrenToShape
    IgnoresTransformations = QGraphicsItem.GraphicsItemFlag.ItemIgnoresTransformations
    IgnoresParentOpacity = QGraphicsItem.GraphicsItemFlag.ItemIgnoresParentOpacity
    DoesntPropagateOpacityToChildren = (
        QGraphicsItem.GraphicsItemFlag.ItemStacksBehindParent
    )
    StacksBehindParent = QGraphicsItem.GraphicsItemFlag.ItemStacksBehindParent
    UsesExtendedStyleOption = QGraphicsItem.GraphicsItemFlag.ItemUsesExtendedStyleOption
    HasNoContents = QGraphicsItem.GraphicsItemFlag.ItemHasNoContents
    SendsGeometryChanges = QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
    AcceptsInputMethod = QGraphicsItem.GraphicsItemFlag.ItemAcceptsInputMethod
    NegativeZStacksBehindParent = (
        QGraphicsItem.GraphicsItemFlag.ItemNegativeZStacksBehindParent
    )
    IsPanel = QGraphicsItem.GraphicsItemFlag.ItemIsPanel
    ContainsChildrenInShape = QGraphicsItem.GraphicsItemFlag.ItemContainsChildrenInShape


class BrushStyleTypes(Enum):
    NoBrush = Qt.BrushStyle.NoBrush
    SolidPattern = Qt.BrushStyle.SolidPattern
    Dense1Pattern = Qt.BrushStyle.Dense1Pattern
    Dense2Pattern = Qt.BrushStyle.Dense2Pattern
    Dense3Pattern = Qt.BrushStyle.Dense3Pattern
    Dense4Pattern = Qt.BrushStyle.Dense4Pattern
    Dense5Pattern = Qt.BrushStyle.Dense5Pattern
    Dense6Pattern = Qt.BrushStyle.Dense6Pattern
    Dense7Pattern = Qt.BrushStyle.Dense7Pattern
    HorizontalPattern = Qt.BrushStyle.HorPattern
    VerticalPattern = Qt.BrushStyle.VerPattern
    CrossPattern = Qt.BrushStyle.CrossPattern
    BDiagonalPattern = Qt.BrushStyle.BDiagPattern
    FDiagonalPattern = Qt.BrushStyle.FDiagPattern
    DiagCrossPattern = Qt.BrushStyle.DiagCrossPattern
    LinearPattern = Qt.BrushStyle.LinearGradientPattern
    RadialPattern = Qt.BrushStyle.RadialGradientPattern
    ConicalPattern = Qt.BrushStyle.ConicalGradientPattern
    TexturePattern = Qt.BrushStyle.TexturePattern


class PenStyleTypes(Enum):
    NoPen = Qt.PenStyle.NoPen
    SolidLine = Qt.PenStyle.SolidLine
    DashLine = Qt.PenStyle.DashLine
    DotLine = Qt.PenStyle.DotLine
    DashDotLine = Qt.PenStyle.DashDotLine
    DashDotDotLine = Qt.PenStyle.DashDotDotLine
    CustomDashLine = Qt.PenStyle.CustomDashLine


class RenderHintTypes(Enum):
    Antialiasing = QPainter.RenderHint.Antialiasing
    TextAntialiasing = QPainter.RenderHint.TextAntialiasing
    SmoothPixmapTransform = QPainter.RenderHint.SmoothPixmapTransform
    VerticalSubpixelPositioning = QPainter.RenderHint.VerticalSubpixelPositioning
    LosslessImageRendering = QPainter.RenderHint.LosslessImageRendering
    NonCosmeticBrushPatterns = QPainter.RenderHint.NonCosmeticBrushPatterns


class ScrollBarPolicyTypes(Enum):
    ScrollBarAsNeeded = Qt.ScrollBarPolicy.ScrollBarAsNeeded
    ScrollBarAlwaysOff = Qt.ScrollBarPolicy.ScrollBarAlwaysOff
    ScrollBarAlwaysOn = Qt.ScrollBarPolicy.ScrollBarAlwaysOn


class DragModeTypes(Enum):
    NoDrag = QGraphicsView.DragMode.NoDrag
    ScrollHandDrag = QGraphicsView.DragMode.ScrollHandDrag
    RubberBandDrag = QGraphicsView.DragMode.RubberBandDrag


class AspectRatioModeTypes(Enum):
    IgnoreAspectRatio = Qt.AspectRatioMode.IgnoreAspectRatio
    KeepAspectRatio = Qt.AspectRatioMode.KeepAspectRatio
    KeepAspectRatioByExpanding = Qt.AspectRatioMode.KeepAspectRatioByExpanding
