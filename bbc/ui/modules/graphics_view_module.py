from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QBrush, QColor, QPainter, QPen, QTransform
from PySide6.QtWidgets import (
    QGraphicsLineItem,
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
                "fill_pattern_scale": 1.0,
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
                "fill_pattern_scale": 10.0,
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
                "fill_pattern_scale": 1.0,
                "fill_pattern_angle": 90,
                "fill_color": QColor(0, 0, 255),
                "fill": True,
                "fill_opacity": 1.0,
            },
        ]

        total_length = sum(data["thickness"] for data in item_data)
        item_width = 100

        top_text = QGraphicsTextItem("Outside Face")
        top_text.setDefaultTextColor(QColor(255, 255, 255))
        top_text.setPos(
            (item_width - top_text.boundingRect().width()) / 2,
            -top_text.boundingRect().height(),
        )

        bottom_text = QGraphicsTextItem("Inside Face")
        bottom_text.setDefaultTextColor(QColor(255, 255, 255))
        bottom_text.setPos(
            (item_width - bottom_text.boundingRect().width()) / 2, total_length
        )

        y_position = 0
        for data in item_data:
            item_thickness = data["thickness"]
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
                brush.setTransform(
                    QTransform().scale(
                        data["fill_pattern_scale"], data["fill_pattern_scale"]
                    )
                )  # FIXME: this is not working
                item.setBrush(brush)

            dimension_text = f"{item_thickness}"
            dim_offset = 50
            dim_item = QGraphicsTextItem(dimension_text)
            dim_item.setDefaultTextColor(QColor(255, 0, 0))
            dim_item.setPos(
                item_width + dim_offset,
                y_position + item_thickness / 2 - dim_item.boundingRect().height() / 2,
            )

            dim_line = QGraphicsLineItem()
            dim_line.setPos(item_width + dim_offset, y_position)
            dim_line.setPen(QPen(QColor(0, 255, 0), 1, Qt.SolidLine))
            dim_line.setLine(0, 0, 0, item_thickness)

            total_dimension_text = f"{total_length}"
            total_dim_offset = 100
            total_dim_item = QGraphicsTextItem(total_dimension_text)
            total_dim_item.setPos(
                item_width + total_dim_offset,
                total_length / 2 - total_dim_item.boundingRect().height() / 2,
            )
            total_dim_item.setDefaultTextColor(QColor(255, 0, 0))
            total_dim_item.setRotation(0)

            total_dim_line = QGraphicsLineItem()
            total_dim_line.setPos(item_width + total_dim_offset, y_position)
            total_dim_line.setPen(QPen(QColor(0, 255, 0), 1, Qt.SolidLine))
            total_dim_line.setLine(0, 0, 0, item_thickness)

            self.scene.addItem(item)
            self.scene.addItem(dim_item)
            self.scene.addItem(dim_line)
            self.scene.addItem(total_dim_item)
            self.scene.addItem(total_dim_line)

            y_position += item_thickness

        self.scene.addItem(top_text)
        self.scene.addItem(bottom_text)

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
