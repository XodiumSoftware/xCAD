from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QBrush, QColor, QPainter, QPen
from PySide6.QtWidgets import (
    QGraphicsLineItem,
    QGraphicsRectItem,
    QGraphicsScene,
    QGraphicsTextItem,
    QGraphicsView,
    QSizePolicy,
)

ITEM_DATA = [
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

        self.create_items()

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

    def create_items(self):
        """
        Draw the items.
        """
        total_length = sum(data["thickness"] for data in ITEM_DATA)
        item_width = 100

        y_position = 0
        for data in ITEM_DATA:
            item_thickness = data["thickness"]
            item = QGraphicsRectItem(0, y_position, item_width, item_thickness)
            pen = QPen(data["pen_color"], data["pen_thickness"], data["pen_style"])
            item.setPen(pen)

            if data["fill"]:
                fill_color = QColor(data["fill_color"])
                fill_color.setAlphaF(data["fill_opacity"])

                brush = QBrush(fill_color)
                brush.setStyle(data["fill_pattern"])

                item.setBrush(brush)

            self.scene.addItem(item)

            self.create_dimension(item, item_width, item_thickness, y_position)

            y_position += item_thickness

        # FIXME: the total dimension line is not drawn and or visible. it looks like the x position is not correct. it should be twice that of the dim_offset.
        self.create_dimension(
            None, item_width, total_length, y_position - total_length, total_length
        )
        self.create_label(item_width, total_length)

    def create_label(self, item_width, total_length):
        """
        Create the label.
        """
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

        self.scene.addItem(top_text)
        self.scene.addItem(bottom_text)

    def create_dimension(
        self, item, item_width, item_thickness, y_position, total_length=None
    ):
        """
        Create the dimension for an item or the total dimension.
        """
        dim_ext = 10

        if item:
            dimension_text = f"{item_thickness}"
        else:
            dimension_text = f"{total_length}"

        dim_offset = 50
        dim_label = QGraphicsTextItem(dimension_text)
        dim_label.setDefaultTextColor(QColor(255, 0, 0))

        if item:
            dim_label.setPos(
                item_width + dim_offset,
                y_position + item_thickness / 2 - dim_label.boundingRect().height() / 2,
            )
        else:
            dim_label.setPos(
                item_width + (dim_offset * 2),
                y_position + total_length / 2 - dim_label.boundingRect().height() / 2,
            )

        dim_line = QGraphicsLineItem()

        if item:
            dim_line.setPos(item_width + dim_offset, y_position - dim_ext)
        else:
            dim_line.setPos(item_width + (dim_offset * 2), y_position - dim_ext)

        dim_line.setPen(QPen(QColor(0, 255, 0), 1, Qt.SolidLine))

        if item:
            dim_line.setLine(0, 0, 0, item_thickness + (dim_ext * 2))
        else:
            dim_line.setLine(0, 0, 0, total_length + (dim_ext * 2))

        start_dim_line = QGraphicsLineItem()
        start_dim_line.setPos(item_width, y_position)
        start_dim_line.setPen(QPen(QColor(0, 255, 0), 1, Qt.SolidLine))

        if item:
            start_dim_line.setLine(0, 0, dim_offset + dim_ext, 0)
        else:
            start_dim_line.setLine(0, 0, (dim_offset * 2) + dim_ext, 0)

        end_dim_line = QGraphicsLineItem()
        end_dim_line.setPos(item_width, y_position + item_thickness)
        end_dim_line.setPen(QPen(QColor(0, 255, 0), 1, Qt.SolidLine))

        if item:
            end_dim_line.setLine(0, 0, dim_offset + dim_ext, 0)
        else:
            end_dim_line.setLine(0, 0, (dim_offset * 2) + dim_ext, 0)

        self.scene.addItem(dim_label)
        self.scene.addItem(start_dim_line)
        self.scene.addItem(dim_line)
        self.scene.addItem(end_dim_line)

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
