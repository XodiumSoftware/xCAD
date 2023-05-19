from PySide6.QtWidgets import QFrame, QLabel, QWidget


class ObjectViewerWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initObjectViewerWidget()

    def initObjectViewerWidget(self):
        self.frame = QFrame()
        label = QLabel("Hello, World!", self.frame)
        label.setGeometry(10, 10, 200, 30)
