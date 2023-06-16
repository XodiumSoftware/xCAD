import os
import sqlite3

from constants import DATABASE_PATH, DEBUG_NAME, INITIAL_GRAPHICS_OBJECT_DATA
from PySide6.QtCore import QObject, QRectF, Qt, Slot
from PySide6.QtGui import QBrush, QColor, QPainter, QPen
from PySide6.QtWidgets import (
    QDoubleSpinBox,
    QGraphicsLineItem,
    QGraphicsRectItem,
    QGraphicsScene,
    QGraphicsTextItem,
    QGraphicsView,
    QHeaderView,
    QLineEdit,
    QSizePolicy,
    QTableWidget,
    QTableWidgetItem,
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
        total_length = 0
        item_width = 100

        data_handler = DataBaseHandler()

        y_position = 0

        item_data = data_handler.execute_db_query(
            """
            SELECT * FROM GraphicsObjectData ORDER BY id
            """
        )

        for row in item_data:
            item_name = row["item_name"]
            item_thickness = row["thickness"]

            item = QGraphicsRectItem(0, y_position, item_width, item_thickness)
            pen = QPen(row["pen_color"], row["pen_thickness"], row["pen_style"])
            item.setPen(pen)

            if row["fill"]:
                fill_color = QColor(row["fill_color"])
                fill_color.setAlphaF(row["fill_opacity"])

                brush = QBrush(fill_color)
                brush.setStyle(row["fill_pattern"])

                item.setBrush(brush)

            self.scene.addItem(item)

            self.create_dimension(item, item_width, item_thickness, y_position)

            data_handler.execute_db_query(
                """
                INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)
                """,
                "item_name",
                item_name,
            )

            for parameter, value in row.items():
                if parameter not in ["id", "item_name", "thickness"]:
                    data_handler.execute_db_query(
                        """
                        INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)
                        """,
                        parameter,
                        str(value),
                    )

            total_length += item_thickness
            y_position += item_thickness

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
        dim_offset = 50
        dim_label_color = QColor(255, 0, 0)
        dim_pen = QPen(QColor(0, 255, 0), 1, Qt.SolidLine)

        dimension_text = item_thickness if item else total_length

        dim_label = QGraphicsTextItem(str(dimension_text))
        dim_label.setDefaultTextColor(dim_label_color)
        dim_label.setPos(
            item_width + (dim_offset if item else dim_offset * 2),
            y_position
            + (item_thickness if item else total_length) / 2
            - dim_label.boundingRect().height() / 2,
        )

        dim_line = QGraphicsLineItem()
        dim_line.setPos(
            item_width + (dim_offset if item else dim_offset * 2),
            y_position - dim_ext,
        )
        dim_line.setPen(dim_pen)
        dim_line.setLine(
            0,
            0,
            0,
            item_thickness + (dim_ext * 2) if item else total_length + (dim_ext * 2),
        )

        start_dim_line = QGraphicsLineItem()
        start_dim_line.setPos(item_width, y_position)
        start_dim_line.setPen(dim_pen)
        start_dim_line.setLine(
            0, 0, (dim_offset if item else dim_offset * 2) + dim_ext, 0
        )

        end_dim_line = QGraphicsLineItem()
        end_dim_line.setPos(item_width, y_position + item_thickness)
        end_dim_line.setPen(dim_pen)
        end_dim_line.setLine(
            0, 0, (dim_offset if item else dim_offset * 2) + dim_ext, 0
        )

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


class GraphicsTableViewModule(QTableWidget):
    def __init__(self, graphics_view, parent=None):
        """
        Initialize the table view module.
        """
        super().__init__(parent)
        self.graphics_view = graphics_view

        header_labels = ["Parameters", "Value"]
        self.setColumnCount(len(header_labels))
        self.setHorizontalHeaderLabels(header_labels)
        self.setEditTriggers(QTableWidget.AllEditTriggers)

        self.populate_table()
        self.set_column_properties()

    def populate_table(self):
        """
        Populate the table with the data from the database.
        """
        data_handler = DataBaseHandler()
        db_data = data_handler.get_db_data()

        self.setRowCount(len(db_data))
        for row, (parameter, value) in enumerate(db_data.items()):
            parameter_item = QTableWidgetItem(parameter)
            parameter_item.setFlags(parameter_item.flags() & ~Qt.ItemIsEditable)

            value_item = QTableWidgetItem(str(value))
            value_item.setFlags(value_item.flags() | Qt.ItemIsEditable)

            self.setItem(row, 0, parameter_item)
            self.setItem(row, 1, value_item)

    def set_column_properties(self):
        """
        Set the column properties.
        """
        self.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.verticalHeader().setVisible(True)

        for row in range(self.rowCount()):
            thickness_item = self.item(row, 1)
            if thickness_item is not None:
                thickness_text = thickness_item.text()
                try:
                    thickness_value = float(thickness_text)
                    if thickness_value.is_integer():
                        # Use QDoubleSpinBox for integer values
                        spin_box = QDoubleSpinBox()
                        spin_box.setRange(0, 999)
                        spin_box.setSingleStep(1)
                        spin_box.setValue(thickness_value)
                        self.setCellWidget(row, 1, spin_box)
                        spin_box.editingFinished.connect(self.update_graphics_view)
                    else:
                        # Use QLineEdit for non-integer values
                        line_edit = QLineEdit()
                        line_edit.setText(thickness_text)
                        self.setCellWidget(row, 1, line_edit)
                        line_edit.editingFinished.connect(self.update_graphics_view)
                except ValueError:
                    # Use QLineEdit for non-numeric values
                    line_edit = QLineEdit()
                    line_edit.setText(thickness_text)
                    self.setCellWidget(row, 1, line_edit)
                    line_edit.editingFinished.connect(self.update_graphics_view)

    def update_graphics_view(self):
        """
        Update the graphics view when the value is changed.
        """
        for row in range(self.rowCount()):
            spin_box = self.cellWidget(row, 1)
            value = spin_box.value()
            item_data = INITIAL_GRAPHICS_OBJECT_DATA[row]
            item_data["thickness"] = value

        self.graphics_view.scene.clear()
        self.graphics_view.create_items()


class DataBaseHandler(QObject):
    def __init__(self):
        super().__init__()
        self.connection = self.create_or_connect_db()

    def create_or_connect_db(self):
        if not os.path.exists(os.path.dirname(DATABASE_PATH)):
            os.makedirs(os.path.dirname(DATABASE_PATH))

        connection = sqlite3.connect(DATABASE_PATH)
        cursor = connection.cursor()

        cursor.execute(
            "CREATE TABLE IF NOT EXISTS GraphicsObjectData ("
            "id INTEGER PRIMARY KEY,"
            "parameter TEXT,"
            "value TEXT)"
        )

        cursor.execute("SELECT COUNT(*) FROM GraphicsObjectData")
        count = cursor.fetchone()[0]

        if count == 0:
            cursor.executemany(
                "INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)",
                [
                    (data["parameter"], data["value"])
                    for data in INITIAL_GRAPHICS_OBJECT_DATA
                ],
            )
            connection.commit()
        else:
            pass

        return connection

    def execute_db_query(self, query, *params):
        cursor = self.connection.cursor()
        cursor.execute(query, params)
        self.connection.commit()
        return cursor.fetchall()

    def get_db_data(self):
        cursor = self.connection.cursor()
        cursor.execute("SELECT parameter, value FROM GraphicsObjectData")
        settings = cursor.fetchall()
        return dict(settings)

    @Slot(dict)
    def save_db_data(self, settings):
        current_settings = self.get_db_data()

        if settings == current_settings:
            print(DEBUG_NAME + "No changes detected. Skipping save operation.")
            return

        with self.connection:
            self.execute_db_query("DELETE FROM settings")

            for name, value in settings.items():
                self.execute_db_query(
                    "INSERT INTO GraphicsObjectData (parameter, value) VALUES (?, ?)",
                    name,
                    value,
                )

        print(DEBUG_NAME + "Changes saved successfully.")

    @Slot()
    def discard_db_data(self):
        self.execute_db_query("ROLLBACK")
        print(DEBUG_NAME + "Changes discarded successfully.")

    def close_db_data(self):
        self.connection.close()
        print(DEBUG_NAME + "Connection closed.")
