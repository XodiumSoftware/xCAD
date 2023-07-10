import sqlite3
import sys

from PySide6 import QtCore, QtGui, QtWidgets

DATABASE_PATH = "tests/example.db"


class GraphicsView(QtWidgets.QGraphicsView):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setScene(QtWidgets.QGraphicsScene(self))
        self.setRenderHint(QtGui.QPainter.RenderHint.Antialiasing)
        self.setRenderHint(QtGui.QPainter.RenderHint.TextAntialiasing)
        self.setRenderHint(QtGui.QPainter.RenderHint.SmoothPixmapTransform)

    def update_rectangle(self, length, height):
        scene = self.scene()
        scene.clear()

        grid_size = 50
        grid_pen = QtGui.QPen(QtGui.QColor(200, 200, 200))
        for x in range(0, length + 1, grid_size):
            scene.addLine(x, 0, x, height, grid_pen)
        for y in range(0, height + 1, grid_size):
            scene.addLine(0, y, length, y, grid_pen)

        rect = QtCore.QRectF(0, 0, length, height)
        rect_item = QtWidgets.QGraphicsRectItem(rect)
        rect_item.setBrush(QtGui.QColor(0, 0, 255, 100))
        scene.addItem(rect_item)


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("PySide6 Table Example")

        self.table = QtWidgets.QTableWidget()
        self.graphicsView = GraphicsView()
        self.saveButton = QtWidgets.QPushButton("Save")
        self.discardButton = QtWidgets.QPushButton("Discard")
        self.resetButton = QtWidgets.QPushButton("Reset")

        self.setup_ui()
        self.init_db()
        self.init_table()
        self.update_rectangle()

    def setup_ui(self):
        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(self.graphicsView)

        buttonLayout = QtWidgets.QHBoxLayout()
        buttonLayout.addWidget(self.saveButton)
        buttonLayout.addWidget(self.discardButton)
        buttonLayout.addWidget(self.resetButton)

        layout.addLayout(buttonLayout)

        widget = QtWidgets.QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

        self.saveButton.clicked.connect(self.save)
        self.discardButton.clicked.connect(self.discard)
        self.resetButton.clicked.connect(self.reset)

    def init_table(self):
        self.table = QtWidgets.QTableWidget()
        header = self.table.horizontalHeader()
        header.setSectionResizeMode(QtWidgets.QHeaderView.ResizeMode.Stretch)

        self.table.itemChanged.connect(self.update_rectangle)

        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(self.table)

        # main_layout = self.centralWidget().layout()
        # main_layout.insertLayout(0, layout)

    def init_db(self):
        conn = sqlite3.connect(DATABASE_PATH)
        c = conn.cursor()
        c.execute("SELECT * FROM data")
        data = c.fetchall()
        print("Retrieved data:", data)

        self.table.setColumnCount(2)
        self.table.setRowCount(len(data))
        self.table.setHorizontalHeaderLabels(["X", "Y"])

        for row, (x, y) in enumerate(data):
            item_x = QtWidgets.QTableWidgetItem()
            item_x.setData(QtCore.Qt.ItemDataRole.EditRole, x)
            item_y = QtWidgets.QTableWidgetItem()
            item_y.setData(QtCore.Qt.ItemDataRole.EditRole, y)
            print(
                f"Item in row {row}: {item_x.data(QtCore.Qt.ItemDataRole.EditRole)}, {item_y.data(QtCore.Qt.ItemDataRole.EditRole)}"
            )
            self.table.setItem(row, 0, item_x)
            self.table.setItem(row, 1, item_y)

    def update_rectangle(self):
        length_item = self.table.item(0, 1)
        height_item = self.table.item(1, 1)

        if length_item is None or height_item is None:
            print("Item in table is None")
            return

        length_text = length_item.text()
        height_text = height_item.text()

        if not length_text or not height_text:
            print("Text is empty in table")
            return

        try:
            length = float(length_text)
            height = float(height_text)
            self.graphicsView.update_rectangle(length, height)
        except ValueError:
            print("Invalid float value in table")

    def save(self):
        conn = sqlite3.connect(DATABASE_PATH)
        c = conn.cursor()
        c.execute("DELETE FROM data")
        for row in range(self.table.rowCount()):
            x = self.table.item(row, 0).data(QtCore.Qt.ItemDataRole.EditRole)
            y = self.table.item(row, 1).data(QtCore.Qt.ItemDataRole.EditRole)
            c.execute("INSERT INTO data VALUES (?, ?)", (x, y))
        conn.commit()

    def discard(self):
        self.init_table()

    def reset(self):
        self.init_table()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec())
