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
    """A class to represent a module type."""

    Widget = QWidget
    StackedWidget = QStackedWidget
    Label = QLabel
    CheckBox = QCheckBox
    DoubleSpinBox = QDoubleSpinBox
    LineEdit = QLineEdit
    PushButton = QPushButton
    GraphicsView = QGraphicsView


class LayoutType(Enum):
    """A class to represent a layout type."""

    HBox = QHBoxLayout
    VBox = QVBoxLayout
    Grid = QGridLayout
    Form = QFormLayout


class AlignmentType(Enum):
    """A class to represent an alignment type."""

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
    """A class to represent a size policy type."""

    Minimum = QSizePolicy.Policy.Minimum
    Maximum = QSizePolicy.Policy.Maximum
    Fixed = QSizePolicy.Policy.Fixed
    Preferred = QSizePolicy.Policy.Preferred
    Expanding = QSizePolicy.Policy.Expanding
    MinimumExpanding = QSizePolicy.Policy.MinimumExpanding
    Ignored = QSizePolicy.Policy.Ignored


class OrientationType(Enum):
    """A class to represent an orientation type."""

    Horizontal = Qt.Orientation.Horizontal
    Vertical = Qt.Orientation.Vertical


class GraphicsItemFlagTypes(Enum):
    """A class to represent a graphics item flag type."""

    ItemIsMovable = QGraphicsItem.GraphicsItemFlag.ItemIsMovable
    ItemIsSelectable = QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
    ItemIsFocusable = QGraphicsItem.GraphicsItemFlag.ItemIsFocusable
    ItemClipsToShape = QGraphicsItem.GraphicsItemFlag.ItemClipsToShape
    ItemClipsChildrenToShape = QGraphicsItem.GraphicsItemFlag.ItemClipsChildrenToShape
    ItemIgnoresTransformations = (
        QGraphicsItem.GraphicsItemFlag.ItemIgnoresTransformations
    )
    ItemIgnoresParentOpacity = QGraphicsItem.GraphicsItemFlag.ItemIgnoresParentOpacity
    ItemStacksBehindParent = QGraphicsItem.GraphicsItemFlag.ItemStacksBehindParent
    ItemUsesExtendedStyleOption = (
        QGraphicsItem.GraphicsItemFlag.ItemUsesExtendedStyleOption
    )
    ItemHasNoContents = QGraphicsItem.GraphicsItemFlag.ItemHasNoContents
    ItemSendsGeometryChanges = QGraphicsItem.GraphicsItemFlag.ItemSendsGeometryChanges
    ItemAcceptsInputMethod = QGraphicsItem.GraphicsItemFlag.ItemAcceptsInputMethod
    ItemNegativeZStacksBehindParent = (
        QGraphicsItem.GraphicsItemFlag.ItemNegativeZStacksBehindParent
    )
    ItemIsPanel = QGraphicsItem.GraphicsItemFlag.ItemIsPanel
    ItemContainsChildrenInShape = (
        QGraphicsItem.GraphicsItemFlag.ItemContainsChildrenInShape
    )


