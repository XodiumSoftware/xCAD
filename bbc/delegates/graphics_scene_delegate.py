from delegates.graphics_object_delegate import GraphicsObjectDelegate
from inits import Inits
from PySide6.QtCore import QSettings
from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem, QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A custom QGraphicsScene class."""

    def __init__(self, parent=None):
        """Initialize the class."""
        super().__init__(parent)
        self._settings_handler = QSettings()

        self.setup_graphics_scene()
        # self.create_objects_by_matrix()

    def setup_graphics_scene(self):
        """Setup the graphics scene."""
        object = QGraphicsRectItem()
        object.setRect(0, 0, 100, 100)

        pen = QPen()
        pen.setColor(QColor(0, 0, 0))
        object.setPen(pen)

        brush = QBrush()
        brush.setColor(QColor(255, 0, 0))
        object.setBrush(brush)

        object.setPos(0, 0)

        self.addItem(object)

    def create_objects_by_matrix(self):
        """Create objects on the scene based on the matrix."""
        matrix = Inits.setup_init_matrix_graphics_objects_position(
            GraphicsObjectDelegate()
        )

        cell_width = GraphicsObjectDelegate().rect().width()
        cell_height = GraphicsObjectDelegate().rect().height()

        for row, row_objects in enumerate(matrix):
            for col, _ in enumerate(row_objects):
                object_delegate = GraphicsObjectDelegate()
                object_delegate.setPos(col * cell_width, row * cell_height)
                self.addItem(object_delegate)
