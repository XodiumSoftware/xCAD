from PySide6.QtCore import Qt
from PySide6.QtGui import QColor, QPainter, QPen
from PySide6.QtWidgets import QGraphicsScene, QGraphicsView, QVBoxLayout


class GraphicsViewModule(QGraphicsView):
    def __init__(self, parent=None):
        """
        Initialize the GraphicsView.
        """
        super().__init__(parent)

        self.scene = QGraphicsScene(self)
        self.setScene(self.scene)

        self.scene.setBackgroundBrush(Qt.white)

        self.setRenderHint(QPainter.Antialiasing)
        self.setDragMode(QGraphicsView.ScrollHandDrag)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.AnchorUnderMouse)

    def setup_graphics_view(self):
        """
        Setup the GraphicsView.
        """
        layout = QVBoxLayout(self)

        # Add any other widgets or elements here as needed
        # ...

        layout.addWidget(self)

        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def drawBackground(self, painter: QPainter, rect):
        """
        Draw a grid background.
        """
        super().drawBackground(painter, rect)

        gridSize = 20
        pen = QPen(QColor(200, 200, 200), 0.5, Qt.SolidLine)
        painter.setPen(pen)

        left = int(rect.left()) - (int(rect.left()) % gridSize)
        top = int(rect.top()) - (int(rect.top()) % gridSize)

        lines = []
        for x in range(int(left), int(rect.right()), gridSize):
            lines.append(((x, rect.top()), (x, rect.bottom())))
        for y in range(int(top), int(rect.bottom()), gridSize):
            lines.append(((rect.left(), y), (rect.right(), y)))

        for line in lines:
            painter.drawLine(*line)