class GraphicsItemChangeTypes(Enum):
    """A class to represent a graphics item change type."""

    ItemEnabledChange = QGraphicsItem.GraphicsItemChange.ItemEnabledChange
    ItemEnabledHasChanged = QGraphicsItem.GraphicsItemChange.ItemEnabledHasChanged
    ItemPositionChange = QGraphicsItem.GraphicsItemChange.ItemPositionChange
    ItemPositionHasChanged = QGraphicsItem.GraphicsItemChange.ItemPositionHasChanged
    ItemTransformChange = QGraphicsItem.GraphicsItemChange.ItemTransformChange
    ItemTransformHasChanged = QGraphicsItem.GraphicsItemChange.ItemTransformHasChanged
    ItemRotationChange = QGraphicsItem.GraphicsItemChange.ItemRotationChange
    ItemRotationHasChanged = QGraphicsItem.GraphicsItemChange.ItemRotationHasChanged
    ItemScaleChange = QGraphicsItem.GraphicsItemChange.ItemScaleChange
    ItemScaleHasChanged = QGraphicsItem.GraphicsItemChange.ItemScaleHasChanged
    ItemTransformOriginPointChange = (
        QGraphicsItem.GraphicsItemChange.ItemTransformOriginPointChange
    )
    ItemTransformOriginPointHasChanged = (
        QGraphicsItem.GraphicsItemChange.ItemTransformOriginPointHasChanged
    )
    ItemSelectedChange = QGraphicsItem.GraphicsItemChange.ItemSelectedChange
    ItemSelectedHasChanged = QGraphicsItem.GraphicsItemChange.ItemSelectedHasChanged
    ItemVisibleChange = QGraphicsItem.GraphicsItemChange.ItemVisibleChange
    ItemVisibleHasChanged = QGraphicsItem.GraphicsItemChange.ItemVisibleHasChanged
    ItemParentChange = QGraphicsItem.GraphicsItemChange.ItemParentChange
    ItemParentHasChanged = QGraphicsItem.GraphicsItemChange.ItemParentHasChanged
    ItemChildAddedChange = QGraphicsItem.GraphicsItemChange.ItemChildAddedChange
    ItemChildRemovedChange = QGraphicsItem.GraphicsItemChange.ItemChildRemovedChange
    ItemSceneChange = QGraphicsItem.GraphicsItemChange.ItemSceneChange
    ItemSceneHasChanged = QGraphicsItem.GraphicsItemChange.ItemSceneHasChanged
    ItemCursorChange = QGraphicsItem.GraphicsItemChange.ItemCursorChange
    ItemCursorHasChanged = QGraphicsItem.GraphicsItemChange.ItemCursorHasChanged
    ItemToolTipChange = QGraphicsItem.GraphicsItemChange.ItemToolTipChange
    ItemToolTipHasChanged = QGraphicsItem.GraphicsItemChange.ItemToolTipHasChanged
    ItemFlagsChange = QGraphicsItem.GraphicsItemChange.ItemFlagsChange
    ItemFlagsHaveChanged = QGraphicsItem.GraphicsItemChange.ItemFlagsHaveChanged
    ItemZValueChange = QGraphicsItem.GraphicsItemChange.ItemZValueChange
    ItemZValueHasChanged = QGraphicsItem.GraphicsItemChange.ItemZValueHasChanged
    ItemOpacityChange = QGraphicsItem.GraphicsItemChange.ItemOpacityChange
    ItemOpacityHasChanged = QGraphicsItem.GraphicsItemChange.ItemOpacityHasChanged
    ItemScenePositionHasChanged = (
        QGraphicsItem.GraphicsItemChange.ItemScenePositionHasChanged
    )


class BrushStyleTypes(Enum):
    """A class to represent a brush style type."""

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
    """A class to represent a pen style type."""

    NoPen = Qt.PenStyle.NoPen
    SolidLine = Qt.PenStyle.SolidLine
    DashLine = Qt.PenStyle.DashLine
    DotLine = Qt.PenStyle.DotLine
    DashDotLine = Qt.PenStyle.DashDotLine
    DashDotDotLine = Qt.PenStyle.DashDotDotLine
    CustomDashLine = Qt.PenStyle.CustomDashLine


class RenderHintTypes(Enum):
    """A class to represent a render hint type."""

    Antialiasing = QPainter.RenderHint.Antialiasing
    TextAntialiasing = QPainter.RenderHint.TextAntialiasing
    SmoothPixmapTransform = QPainter.RenderHint.SmoothPixmapTransform
    VerticalSubpixelPositioning = QPainter.RenderHint.VerticalSubpixelPositioning
    LosslessImageRendering = QPainter.RenderHint.LosslessImageRendering
    NonCosmeticBrushPatterns = QPainter.RenderHint.NonCosmeticBrushPatterns


class ScrollBarPolicyTypes(Enum):
    """A class to represent a scroll bar policy type."""

    ScrollBarAsNeeded = Qt.ScrollBarPolicy.ScrollBarAsNeeded
    ScrollBarAlwaysOff = Qt.ScrollBarPolicy.ScrollBarAlwaysOff
    ScrollBarAlwaysOn = Qt.ScrollBarPolicy.ScrollBarAlwaysOn


class DragModeTypes(Enum):
    """A class to represent a drag mode type."""

    NoDrag = QGraphicsView.DragMode.NoDrag
    ScrollHandDrag = QGraphicsView.DragMode.ScrollHandDrag
    RubberBandDrag = QGraphicsView.DragMode.RubberBandDrag
