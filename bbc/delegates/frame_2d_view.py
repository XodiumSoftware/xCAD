import sys
from typing import Optional

from handlers.events_handler import EventsHandler
from PySide6.QtCore import QRectF, QSettings, Qt
from PySide6.QtGui import (
    QBrush,
    QColor,
    QKeyEvent,
    QMouseEvent,
    QPainter,
    QPen,
    QResizeEvent,
)
from PySide6.QtWidgets import (
    QDialog,
    QDoubleSpinBox,
    QGraphicsItem,
    QGraphicsScene,
    QGraphicsView,
    QGridLayout,
    QLabel,
    QMessageBox,
    QPushButton,
    QSizePolicy,
    QWidget,
)


class DimensionDialog(QDialog):
    """A dialog for setting the dimensions (lxb)."""

    def __init__(self, length: float, height: float, parent: Optional[QWidget] = None):
        """Initialize the dialog."""
        super().__init__(parent)
        self._changes_made = False
        self._events_handler = EventsHandler()
        self.setup_ui(length, height)

    def setup_ui(self, length: float, height: float):
        """Setup the UI."""
        self.setWindowTitle("Set Dimensions")

        self.length_edit = QDoubleSpinBox()
        self.height_edit = QDoubleSpinBox()
        self.ok_button = QPushButton("OK")

        layout = QGridLayout()

        layout.addWidget(QLabel("Length:"), 0, 0)
        layout.addWidget(self.length_edit, 0, 1)

        layout.addWidget(QLabel("Height:"), 1, 0)
        layout.addWidget(self.height_edit, 1, 1)

        layout.addWidget(self.ok_button, 2, 0, 1, 2)
        self.setLayout(layout)

        max_double_value = sys.float_info.max

        self.length_edit.setValue(length)
        self.length_edit.setRange(0, max_double_value)
        self.length_edit.setDecimals(0)
        self.length_edit.setSuffix(" mm")

        self.height_edit.setValue(height)
        self.height_edit.setRange(0, max_double_value)
        self.height_edit.setDecimals(0)
        self.height_edit.setSuffix(" mm")

        self.ok_button.clicked.connect(self.accept_changes)

    def accept_changes(self):
        """Accept the changes."""
        self._changes_made = True
        self.setWindowTitle("Set Dimensions *")
        self.accept()

    def reject(self):
        """Reject the changes."""
        if self._changes_made:
            self._events_handler.show_quit_message_box()
        else:
            super().reject()

    def keyPressEvent(self, event: QKeyEvent):
        """Handle the key press event."""
        if event.key() == Qt.Key.Key_Enter or event.key() == Qt.Key.Key_Return:
            if self.length_edit.hasFocus() or self.height_edit.hasFocus():
                self._changes_made = True
                event.accept()
        elif event.key() == Qt.Key.Key_Escape:
            if self._changes_made:
                self.reject()
            else:
                super().reject()

    def exec_(self):
        """Execute the dialog."""
        result = super().exec_()
        if result == QDialog.DialogCode.Accepted:
            self._changes_made = True
        return result

    def load_dialog_values(self, length: float, height: float):
        """Load values into the dialog."""
        self.length_edit.setValue(length)
        self.height_edit.setValue(height)


class Frame2DView(QGraphicsView):
    """A class to represent a 2D frame view."""

    def __init__(
        self, module_data: Optional[dict] = None, parent: Optional[QWidget] = None
    ):
        """Initialize the 2D frame view."""
        super().__init__(parent)
        self.module_data = module_data
        self._settings = QSettings()
        self.load_item_values()
        self.setup_frame_2d_view()

    def setup_frame_2d_view(self):
        """Setup the frame 2D view."""
        self._scene = QGraphicsScene(self)
        self.setScene(self._scene)

        self._scene.setBackgroundBrush(QColor(0, 0, 0))

        self.setTransformationAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.ViewportAnchor.AnchorUnderMouse)
        self.setMinimumSize(300, 300)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)

        self.create_items()

    def drawBackground(self, painter: QPainter, rect: QRectF):
        """Draw the background."""
        super().drawBackground(painter, rect)

        painter.setPen(QPen(QColor(200, 200, 200), 0.5, Qt.PenStyle.SolidLine))
        grid_size = 50
        left = int(rect.left()) - (int(rect.left()) % grid_size)
        top = int(rect.top()) - (int(rect.top()) % grid_size)

        lines = []
        for x in range(int(left), int(rect.right()), grid_size):
            lines.append(((x, rect.top()), (x, rect.bottom())))
        for y in range(int(top), int(rect.bottom()), grid_size):
            lines.append(((rect.left(), y), (rect.right(), y)))

        for line in lines:
            painter.drawLine(*line[0], *line[1])

    def create_items(self):
        """Draw the items."""
        self._item_length = float(self._item_length) if self._item_length else 100.0
        self._item_height = float(self._item_height) if self._item_height else 100.0

        self._item = self._scene.addRect(0, 0, self._item_length, self._item_height)
        self._item.setFlags(
            QGraphicsItem.GraphicsItemFlag.ItemIsMovable
            | QGraphicsItem.GraphicsItemFlag.ItemIsSelectable
        )

        pen = QPen(QColor(255, 255, 255))
        self._item.setPen(pen)

        brush = QBrush(QColor(235, 211, 176))
        brush.setStyle(Qt.BrushStyle.SolidPattern)
        self._item.setBrush(brush)

    def mousePressEvent(self, event: QMouseEvent):
        """Handle mouse press event."""
        super().mousePressEvent(event)

        if event.button() == Qt.MouseButton.RightButton:
            item = self.itemAt(event.pos())
            if isinstance(item, QGraphicsItem) and item == self._item:
                self.show_dimension_dialog()

    def show_dimension_dialog(self):
        """Show the dimension dialog."""
        if self._item.isUnderMouse():
            self._dialog = DimensionDialog(0, 0, self)
            self._dialog.load_dialog_values(self._item_length, self._item_height)
            self._dialog.ok_button.clicked.connect(self.update_rect_dimensions)
            result = self._dialog.exec_()
            if result == QDialog.DialogCode.Accepted:
                self._item_length = self._dialog.length_edit.value()
                self._item_height = self._dialog.height_edit.value()
                self.update_rect_dimensions()

    def load_item_values(self):
        self._item_length = self._settings.value("item_length", 38, type=float)
        self._item_height = self._settings.value("item_height", 1000, type=float)

    def save_item_values(self):
        self._settings.setValue("item_length", self._item.rect().width())
        self._settings.setValue("item_height", self._item.rect().height())

    def update_rect_dimensions(self):
        """Update the dimensions of the rectangle."""
        try:
            length = float(self._dialog.length_edit.value())
            height = float(self._dialog.height_edit.value())
        except ValueError:
            return

        self._item.setRect(0, 0, length, height)
        self.fit_to_items()
        self._scene.update()

        self.save_item_values()

    def fit_to_items(self):
        """Fit the view to the items."""
        extra_space = 50
        items_rect = self._scene.itemsBoundingRect()
        scene_rect = items_rect.adjusted(
            -extra_space, -extra_space, extra_space, extra_space
        )
        self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def resizeEvent(self, event: "QResizeEvent"):
        """Resize the event."""
        super().resizeEvent(event)
        self.fit_to_items()
