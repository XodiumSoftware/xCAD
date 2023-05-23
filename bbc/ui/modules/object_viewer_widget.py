from PySide6.QtWidgets import QFrame, QVBoxLayout, QWidget


class ObjectViewerWidget(QWidget):
    def __init__(self, parent=None):
        """
        Initialize the ObjectViewerWidget.
        """
        super().__init__(parent)
        self.init_object_viewer_widget()

    def init_object_viewer_widget(self):
        """
        Initialize the object viewer widget.
        """
        layout = QVBoxLayout(self)

        box = QFrame(self)
        box.setStyleSheet(
            "QFrame { border: 1px solid black; background-color: lightgray; }"
        )
        layout.addWidget(box)

        self.setLayout(layout)
        self.hide()
