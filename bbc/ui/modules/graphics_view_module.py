# from constants import DEBUG_NAME
# # from handlers.db_handler import DataBaseHandler
# from PySide6.QtCore import QRectF, Qt
# from PySide6.QtGui import QBrush, QColor, QPainter, QPen
# from PySide6.QtWidgets import (
#     QGraphicsLineItem,
#     QGraphicsRectItem,
#     QGraphicsScene,
#     QGraphicsTextItem,
#     QGraphicsView,
#     QSizePolicy,
# )


# class GraphicsViewModule(QGraphicsView):
#     def __init__(self, parent=None):
#         """
#         Initialize the GraphicsView.
#         """
#         super().__init__(parent)
#         self.setup_graphics_view()

#     def setup_graphics_view(self):
#         """
#         Setup the GraphicsView.
#         """
#         self.scene = QGraphicsScene(self)
#         self.setScene(self.scene)

#         self.scene.setBackgroundBrush(QColor(0, 0, 0))

#         self.setDragMode(QGraphicsView.ScrollHandDrag)
#         self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
#         self.setResizeAnchor(QGraphicsView.AnchorUnderMouse)
#         self.setMinimumSize(300, 300)
#         self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

#         self.create_items()

#     def drawBackground(self, painter: QPainter, rect: QRectF):
#         """
#         Draw the background.
#         """
#         super().drawBackground(painter, rect)

#         painter.setPen(QPen(QColor(200, 200, 200), 0.5, Qt.SolidLine))

#         grid_size = 50

#         left = int(rect.left()) - (int(rect.left()) % grid_size)
#         top = int(rect.top()) - (int(rect.top()) % grid_size)

#         lines = []
#         for x in range(int(left), int(rect.right()), grid_size):
#             lines.append(((x, rect.top()), (x, rect.bottom())))
#         for y in range(int(top), int(rect.bottom()), grid_size):
#             lines.append(((rect.left(), y), (rect.right(), y)))

#         for line in lines:
#             painter.drawLine(*line[0], *line[1])

#     def create_items(self):
#         """
#         Draw the items.
#         """
#         total_length = 0
#         item_width = 100

#         # data_handler = DataBaseHandler()

#         y_position = 0

#         # item_data = data_handler.execute_db_query(
#             """
#             SELECT * FROM GraphicsObjectData ORDER BY id
#             """
#         )

#         # for row in item_data:
#             item_name = row[0]
#             item_thickness = row[1]

#             try:
#                 item_thickness = int(item_thickness)
#             except ValueError:
#                 print(
#                     DEBUG_NAME
#                     + f"Skipping item '{item_name}' due to invalid thickness value: {item_thickness}"
#                 )
#                 continue

#             item = QGraphicsRectItem(0, y_position, item_width, item_thickness)
#             pen = QPen(row["pen_color"], row["pen_thickness"], row["pen_style"])
#             item.setPen(pen)

#             if row["fill"]:
#                 fill_color = QColor(row["fill_color"])
#                 fill_color.setAlphaF(row["fill_opacity"])

#                 brush = QBrush(fill_color)
#                 brush.setStyle(row["fill_pattern"])

#                 item.setBrush(brush)

#             self.scene.addItem(item)

#             self.create_dimension(item, item_width, item_thickness, y_position)

#             data_handler.execute_db_query(
#                 """
#                 INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)
#                 """,
#                 ("item_name", item_name),
#             )

#             for parameter, value in row.items():
#                 if parameter not in ["id", "item_name", "thickness"]:
#                     data_handler.execute_db_query(
#                         """
#                         INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)
#                         """,
#                         (str(value), parameter),
#                     )

#             total_length += item_thickness
#             y_position += item_thickness

#         self.create_dimension(
#             None, item_width, total_length, y_position - total_length, total_length
#         )
#         self.create_label(item_width, total_length)

#     def create_label(self, item_width, total_length):
#         """
#         Create the label.
#         """
#         top_text = QGraphicsTextItem("Outside Face")
#         top_text.setDefaultTextColor(QColor(255, 255, 255))
#         top_text.setPos(
#             (item_width - top_text.boundingRect().width()) / 2,
#             -top_text.boundingRect().height(),
#         )

#         bottom_text = QGraphicsTextItem("Inside Face")
#         bottom_text.setDefaultTextColor(QColor(255, 255, 255))
#         bottom_text.setPos(
#             (item_width - bottom_text.boundingRect().width()) / 2, total_length
#         )

#         self.scene.addItem(top_text)
#         self.scene.addItem(bottom_text)

#     def create_dimension(
#         self, item, item_width, item_thickness, y_position, total_length=None
#     ):
#         """
#         Create the dimension for an item or the total dimension.
#         """
#         dim_ext = 10
#         dim_offset = 50
#         dim_label_color = QColor(255, 0, 0)
#         dim_pen = QPen(QColor(0, 255, 0), 1, Qt.SolidLine)

#         dimension_text = item_thickness if item else total_length

#         dim_label = QGraphicsTextItem(str(dimension_text))
#         dim_label.setDefaultTextColor(dim_label_color)
#         dim_label.setPos(
#             item_width + (dim_offset if item else dim_offset * 2),
#             y_position
#             + (item_thickness if item else total_length) / 2
#             - dim_label.boundingRect().height() / 2,
#         )

#         dim_line = QGraphicsLineItem()
#         dim_line.setPos(
#             item_width + (dim_offset if item else dim_offset * 2),
#             y_position - dim_ext,
#         )
#         dim_line.setPen(dim_pen)
#         dim_line.setLine(
#             0,
#             0,
#             0,
#             item_thickness + (dim_ext * 2) if item else total_length + (dim_ext * 2),
#         )

#         start_dim_line = QGraphicsLineItem()
#         start_dim_line.setPos(item_width, y_position)
#         start_dim_line.setPen(dim_pen)
#         start_dim_line.setLine(
#             0, 0, (dim_offset if item else dim_offset * 2) + dim_ext, 0
#         )

#         end_dim_line = QGraphicsLineItem()
#         end_dim_line.setPos(item_width, y_position + item_thickness)
#         end_dim_line.setPen(dim_pen)
#         end_dim_line.setLine(
#             0, 0, (dim_offset if item else dim_offset * 2) + dim_ext, 0
#         )

#         self.scene.addItem(dim_label)
#         self.scene.addItem(start_dim_line)
#         self.scene.addItem(dim_line)
#         self.scene.addItem(end_dim_line)

#     def fit_to_items(self):
#         """
#         Automatically zoom in to fit the items in the view with some extra space.
#         """
#         extra_space = 50
#         items_rect = self.scene.itemsBoundingRect()
#         scene_rect = items_rect.adjusted(
#             -extra_space, -extra_space, extra_space, extra_space
#         )
#         self.fitInView(scene_rect, Qt.AspectRatioMode.KeepAspectRatio)

#     def resizeEvent(self, event):
#         """
#         Override the resize event to fit the items whenever the view is resized.
#         """
#         super().resizeEvent(event)
#         self.fit_to_items()
