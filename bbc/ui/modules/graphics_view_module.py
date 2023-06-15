from cgitb import text

from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QBrush, QColor, QPainter, QPen, QTransform
from PySide6.QtWidgets import (
    QGraphicsRectItem,
    QGraphicsScene,
    QGraphicsTextItem,
    QGraphicsView,
    QSizePolicy,
)


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

        self.scene.setBackgroundBrush(QColor(0, 0, 0))

        self.setDragMode(QGraphicsView.ScrollHandDrag)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.AnchorUnderMouse)
        self.setMinimumSize(300, 300)
        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        self.draw_items()

    def drawBackground(self, painter: QPainter, rect: QRectF):
        """
        Draw the background.
        """
        super().drawBackground(painter, rect)

        painter.setPen(QPen(QColor(200, 200, 200), 0.5, Qt.SolidLine))

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

    def draw_items(self):
        """
        Draw the items.
        """
        item_data = [
            {
                "draw_order": 0,
                "thickness": 60,
                "pen_color": QColor(255, 255, 255),
                "pen_thickness": 1,
                "pen_style": Qt.SolidLine,
                "fill_pattern": Qt.SolidPattern,
                "fill_pattern_angle": None,
                "fill_color": QColor(255, 0, 0),
                "fill": True,
                "fill_opacity": 0.5,
            },
            {
                "draw_order": 1,
                "thickness": 170,
                "pen_color": QColor(255, 255, 255),
                "pen_thickness": 1,
                "pen_style": Qt.DashLine,
                "fill_pattern": Qt.DiagCrossPattern,
                "fill_pattern_angle": None,
                "fill_color": QColor(0, 255, 0),
                "fill": True,
                "fill_opacity": 1.0,
            },
            {
                "draw_order": 2,
                "thickness": 12,
                "pen_color": QColor(0, 0, 255),
                "pen_thickness": 1,
                "pen_style": Qt.SolidLine,
                "fill_pattern": Qt.BDiagPattern,
                "fill_pattern_angle": 90,
                "fill_color": QColor(0, 0, 255),
                "fill": True,
                "fill_opacity": 1.0,
            },
        ]

        # TODO: add func that based on the draw_order in the item_data, raises the items when overlapping based on an numerical order.

        y_position = 0
        for data in item_data:
            item_thickness = data["thickness"]
            item_width = 100
            item = QGraphicsRectItem(0, y_position, item_width, item_thickness)
            pen = QPen(data["pen_color"], data["pen_thickness"], data["pen_style"])
            item.setPen(pen)

            if data["fill"]:
                fill_color = QColor(data["fill_color"])
                fill_color.setAlphaF(data["fill_opacity"])
                brush = QBrush(fill_color)

                if data["fill_pattern_angle"] is not None:
                    pattern_transform = QTransform()  # FIXME: this is not working
                    pattern_transform.rotate(data["fill_pattern_angle"])
                    brush.setTransform(pattern_transform)

                brush.setStyle(data["fill_pattern"])
                item.setBrush(brush)

            self.scene.addItem(item)

            dimension_text = f"{item_thickness} mm"
            text_item = QGraphicsTextItem(dimension_text)
            text_item.setPos(item_width + 50, y_position)
            text_item.setDefaultTextColor(QColor(255, 255, 255))
            text_item.setRotation(90)
            self.scene.addItem(text_item)

            y_position += item_thickness

    def fit_to_items(self):
        """
        Automatically zoom in to fit the items in the view with some extra space.
        """
        extra_space = 50
        items_rect = self.scene.itemsBoundingRect()
        scene_rect = items_rect.adjusted(
            -extra_space, -extra_space, extra_space, extra_space
        )
        self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

    def resizeEvent(self, event):
        """
        Override the resize event to fit the items whenever the view is resized.
        """
        super().resizeEvent(event)
        self.fit_to_items()
