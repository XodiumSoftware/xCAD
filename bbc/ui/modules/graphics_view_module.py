from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QColor, QPainter, QPen
from PySide6.QtWidgets import QGraphicsRectItem, QGraphicsScene, QGraphicsView

GRIDSIZE = 50
PEN = QPen(QColor(200, 200, 200), 0.5, Qt.SolidLine)
SCENE_BACKGROUND_COLOR = QColor(0, 0, 0)


class GraphicsViewModule(QGraphicsView):
    def __init__(self, parent=None):
        """
        Initialize the GraphicsView.
        """
        super().__init__(parent)
        self.setup_graphics_view()

    def setup_graphics_view(self):
        """
        Setup the GraphicsView.
        """
        self.scene = QGraphicsScene(self)
        self.setScene(self.scene)

        self.scene.setBackgroundBrush(SCENE_BACKGROUND_COLOR)

        self.setRenderHint(QPainter.Antialiasing)
        self.setDragMode(QGraphicsView.ScrollHandDrag)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.AnchorUnderMouse)

        self.draw_items()

    def drawBackground(self, painter: QPainter, rect: QRectF):
        """
        Draw the background.
        """
        super().drawBackground(painter, rect)

        painter.setPen(PEN)

        left = int(rect.left()) - (int(rect.left()) % GRIDSIZE)
        top = int(rect.top()) - (int(rect.top()) % GRIDSIZE)

        lines = []
        for x in range(int(left), int(rect.right()), GRIDSIZE):
            lines.append(((x, rect.top()), (x, rect.bottom())))
        for y in range(int(top), int(rect.bottom()), GRIDSIZE):
            lines.append(((rect.left(), y), (rect.right(), y)))

        for line in lines:
            painter.drawLine(*line[0], *line[1])

    def draw_items(self):
        """
        Draw the items.
        """
        rect = QGraphicsRectItem(50, 50, 100, 100)
        rect.setBrush(QColor(255, 0, 0))
        self.scene.addItem(rect)
