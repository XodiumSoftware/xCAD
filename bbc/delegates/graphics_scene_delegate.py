from PySide6.QtGui import QBrush, QColor, QPen
from PySide6.QtWidgets import QGraphicsRectItem, QGraphicsScene


class GraphicsSceneDelegate(QGraphicsScene):
    """A custom QGraphicsScene class."""

    def __init__(self, parent=None):
        """Initialize the class."""
        super().__init__(parent)
        self.setup_graphics_scene()

    def setup_graphics_scene(self):
        """Setup the graphics scene."""
        wall_width = 3000
        wall_height = 6000
        beam_width = 38
        vertical_beam_spacing = 600

        sls_horizontal_beam_height = 2400
        sls_vertical_beam_width = 1200

        white_pen = QPen(QColor("#FFFFFF"))
        beam_brush_color = QColor("#ebd3b0")

        num_horizontal_beams = wall_height // sls_horizontal_beam_height
        for i in range(num_horizontal_beams + 1):
            rect_item = QGraphicsRectItem(
                0, i * sls_horizontal_beam_height, wall_width, beam_width
            )
            rect_item.setBrush(QBrush(beam_brush_color))
            rect_item.setPen(white_pen)
            self.addItem(rect_item)

        num_vertical_beams = wall_width // sls_vertical_beam_width
        for i in range(num_vertical_beams + 1):
            x_position = i * sls_vertical_beam_width
            if i > 0:
                x_position += i * (vertical_beam_spacing // beam_width) * beam_width

            y_position = -beam_width if i > 0 else 0
            beam_height = wall_height - 2 * beam_width if i > 0 else wall_height

            rect_item = QGraphicsRectItem(
                x_position, y_position, beam_width, beam_height
            )
            rect_item.setBrush(QBrush(beam_brush_color))
            rect_item.setPen(white_pen)
            self.addItem(rect_item)

        bounding_rect = self.itemsBoundingRect()
        self.setSceneRect(bounding_rect)
